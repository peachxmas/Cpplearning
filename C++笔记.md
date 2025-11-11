[TOC]

# C++笔记

##  第1部分 基础知识

编写简单c++程序，并介绍常见c++关键字

#### 第二章：

- cout（控制台输出，读作see-out）

- ’<<‘ 插入运算符

- endl 回车

- std::名称空间

- cin输入

- '>>’提取运算符

#### 第三章：变量和常量

 - 使用列表初始化避免缩窄转换错误，要使用这种功能，可将用于初始化的变量或值放在大括号（{}）内。如：

  ```cpp
  int largeNum = 5000000; 
  short anotherNum{ largeNum }; // error! Amend types
  ```
 - 使用auto自动推断类型

 - 使用 typedef 替换变量类型

 - bool相等性检查的结果为布尔值，即 true 或 false：

  ```cpp
  int personAge = 20; 
  bool checkEquality = (personAge == 20); // true 
  bool checkInequality = (personAge != 100); // true 
  bool checkEqualityAgain = (personAge == 200); // false 
  bool checkInequalityAgain = (personAge != 20); // false
  ```

 - 在 C++中，常量可以是：

   - 字面常量；

   - 使用关键字 const 声明的常量；

       ```cpp
       const double pi = 22.0 / 7;//这里使用了关键字 const 来告诉编译器，pi 是一个类型为 double的常量。
       ```

   - 使用关键字 constexpr 声明的常量表达式（C++11 新增的）；
		```cpp
     constexpr double GetPi() {return 22.0 / 7;} //通过关键字 constexpr，可让常量声明像函数
     constexpr double TwicePi() {return 2 * GetPi();}//  在一个常量表达式中，可使用另一个常量表达式
   	```
   
   - 使用关键字 enum 声明的枚举常量；
		```cpp
   	enum CardinalDirections 
   	{ 
   		North = 25, 
   		South, 
   		East, 
   		West 
   	 };
		```
   

#### 第四章：管理数组和字符串

- vector动态数组

  ```cpp
  vector<int> dynArray (3); 
  ```
  
- 测验
  ```cpp
  //声明一个表示国际象棋棋盘的数组；该数组的类型应为枚举，该枚举定义了可能出现在棋盘方
  //格中的棋子。
  //提示：这个枚举包含枚举量 Rook、Bishop 等，从而限制了数组元素的取值范围。另外，别忘
  //了棋盘方格也可能为空！
  int main() {
      enum Square {
          Empty = 0,
          Pawn,
          Rook,
          Knight,
          Bishop,
          King,
          Queen
      };
      Square chessBoard[8][8];
      // Initialize the squares containing rooks
      chessBoard[0][0] = chessBoard[0][7] = Rook;
      chessBoard[7][0] = chessBoard[7][7] = Rook;
      return 0;
  }
  
  ```



#### 第五章：使用表达式、语句和运算符

- bitset<8> inputBits (inputNum);旨在简化二进制数据显示

- 运算符优先级

#### 第六章：控制程序流程

 ```cpp
 getline(cin, userInput);          // 步骤1：获取用户输入的完整字符串
 if (userInput.length() < 20) {    // 步骤2：检查输入长度是否安全
    strcpy(copyInput, userInput.c_str());  // 步骤3：安全复制字符串
 }
 ```

- 三目运算符?:相当于紧凑的 if-else 结构。

  可使用这个运算符获得两个数字中较大的那个：
  ```cpp
  int max = (num1 > num2)? num1 : num2;
  ```

- 基于范围的for循环（C++11）
   ```cpp
  int max = (num1 > num2)? num1 : num2;
  ```

  - 任务 2：遍历数组，修改所有元素（用引用）

  	```cpp
      int nums[] = {1,2,3,4,5};
      // 用 & 引用，把所有元素改成原来的2倍
      for (int& num : nums) {
        num *= 2;
      }
      // 再遍历输出，预期：2 4 6 8 10
      for (auto num : nums) {
        cout << num << " ";
      }
  	```

  - 任务 3：遍历字符串，统计大写字母的个数

      ```cpp
         string str = "Hello World! 2024 C++";
         int count = 0;
         for (auto c : str) {
         // 判断是否是大写字母（A-Z 的 ASCII 码 65-90）
         if (c >= 'A' && c <= 'Z') {
               count++;
           }
          }
         cout << "大写字母个数：" << count << endl; // 预期：3（H、W、C）
      ```

#### 第七章：使用函数组织代码

- 递归函数——让函数调用自己
   ```cpp
  int GetFibNumber(int fibIndex) 
  { 
      if (fibIndex < 2)  // 退出条件：当索引小于2时
          return fibIndex;  // 直接返回索引值（因为F(0)=0，F(1)=1）
      else  // 当索引>=2时，递归计算
          return GetFibNumber(fibIndex - 1) + GetFibNumber(fibIndex - 2); 
  }
  ```

- 包含多条return语句的函数

- 函数重载

- 按引用传递参数

- 微处理器如何处理函数调用

- 内联函数inline double GetPi()

- 自动推断返回类型auto Area(double radius)

- lanbda函数
   ```cpp
  [optional parameters](parameter list){ statements;}
  ```

- 测验
  
  编写一个函数，它将一个 double 数组作为参数。
  
  ```cpp
  void ProcessArray(double numbers[], int length);
  ```

	编写一个返回类型为 void 的函数，在提供了半径的情况下，它能帮助调用者计算圆的周长和面积。
   ```cpp
   void Calculate (double radius, double &Area, double &Circumference) 
   { 
    Area = 3.14 * radius * radius; 
    Circumference = 2 * 3.14 * radius; 
   }
   ```

#### 第八章：阐述指针和引用

- 声明并初始化指针int* pointsToInt = &age; 

- 解除引用运算符*p

- 不管指针指向的内存单元是 1 字节还是 8 字节，存储指针所需的内存量都相同。

