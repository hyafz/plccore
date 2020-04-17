/**
  * @file  plc_io.c
  * @brief  PLC与输入输出相关的实现
  * @author  hyafz
  */
/* includes -----------------------------------------------------------------*/
#include <string.h>
#include <rtthread.h>
#ifdef RT_USING_DEVICE
#include <rtdevice.h>
#endif
#include "plc_type_define.h"
#include "plc_mem.h"
#include "plc_io.h"

/* Private define -----------------------------------------------------------*/
#define DEV_INPUT_SCAN_GAP_TIME     10  /**< 输入设备扫描间隔时间，单位为SysTick */
#define DEV_INPUT_DEBOUNCE_TIMES    3   /**< 输入设备检测去抖次数 */
/* Private typedef ----------------------------------------------------------*/
/* Private macro ------------------------------------------------------------*/
/* Variables ----------------------------------------------------------------*/
/**
 * @brief 输入设备控制结构数组
 * @note 第0个数组成员必须为运行开关RUN Switch，然后依次是数字量输入点IX0 ~ IXn
 */
DEV_IN_CTRL_S DevInput[DEV_INPUT_NUM] = DI_INIT_INFO;
/**
 * @brief 输出设备控制结构数组
 * @note 第0个必须为运行状态LED，第1个为停止状态LED，第2个为错误状态LED，然后依次是数字量输出点QX0 ~ QXn
 */
DEV_OUT_CTRL_S DevOutput[DEV_OUTPUT_NUM] = DO_INIT_INFO;
/* Private function declaration ---------------------------------------------*/
/* Functions ----------------------------------------------------------------*/

/**
  * @brief 所有IO设备的初始化
*/
void plcIOInit(void)
{
#ifdef RT_USING_DEVICE
    int i;
    for(i = 0; i < DEV_INPUT_NUM; i++){
        rt_pin_mode(DevInput[i].pin, PIN_MODE_INPUT);
    }
    for(i = 0; i < DEV_OUTPUT_NUM; i++){
        rt_pin_mode(DevOutput[i].pin, PIN_MODE_OUTPUT);
        /* 为输出设备设置初始状态 */
        DevOutput[i].out_value = DevOutput[i].off_value;
        rt_pin_write(DevOutput[i].pin, DevOutput[i].out_value);
    }
#else
    extern void devIOInit(void);
    devIOInit();
#endif
}

/**
  * @todo 如果把这个变量定义为静态的局部变量，使用gcc编译后发现map文件中没有为它分配地址。
  *       在keil中使用armcc编译则会为它分配一个data区地址。这个区别导致触发了HardFault，需要深入分析原因。
  */
static int ScanTimeCnt = 0;         /* 扫描时间计数 */
/**
  * @brief 输入设备状态扫描
  */
void plcInputScan(void)
{
    int i;
    int curr_input_state;

    ScanTimeCnt++;
    if(ScanTimeCnt < DEV_INPUT_SCAN_GAP_TIME){
        return;
    }
    ScanTimeCnt = 0;

    for(i = 0; i < DEV_INPUT_NUM; i++){
#ifdef RT_USING_DEVICE
        curr_input_state = rt_pin_read(DevInput[i].pin);
#else
        extern unsigned char devInputPinRead(unsigned int pin);
        curr_input_state = devInputPinRead(DevInput[i].pin);
#endif
        if(curr_input_state == DevInput[i].state){
            //输入状态与当前状态一致，没有变化，判断下一个输入点。
            continue;
        }
        //输入状态与当前状态不一致
        if(curr_input_state == DevInput[i].prev_input_state){
            //输入状态与上一次输入状态一致，已处于去抖阶段
            if(DevInput[i].state_debounce_time < DEV_INPUT_DEBOUNCE_TIMES){
                //去抖未完成，继续去抖
                DevInput[i].state_debounce_time++;
            }else{
                //去抖完成，状态生效
                DevInput[i].state = curr_input_state;
            }
        }else{
            //输入状态与上一次输入状态不一致，开始去抖
            DevInput[i].prev_input_state = curr_input_state;
            DevInput[i].state_debounce_time = 0;
        }
    }
}

/**
  * @brief  获取指定输入对应的管脚状态的函数
  * @param  x DI编号
  * @return 0 or 1
  */
