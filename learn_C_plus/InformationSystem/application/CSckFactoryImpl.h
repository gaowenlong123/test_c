#ifndef CSCKFACTORYIMPL_H
#define CSCKFACTORYIMPL_H
#include <iostream>
#include "csocketprotocol.h"
using namespace std;

class CSckFactoryImpl : public CSocketProtocol
{

public:


   //客户端初始化 获取handle上下
   virtual int cltSocketInit();

   //客户端发报文
   virtual int cltSocketSend( unsigned char *buf , int buflen );

   //客户端接受报文
   virtual int cltSocketRev( unsigned char *buf ,int *buflen );

   //客户端释放资源
   virtual int cltSocketDestory();

private:
    unsigned char* p;
    int len;
};

#endif // CSCKFACTORYIMPL_H
