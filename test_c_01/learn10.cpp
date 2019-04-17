//assert
#include <assert.h>
assert(1==2);


//捕获异常
//继承基类exception来创建个人的子类以管理异常。 然后抛出和捕获的是exception类或其子类的对象。 如果打算以对象作为异常有一个原则：以值传递方法抛出异常，以引用传递方式捕获异常。
try{



}
catch(int e){

}
catch(...){ //捕获任意类型

}




//动态内存管理


//动态数组  在运行的时候申请内存，所以称之为动态
int cout =10;
int * x = new int[cout];
//x[i]  数组的值
delete[] x;  //删除一个动态数组


//从函数或方法返回内存
//动态内存的另一个常见的用途是让函数申请并返回一个指向内存块的指针。  当你打算使用别人编写的库文件时。
//在函数中调用new语句为某种对象或某个基本数据类型分配一块内存，再把内存地址返回给程序的主代码块，完成功能后就释放。
int main(){
    int *x = newInt(20);

    delete x;
    x = NULL;    //放在重复用指针导致之前的数据被锁死，导致内存的泄露

}

int* newInt(int value){
    int* myInt = new int;
    *myInt value;
    return myInt;
}



//声明函数指针
int mian(){

    int a;

    int (*p)();   //声明函数指针

    p = fun;     //给函数指针p赋值，使他指向函数 f

    a= (*p)(a,b); //通过指针p调用函数
}

fun(int x , int y){

}


//指针函数
int* newInt(int value){
    int* myInt = new int;
    *myInt value;
    return myInt;
}



//副本构造器




//静态对象强制类型转换
A* a = new B();

B* b = (B)a;

delete a;  //任远一个删除，因为都是指向一个地址
a =NULL;
b =NULL;


//动态对象强制类型转换
dynamic_cast<MyClass*>(value)   //用来把一种类型的对象指针安全地强制转换为另一种类型的对象指针

A* a = new B();

B* b = dynamic_cast<B*>(a);


//内存泄露
(1):
int* x;
x = new int[3000]; //该值丢失，造成泄露。
x = new int[4000];
delete[] x;
x=NULL;

(2):当foo函数结束，指针变量x将超出它的作用域，这意味着它将不复存在，它的值就会丢失。
void foo(){
    myclass *x ;
    x = new myclass();
}



//内存作用域
































