//结构体

struct 结构名
{
//    成员列表
    int num ;
    char name[30];
};



//结构的嵌套 ， 外加结构的定义

struct date
{
    int month;
    int day;
    int year;

};

struct{
    int num;
    char num[20];
    char sex;
    struct date brithday;
    float score;
}boy1 , boy2;


printf("%d" , &boy1.brithday.day);



//结构体的初始化
struct date
{
    int month;
    int day;
    int year;

}a,b={1,2,3};
a=b;



//结构体的数组
struct student{
    int num;
    char num[20];
    char sex;
    float score;
};
struct student student[3];

//或
struct student{
    int num;
    char num[20];
    char sex;
    float score;
}student[3];


//结构体数组的初始化
//struct student{
//    int num;
//    char num[20];
//    char sex;
//    float score;
//}stu[2]={
//                {1,"char","nan",1.2}，
//                {1,"char","nv",1.2}
//            };



//指向结构体变量的指针就是该结构体变量所占据的内存段的起始位置。
struct student* pstu;

如果boy是结构体student的结构变量，那么有这样的区别，因为结构名是不分配内存的
pstu = &boy;
//pstu =&student; 错误


//取出结构指针变量的值
//              （*结构指针的变量）.成员名

//或

//                *结构指针的变量->成员名


//指向结构体变量的指针作为实参 （效率高）
void print(struct student *p)
{
    p->num;
}

struct student stu;

print(&stu);  //传递地址，用指针来接收





//动态存储的分配
常用的内存管理函数：
1.分配内存空间韩束  malloc ，calloc
2.释放内存空间函数 free


//链表
是常见的重要的数据结构，是动态地进行存储分配的一种结构。与数组的不同，是储存两个东西，一个是自身的内容+下一个链表的地址。最简单的好处，可以动态的分配。
链表的组成：
        头指针：存放一个地址，该地址指向第一个元素

//链表的新建
新建两个指向某个结构体的指针，如果第一个是为1，就让他为head。如果非1，就将p1的地址的值给p2的next变量。
再次新开辟一个指针，将p1指向一个空指针。这样依次循环。


//链表的删除
新建两个指针p1,p2 。将第一个节点的地址给p1 , 将第二个节点的地址（*p1.next）给p2。
这样就有三个地址的指针即： p1 ,p2 ,*p2.next
想要删除第二个：即 *p1.next = *p2.next;

//链表的插入
需要在链表中有按顺序增加的标识变量
















































