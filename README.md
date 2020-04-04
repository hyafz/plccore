# plccore

## 1、介绍

plccore是一个基于rt-thread的可编程控制器（PLC）运行时内核，与本人开发的上位机编程软件——plcide一起构成一套完整的可编程控制器开发系统。依托RT-Thread的大量板级支持包（BSP），plccore可以快速移植适配更多MCU，节省大量开发时间。对于MCU开发者，plcide + plccore + rt-thread提供一种图形化、表格化的方式来开发MCU控制程序，非常方便、简单。

### 1.1 plccore的目标
开发plccore + plcide可编程控制器系统的目标有三点：
- 实现完全遵循IEC61131-3标准的可扩展的开放型PLC编程系统，提高代码模块复用率；
- 实现编译型PLC，相比解释型PLC不论指令密度还是执行效率都大大提升；
- 探索使用图形化和表格化的形式开发嵌入式应用程序，简化MCU开发；

### 1.2 plccore能做什么？
对于MCU开发者，当你完成了RT-Thread + plccore移植后，可以使用plcide进行：
1. 图形化编写控制逻辑，任意多平台复用
2. 表格化配置多任务系统，不用写代码，支持不同的任务驱动模式：
   - 循环执行
   - 外部信号触发
   - 定时触发

### 1.3 目录结构

| 名称 | 说明 |
| ---- | ---- |
| docs  | 文档目录 |
| examples | 例子目录，并有相应的一些说明 |
| inc  | 头文件目录 |
| src  | 源代码目录 |
| port | 移植代码目录 |

### 1.4 许可证

plccore package 遵循 LGPLv2.1 许可，详见 `LICENSE` 文件。

### 1.5 依赖

- RT-Thread nano 3.1.3+

## 2 如何移植plccore？
请参考软件包docs目录下给出的移植教程：

GitHub: https://github.com/hyafz/plccore/blob/master/docs/plccore%E8%BD%AF%E4%BB%B6%E5%8C%85%E7%A7%BB%E6%A4%8D%E5%8F%8A%E4%BD%BF%E7%94%A8%E8%AF%B4%E6%98%8E.md

码云： https://gitee.com/hyafz/plccore/blob/master/docs/plccore%E8%BD%AF%E4%BB%B6%E5%8C%85%E7%A7%BB%E6%A4%8D%E5%8F%8A%E4%BD%BF%E7%94%A8%E8%AF%B4%E6%98%8E.md

## 3 如何获取上位机编程软件plcide？
发送电子邮件至 401190549@qq.com 索取。

## 4 如何使用plcide？
请参考软件包docs目录下给出的PLC集成开发环境用户手册：

GitHub: https://github.com/hyafz/plccore/blob/master/docs/PLC%E9%9B%86%E6%88%90%E5%BC%80%E5%8F%91%E7%8E%AF%E5%A2%83%E7%94%A8%E6%88%B7%E6%89%8B%E5%86%8C.md

码云： https://gitee.com/hyafz/plccore/blob/master/docs/PLC%E9%9B%86%E6%88%90%E5%BC%80%E5%8F%91%E7%8E%AF%E5%A2%83%E7%94%A8%E6%88%B7%E6%89%8B%E5%86%8C.md

以及编程参考手册：

GitHub: https://github.com/hyafz/plccore/blob/master/docs/IEC61131-3%E6%A0%87%E5%87%86PLC%E7%BC%96%E7%A8%8B%E5%8F%82%E8%80%83%E6%89%8B%E5%86%8C.md

码云： https://gitee.com/hyafz/plccore/blob/master/docs/IEC61131-3%E6%A0%87%E5%87%86PLC%E7%BC%96%E7%A8%8B%E5%8F%82%E8%80%83%E6%89%8B%E5%86%8C.md

## 5 示例
目前提供一个示例：

GitHub: https://github.com/hyafz/plccore/blob/master/docs/PLC%E9%9B%86%E6%88%90%E5%BC%80%E5%8F%91%E7%8E%AF%E5%A2%83%E4%BD%BF%E7%94%A8%E7%A4%BA%E4%BE%8B1.md

码云： https://gitee.com/hyafz/plccore/blob/master/docs/PLC%E9%9B%86%E6%88%90%E5%BC%80%E5%8F%91%E7%8E%AF%E5%A2%83%E4%BD%BF%E7%94%A8%E7%A4%BA%E4%BE%8B1.md

后续将增加更多的示例。

## 6 联系方式 & 感谢

* 维护
  - hyafz(401190549@qq.com)
* 主页：
  - GitHub: https://github.com/hyafz/plccore
  - 码云：https://gitee.com/hyafz/plccore


## The End