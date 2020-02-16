#include <iostream>
#include "string"
#include <vector>
#include <list>
#include "set"
#include <algorithm>
#include "functional"

using namespace std;


void printV(vector<int> &v)
{
    for(vector<int>::iterator it=v.begin() ; it!=v.end();it++){
        cout<<*it<<"|"<<endl;
    }
}
void printL(list<int> &v)
{
    for(list<int>::iterator it=v.begin() ; it!=v.end();it++){
        cout<<*it<<"|"<<endl;
    }
}


void showElement(int &n)
{
    cout<<n<<"-"<<endl;
}

class CShowElem
{
public:
    int num;
    CShowElem() {num=0;}

    void operator()(int &n){
         num++;
         cout<<n<<"*"<<endl;
    }

    printMy(){
        cout<<num<<"==>num"<<endl;
    }

};


void main_foreach()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(7);

    printV(v1);

    //传入函数对象
    for_each(v1.begin(),v1.end(), showElement);


    //传入类对象
    for_each(v1.begin(),v1.end(), CShowElem());


    //可以得到类的对象
    CShowElem my1;
    CShowElem my2 = for_each(v1.begin(),v1.end(), my1);       // my1 和 my2 是不同的对象
    my1.printMy();
    my2.printMy();

}

int increase(int i){

    return i+10;
}


void main_transform()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(7);

    printV(v1);

    //使用回调函数
    transform(v1.begin(),v1.end(),v1.begin(),increase);
    printV(v1);

    //使用预定义的函数对象
    transform(v1.begin(),v1.end(),v1.begin(),negate<int>());
    printV(v1);


    //使用函数适配器 和函数对象
    list<int> mylist;
    mylist.resize(v1.size());

    transform(v1.begin(),v1.end(),mylist.begin(), bind2nd(multiplies<int>(),10));
    printV(v1);
    printL(mylist);

}

int main1(int argc, char *argv[])
{
//    main_foreach();
    main_transform();
    cout << "Hello World!" << endl;
    return 0;
}