- 使用 new 和 delete 动态地分配和释放内存

   ```cpp
   使用 new 分配的内存最终都需使用对应的 delete 进行释放：
   Type* Pointer = new Type; // allocate memory 
   
   delete Pointer; // release memory allocated above 
   
   这种规则也适用于为多个元素分配的内存：
   
   Type* Pointer = new Type[numElements]; // allocate a block 
   
   delete[] Pointer; // release block allocated above
   ```


- 将递增和递减运算符（++和−−）用于指针的结果

- 常量指针和指针常量
- 将指针传递给函数
- 数组和指针的类似之处

- 使用指针时常犯的编程错误
  - 内存泄露
  - 指针指向无效的内存单元
  - 悬浮指针（也叫迷途或失控指针）
  - 检查使用 new 发出的分配请求是否得到满足

- **关于 `const` 修饰的指针**：

  - **常量指针**（`const int* ptr`）：指向的**内容不可通过指针修改**，但指针的**指向可改**（可以指向其他变量）。
  - **指针常量**（`int* const ptr`）：指针的**指向不可改**（必须始终指向初始地址），但指向的**内容可以通过指针修改**。

  - 记忆技巧：`const` 离谁近就修饰谁 —— 离 `*` 近修饰 “内容”，离指针名近修饰 “指向”。

- C++ 的规则是：**指针的`const`权限只能 “缩小”，不能 “放大”**。

  你不能把 “只读权限的常量指针”，赋给 “读写权限的普通指针”—— 否则`const`就失去了意义，没法保护变量不被修改。编译器会直接报错阻止这种操作～
  
##  第2部分 C++面向对象编程基础
> 介绍类的概念，您将学习 C++如何支持封装、抽象、继承和多态等重要的面向对象编程原则。第 9 章将介绍 C++11 新增的移动构造函数，而第 12 章将介绍移动赋值运算符。这些功能有助于避免不必要的复制步骤，从而提升应用程序的性能。第 14 章是一个跳板，帮助您编写功能强大的 C++通用代码。
#### 第九章：类和对象
- 值传递  s.name
- 地址传递 p->name
```cpp
//访问权限
//公共权限 public       类内类外都可以访问
//保护权限 protected    类外不可以访问 子类可以访问父类保护内容
//私有权限 private      类外不可以访问 子类不可以访问父类私有内容
class Human //声明类
{ 
 string name; 
 string dateOfBirth; 
 string placeOfBirth; 
 string gender; 
 void Talk(string textToTalk); 
 void IntroduceSelf(); 
 ... 
};
Human firstMan;//创建human对象
```
```cpp
/*使用new为human对象动态地分配内存*/
Human* firstWoman = new Human(); 
firstWoman->dateOfBirth = "1970"; 
firstWoman->IntroduceSelf();//使用指针运算符（->）来访问成员属性和方法
delete firstWoman; 
```
- 关键字public和private
```cpp
class Human 
{ 
private: 
 int age; //不能直接给age赋值   eve.age = 22;compile error
public: 
 void SetAge(int humansAge) //只能通过   eve.SetAge(22); OK
 { 
 if (humansAge > 0) 
 age = humansAge; 
 }；
};
```
- 初始化列表初始化属性
```cpp
class Person 
{ 
public: 
  Person(int a,int b,int c):m_A(a),m_B(b),m_C(c)//初始化列表初始化属性
  {

  }
  int m_A;
  int m_B;
  int m_C;

};
```
- 构造函数
  构造函数是一种特殊的函数，它与类同名且不返回任何值。
  按参数分：有参构造和无参构造
  按类型分：普通构造和拷贝构造（复制构造）
  ::作用域解析运算符
- 重载构造函数
```cpp
class Human 
{ 
public: 
 Human() 
 {  } 
 Human(string humansName) 
 {  } 
};
```
- 没有构造函数的类
```cpp
class Student {
private:
    string name;
    int age;
    string idPrefix;

public:
    // 1. 无参构造函数（默认创建方式）
    Student() : name("未知"), age(18), idPrefix("STU-") {}

    // 2. 单参数构造函数（只传姓名，年龄默认18）
    Student(string n) : name(n), age(18), idPrefix("STU-") {}

    // 3. 双参数构造函数（传姓名+年龄）
    Student(string n, int a) : name(n), age(a), idPrefix("STU-") {
        if (age < 0) age = 18;
    }

    void showInfo() {
        cout << idPrefix << "：" << name << "，" << age << "岁" << endl;
    }
};

int main() {
    Student s1; // 调用无参构造 → STU-：未知，18岁
    Student s2("小李"); // 调用单参数构造 → STU-：小李，18岁
    Student s3("小王", 20); // 调用双参数构造 → STU-：小王，20岁

    s1.showInfo();
    s2.showInfo();
    s3.showInfo();
    return 0;
}
```
- 默认构造函数是调用时可不提供参数的构造函数，而并不一定是不接受任何参数的构造
函数。
- 包含初始化列表的构造函数
  ```cpp
  public: 
  Human(string humansName = "Adam", int humansAge = 25) 
  :name(humansName), age(humansAge) 
  { 
  cout << "Constructed a human called " << name; 
  cout << ", " << age << " years old" << endl; 
  }
  ```
- 析构函数
  与构造函数一样，析构函数也是一种特殊的函数。构造函数在实例化对象时被调用，而析构函数在对象销毁时自动被调用。
- 指针的本质：指针就是 “内存地址的持有者”，它永远指向一块合法内存 —— 要么是栈内存（比如 int a=10; int* p=&a;），要么是堆内存（比如 int* p=new int(10);），核心作用是 “访问指向的内存数据”。
- 堆内存的使用场景：只有遇到以下需求时，才需要用 new 给指针分配堆内存（栈内存满足不了）：
    - 资源大小不确定（需动态调整，比如用户输入长度的字符串）；
    - 资源生命周期要超过当前作用域（比如函数创建后，返回给其他函数使用）；
    - 需要存储大量数据（栈内存空间有限，容易溢出）。

