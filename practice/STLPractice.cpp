//deque容器练习
// int main(){
//     test01();
//     return 0;
// }
// #include <iostream>
// using namespace std;
// #include <deque>
// #include <algorithm>
// void printDeque(const deque<int>&d)
// {
//     for(deque<int>::const_iterator it=d.begin();it!=d.end();it++)
//     {
//         cout<<*it<<" ";
//     }
//     cout<<endl;
// }
// void test02()
// {
//     deque<int>d1;
//     for(int i=0;i<10;i++)
//     {
//         d1.push_back(i);
//     }
//     printDeque(d1);
//     deque<int>d2(d1.begin(),d1.end());
//     printDeque(d2);
//     deque<int>d3(10,100);
//     printDeque(d3);
//     deque<int>d4(d3);
//     printDeque(d4);
// }
// void test01()
// {
//     deque<int>d1;
//     for(int i=0;i<10;i++) 
//     {
//         d1.push_back(i);
//     }
//     //插入
//     printDeque(d1);
//     d1.push_back(10);
//     d1.push_back(100);
//     d1.push_front(20);
//     d1.push_front(200);
//     printDeque(d1);
//     d1.pop_back();
//     d1.pop_front();
//     printDeque(d1);
//     //删除
//     deque<int>::iterator it=d1.begin();
//     it++;
//     d1.erase(it);
//     //访问
//     for(int i=0;i<d1.size();i++)
//     {
//         cout<<d1[i]<<" ";
//     }
//     cout<<endl;
//     for(int i=0;i<d1.size();i++)
//     {
//         cout<<d1.at(i)<<" ";
//     }
//     cout<<endl;
//     //排序(vector也可以用sort排序)
//     sort(d1.begin(),d1.end());
//     printDeque(d1);   
//     //大小操作
//     if(d1.empty())
//     {
//         cout<<"d1为空"<<endl;
//     }
//     else
//     {
//         cout<<"d1不为空"<<endl;
//         cout<<"d1大小为"<<d1.size()<<endl;
//     }
//     d1.resize(15,1);
//     printDeque(d1);
//     d1.resize(5);
//     printDeque(d1);
// }
// int main(){
//     test01();
//     return 0;
// }

//有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。
// #include <iostream>
// using namespace std;
// #include <vector>
// #include <deque>
// #include <string>
// #include <algorithm>
// #include <ctime>
// class Person
// {
// public:
//     Person(string name,int score)
//     {
//         this->m_Name=name;
//         this->m_Score=score;
//     }
//     string m_Name;//姓名
//     int m_Score;//分数
// };
// void createPerson(vector<Person>&v)
// {
//     string nameSeed="ABCDE";
//     for(int i=0;i<5;i++)
//     {
//         string name="选手";
//         name+=nameSeed[i];
//         int score=0;
//         Person p(name,score);
//         v.push_back(p);
//     }
// }
// void setScore(vector<Person>&v)
// {
//     for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
//     {
//         //将分数放入deque
//         deque<int>d;
//         for(int i=0;i<10;i++)
//         {
//             int score=rand()%41+60;//10~100
//             d.push_back(score);
//         }
//         // cout<<"选手："<<it->m_Name<<"  打分："<<endl;
//         // for(deque<int>::iterator dit=d.begin();dit!=d.end();dit++)
//         // {
//         //     cout<<*dit<<" ";
//         // }
//         // cout<<endl;
//         //排序
//         sort(d.begin(),d.end());
//         //去除最高分
//         d.pop_back();
//         d.pop_front();
//         //取平均分
//         int sum=0;
//         for(deque<int>::iterator dit=d.begin();dit!=d.end();dit++)
//         {
//             sum+=*dit;
//         }
//         int avg=sum/d.size();
//         //将平均分赋值给选手
//         it->m_Score=avg;
//     }
// }
// void showScore(vector<Person>&v)
// {
//     for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
//     {
//         cout<<"姓名："<<it->m_Name<<"     平均分"<<it->m_Score<<endl;
//     }
// }
// int main()
// {
//     //随机数种子
//     srand((unsigned int)time(NULL));
//     //创建五名选手
//     vector<Person>v;
//     createPerson(v);
//     // for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
//     // {
//     //     cout<<"姓名："<<(*it).m_Name<<"   成绩："<<(*it).m_Score<<endl;
//     // }
//     //打分
//     setScore(v);
//     //显示最后得分
//     showScore(v);
//     return 0;
// }

//stack容器（先进后出）
// #include <iostream>
// using namespace std;
// #include <stack>
// void test01()
// {
//     stack<int>s;
//     //入栈
//     s.push(10);
//     s.push(20);
//     s.push(30);
//     s.push(40);
//     s.push(50);
//     s.push(60);   
//     cout<<"栈的大小为"<<s.size()<<endl;
//     //只要栈不为空，查看栈顶，并且执行出栈操作
//     while(!s.empty())
//     {
//         //查看栈顶
//         cout<<"栈顶元素为："<<s.top()<<endl;
//         //出栈
//         s.pop();
//     }
//     cout<<"栈的大小为"<<s.size()<<endl;
// }
// int main()
// {
//     test01();
//     return 0;
// }

//queue容器(先进先出)
#include <iostream>
using namespace std;
#include <queue>
#include <string>
class Person
{
    public:
    Person(string name,int age)
    {
        this->m_Age=age;
        this->m_Name=name;
    }
    string m_Name;
    int m_Age;
};
void test01()
{
    queue<Person>q;
    //入栈
    Person p1("aaa",10);
    Person p2("bbb",10);
    Person p3("ccc",10);
    Person p4("ddd",10);
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);

    // cout<<"栈的大小为"<<q.size()<<endl;
    //只要队不为空，查看队头队尾，出队
    while(!q.empty())
    {
        cout<<"队头元素为："<<q.front().m_Name<<q.front().m_Age<<endl;
        cout<<"队尾元素为："<<q.back().m_Name<<q.back().m_Age<<endl;
        //出队
        q.pop();
    }
    cout<<"队的大小为"<<q.size()<<endl;
}
int main()
{
    test01();
    return 0;
}