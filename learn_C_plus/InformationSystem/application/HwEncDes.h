
#ifndef HWENCDES_H
#define HWENCDES_H
#include<iostream>
using namespace std;

#include "cencdesprotocol.h"


class HwEncDes : public CEncDesProtocol
{

    virtual int EncData(unsigned char *plain , int plainlen , unsigned char * cryptdata , int * cryptlen);
    virtual int DecData( unsigned char * cryptdata , int  cryptlen ,unsigned char *plain , int* plainlen );



};

#endif // HWENCDES_H