- 类与构造 / 析构的关系：类的构造函数是 “资源申请入口”，如果构造函数里用 new 申请了堆内存（比如 char* buffer=new char[100]），就必须在析构函数里用 delete 释放 —— 因为外部访问不到类的私有成员指针（比如 buffer），只能靠析构函数在对象销毁时自动清理，避免内存泄漏。
- 「C++ 核心原则」—— 优先使用栈内存、标准库容器（vector/string）和智能指针，避免直接用new/delete；若必须使用动态资源，务必通过「析构函数」或「智能指针」自动释放，遵循 RAII 思想。
- 复制构造函数
    - 三种调用时机
      - 使用一个已创建完毕的对象来初始化一个新对象
      - 值传递的方式给函数参数传值
      - 值返回局部对象
    - 解决浅复制存在两个对象指向同一块动态分配的内存的问题 使用复制构造函数确保深复制
- 深拷贝和浅拷贝
    - 浅拷贝：简单的赋值
    - 深拷贝：在堆区重新申请空间，进行拷贝操作
    ```cpp
    为 MyString 类声明复制构造函数的语法如下：
    class MyString 
    { 
    MyString(const MyString& copySource); 
    }; 
    MyString::MyString(const MyString& copySource) 
    { 
    }
    ```
- 构造函数调用规则
    - 只要创建一个类，编译器至少提供三个函数
      - 默认构造
      - 默认析构
      - 默认拷贝构造
    - 如果写了有参构造函数，编 译器不再提供默认构造，依然提供拷贝构造
    - 如果写了拷贝构造，编译器不再提供其他函数
- MyString 完整代码
```cpp
#include <iostream>
#include <cstring> // 用于strlen、strcpy
using namespace std;

class MyString {
private:
    char* buffer; // 存储字符串的缓冲区（核心资源）

public:
    // 1. 普通构造函数（创建字符串）
    MyString(const char* initString = nullptr) {
        buffer = nullptr;
        if (initString != nullptr) {
            buffer = new char[strlen(initString) + 1]; // 分配内存
            strcpy(buffer, initString); // 复制字符串内容
            cout << "普通构造：创建字符串 \"" << buffer << "\"" << endl;
        } else {
            cout << "普通构造：创建空字符串" << endl;
        }
    }

    // 2. 复制构造函数（深复制）
    MyString(const MyString& copySource) {
        buffer = nullptr;
        if (copySource.buffer != nullptr) {
            // 深复制：重新分配内存，拷贝内容（耗时操作）
            buffer = new char[strlen(copySource.buffer) + 1];
            strcpy(buffer, copySource.buffer);
            cout << "复制构造：拷贝字符串 \"" << buffer << "\"" << endl;
        }
    }

    // 3. 移动构造函数（C++11核心，资源转移）
    MyString(MyString&& moveSource) {
        // 直接拿移动源的buffer，不复制
        buffer = moveSource.buffer;
        // 把移动源的buffer设为NULL，避免析构时重复释放
        moveSource.buffer = nullptr;
        cout << "移动构造：转移临时对象的资源" << endl;
    }

    // 析构函数（释放内存，避免泄漏）
    ~MyString() {
        if (buffer != nullptr) {
            cout << "析构：释放字符串 \"" << buffer << "\" 的内存" << endl;
            delete[] buffer;
        } else {
            cout << "析构：释放空字符串" << endl;
        }
    }

    // 辅助函数：获取字符串（供Copy函数使用）
    const char* GetString() const {
        return buffer ? buffer : "";
    }
};

// 按值返回的Copy函数（触发临时对象）
MyString Copy(MyString& source) {
    cout << "\n进入Copy函数：" << endl;
    // 创建局部对象（调用复制构造）
    MyString copyForReturn(source.GetString());
    cout << "Copy函数准备返回" << endl;
    return copyForReturn; // 返回临时对象（触发移动构造）
}

int main() {
    // 第一步：创建原始字符串
    MyString sayHello("Hello World of C++");

    // 第二步：调用Copy函数，创建新对象
    cout << "\n===== 开始调用Copy函数 =====" << endl;
    MyString sayHelloAgain(Copy(sayHello));
    cout << "===== Copy函数调用结束 =====" << endl;

    // 验证结果
    cout << "\n最终sayHelloAgain的内容：" << sayHelloAgain.GetString() << endl;

    return 0;
}
```
- 当其他类对象作为本类成员，构造时候先构造类对象再构造自身。析构和构造顺序相反
- 静态成员
  - 静态成员变量
    - 所有对象共享一份数据
    - 编译阶段就分配内存
    - 类内声明类外初始化
      ```cpp
        class Person
        {
          public:
            static int m_A;
        }
        void text02()
        {
          //静态成员变量不属于某个对象，所有对象共享一份数据 
            //1.通过对象进行访问
            Person p;
            cout<<p.m_A<<endl;
            //2.通过类名进行访问
            cout<<Person::m_A<<endl;
        }
        int Person::m_A=100;
      ```
  - 静态成员函数
    - 所有对象共享同一函数
    - 静态成员函数只能访问静态成员变量
      ```cpp
        class Person
        {
          public:
            static void func()
            {
                cout<<"static void func调用"<<endl;
            };
        }
        void text02()
        {
          //静态成员变量不属于某个对象，所有对象共享一份数据 
            //1.通过对象进行访问
            Person p;
            p.func();
            //2.通过类名进行访问
            Person::func();
        }
      ```    
- 成员函数和成员变量分开储存
  空对象占用内存空间为：1
  编译器会给空对象分配一个字节空间为了区分空对象占内存位置
  非静态成员变量  属于类对象上
  静态成员变量    不属于类对象上
  非静态成员函数  不属于类对象上
  静态成员函数    不属于类对象上
- 不允许复制的类
  将复制构造函数和赋值运算符声明为私有的确保对象是不可复制的。
- 只能有一个实例的单例类
- 禁止在栈中实例化
  将析构函数声明为私有的
- 使用构造函数进行类型转换
  - 未归纳 -
