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
// #include <iostream>
// using namespace std;
// #include <queue>
// #include <string>
// class Person
// {
//     public:
//     Person(string name,int age)
//     {
//         this->m_Age=age;
//         this->m_Name=name;
//     }
//     string m_Name;
//     int m_Age;
// };
// void test01()
// {
//     queue<Person>q;
//     //入栈
//     Person p1("aaa",10);
//     Person p2("bbb",10);
//     Person p3("ccc",10);
//     Person p4("ddd",10);
//     q.push(p1);
//     q.push(p2);
//     q.push(p3);
//     q.push(p4);

//     // cout<<"栈的大小为"<<q.size()<<endl;
//     //只要队不为空，查看队头队尾，出队
//     while(!q.empty())
//     {
//         cout<<"队头元素为："<<q.front().m_Name<<q.front().m_Age<<endl;
//         cout<<"队尾元素为："<<q.back().m_Name<<q.back().m_Age<<endl;
//         //出队
//         q.pop();
//     }
//     cout<<"队的大小为"<<q.size()<<endl;
// }
// int main()
// {
//     test01();
//     return 0;
// }

//list链表
// #include <iostream>
// using namespace std;
// #include <list>
// #include <algorithm>
// void printList(const list<int>&L)
// {
//     for(list<int>::const_iterator it=L.begin();it!=L.end();it++)
//     {
//         cout<<*it<<" ";
//     }
//         cout<<endl;
// }
// bool myCompare(int v1,int v2)
// {
//     return v1>v2;
// }
// void test01()
// {

//     list<int>L1;
//     L1.push_back(20);
//     L1.push_back(40);
//     L1.push_back(30);
//     L1.push_back(10);
    
    // printList(L1);
    // list<int>L2(L1.begin(),L1.end());
    // printList(L2);
    // list<int>L3;
    // L3.assign(10,100);
    // printList(L3);

    // L3.swap(L2);
    // printList(L2);
    // printList(L3);
    // cout<<L2.size()<<endl;
    // L2.insert(L2.begin(),1000);
    // printList(L2);
    // list<int>::iterator it=L2.begin();
    // L2.insert(++it,200);
    // printList(L2);
    // it=L2.begin();
    // L2.erase(++it);
    // printList(L2);
    // L2.remove(100);
    // printList(L2);
    // L2.clear();
    // printList(L2);
    // cout<<"第一个元素"<<L3.front()<<endl;
    // cout<<"最后一个元素"<<L3.back()<<endl;

//     printList(L1);
//     L1.reverse();
//     printList(L1);
//     L1.sort(myCompare);
//     printList(L1);

// }
// int main(){
//     test01();
//     return 0;
// }

//set/multiset容器
// #include <iostream>
// using namespace std;
// #include <set>
// void printSet(set<int>&s)
// {
//     for(set<int>::iterator it=s.begin();it!=s.end();it++)
//     {
//         cout<<*it<<" ";
//     }
//     cout<<endl;
// }
// void test01()
// {
//     set<int>s1;
//     pair<set<int>::iterator,bool>ret=s1.insert(10);
//     if(ret.second)
//     {
//         cout<<"插入成功"<<endl;
//     }
//     else
//     {
//         cout<<"插入失败"<<endl;
//     }
//     ret=s1.insert(10);
//     if(ret.second)
//     {
//         cout<<"插入成功"<<endl;
//     }
//     else
//     {
//         cout<<"插入失败"<<endl;
//     }

//     multiset<int>ms;
//     ms.insert(10);
//     ms.insert(10);
//     for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++) {
//     cout << *it << " ";
//     }
//     cout << endl;
// }
// int main()
// {
//     test01();
//     return 0;
// }


//pair对组
// #include <iostream>
// using namespace std;
// #include <string>
// //对组创建
// void test01()
// {
//     pair<string,int>p("Tom",10);
//     cout<<"姓名"<<p.first<<"年龄"<<p.second<<endl;
//     pair<string,int>p2=make_pair("Jeery",30);
//     cout<<"姓名"<<p2.first<<"年龄"<<p2.second<<endl;
// }
// int main() {
// test01();
// system("pause");
// return 0;
// }

