#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

//应用
int myadd1(int a , int b){

}

int myadd2(int a , int b){

}
int myadd3(int a , int b){

}
int myadd4(int a , int b){

}


typedef int (*MyTypeFuncAdd)(int a , int b);

int MainOP(MyTypeFuncAdd myFuncAdd){
    int c = myFuncAdd(1,3);
}
int MainOP2(int (*MyTypeFuncAdd)(int a , int b)); //这个跟上面是一样的


int main(int argc, char *argv[])
{

    //老的框架可以复用前人的代码
    // 通过函数指针做函数参数  实现了 函数的实现 和 任务调度的分离
    MainOP(myadd1);
    MainOP(myadd2);

    MainOP(myadd3);
    MainOP(myadd4);
}












//函数指针
//1 如何定义一个函数类型
//2 如何定义一个函数指针类型
//3 如何定义一个函数指针，指向一个函数的入口地址

int add(int a , int b){
    return 0;
}

int main1(int argc, char *argv[])
{

    add(1,3);  // 直接调用 //函数名就是函数入口地址


    {
        //定义一个函数类型   // 间接调用
        typedef int(MyFuncType)(int a , int b); // 定义了一个类型

        MyFuncType *myPointerFunc = NULL;

        myPointerFunc = &add;

        myPointerFunc(1,3);

    }


    {
        //定义一个函数指针类型
        typedef int (*MyPointerFuncType)(int a ,int b);

        MyPointerFuncType myPointer;

        myPointer = add;  // 加不加& 都兼容

        myPointer(5,6);

    }

    {
        //直接定义一个函数指针
        int (*MyPointerFunc)(int a ,int b); // 定义了一个变量
        MyPointerFunc = add;
        MyPointerFunc(1,3);



    }

    cout << "Hello World!" << endl;
    return 0;
}










//数组指针
int main2(int argc, char *argv[])
{

    int a[10];   // a代表的是数组首元素的地址   &a代表整个数组的地址 ； a+1 步长是4     &a+1 步长是40



    {
        //定义一个数组类型
        typedef int (myTypeArray)[10];

        myTypeArray myArray;  //等同于第10行
    }

    {
        //定义一个指针数组类型
        typedef int (*PTypeArray)[10]; //int *p

        PTypeArray myPArray;  // 步长为sizeof(int) * 10

        myPArray = &a;

        (*myPArray)[0]=20;  // 操作数组首位的值

    }


    {
        //定义一个指向 数组类型的指针 数组类的指针
        int (*MyPointer)[10];
        MyPointer = &a;
        (*MyPointer)[0]=20;
    }

    cout << "Hello World!" << endl;
    return 0;
}
