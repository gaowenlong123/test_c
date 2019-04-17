//共用体
使几个不同的变量共占用一段内存的结构


//定义共用体
union data{
    int i;
    char ch;
} a ,b ,c ;


或
union data{
    int i;
    char ch;
};

union data a,b,c;



//共用体和结构体的比较
结构体占内存长度是各成员占的内存长度之和。

共用体变量所占的内存长度等于最长的成员的长度。


//只有先定义了共用体变量才能引用它，而且不能引用共用体变量，而只能引用共用体变量中的成员。






//枚举

//定义
enum weekday{sun ,mon,tue};
enum weekday a,b,c;

或
enum weekday {sun ,mon ,tue} a,b,c;