- this指针 
  - 本质：指针常量 不可修改指向
  - 指向被调用的成员函数所属对象
  - 在类中，关键字 this 包含当前对象的地址
  - 用途：
    - 解决名称冲突：在形参和成员变量同名时，可使用this指针来区分
    - 返回对象本身：在类的非静态成员函数中返回对象本身，可使用return *this
- 空指针访问成员函数 
  if空指针就return掉
- const修饰成员函数 
  - 常函数
    - 成员函数后加const后我们称这个函数为常函数
      修饰的是this指向，让指针指向的值也不可以修改
    - 常函数内不可以修改成员属性
    - 成员属性声明时加关键字mutable后，常函数依然可以修改 

- 将sizeof()用于类
  sizeof(MyString)
- 声明友元
  ```cpp
  friend void DisplayAge(const Human& person);
  ```
  函数 DisplayAge( )是全局函数，还是 Human 类的友元，因此能够访问Human 类的私有数据成员。
  三种实现
  - 全局函数做友元
  - 类做友元
  - 成员函数做友元
- 共用体
  - 未归纳 -
- 对类和结构使用聚合初始化
  - 未归纳 -

#### 第十章：实现继承
- 继承基本语法
  class 子类:继承方式 父类
  ```cpp
  class Java:public BasePage
  {};
  ```  
- 基类初始化————向基类传递参数
  ```cpp
  class Base
  {
    public:
      Base(int someNumber)
      {

      }
  };
  class Derived:public Base
  {
    public:
      Derived():Base(25)
      {

      }
  }
  ``` 
-  在派生类中覆盖基类的办法
  ```cpp
  class Base 
  { 
  public: 
  void DoSomething() 
  { 
  // implementation code… Does something 
  } 
  }; 
  class Derived:public Base 
  { 
  public: 
  void DoSomething() 
  { 
  // implementation code… Does something else 
  } 
  };
  ``` 
- 在派生类中隐藏基类
  - 解决方案1：在 main( )中使用作用域解析运算符（::）：
    ```cpp
    myDinner.Fish::Swim();
    ``` 
  - 解决方案2：在 Tuna 类（子类）中，使用关键字 using 解除对 Fish::Swim( )的隐藏：
    ```cpp
    class Tuna: public Fish 
    { 
    public: 
    using Fish::Swim; // unhide all Swim() methods in class Fish
    void Swim() 
    { 
    cout << "Tuna swims real fast" << endl; 
    } 
    };
    ``` 
  - 解决方案3：在 Tuna 类中，覆盖 Fish::Swim( )的所有重载版本（如果需要，可通过 Tuna::Fish(…)调用方法 Fish::Swim( )）：
    ```cpp
    class Tuna: public Fish 
    { 
    public: 
    void Swim(bool isFreshWaterFish) 
    { 
    Fish::Swim(isFreshWaterFish); 
    } 
    void Swim() 
    { 
    cout << "Tuna swims real fast" << endl; 
    } 
    };
    ```   
- 切除问题  
    ```cpp
    Derived objDerived; 
    Base objectBase = objDerived; 
    //或
    void UseBase(Base input); 
    Derived objDerived; 
    UseBase(objDerived); // copy of objDerived will be sliced and sent
    ``` 
    Derived 的数据成员包含的信息将丢失。这种无意间裁减数据，导致 Derived 变成 Base 的行为称为切除（slicing）。
    要避免切除问题，不要按值传递参数，而应以指向基类的指针或 const 引用的方式传递。
- 继承方式
  - 公共继承
    访问不到父类私有权限，其他权限不变
  - 保护继承
    访问不到父类私有权限，其他权限变为保护权限
  - 私有继承  
    访问不到父类私有权限，其他权限变为私有权限
- 继承中的子类模型
  - 利用开发人员命令提示工具查看对象模型
- 继承中的构造和析构顺序
  父类构造-子类构造-子类析构-父类析构
- 继承同名成员处理方式
  - 访问子类同名成员 直接访问即可
    s.A
  - 访问父类同名成员 需要加作用域
    s.Base::A
- 多继承语法    
  允许一个类继承多个类
  实际开发中不建议使用多继承
- 使用final禁止继承
    ```cpp
    class Platypus final: public Mammal, public Bird, public Reptile 
    { 
    public: 
    void Swim() 
    { 
    cout << "Platypus: Voila, I can swim!" << endl; 
    } 
    };
    ``` 
- 菱形继承
  在继承之前加virtual变为虚继承
#### 第十一章：多态
- 多态基本概念
  多态是C++面向对象编程的三大特性之一
  多态分为两类
  - 静态多态：函数重载和运算符重载属于静态多态，复用函数名
  - 动态多态：派生类和虚函数实现运行时多态
  静态多态和动态多态区别：
  - 静态多态的函数地址早绑定-编译阶段确定函数地址
  - 动态多态的函数地址晚绑定-运行阶段确定函数地址

  - 动态多态满足条件
    - 有继承关系
    - 子类重写父类虚函数
  - 动态多态调用
    父类的指针或者引用指向子对象的时候发生多态
- 多态原理剖析
  - 虚函数表
    每个含有虚函数的类（包括子类）都会生成一个独立的虚表，表中存储该类所有虚函数的地址；
  - 虚表指针
    每个该类的对象会隐含一个 vptr 指针（占用对象内存空间），vptr 指向所属类的虚表；
  - 构造函数不能是虚函数
  - 析构函数必须是虚函数
- 纯虚函数
  virtual void func()=0;
  只要有一个纯虚函数，这个类称为抽象类
  抽象的子类必须重写父类中的纯虚函数否则也属于抽象类
 - 虚析构和纯虚析构
    共性
    - 都可以解决父类指针释放子类对象
    - 都需要有具体的函数实现
    区别
    - 如果是纯虚析构，该类属于抽象类，无法实例化对象
- 表明覆盖意图的限定符override
从 C++11 起，程序员可使用限定符 override 来核实被覆盖的函数在基类中是否
被声明为虚的：

    ```cpp
    class Tuna:public Fish 
    { 
    public: 
    void Swim() const override // Error: no virtual fn with this sig in Fish 
    { 
    cout << "Tuna swims!" << endl; 
    } 
    };
    ``` 
