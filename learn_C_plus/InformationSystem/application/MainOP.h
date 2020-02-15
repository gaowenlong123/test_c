#ifndef MAINOP_H
#define MAINOP_H
#include <iostream>
#include "cencdesprotocol.h"
#include "csocketprotocol.h"

using namespace std;

class MainOP
{
public:
    MainOP(){
        ;
    }

    MainOP( CSocketProtocol *sp ,CEncDesProtocol *edp){
       this->sp = sp;
         this->edp = edp;
    }


    virtual int SckSendAndRec( unsigned char *in , int inlen , unsigned char *out , int *outlen);

    SetSocket(CSocketProtocol *sp){
        this->sp = sp;
    }
    SetEncDes(CEncDesProtocol *edp){
        this->edp = edp;
    }
private:



    CSocketProtocol *sp;
    CEncDesProtocol *edp;
};


#endif // MAINOP_H