//set存放自定义数据类型怎么排序
// #include <iostream>
// using namespace std;
// #include <string>
// #include <set>
// class Person
// {
// public:
// Person(string name, int age)
// {
// this->m_Name = name;
// this->m_Age = age;
// }
// string m_Name;
// int m_Age;
// };
// class PersonCompare
// {
// public:
// bool operator()(const Person&p1,const Person&p2)
// {
//     return p1.m_Age>p2.m_Age;
// }
// };
// void test01()
// {
//     set<Person,PersonCompare>s;
// // set<Person, comparePerson> s;
// Person p1("刘备", 23);
// Person p2("关羽", 27);
// Person p3("张飞", 25);
// Person p4("赵云", 21);
// s.insert(p1);
// s.insert(p2);
// s.insert(p3);
// s.insert(p4);
// for (set<Person, PersonCompare>::iterator it = s.begin(); it != s.end(); it++)
// {
// cout << "姓名： " << it->m_Name << " 年龄： " << it->m_Age << endl;
// }
// }
// int main() {
// test01();
// system("pause");
// return 0;
// }

//员工分组
// #include <iostream>
// #include <map>
// #include <string>
// #include <vector>
// #include <ctime>
// using namespace std;

// #define CEHUA 0
// #define MEISHU 1
// #define YANFA 2
// class Worker
// {
// public:
//     string m_Name;
//     int m_Salary;
// };
// void createWorker(vector<Worker>&v)
// {
//     string nameSeed="ABCDEFGHIJ";
//     for(int i=0;i<10;i++)
//     {
//         Worker worker;
//         worker.m_Name="员工";
//         worker.m_Name+=nameSeed[i];
//         worker.m_Salary=rand()%10000+10000;//10000~19999
//         v.push_back(worker);

//     }
// }
// void setGroup(vector<Worker>&v,multimap<int,Worker>&m)
// {
//     for(vector<Worker>::iterator it=v.begin();it!=v.end();it++)
//     {
//         int deptId=rand()%3;//0 1 2
//         //key:部门编号  value:员工
//         m.insert(make_pair(deptId,*it));
//     }
// }
// void showWorkerByGroup(multimap<int,Worker>&m)
// {

//         cout<<"策划部门："<<endl;
//         multimap<int,Worker>::iterator pos=m.find(CEHUA);//查找第一个元素
//         int count=m.count(CEHUA);//统计元素个数
//         int index=0;
//         for(;pos!=m.end()&&index<count;pos++,index++)
//         {
//             cout<<"姓名："<<pos->second.m_Name<<"  薪资："<<pos->second.m_Salary<<endl;
//         }
//         cout<<"美术部门："<<endl;
//         pos=m.find(MEISHU);
//         count=m.count(MEISHU);
//         index=0;
//         for(;pos!=m.end()&&index<count;pos++,index++)
//         {
//             cout<<"姓名："<<pos->second.m_Name<<"  薪资："<<pos->second.m_Salary<<endl;
//         }
//         cout<<"研发部门："<<endl;
//         pos=m.find(YANFA);
//         count=m.count(YANFA);  
//         index=0;
//         for(;pos!=m.end()&&index<count;pos++,index++)
//         {
//             cout<<"姓名："<<pos->second.m_Name<<"  薪资："<<pos->second.m_Salary<<endl;
//         }   

// }
// int main()
// {
//     srand((unsigned int)time(NULL));
//     //创建员工
//     vector<Worker>vWorker;
//     createWorker(vWorker);  
//     //分组
//     multimap<int,Worker>mWorker;
//     setGroup(vWorker,mWorker);
//     //显示分组结果
//     showWorkerByGroup(mWorker);
//     return 0;
// }