- 可将复制构造函数声明为虚函数吗
    - 未归纳 -
#### 第十二章：运算符与运算符重载
运算符重载
  对已有的运算符进行重新定义，赋予其另一种功能
  ```cpp
      return_type operator operator_symbol (...parameter list...);
  ``` 
- 加号运算符重载
- 左移运算符重载
  ```cpp
    operator const char*() 
    { 
    ostringstream formattedDate; //formattedDate 的类型是 ostringstream（输出字符串流）
    formattedDate << month << " / " << day << " / " << year; 
    dateInString = formattedDate.str(); 
    return dateInString.c_str(); 
    }
    int main () 
    { 
    Date Holiday (12, 25, 2016); 
    cout << "Holiday is on: " << Holiday << endl; 
    return 0; 
    }
  ```  
- 递增运算符重载    
  区分前置递增和后置递增，在括号里加int
  ```cpp
      Date& operator ++()//前置递增
      {
        ++day;
        return *this;
      }
      Date operator ++(int)//后置递增
      {
        Date copy(month,day,year);
        ++day;
        return copy;
      }
  ``` 
  后置不可以链式编程
- 解引用（*）和成员选择运算符（->）
  ```cpp
      unique_ptr<int> smartIntPtr(new int);/智能指针
  ``` 
- 双目运算符
  对两个操作数进行操作的运算符称为双目运算符。
  双目加法
  ```cpp
    Date operator + (int daysToAdd) // binary addition 
    { 
    Date newDate (month, day + daysToAdd, year); 
    return newDate; 
    }
    Date PreviousHoliday (Holiday - 19);
  ``` 
- 赋值运算符重载
  ```cpp
    bool operator== (const Date& compareTo) 
    { 
    return ((day == compareTo.day) 
    && (month == compareTo.month) 
    && (year == compareTo.year)); 
    }
  ``` 
- 重载复制赋值运算符（=）
  ```cpp
    // 复制赋值运算符：返回 MyString&，参数是 const MyString& copySource
    MyString& operator= (const MyString& copySource) 
    { 
        if ((this != &copySource) && (copySource.buffer != NULL)) 
        { 
            // 关键步骤1：释放当前对象（this）原有 buffer 的内存
            if (buffer != NULL) 
                delete[] buffer;  // 避免内存泄漏（先清空旧的，再装新的）

            // 关键步骤2：为当前对象分配新内存（深复制的核心）
            // 内存大小 = 源对象字符串长度 + 1（+1是给 '\0' 结束符留位置）
            buffer = new char [strlen(copySource.buffer) + 1]; 

            // 关键步骤3：把源对象的内容拷贝到新内存
            strcpy(buffer, copySource.buffer);  // strcpy：C语言函数，复制字符串
        } 

        return *this;  // 返回当前对象本身
    } 
  ``` 
- 下标运算符
  下标运算符让您能够像访问数组那样访问类，其典型语法如下：
  return_type& operator [] (subscript_type& subscript);
- 函数调用运算符重载
- 用于高性能编程的移动构造函数和移动赋值运算符
  - 未归纳 -
- 用户定义的自变量
  ```cpp
  Temperature operator"" _C(long double celcius) 
  { 
  return Temperature(celcius + 273); 
  } 
  
  Temperature operator "" _F(long double fahrenheit) 
  { 
  return Temperature((fahrenheit + 459.67) * 5 / 9); 
  }
 
  Temperature k1 = 31.73_F; 
 
 
  ```
#### 第十三章：类型转换运算符

语法统一是：`目标类型 结果 = 转换运算符<目标类型>(要转换的数据)`。

 1. static_cast：“安全相关类型”的转换
- **用途**：
  - 相关类型的指针转换（比如继承体系里的基类和派生类指针）；
  - 显式执行“本来能自动转换”的操作（比如`double`转`int`），让代码更易读。
- **关键特点**：
  - 编译时检查：只能转相关类型（比如基类和派生类），转完全不相关的类型会报错（比C风格安全）；
  - 不做运行时检查：可能有隐患。比如把基类指针转成派生类指针（叫“向下转换”），哪怕基类指针实际指向的是基类对象，编译器也不报错，但运行时调用派生类特有函数会出问题。
- **例子**：
  ```cpp
  double Pi = 3.14;
  int num = static_cast<int>(Pi); // 显式把double转int，比直接写int num=Pi更清晰
  ```

 2. dynamic_cast：“带运行时检查”的转换
- **用途**：主要用于继承体系的“向下转换”（基类指针转派生类指针），能判断转换是否成功。
- **关键特点**：
  - 运行时检查：依赖“运行阶段类型识别（RTTI）”，转换成功返回有效指针，失败返回`NULL`；
  - 必须有虚函数：基类里至少要有一个虚函数（比如析构函数），否则不能用。
- **核心用法**：转换后一定要检查指针是否有效！
- **例子**（对应书中代码）：
  ```cpp
  Fish* objBase = new Tuna(); // Fish是基类，Tuna是派生类
  Tuna* objTuna = dynamic_cast<Tuna*>(objBase);
  if (objTuna) { // 检查转换成功
    objTuna->BecomeDinner(); // 安全调用派生类特有函数
  }
  ```

 3. reinterpret_cast：“暴力重新解读”的转换
- **用途**：强制转换完全不相关的类型，相当于C风格转换的“C++版”。
- **关键特点**：
  - 不做任何类型检查，纯粹让编译器重新解读数据的二进制；
  - 极不安全、不可移植，只在特殊场景用（比如驱动开发中把对象转成字节流给API）。
- **警告**：非必要绝对不用！
- **例子**：
  ```cpp
  SomeClass* obj = new SomeClass();
  unsigned char* bytes = reinterpret_cast<unsigned char*>(obj); // 把对象转成字节流
  ```

 4. const_cast：“移除const限制”的转换
