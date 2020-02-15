#include <iostream>
#include <csocketprotocol.h>
#include <string.h>
#include "csckfactoryimpl.h"
#include "hwencdes.h"
#include "mainop.h"
using namespace std;


//面向抽象类编程，框架已经搭起来了
int main(int argc, char *argv[])
{

     unsigned char in[4096] ;
     int inlen ;
     unsigned char out[4096] ;
     int outlen =0;


     strcpy((char*)in,"aaaaaaaaaaaaaaaa9999999999999");

     inlen = 9;
    MainOP *mp = new MainOP;
    CSocketProtocol *sp = NULL;
    CEncDesProtocol *edp = NULL;
    sp =new CSckFactoryImpl;
    edp = new HwEncDes;

    mp->SetEncDes(edp);
    mp->SetSocket(sp);

    mp->SckSendAndRec (in ,inlen , out ,&outlen);

    delete sp;
    delete edp;
    delete mp;
    cout << "Hello World!" << endl;
    return 0;
}
