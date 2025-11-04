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

  - **常量指针**（`const int* ptr`）：指向的**内容不可改**，但指针的**指向可改**（可以指向其他变量）。
  - **指针常量**（`int* const ptr`）：指针的**指向不可改**（必须始终指向初始地址），但指向的**内容可改**。

  - 记忆技巧：`const` 离谁近就修饰谁 —— 离 `*` 近修饰 “内容”，离指针名近修饰 “指向”。

- C++ 的规则是：**指针的`const`权限只能 “缩小”，不能 “放大”**。

  你不能把 “只读权限的常量指针”，赋给 “读写权限的普通指针”—— 否则`const`就失去了意义，没法保护变量不被修改。编译器会直接报错阻止这种操作～
  