- **用途**：关闭变量的`const`属性，比如调用一个非`const`成员函数，但传入的参数是`const`对象。
- **关键特点**：
  - 只能修改`const`修饰符，不能改变类型；
  - 风险高：如果原对象本身是`const`的，用它修改对象可能导致不可预料的行为。
- **场景**：兼容第三方库（比如库函数没声明为`const`，但你的代码需要传`const`对象）。
- **例子**：
  ```cpp
  void Display(const SomeClass& obj) {
    SomeClass& ref = const_cast<SomeClass&>(obj); // 移除const
    ref.DisplayMembers(); // 调用非const成员函数
  }
  ```

5. 向上转换vs向下转换
- **向上转换**：派生类指针→基类指针（比如`Tuna*`转`Fish*`），安全！不用显式转换，编译器自动支持；
- **向下转换**：基类指针→派生类指针（比如`Fish*`转`Tuna*`），不安全！必须用显式转换，最好用`dynamic_cast`并检查结果。

6. C++转换运算符不是万能的
虽然比C风格精准，但也有缺点：
- 语法繁琐：比如`static_cast<int>(Pi)`比`(int)Pi`写起来麻烦；
- 部分场景没必要：简单的类型转换（比如`double`转`int`），C风格更简洁，很多程序员仍习惯用；
- 尽量避免转换：类型转换本质上是“绕开编译器的类型检查”，优秀的代码应尽量减少转换。







##  第3部分 学习标准模板库（STL）
>将帮助您使用 STL string 类和容器编写高效而实用的 C++代码。您将了解到，使用 std::string 可安全而轻松地拼接字符串，您不再需要使用 C 风格的字符串 char*。您可使用 STL 动态数组和链表，而无需自己编写这样的类。
#### 第十四章：宏和模板简介
两种模板机制
- 函数模板
  - 作用：建立一个通用函数，其返回值和形参不具体制定，用一个虚拟的类型来代表。
  - 语法：
  ```cpp
  template<class T>
  //函数声明或定义
  //1.自动类型推导
  //mySwap(a,b);
  //2.显式指定类型
  //maSwap<int>(a,b);
  ```
  - 意义：提高复用性，类型参数化
  - 注意事项：
    - 自动类型推导，必须推导出一致的数据类型T，才可以使用
    - 模板必须要确定出T的数据类型，才可以使用
  - 普通函数与函数模板区别：
    - 普通函数调用时可以发生自动类型转换（隐式转换）
    - 函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
    - 如果利用显示指定类型的方式，可以发送隐式类型转换
  - 普通函数和函数模板的调用规则
    - 如果函数模板和普通函数都可以实现，优先调用普通函数
    - 可以通过空模板参数列表来强制调用函数模板
      ```cpp
      maSwap<>(a,b);
      ```
    - 函数模板也可以重载
    - 如果函数模板可以产生更好的匹配有限调用函数模板
  - 模板的局限性
    有些特定的数据类型需要具体化方式做特殊实现
    具体化：解决自定义类型通用化
      ```cpp
      template<>bool myCompare(Person &p1,Person&p2)
      ```
- 类模板
  - 作用：建立一个通用类，类中的成员不具体制定，用虚拟类型代表
  - 类模板和函数模板的区别
    - 类模板没有自动类型推导的使用方式
    - 类模板在模板参数列表中可以有默认参数
  - 类模板中成员函数创建时机
    - 普通类中的成员函数一开始就可以创建
    - 类模板中的成员函数在调用时才创建
  - 类模板对象做函数参数
    - 类模板实例化出的对象，向函数传参的方式
    1. 指定传入的类型 --- 直接显示对象的数据类型
    2. 参数模板化 --- 将对象中的参数变为模板进行传递
    3. 整个类模板化 --- 将这个对象类型 模板化进行传递
  - 类模板与继承
    - 当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
    - 如果不指定，编译器无法给子类分配内存
    - 如果想灵活指定出父类中T的类型，子类也需变为类模板
  - 类模板成员函数类外实现
    需要加上模板的参数列表
  - 类模板分文件编写
    类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到
    - 解决方式1：直接包含.cpp源文件
    - 解决方式2：将声明和实现写到同一个文件中，并更改后缀名为.hpp，hpp是约定的名称，并不是强制
  - 类模板与友元
    - 掌握类模板配合友元函数的类内和类外实现
        全局函数类内实现 - 直接在类内声明友元即可
        全局函数类外实现 - 需要提前让编译器知道全局函数的存在

#### 第十五章：标准库简介
- C++的面向对象和泛型编程思想，目的就是复用性的提升
为了建立数据结构和算法的一套标准,诞生了STL
- STL基本概念
  STL(Standard Template Library,标准模板库)
  STL 从广义上分为: 容器(container) 算法(algorithm) 迭代器(iterator)
  容器和算法之间通过迭代器进行无缝连接。
  STL 几乎所有的代码都采用了模板类或者模板函数
- STL六大组件
STL大体分为六大组件，分别是:容器、算法、迭代器、仿函数、适配器（配接器）、空间配置器
1. 容器：各种数据结构，如vector、list、deque、set、map等,用来存放数据。
2. 算法：各种常用的算法，如sort、find、copy、for_each等
3. 迭代器：扮演了容器与算法之间的胶合剂。
4. 仿函数：行为类似函数，可作为算法的某种策略。
5. 适配器：一种用来修饰容器或者仿函数或迭代器接口的东西。
6. 空间配置器：负责空间的配置与管理。
- STL中容器、算法、迭代器
  - 容器：
  STL容器就是将运用最广泛的一些数据结构实现出来
  常用的数据结构：数组, 链表,树, 栈, 队列, 集合, 映射表 等
  这些容器分为序列式容器和关联式容器两种:
    - 序列式容器:强调值的排序，序列式容器中的每个元素均有固定的位置。 
    - 关联式容器:二叉树结构，各元素之间没有
