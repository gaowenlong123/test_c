#ifndef CENCDESPROTOCOL_H
#define CENCDESPROTOCOL_H
#pragma once
#include <iostream>
using namespace std;

class CEncDesProtocol
{
 public:

    CEncDesProtocol(){
        ;
    }

    virtual ~CEncDesProtocol(){

        ;
    }

    virtual int EncData(unsigned char *plain , int plainlen , unsigned char * cryptdata , int * cryptlen) =0;
    virtual int DecData( unsigned char * cryptdata , int  cryptlen ,unsigned char *plain , int* plainlen )=0;


private:


};

#endif // CENCDESPROTOCOL_H
