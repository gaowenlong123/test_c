#include "thread.h"
#include <pthread.h>

#define NUM_THREADS 5

Cthread::Cthread(){
    //mutex
    std::cout<<"aaaaaaaaa"<<std::endl;

//    pthread_create(new_thread ,attr , start_routine, arg );

    int m_ThreadID =0;
    pthread_attr_t sThreadAttr = {0};

    pthread_create((pthread_t*)&m_ThreadID , &sThreadAttr ,ProcTest ,this);



}

Cthread::~Cthread()
{
        std::cout<<"~~~~~~~~"<<std::endl;
}


void* Cthread::ProcTest(void* pParam)
{
    cout<<"test"<<endl;

    cout<<pParam<<endl;
}
