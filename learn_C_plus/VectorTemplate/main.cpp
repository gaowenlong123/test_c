#include <iostream>
#include "myvector.h"
#include "myvector.cpp"

using namespace std;

int main(int argc, char *argv[])
{
 cout << "Hello World!" << endl;
    MyVector<int> myv(10);

    for(int i = 0; i < myv.getLen() ; i++){
        myv[i] = i+10;
    }

     MyVector<int> myv2 = myv;  //重载拷贝构造函数

     for(int i = 0; i < myv2.getLen() ; i++){
         cout<<myv2[i]<<endl;
     }

     cout << myv2;   //重载左移运算符

    cout << "Hello World!" << endl;
    return 0;
}