严格的物理上的顺序关系
  - 算法：
  有限的步骤，解决逻辑或数学上的问题，这一门学科我们叫做算法(Algorithms)
  算法分为:质变算法和非质变算法。
    - 质变算法：是指运算过程中会更改区间内的元素的内容。例如拷贝，替换，删除等等
    - 非质变算法：是指运算过程中不会更改区间内的元素内容，例如查找、计数、遍历、寻找极值等等
  - 迭代器：
  提供一种方法，使之能够依序寻访某个容器所含的各个元素，而又无需暴露该容器的内部表示方式。
  每个容器都有自己专属的迭代器
  迭代器使用非常类似于指针，初学阶段我们可以先理解迭代器为指针
  迭代器种类

  |种类| 功能 |支持运算|
  |-----|-------|----- |
  |输入迭代器|对数据的只读访问 |只读，支持++、==、！=|
  |输出迭代器| 对数据的只写访问 |只写，支持++|
  前向迭代器 |读写操作，并能向前推进迭代器 |读写，支持++、==、！=|
  双向迭代器 |读写操作，并能向前和向后操作 |读写，支持++、--，|
  随机访问迭代器|读写操作,可以以跳跃的方式访问任意数据，功能最强的迭代器|读写，支持++、--、[n]、-n、<、<=、>、>=
- 容器算法迭代器初识
  - vector存放内置数据类型
  容器：`vector`
  算法： `for_each`
  迭代器： `vector<int>::iterator`
  ```cpp
  #include <vector>
  #include <algorithm>
  void MyPrint(int val)
  {
  cout << val << endl;
  }

  void test01() 
  {
  //创建vector容器对象，并且通过模板参数指定容器中存放的数据的类型
  vector<int> v;
  //向容器中放数据
  v.push_back(10);
  v.push_back(20);
  v.push_back(30);
  v.push_back(40);
  //每一个容器都有自己的迭代器，迭代器是用来遍历容器中的元素
  //v.begin()返回迭代器，这个迭代器指向容器中第一个数据
  //v.end()返回迭代器，这个迭代器指向容器元素的最后一个元素的下一个位置
  //vector<int>::iterator 拿到vector<int>这种容器的迭代器类型
  vector<int>::iterator pBegin = v.begin();
  vector<int>::iterator pEnd = v.end();
  //第一种遍历方式：
  while (pBegin != pEnd) {
  cout << *pBegin << endl;
  pBegin++;
  }

  //第二种遍历方式：
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
  cout << *it << endl;
  }
  cout << endl;
  //第三种遍历方式：
  //使用STL提供标准遍历算法 头文件 algorithm
  for_each(v.begin(), v.end(), MyPrint);
  }

  int main() {
  test01();
  system("pause");
  return 0;
  }

  ```
  - Vector存放自定义数据类型
  ```cpp
  #include <vector>
  #include <string>
  //自定义数据类型
  class Person {
  public:
  Person(string name, int age) {
  mName = name;
  mAge = age;
  }
  public:
  string mName;
  int mAge;
  };
  //存放对象
  void test01() {
  vector<Person> v;
  //创建数据
  Person p1("aaa", 10);
  Person p2("bbb", 20);
  Person p3("ccc", 30);
  Person p4("ddd", 40);
  Person p5("eee", 50);
  v.push_back(p1);
  v.push_back(p2);
  v.push_back(p3);
  v.push_back(p4);
  v.push_back(p5);
  for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
  cout << "Name:" << (*it).mName << " Age:" << (*it).mAge << endl;
  }
  }
  //放对象指针
  void test02() {
  vector<Person*> v;
  //创建数据
  Person p1("aaa", 10);
  Person p2("bbb", 20);
  Person p3("ccc", 30);
  Person p4("ddd", 40);
  Person p5("eee", 50);
  v.push_back(&p1);
  v.push_back(&p2);
  v.push_back(&p3);
  v.push_back(&p4);
  v.push_back(&p5);
  for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++) {
  Person * p = (*it);
  cout << "Name:" << p->mName << " Age:" << (*it)->mAge << endl;
  }
  }
  int main() {
  test01();
  test02();
  system("pause");
  return 0;
  }
  ```
  -  Vector容器嵌套容器
  ```cpp
  #include <vector>
  //容器嵌套容器
  void test01() {
  vector< vector<int> > v;
  vector<int> v1;
  vector<int> v2;
  vector<int> v3;
  vector<int> v4;
  for (int i = 0; i < 4; i++) {
  v1.push_back(i + 1);
  v2.push_back(i + 2);
  v3.push_back(i + 3);
  v4.push_back(i + 4);
  }
  //将容器元素插入到vector v中
  v.push_back(v1);
  v.push_back(v2);
  v.push_back(v3);
  v.push_back(v4);
  for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) //大容器遍历*it
  {
  for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++) {
  cout << *vit << " ";
  }
  cout << endl;
  }
  }
  int main() {
  test01();
  system("pause");
  return 0;
  }
  ```
