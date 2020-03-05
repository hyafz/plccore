# plccore

## 1、介绍


plccore是一个基于rt-thread的可编程控制器（PLC）运行时内核。

### 1.1 目录结构

| 名称 | 说明 |
| ---- | ---- |
| docs  | 文档目录 |
| examples | 例子目录，并有相应的一些说明 |
| inc  | 头文件目录 |
| src  | 源代码目录 |
| port | 移植代码目录。 |

### 1.2 许可证

plccore package 遵循 LGPLv2.1 许可，详见 `LICENSE` 文件。

### 1.3 依赖

- RT-Thread nano 3.1.3+
- RT-Thread Studio软件（用于移植）
- Stm32CubeMX软件（用于移植）

## 3、使用 plccore

为了使plccore适配你的微处理器，需要进行一些移植工作。详细移植说明文档位于[`/docs`](/docs)下，使用前 **务必查看**

## 4、注意事项

移植过程需要使用STM32CubeMX与RT-Thread两个软件，请先安装好。

## 5、联系方式 & 感谢

* 维护：hyafz(401190549@qq.com)
* 主页：https://github.com/hyafz/plccore