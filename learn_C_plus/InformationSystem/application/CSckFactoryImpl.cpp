#include "csckfactoryimpl.h"



 int CSckFactoryImpl::cltSocketInit()
 {
     p = NULL;
     len = 0;
    return 0;
 }


 int CSckFactoryImpl::cltSocketSend( unsigned char *buf , int buflen )
 {
     p = (unsigned char*)malloc(sizeof(unsigned char) *buflen);
     if(p==NULL){
         return  -1;
     }
     memcpy(p ,buf , buflen);
     len = buflen;
     return 0;
 }


 int CSckFactoryImpl::cltSocketRev( unsigned char *buf ,int *buflen )
 {
     if(buf == NULL || buflen ==NULL){
        return -1;
     }

     *buflen = len;
     memcpy(buf , p , len);
    return 0;

 }



 int CSckFactoryImpl::cltSocketDestory()
 {
    if(p!=NULL){
        free(p);
        p =NULL;
        len = 0;
    }
     return 0;
 }
