//头文件
不要声明变量 除非声明 static const


//使用头文件
#include "includes/a.h"
#include "../includes/a.h"


//命名空间
namespace name1 {

}


//链接 作用域 存储类 都是互相关联的概念，只是观察和描述问题的角度不同。
编译器编译程序时，有三个步骤：
1：执行预处理器指令
2：把.cpp文件编译成.o文件
3：把.o文件链接成一个可执行的文件


//链接
分为外链接(external) 内链接（internal） 无链接（none）



//存储类
auto  默认的
static
extern ： 它在有多个翻译单元时非常重要。这个关键字用来把另一个翻译单元里的某个变量声明为本翻译单元里的一个同名全局变量

就是将其他cpp文件里的变量，拿过来使用





//模板  泛型编程
泛型编程技术支持程序员创建函数和类的模板，而不是具体的函数和类。

//函数模板
template <class T>  // 字母T将在接下来的函数里代表一种不确定的数据类型
void swap(T &a , T &b){
}

swap<int>(a,b); //声明类型



//类模板
template <class T>
class myclass
{
public:
    myclass();
    void swap(T &a, T &b);
};


//构造器的实现   必须声明尖括号，没有实际类型，就写占位符T ，为了区别普通的类
template <class T>
myclass<T>::myclass()
{

}

//调用
myclass<int> my;




//内联模板
inline ，函数前面声明这个，整个函数会在main中调用

inline int add(int x,int y)
{
    return  x+y;
}



//模板可以用很多类型
template <class T,class U>
class myclass{

};

myclass<int,float>  my;





//迭代器
std::vector <std::string> names;
name.push_back("1");
name.push_back("2");
std::vector<std::string>::iterator iter = name.begin();

while(iter != name.end()){
    std::cout<<*iter;
    ++iter;
}


//容器 算法
拼写检查程序最适合用来解决这类问题的数据结构是散列表和二叉树

C++的一系列的算法都在标准库

容器 vector



