unsigned char devInputGet(unsigned int x)
{
    return (DevInput[x].state != DevInput[x].default_state);
}

/**
  * @brief 设置输出设备状态
  * @param dev_id 输出设备ID
  * @param sw 状态开关 0 关闭，1 打开
  */
void devOutputSet(int8_t dev_id, uint8_t sw)
{
  if((dev_id < DEV_FIRST_OUTPUT_ID) || (dev_id > DEV_LAST_OUTPUT_ID)){
    return;
  }

  if(sw == DEV_OUTPUT_ON){
    DevOutput[dev_id].out_value = DevOutput[dev_id].on_value;
  }else{
    DevOutput[dev_id].out_value = DevOutput[dev_id].off_value;
  }
#ifdef RT_USING_DEVICE
  rt_pin_write(DevOutput[dev_id].pin, DevOutput[dev_id].out_value);
#else
  extern void devOutputPinWrite(unsigned int pin, unsigned int val);
  devOutputPinWrite(DevOutput[dev_id].pin, DevOutput[dev_id].out_value);
#endif
}

/**
  * @brief 检查是否处于运行模式，返回1表示处于运行模式，返回0表示处于停止模式。
  * @retval 1 处于运行模式
  * @retval 0 处于停止模式
  */
int8_t isRunMode(void)
{
	int8_t run_mode = 0;
	if(DevInput[DEV_RUN_SW_ID].state != DevInput[DEV_RUN_SW_ID].default_state){
		run_mode = 1;
	}else{
		run_mode = 0;
	}
	return run_mode;
}

static int8_t PrevRunMode = -1;
int8_t isRunModeSwitched(void)
{
	int8_t mode_switched = 0;
	uint8_t run_mode = isRunMode();
	if(PrevRunMode != run_mode){
		if(PrevRunMode != -1){
			mode_switched = 1;
		}
		PrevRunMode = run_mode;
	}
	return mode_switched;
}

int LedTogglePeriod = 0;
/**
  * @brief 设置LED闪烁周期，如果周期为0表示不闪烁。
  */
void ledToggleSet(int nms)
{
	LedTogglePeriod = nms;
}

static int ToggleTimeCnt = 0;
static uint8_t ToggleState = 0;
void ledToggleUpdate(void)
{
	
	if(LedTogglePeriod == 0){
		LED_RUN_OFF();
		return;
	}
	
	ToggleTimeCnt++;
	if(ToggleTimeCnt >= LedTogglePeriod){
		ToggleTimeCnt = 0;
		if(ToggleState == 0){
			ToggleState = 1;
			//LED_RUN_ON();
		}else{
			ToggleState = 0;
			//LED_RUN_OFF();
		}
	}
}

/**
  * @brief PLC本地数字量输入点映像区刷新。
  */
void plcLocalDiRefresh(void)
{
	int x;
	unsigned char diTmp;
	unsigned int offset;

	for(x = 0; x < LOC_DI_NUM; x++){
		offset = x % 8;
		if(offset == 0){
			diTmp = 0;
		}
		diTmp |= (devInputGet(DEV_IX0_ID + x) << offset);
		if((offset == 7) || (x == LOC_DI_NUM - 1)){
			I[x / 8] = diTmp;
		}
	}
}

/**
  * @brief PLC本地数字量输出点状态刷新。
  */
void plcLocalDqRefresh(void)
{
	unsigned int x;
	for(x = 0; x < LOC_DQ_NUM; x++)
	{
	    devOutputSet(DEV_QX0_ID + x, (Q[(x >> 3)] >> (x & 0x07)) & 0x01);
	}
}

/**
  * @brief PLC本地数字量输出点在停机时全部输出低。
  */
void plcLocalDqOutputWhenStopped(void)
{
	memset((void*)Q, 0, sizeof(Q));
	plcLocalDqRefresh();
}



/**
  * @brief PLC本地模拟量输入点映像区刷新。
  */
void plcLocalAiRefresh(void)
{
	//test
    *(REAL *)&I[12] = 3.14159;
}

/**
  * @brief PLC本地模拟量输出点状态刷新。
  */
void plcLocalAqRefresh(void)
{

}
