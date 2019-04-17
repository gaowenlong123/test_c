//类

//构造器
//1：构造器的名字必须和它所在的类的名字一样
//2：创建实例会第一时间调用
//3：构造器永远不会返回任何值


//析构器
//1：在销毁一个对象时，就会自动调用该方法

//this 指向当前类生成的对象

#include <iostream>
class Test
{
public:
    std::string name;


    Test(std::string name);
    ~Test();
    void setColor(std::string col);

};

//构造器
Test::Test(){

}


//析构器
Test::~Test(){

}

void Test::setColor(std::string col)
{
    this->name=col;
}



//继承
//基类的构造器先调用，之后是子类的构造器

class TestKid : public Test
{
public:
    std::string name;


    TestKid(std::string name);
    ~TeTestKidst();
//    void setColor(std::string col);
};

void TestKid::setColor(std::string col)
{
    this->name=col+"_kid";
}


//如果构造器传参，可以使调用子类的时候，将子类构造器传参的动作在父类中执行

TestKid::TestKid(std::string name):Test(name){

}




//访问控制
//类的内部定义
//public
//private   自己
//protected 这个类本身和他子类



//继承时的定义
//class TestKid : public Test{}
//这里的public是基类的方法和属性的访问级别不发生改变
//protected只能由基类的子类访问，子类的外部代码不能通过子类去修改基类的代码
//private只能由基类自身访问




//覆盖方法
//重写父类的方法


//重载方法
//同名方法，不同参数
//从基类继承过来的方法，进行重载需要慎重操作


//友元关系
//允许友元类访问对方的protected和private方法和属性
class A{
    friend class B;
};


//静态属性  静态方法
class A{
public:
    static int getcount();

private:
    static int count;
};


//堆

//栈： 将函数返回地址、参数等放入栈里，然后再从外面取出来。

int* p = new int; //在没有创建变量的情况下为有关数据分配内存空间
*p = 110;
delete p;


//虚方法
Pet *cat = new Cat("猫");
Pet *dog = new Dog("狗");
左边是编译的时候运行，在程序运行的时候分配了cat和dog类型的指针。如果调用方法肯定优先基类的方法，因为快。所以这种情况下引入了虚方法

virtual void play();



//抽象方法
virtual void play()=0;  //不需要写实现,纯虚函数


//运算符的重载
函数类型 operator 运算符名称(形参列表)
{
    重载处理
}


int operator +(int a, int b){
    return(a-b);
}



//多继承

class O{};

//
class A:public O{
public:
    A();
};

A::A() : O(){

}

//
class B :public O{
public:
    B();
};


B::B() : O(){

}

//
class c : public A,public B   //多继承可能会出现问题
{

};

C::C(): A(),B(),O(){  //???

}

//虚继承
//从当前这个类派生出来的子类只能拥有那个基类的一个实例。
//
class A:virtual public O{
public:
    A();
};

A::A() : O(){

}

//
class B :virtual public O{
public:
    B();
};


B::B() : O(){

}

//
class c : public A,public B   //多继承可能会出现问题
{

};

C::C(): A(),B(),O(){  //只能得到 基类的实例

}














