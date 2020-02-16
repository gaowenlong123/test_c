#include "myvector.h"
#include <iostream>

using namespace std;


template <typename  T>
ostream& operator<< (ostream &out , const MyVector<T> &obj)   // 重载左移运算符 ，将数据一一打印出来
{
    for(int i=0;i<obj.m_len ;i++){
        out << obj.m_space[i]<<" | ";
    }
    out << endl;
    return out;
}



template <typename T>
MyVector<T>::MyVector(int size) // 构造函数
{
    m_space = new T[size];
    m_len = size;
}

template <typename T>
MyVector<T>::MyVector(const MyVector &obj) //拷贝构造函数
{
    //根据传入对象的大小分配内存
    m_len = obj.m_len;
    m_space = new T[m_len];


    //copy数据
    for(int i=0;i<m_len ;i++){
        m_space[i] = obj.m_space[i];
    }
}

template <typename T>
MyVector<T>::~MyVector()//析构函数
{
    if(m_space != NULL){
        delete []m_space;
        m_space = NULL;
        m_len =0;
    }
}

template <typename T>
T& MyVector<T>::operator [] (int index)//重载[]，即可以当左值又可以当右值，返回的是一个元素（引用）
{
    return m_space[index];
}

template <typename T>  //需要添加具体的类型
MyVector<T> & MyVector<T>::operator = (const MyVector<T> &obj) //a3 = a2 =a1  可能当左值需要返回一个引用
{
    //先把旧有的内存数据释放掉
    if(m_space != NULL){
        delete []m_space;
        m_space = NULL;
        m_len =0;
    }

    //根据传入分配内存
    m_len = obj.m_len;
    m_space = new T[m_len];


    //copy数据
    for(int i=0;i<m_len ;i++){
         m_space[i] = obj.m_space[i];
    }

    //返回一个自己的本身
    return *this;
}


