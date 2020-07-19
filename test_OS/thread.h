#ifndef THREAD_H
#define THREAD_H


#include <vector>
#include <string>
#include <iostream>

using namespace std;



class Cthread
{
public:
    Cthread();
    ~Cthread();

    int Test();

private:

   static void* ProcTest(void* pParam);
//    static void ThreadProc(int pArgv){
//        ((Cthread*)pArgv) ->ProcTest();
//    }


     std::vector<string> vLibnameList;
};


#endif // THREAD_H


