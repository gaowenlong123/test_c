//预处理
#define 标识符 字符串

//#表示这是一条预处理命令
//define 为宏定义命令。
//“标识符” 为定义的宏名
//字符串可以是常数、表达式、格式串等



//例如
#define PI 3.1415926  // 指定标识符PI来代替数3.1415926


//宏定义必须写在函数之外，其作用域为宏定义命令起到源程序结束。如果要终止其作用域可使用#undef命令

//宏定义 允许嵌套

//宏名 一般是大写

//各个操作系统cpu的类型字节数不同，所以只需要该头文件的宏定义，就可以移植到其他平台



//typedef char* PIN2
//在编译的时候处理
//不仅仅只是简单的代换，而是对类型说明符重新命名。



//带参宏定义

#define M(y) (y)*(y)+3*(y)

//形参只是标识符用来做替换，所以没有类型的限制
//最好加上括号





//文件包含
#include "stdio.h"
#include <math.h>

//第一种，首先在当前的源文件目录中查找，没有找到才到包含目录中查找
//第二种  在包含的文件目录中查找，而不在源文件目录中去查找



//条件编译

#ifdef 标识符  //如果标识符被#define命令定义过，就执行程序1的代码，如果没有就执行程序2
    程序段1
#else
    程序段2
#endif


#ifndef 标识符  //如果标识符没有被#define命令定义过，就执行程序1的代码（这块代码一般是用来定义），如果有就执行程序2
    程序段1
#else
    程序段2
#endif


#if 常量表达式
    程序段1
#else
    程序段2
#endif




//typedef
给类型名取别名

typedef int myint;


typedef int NUM[100];   //声明num为整型数组类型

typedef char* STRING;  //声明字符指针类型

typedef int(*POINTER)(); //POINTER为指向函数的指针类型，该函数返回整型值








