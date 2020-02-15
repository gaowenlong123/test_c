#ifndef CSOCKETPROTOCOL_H
#define CSOCKETPROTOCOL_H
#pragma once
#include <iostream>
using namespace std;

class CSocketProtocol
{
 public:

    CSocketProtocol(){
        ;
    }

    virtual ~CSocketProtocol(){

        ;
    }


    //客户端初始化 获取handle上下
    virtual int cltSocketInit() =0;

    //客户端发报文
    virtual int cltSocketSend( unsigned char *buf , int buflen ) =0;

    //客户端接受报文
    virtual int cltSocketRev( unsigned char *buf ,int *buflen )=0;

    //客户端释放资源
    virtual int cltSocketDestory()=0;

private:


};




#endif // CSOCKETPROTOCOL_H
