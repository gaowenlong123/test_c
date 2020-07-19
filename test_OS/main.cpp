#include <iostream>
#include <time.h>
#include <thread.h>
#include <unistd.h>

using namespace std;
void test();
void test1();
void Example(Cthread* thread ,std::vector<float>& vList);
int main(int argc, char *argv[])
{

    cout << "Hello World!" << endl;

    int a =0;
    cout << "Main >>>"<< (void*)&a << endl; //该指针的地址
    cout << "Main >>>"<< a << endl; //值


     Cthread  *m_thread = new Cthread();
     cout << "Main >>>"<< m_thread << endl; //这个不是地址，是他的值。可以重写他的操作函数tostring()
     cout << "Main >>>"<< &m_thread << endl;//该指针的地址


     Cthread  m_thread_other;
//     cout << "Main >>>"<< m_thread_other << endl;//报错，只是声明的变量，但是没有具体分配内存空间
     cout << "Main >>>"<< &m_thread_other << endl;//该对象的地址
     m_thread_other = *m_thread;
     cout << "Main >>>"<< &m_thread_other << endl;//该对象的地址


     Cthread  *m_thread_None;        //可以用于动态绑定
     cout << "Main >>>"<< m_thread_None << endl;//值
     cout << "Main >>>"<< &m_thread_None << endl;//该指针的地址
     m_thread_None =  new Cthread();
     cout << "Main >>>"<< m_thread_None << endl;//值,发生更新
     cout << "Main >>>"<< &m_thread_None << endl;//该指针的地址



     sleep(1);

     test1();
    return 0;
}



/*
1：从静态存储区域分配。内存在程序便于的时候已经分配好，在程序运行的整个周期存在。例如全局变量，static变量
2：在栈上创建，在执行函数的时候，函数内局部变量的存储单元可以在栈上创建，函数结束后，自动销毁。每个线程都有一个栈
3：在堆上分配，程序在运行时用malloc或new申请任意多少的内存，程序员自己负责何时free或delete释放内存。


 https://blog.csdn.net/dongxianfei/article/details/79031943
 new 和 delete 是 C++ 用于管理堆内存的两个运算符，对应于C语言中的 malloc 和 free，但是 malloc 和 free 是函数，而new 和 delete 是运算符。
 除此之外，new 在申请内存的同时，还会调用对象的构造函数，而 malloc 只会申请内存；同样，delete 在释放内存之前，会调用对象的析构函数，而 free 只会释放内存。
 */


void test(){

    /*
     *要区分是声明的时候还是语句中的。
    声明： int *p = a；  声明×p是int型的指针，初始化a[数组]的起始地址
    声明： int p = &a；  声明p是int类型的常量（不是指针） ， 初始化：把变量a的地址赋给p     err!!!!!!!!
          long p2  = (long)&num2;   OK

    语句中：若p是指针变量
    *p = a； 把a值赋给p指向地址的值
    p = &a； p表示指向地址的指针，把变量a的地址赋给p


    语句中：若p不是指针变量
    *p = a；         err!!!!!!!!
    p = &a；         err!!!!!!!!
    p2  = (long)&a;


    字符串和数组都是将第一位的地址传入，所以不需要特意标示&
     *
     */
    cout << "test========================== >>>" << endl;

    int num1[] = {10,2};
    int *p1 = num1;

    cout << "test>>> >>>"<< p1 << endl;
    cout << "test>>> >>>"<< *p1 << endl;
    cout << "test>>> >>>"<< &num1[0] << endl;
    cout << "test>>> >>>"<< &num1[1] << endl;



    char* str = "mesaage";
    str = "ausssasu";
    cout << "test>>> >>>"<< str << endl; //值
    cout << "test>>> >>>"<< (void*)str << endl;//强转成指针
    cout << "test>>> >>>"<< &str << endl; //地址
    cout << "test========================== >>>" << endl;




}

void test1(){

    /*
    指针 与 引用
1：引用必须被初始化
2：引用一旦绑定就不会发生变化
3：引用的类型相同，且是一个对象
4: 类似于声明指针一样，声明引用只是加个&做标示

还有指针引用:
int a =20 ;
int *&b = &a;


先把引用学好，因为传参的时候，只需要传递引用就行

慢慢学习
    */

    int val =100;
    int &refval = val;
    int &refval1 = refval;

    cout << "引用>>> >>>"<< val << endl; //值
    cout << "引用>>> >>>"<< &val << endl; //地址
    cout << "引用>>> >>>"<< refval << endl;//值
    cout << "引用>>> >>>"<< &refval << endl; //地址
    cout << "引用>>> >>>"<< refval1 << endl;//值
    cout << "引用>>> >>>"<< &refval1 << endl; //地址


    int val3 =100;
    int &refval3 = val3;
    int *ptr3 = &refval3;

    cout << "引用>>> >>>"<< &val3 << endl; //地址
    cout << "引用>>> >>>"<< ptr3 << endl; //地址
    cout << "引用>>> >>>"<< *ptr3 << endl;//值
    cout << "引用>>> >>>"<< &*ptr3 << endl; //值的地址

//    int a =20 ;
//    int *&b = &a;

    cout << "引用========================== >>>" << endl;

    Cthread thread;
    std::vector<float> vList = {0,1};
    Example(&thread,vList);
}



void Example(Cthread* thread ,std::vector<float>& List)
{
//Cthread* thread = &thread; 通过指针简介操作一个变量
//std::vector<float>& List = vList; 直接操作同一个变量
    cout << "Example>>> >>>"<< thread << endl;//地址
    cout << "Example>>> >>>"<< List[0] << endl; //值
    cout << "Example>>> >>>"<< &List << endl; //地址
}
