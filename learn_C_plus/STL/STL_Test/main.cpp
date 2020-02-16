#include <iostream>
#include "string"
#include <vector>
#include <list>
#include "set"
#include <algorithm>
#include "functional"
#include "iterator" //输出流迭代器的头文件
#include <numeric>
#include "map"
#include "deque"
using namespace std;

class Speaker
{
public:
    string n_name;
    int m_score[2];

};


int  GenSpeaker(map<int , Speaker> &mapSpeaker , vector<int> &v)
{
    string str ="QWERTYUIOPASDFGHJKLZ";
    random_shuffle(str.begin(),str.end());

    for(int i=0;i<20;i++){
        Speaker tmp;
        tmp.n_name="Player";
        tmp.n_name += str[i];

        mapSpeaker.insert(pair<int,Speaker> (i,tmp));
    }

      for(int i=0;i<20;i++){

          v.push_back(i);
      }

    return 0;
}

int speech_contest_draw(vector<int> &v)
{
    random_shuffle(v.begin(),v.end());
}

int speech_contest(int index ,vector<int> &in_v ,map<int , Speaker> &mapSpeaker , vector<int> &out_v)
{
    //总的容器
    multimap<int,int,greater<int>> multGroup;
    int count;

    for(vector<int>::iterator it=in_v.begin() ; it!=in_v.end();it++)
    {
        count ++;
        //打分
        deque<int> dscore;
        for(int j=0;j<10;j++){
            int score = 50+rand()%50;
            dscore.push_back(score);
        }

        sort(dscore.begin(),dscore.end());
        dscore.pop_back();
        dscore.pop_front();

        //求平均分
        int scoresum = accumulate(dscore.begin(),dscore.end(),0);
        int scoreavg = scoresum / dscore.size();

        mapSpeaker[*it].m_score[index-1]=scoreavg;

        multGroup.insert(pair<int,int>(scoreavg ,*it));
    }

    int temp= multGroup.size();
    for(int i =0;i<temp-4;i++){
        multimap<int,int,greater<int>>::iterator it1 = multGroup.begin();
        out_v.push_back(it1->second);
        multGroup.erase(it1);
    }

    multGroup.clear();
    return 0;
}

int speech_contest_print(int index  ,vector<int> &in_v  ,map<int , Speaker> &mapSpeaker)
{
        printf("result");

       for(vector<int>::iterator it=in_v.begin() ; it!=in_v.end();it++)
       {
           cout<<"ID:"<<*it<<"NAME:"<<mapSpeaker[*it].n_name<<"SCORE:"<<mapSpeaker[*it].m_score<<endl;
       }


}

int main(int argc, char *argv[])
{
    map<int , Speaker> mapSpeaker;
    vector<int>  v1; //第一轮
    vector<int>  v2; //第二轮
    vector<int>  v3; //结果

    //产生选手 得到第一轮的参赛名单
    GenSpeaker(mapSpeaker,v1);

    //第一轮 选手抽签 选手比赛 查看比赛结果
    speech_contest_draw(v1);
    speech_contest(1,v1,mapSpeaker,v2);
    speech_contest_print(1 ,v2 ,mapSpeaker);

    //2
    speech_contest_draw(v2);
    speech_contest(2,v2,mapSpeaker,v3);
    speech_contest_print(2 ,v3 ,mapSpeaker);

    //结果提取前三

    cout << "Hello World!" << endl;
    return 0;
}
