#include "mainop.h"

int MainOP::SckSendAndRec( unsigned char *in , int inlen , unsigned char *out , int *outlen)
{
    int ret =0;
    unsigned char data[4096] ;
    int datalen =0;
    ret = sp->cltSocketInit();
    if(ret!=0){
        goto End;
    }

    edp->EncData(in , inlen ,data , &datalen);
    ret = sp->cltSocketSend(in ,inlen);
    if(ret!=0){
        goto End;
    }


    ret = sp->cltSocketRev(data, &datalen);
    if(ret!=0){
        goto End;
    }

    edp->DecData(data , datalen, out , outlen  );

 End:
   ret = sp ->cltSocketDestory();
   return 0;
}
