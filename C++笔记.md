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
 } 
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
    - 如果写了有参构造函数，编译器不再提供默认构造，依然提供拷贝构造
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

    // 2. 复制构造函数（深复制，原来的性能瓶颈）
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
- 不允许复制的类
  将复制构造函数和赋值运算符声明为私有的确保对象是不可复制的。
- 只能有一个实例的单例类
- 禁止在栈中实例化
  将析构函数声明为私有的
- 使用构造函数进行类型转换
  - 未归纳 -
- this指针 
  在类中，关键字 this 包含当前对象的地址
- 将sizeof()用于类
  sizeof(MyString)
- 声明友元
  ```cpp
  friend void DisplayAge(const Human& person);
  ```
  函数 DisplayAge( )是全局函数，还是 Human 类的友元，因此能够访问Human 类的私有数据成员。
- 共用体
  - 未归纳 -
- 对类和结构使用聚合初始化
  - 未归纳 -

#### 第十章：实现继承
#### 第十一章：多态
#### 第十二章：运算符与运算符重载
#### 第十三章：类型转换运算符
#### 第十四章：宏和模板简介








##  第3部分 学习标准模板库（STL）
>将帮助您使用 STL string 类和容器编写高效而实用的 C++代码。您将了解到，使用 std::string 可安全而轻松地拼接字符串，您不再需要使用 C 风格的字符串 char*。您可使用 STL 动态数组和链表，而无需自己编写这样的类。
#### 第十五章：标准库简介
#### 第十六章：STL string类
#### 第十七章：STL 动态数组类
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