//stl常用算法
// for_each最常用
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
void print01(int val)
{
    cout<<val<<" ";
}
class print02
{
    public:
    void operator()(int val)
    {
        cout<<val<<" ";
    }
};
class Transform
{
    public:
    int operator()(int val)
    {
        return val*2;
    }
};
class Person
{
    public:
    Person(string name,int age)
    {
        this->m_Name=name;
        this->m_Age=age;
    }
    bool operator==(const Person&p)const
    {
        return this->m_Age==p.m_Age;
    }
    string m_Name;
    int m_Age;
};
void test01()
{
    vector<int>v;
    vector<int>v2;
    for(int i=1;i<10;i++)
    {
        v.push_back(i);
        v2.push_back(i+5);
    }  
    // for_each(v.begin(),v.end(),print01);
    // cout<<endl;
    // for_each(v.begin(),v.end(),print02());
    // cout<<endl;
    vector<int>vT;
    vT.resize(v.size()+v2.size());
    // transform(v.begin(),v.end(),vT.begin(),Transform());
    // for_each(vT.begin(),vT.end(),print02());
    // cout<<endl;
    vector<Person>vP;
    vP.push_back(Person("aaa",10));
    vP.push_back(Person("bbb",20));
    vP.push_back(Person("ccc",30));
    vP.push_back(Person("ddd",40));
    vP.push_back(Person("eee",20));

    // 查找 
    find(v.begin(),v.end(),5)!=v.end()?cout<<"找到5了"<<endl:cout<<"没找到5"<<endl;
    find(vP.begin(),vP.end(),Person("ccc",30))!=vP.end()?cout<<"找到了"<<endl:cout<<"没找到"<<endl;//需要重载==号

    find_if(v.begin(),v.end(),[](int val){return val>5;})!=v.end()?cout<<"找到大于5的值了"<<endl:cout<<"没找到大于5的值"<<endl;
    find_if(vP.begin(),vP.end(),[](const Person&p){return p.m_Age>30;})!=vP.end()?cout<<"找到年龄大于30的值了"<<endl:cout<<"没找到年龄大于30的值"<<endl;

    adjacent_find(v.begin(),v.end())!=v.end()?cout<<"有相邻重复元素"<<endl:cout<<"没有相邻重复元素"<<endl;

    binary_search(v.begin(),v.end(),5)?cout<<"找到5了"<<endl:cout<<"没找到5"<<endl;//必须有序序列
    cout<<"5出现的次数为"<<count(v.begin(),v.end(),5)<<endl;
    cout<<"年龄为20的人数为"<<count(vP.begin(),vP.end(),Person("bbb",20))<<endl;
    cout<<"年龄大于25的人数为"<<count_if(vP.begin(),vP.end(),[](const Person&p){return p.m_Age>25;})<<endl;
    cout<<"大于3的元素个数为"<<count_if(v.begin(),v.end(),[](int val){return val>3;})<<endl;

    // 排序
    sort(v.begin(),v.end(),[](int a,int b){return a>b;});
    for_each(v.begin(),v.end(),print02());
    cout<<endl;
    random_shuffle(v.begin(),v.end());
    for_each(v.begin(),v.end(),print02());
    cout<<endl;

    merge(v.begin(),v.end(),v2.begin(),v2.end(),vT.begin(),[](int a,int b){return a<b;});
    for_each(vT.begin(),vT.end(),print02());
    cout<<endl;

    reverse(v.begin(),v.end());
    for_each(v.begin(),v.end(),print02());
    cout<<endl;

    // 替换和拷贝
    replace(v.begin(),v.end(),5,500);
    for_each(v.begin(),v.end(),print02());
    cout<<endl;
    vector<int>vC;
    vC.resize(v.size());
    copy(v.begin(),v.end(),vC.begin());
    for_each(vC.begin(),vC.end(),print02());
    cout<<endl;

    replace_if(vC.begin(),vC.end(),[](int val){return val>5;},1000);
    for_each(vC.begin(),vC.end(),print02());
    cout<<endl;
    swap(v2,vC);
    for_each(v2.begin(),v2.end(),print02());
    cout<<endl;

    // //数值计算相关
    // cout<<"v中所有元素的和为"<<accumulate(v.begin(),v.end(),0)<<endl;//参数3：初始累加值
    // cout<<"v中所有元素的乘积为"<<accumulate(v.begin(),v.end(),1,[](int a,int b){return a*b;})<<endl;
    // fill(v.begin()+1,v.end(),10);
    // for_each(v.begin(),v.end(),print02());
    // cout<<endl;
    
    // //集合算法
    // vector<int>vTarget;
    // vTarget.resize(min(v.size(),v2.size()));
    // vector<int>::iterator itEnd=set_intersection(v.begin(),v.end(),v2.begin(),v2.end(),vTarget.begin());
    // for_each(vTarget.begin(),set_intersection(v.begin(),v.end(),v2.begin(),v2.end(),vTarget.begin()),print02());
    // cout<<endl;

    // vector<int>vTarget;
    // vTarget.resize(v.size()+v2.size());
    // // set_union(v.begin(),v.end(),v2.begin(),v2.end(),vTarget.begin());
    // for_each(vTarget.begin(),set_union(v.begin(),v.end(),v2.begin(),v2.end(),vTarget.begin()),print02());
    // cout<<endl;

    vector<int>vTarget;
    vTarget.resize(max(v.size(),v2.size()));
    // set_difference(v.begin(),v.end(),v2.begin(),v2.end(),vTarget.begin());
    for_each(vTarget.begin(),set_difference(v.begin(),v.end(),v2.begin(),v2.end(),vTarget.begin()),print02());
    cout<<endl;
}
int main()
{
    test01();
    return 0;
}