//C++

//argc 与 argc[]：在程序中，mian函数有两个参数，整型变量argc和字符指针数组argc[]
//        aegc 是程序的参数数量，包含本身
//        argc[]的每个指针指向命令行的一个字符串




//文件流
//ifstream in;
//in.open("");
//in>>_char;
//in.close();

//ofstream on;
//on.open("");
//on<<_char;
//on.close();

//cin



//函数的重载


//cpu
//32位编译器在储存变量时会自动对齐四个字节。八位


//联合类型
联合类型与结构类型不同的地方，联合也可以容纳多种不同类型的值，但是它每次只能存储这些值中的某一个。
union lianhe{
    char* p;
    unsigned short ssn;

};

lianhe l;
l.ssn  =10;


//枚举

//类型别名