#### 第十六章：STL string类
- **string基本概念**
  - 本质：
    string是C++风格的字符串，而string本质上是一个类
  - string和char * 区别：
    char * 是一个指针
    string是一个类，类内部封装了char*，管理这个字符串，是一个char*型的容器。
  - **string构造函数**
    `string();` //创建一个空的字符串 例如: string str;
    `string(const char* s);` //使用字符串s初始化
    `string(const string& str);` //使用一个string对象初始化另一个string对象
    `string(int n, char c);` //使用n个字符c初始化
  - **string赋值操作**
    `string& operator=(const char* s);` //char*类型字符串 赋值给当前的字符串
    `string& operator=(const string &s); `//把字符串s赋给当前的字符串
    `string& operator=(char c);` //字符赋值给当前的字符串
    `string& assign(const char *s); `//把字符串s赋给当前的字符串
    `string& assign(const char *s, int n); `//把字符串s的前n个字符赋给当前的字符串
    `string& assign(const string &s); `//把字符串s赋给当前字符串
    `string& assign(int n, char c);` //用n个字符c赋给当前字符串
  - **string字符串拼接**
    `string& operator+=(const char* str); `//重载+=操作符
    `string& operator+=(const char c); `//重载+=操作符
    `string& operator+=(const string& str); `//重载+=操作符
    `string& append(const char *s);` //把字符串s连接到当前字符串结尾
    `string& append(const char *s, int n); `//把字符串s的前n个字符连接到当前字符串结尾
    `string& append(const string &s); `//同operator+=(const string& str)
    `string& append(const string &s, int pos, int n);` //字符串s中从pos开始的n个字符连接到字符串结尾
  - **string查找和替换**
    `int find(const string& str, int pos = 0) const; `//查找str第一次出现位置,从pos开始查找
    `int find(const char* s, int pos = 0) const;` //查找s第一次出现位置,从pos开始查找
    `int find(const char* s, int pos, int n) const;` //从pos位置查找s的前n个字符第一次位置
    `int find(const char c, int pos = 0) const; `//查找字符c第一次出现位置
    `int rfind(const string& str, int pos = npos) const; `//查找str最后一次位置,从pos开始查找
    `int rfind(const char* s, int pos = npos) const; `//查找s最后一次出现位置,从pos开始查找
    `int rfind(const char* s, int pos, int n) const; `//从pos查找s的前n个字符最后一次位置
    `int rfind(const char c, int pos = 0) const;` //查找字符c最后一次出现位置
    `string& replace(int pos, int n, const string& str); `//替换从pos开始n个字符为字符串str
    `string& replace(int pos, int n,const char* s); `//替换从pos开始的n个字符为字符串s

  find查找是从左往后，rfind从右往左
  find找到字符串后返回查找的第一个字符位置，找不到返回-1
  replace在替换时，要指定从哪个位置起，多少个字符，替换成什么样的字符串
  - **string字符串比较**
  字符串比较是按字符的ASCII码进行对比
    = 返回 0
    \> 返回 1
    < 返回 -1
  `int compare(const string &s) const; `//与字符串s比较
  `int compare(const char *s) const; `//与字符串s比较
  - **string字符存取**
  `char& operator[](int n);` //通过[]方式取字符
  `char& at(int n);` //通过at方法获取字符
  - **string插入和删除**
  `string& insert(int pos, const char* s); `//插入字符串
  `string& insert(int pos, const string& str); `//插入字符串
  `string& insert(int pos, int n, char c); `//在指定位置插入n个字符c
  `string& erase(int pos, int n = npos);`//删除从Pos开始的n个字符
  - **string子串**
  `string substr(int pos = 0, int n = npos) const; `//返回由pos开始的n个字符组成的字符串
#### 第十七章：STL 动态数组类
- **vector基本概念**
  - 功能：
  vector数据结构和数组非常相似，也称为单端数组
  - vector与普通数组区别：
  不同之处在于数组是静态空间，而vector可以动态扩展
  - 动态扩展：
    - 并不是在原空间之后续接新空间，而是找更大的内存空间，然后将原数据拷贝新空间，释放原空间
    - vector容器的迭代器是支持随机访问的迭代器
- **vector构造函数**
  `vector<T> v; `//采用模板实现类实现，默认构造函数
  `vector(v.begin(), v.end());` //将v[begin(), end())区间中的元素拷贝给本身。
  `vector(n, elem); `//构造函数将n个elem拷贝给本身。
  `vector(const vector &vec);` //拷贝构造函数。
- **vector赋值操作**
  `vector& operator=(const vector &vec);` //重载等号操作符
  `assign(beg, end); `//将[beg, end)区间中的数据拷贝赋值给本身。
  `assign(n, elem); `//将n个elem拷贝赋值给本身。
#### 第十八章：STL list和forward_list
#### 第十九章：STL集合类
#### 第二十章：STL映射类
#### 第二十一章：理解函数对象

##  第4部分 再谈STL
>专注于算法，您将学习如何通过迭代器对 vector 等容器进行 sort 操作。在这部分，您将发现，通过使用 C++11 新增的关键字 auto，可极大地简化冗长的迭代器声明。第 22 章将介绍 C++11 新增的 lambda 表达式，这可极大地简化使用 STL 算法的代码。
#### 第二十二章：lambda表达式
#### 第二十二章：STL算法
#### 第二十二章：自适应容器：栈和队列
#### 第二十二章：使用STL位标志
##  第5部分 高级C++概念
>阐述智能指针和异常处理等 C++功能。对 C++应用程序来说，这些功能并非必需的，但可极大地提高应用程序的稳定性和品质。在这部分的最后，简要地介绍了有助于编写杰出 C++应用程序的最佳实践，还展望了下一个 ISO 标准—C++17 有望引入的新特性。
#### 第二十六章：理解智能指针
#### 第二十七章：使用流进行输入和输出
#### 第二十八章：异常处理
#### 第二十九章：


#### 文件操作
- 操作文件三大类
  1.ofstream:读操作
  2.ifstream:写操作
  3.fstream:读写操作
- 写文件
  1.包含头文件
    #include <fstream>
  2.创建流对象
    ofstream ofs;
  3.打开文件
    ofs.open("文件路径",打开方式);
  4.写数据
    ofs<<"写入的数据";
  5.关闭文件
    ofs.close();
- 二进制写文件
  ofs.write((const char*)&p,sizeof(p));
- 读文件
  1.包含头文件
    #include <fstream>
  2.创建流对象
    ifstream ifs;
  3.打开文件
    ifs.open("文件路径",打开方式);
  4.读数据
  ```cpp
  char buf[]={0};
  while(ifs>>buf)
  {
    cout<<buf<<endl;
  }
  ```    
  5.关闭文件
    ifs.close();
- 二进制读文件
  ifs.read((char*)&p,sizeof(p));
- 文件打开方式
  | 打开方式     | 解释 |
  | ----------- | ----------- |
  |ios::in       | 为读文件而打开文件|
  ios::out|为写文件而打开文件
  ios::ate|初始位置：文件尾
  ios::app|追加方式写文件
  ios::trunc|如果文件存在先删除再创建
  ios::binary|二进制方式