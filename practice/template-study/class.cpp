#include <iostream>
using namespace std;
#include "MyArray.hpp"
void printIntArray(MyArray<int>& arr)
{
    for(int i=0;i<arr.getSize();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void test01()
{
    MyArray<int>arr1(5);
    for(int i=0;i<5;i++)
    {
        arr1.push_Back(i);
    }   
    printIntArray(arr1);
    // MyArray<int>arr2(arr1);
    // MyArray<int>arr3(100);
    // arr3 = arr1;
}
//测试自定义数据类型
class Person
{
public:
    Person(){};
    Person(string name,int age)
    {
        this->m_Name=name;
        this->m_Age=age;
    }
    string m_Name;     
    int m_Age;
};
void test02()
{
    MyArray<Person>arr(10);
    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);
    Person p5("eee",50);
    arr.push_Back(p1);
    arr.push_Back(p2);
    arr.push_Back(p3);
    arr.push_Back(p4);
    arr.push_Back(p5);
    for(int i=0;i<arr.getSize();i++)
    {
        cout<<"姓名："<<arr[i].m_Name<<" 年龄："<<arr[i].m_Age<<endl;
    }
}
int main()
{
    test02();
    
    return 0;
}
