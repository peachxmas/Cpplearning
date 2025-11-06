/*待优化，预计11.7完成优化*/
#include <iostream>
#include <string>

using namespace std;
const int MAX=1000;

//联系人类
class Person
{
    public:
    //姓名
    string m_Name;
    //性别 1男 2女
    int m_Sex;
    //年龄
    int m_Age;
    //电话
    string m_Phone;
    //住址
    string m_Addr;
};
//通讯录类
class Addressbooks
{
    public:
    //通讯录中保存的联系人数组
    class Person personArray[MAX];
    //通讯录中当前记录的联系人个数
    int m_Size;
};

void addPerson(Addressbooks * abs)
{
    //通讯录是否已满
    if(abs->m_Size==MAX)
    {
        cout<<"通讯录已满，无法添加"<<endl;
        return;
    }
    else
    {
        //添加联系人
        //姓名
        string name;
        cout<<"请输入姓名："<<endl;
        cin>>name;
        abs->personArray[abs->m_Size].m_Name=name;
        //性别
        int sex;
        cout<<"请输入性别："<<endl;
        cout<<"1---男"<<endl;
        cout<<"2---女"<<endl;
        while (1)
        {
            cin>>sex;
            if(sex==1||sex==2)
            {
               abs->personArray[abs->m_Size].m_Sex=sex;
               break;
            }
            else
            {
                cout<<"输入有误重新输入"<<endl;
            }
        }
        //年龄
        cout<<"请输入年龄："<<endl;
        int age=0;
        cin>>age;
        abs->personArray[abs->m_Size].m_Age=age;
        //电话
        cout<<"请输入联系电话："<<endl;
        string phone;
        cin>>phone;
        abs->personArray[abs->m_Size].m_Phone=phone;
        //住址
        cout<<"请输入住址："<<endl;
        string address;
        cin>>address;
        abs->personArray[abs->m_Size].m_Addr=address;
        //更新通讯录人数
        abs->m_Size++;
        cout<<"添加成功"<<endl;
        getchar();
        system("clear");//清屏
    }
    
};
void showPerson(Addressbooks * abs)
{
    if(abs->m_Size==0)
    {
        cout<<"当前记录为空"<<endl;
    }
    else
    {
        for(int i=0;i<abs->m_Size;i++)
        {
            cout<<"姓名："<<abs->personArray[i].m_Name<<"\t";
            cout<<"性别："<<(abs->personArray[i].m_Sex==1?"男":"女")<<"\t";
            cout<<"年龄："<<abs->personArray[i].m_Age<<"\t";
            cout<<"电话："<<abs->personArray[i].m_Phone<<"\t";
            cout<<"住址："<<abs->personArray[i].m_Addr<<endl;
        }

    }
    getchar();
    system("clear");

}
//检测联系人是否存在，如存在返回具体位置，不存在返回-1
int isExist(Addressbooks *abs,string name)
{
    for(int i=0;i<abs->m_Size;i++)
    {
        if(abs->personArray[i].m_Name==name)
        {
            return i;
        }  
    }
    return -1;
}
void deletePerson(Addressbooks * abs)
{
    cout<<"请输入您要删除的联系人"<<endl;
    string name;
    cin>>name;
    int ret=isExist(abs,name);
    if(ret!=-1)
    {
        for(int i=ret;i<abs->m_Size;i++)
        {
            abs->personArray[i]=abs->personArray[i+1];
        }
        abs->m_Size--;
        cout<<"删除成功"<<endl;
    }
    else
    {
        cout<<"查无此人"<<endl;
    }
    getchar();
    system("clear");
}
void findPerson(Addressbooks * abs)
{
    cout<<"请输入您要查找的联系人"<<endl;
    string name;
    cin>>name;
    int ret=isExist(abs,name);
    if(ret!=-1)
    {
        cout<<"姓名："<<abs->personArray[ret].m_Name<<"\t";
        cout<<"性别："<<(abs->personArray[ret].m_Sex==1?"男":"女")<<"\t";
        cout<<"年龄："<<abs->personArray[ret].m_Age<<"\t";
        cout<<"电话："<<abs->personArray[ret].m_Phone<<"\t";
        cout<<"住址："<<abs->personArray[ret].m_Addr<<endl;
    }
    else
    {
        cout<<"查无此人"<<endl;
    }
    getchar();
    system("clear");
}
void modifyPerson(Addressbooks * abs)
{
    cout<<"请输入需要修改的联系人"<<endl;
    string name;
    cin>>name;
    
    int ret=isExist(abs,name);

    if(ret!=-1)
    {
       //姓名
        string name;
        cout<<"请输入姓名："<<endl;
        cin>>name;
        abs->personArray[ret].m_Name=name;
        //性别
        int sex;
        cout<<"请输入性别："<<endl;
        cout<<"1---男"<<endl;
        cout<<"2---女"<<endl;
        while (1)
        {
            cin>>sex;
            if(sex==1||sex==2)
            {
               abs->personArray[ret].m_Sex=sex;
               break;
            }
            else
            {
                cout<<"输入有误重新输入"<<endl;
            }
        }
        //年龄
        cout<<"请输入年龄："<<endl;
        int age=0;
        cin>>age;
        abs->personArray[ret].m_Age=age;
        //电话
        cout<<"请输入联系电话："<<endl;
        string phone;
        cin>>phone;
        abs->personArray[ret].m_Phone=phone;
        //住址
        cout<<"请输入住址："<<endl;
        string address;
        cin>>address;
        abs->personArray[ret].m_Addr=address;
        cout<<"修改成功"<<endl;

    }
    else
    {
        cout<<"查无此人"<<endl;

    }
    getchar();
    system("clear");

}
void cleanPerson(Addressbooks * abs)
{
    abs->m_Size=0;
    cout<<"通讯录已清空"<<endl;
    getchar();
    system("clear");
}
//菜单界面
void showMenu()
{
    cout<<"1.添加联系人"<<endl;
    cout<<"2.显示联系人"<<endl;
    cout<<"3.删除联系人"<<endl;
    cout<<"4.查找联系人"<<endl;
    cout<<"5.修改联系人"<<endl;
    cout<<"6.清空联系人"<<endl;
    cout<<"0.退出通讯录"<<endl;
}
int main()
{
    //创建通讯录类变量
    Addressbooks abs;
    //初始化通讯录中当前人员个数
    abs.m_Size=0;
    int select=0;//选择变量

    while (1)
    {
    //菜单调用
    showMenu();
    cin>>select;

    switch (select)
    {
        case 1://1.添加联系人
            addPerson(&abs);//利用地址传递，可以修饰实参
            break;
        case 2://2.显示联系人
            showPerson(&abs);
            break;
        case 3://3.删除联系人
            deletePerson(&abs);
            break;
        case 4://4.查找联系人
             findPerson(&abs);
            break;
        case 5://5.修改联系人
            modifyPerson(&abs);
            break;
        case 6://6.清空联系人
            cleanPerson(&abs);
            break;
        case 0://0.退出通讯录
            cout<<"欢迎下次使用"<<endl;
            getchar();
            return 0;
            break;
        default:
            break;
    }

    }
    getchar();
    return 0;
}