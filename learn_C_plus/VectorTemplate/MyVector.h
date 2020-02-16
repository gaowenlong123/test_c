#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>
using namespace std;


template <typename T>
class MyVector
{

    //在友元函数声明前定义一个和 type不同的模板参数U ,在类的外部实现
    template <typename U>
    friend ostream& operator <<(ostream &out , const MyVector<U> &obj);


public:
    MyVector(int size); // 构造函数

    MyVector(const MyVector &obj); //拷贝构造函数

    ~MyVector(); //析构函数

    int getLen(){
        return m_len;
    }

public:

    T& operator[] (int index); //重载[]，即可以当左值又可以当右值，返回的是一个元素（引用）

    MyVector& operator= (const MyVector &obj); //a3 = a2 =a1  可能当左值需要返回一个引用


protected:
    T *m_space;
    int m_len;

};

#endif // MYVECTOR_H
