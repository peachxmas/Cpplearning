#include <iostream>

using namespace std;

//int main() {
//    const double pi = 22.0 / 7;
//    int r = 0;
//    cout << "请输入圆的半径：";
//    cin >> r;
//    cout << endl;
//    cout << "圆的面积为：" << pi * r * r << "\n"
//         << "圆的周长为：" << pi * 2 * r << endl;
//    return 0;
//}

// int main() {
    //>>提取运算符<<插入运算符
//    char ch = 'a';
//    std::cout << ch << std::endl;
//    std::cout << sizeof(char) << std::endl;
//    std::cout << "Hello, World!" << std::endl;
//    cout << "\n" << endl;
//    cout << "\\" << endl;
//    cout << "\t" << endl;//输出更整齐

//    string str1 = "hello world";//字符串
//    cout << str1 << endl;

//    bool flag = true;//bool数据类型本质上1真0假
//    cout << flag << endl;


//    float a = 0;
//    cout << "请给浮点型变量a赋值：" << endl;
//    cin >> a;//数据输入
//    cout << "浮点型变量a=" << a << endl;
//    char ch = 'a';
//    cout << "请给浮点型变量a赋值：" << endl;
//    cin >> ch;//数据输入
//    cout << "浮点型变量a=" << ch << endl;
//    string str = "abc";
//    cout << "请给字符串str赋值：" << endl;
//    cin >> str;//数据输入
//    cout << "字符串str=" << str << endl;
/*第三章运算符*/
//    int a1 = 10;
//    int b1 = 3;
//    cout << a1 / b1 << endl;//两个整数相除还是整数
//只有整型变量可以做取模运算
//前置递增先让变量+1然后进行表达式运算
//后置递增先进行表达式运算然后让变量+1
//三目运算符
//    int a = 10;
//    int b = 10;
//    int c = 0;
//    c = (a > b ? a : b);//a>b则为c=a否则为b

//系统生成随机数
//    rand() % 100;//0~99的随机数
//    srand(time(0));
//    int num = rand() % 100 + 1;//0+1~99+1的随机数
//    cout << num << endl;


////水仙花数
//    int num = 100;
//
//    do {
//        int a = 0;
//        int b = 0;
//        int c = 0;
//        a = num % 10;//个位
//        b = num / 10 % 10;//十位
//        c = num / 100;//百位
//        if (a * a * a + b * b * b + c * c * c == num) {
//            cout << num << endl;
//
//        }
//        num++;
//    } while (num < 1000);

//乘法口诀
//    int j = 1;
//    int i = 1;
//    for (i = 1; i <= 9; i++) {
//        for (j = 1; j <= i; j++) {
//            cout << j << "*" << i << "=" << i * j << "\t";
//        }
//        cout << endl;
//    }
//break退出循环和continue不执行后面的语句继续循环
//goto
//    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    cout << arr << endl;//数组首地址
//    cout << (int) arr[0] << endl;//数组首地址
//冒泡排序
//    int arr[9] = {4, 2, 8, 0, 5, 7, 1, 3, 9};
//    for (int j = 9; j > 1; j--) {
//        for (int i = 0; i < j; i++) {
//            int temp = 0;
//            if (arr[i] > arr[i + 1]) {
//                temp = arr[i];
//                arr[i] = arr[i + 1];
//                arr[i + 1] = temp;
//            }
//        }
//    }
//    for (int a = 0; a < 9; a++) {
//        cout << arr[a] << " ";
//    }
//    cout << endl;
//外层行数内层列数


//指针
//可以通过指针来保存一个地址
//指针定义的语法：数据类型 *指针变量名
//    int *p;
//    int a = 10;
//    //让指针记录a的地址
//    p = &a;
//    cout << &a << endl;
//    cout << p << endl;
////使用指针
////可以通过解引用的方式来找到指针指向的内存
////指针前加*代表解引用，找到指针指向的内存
//    cout << *p << endl;
////32位操作系统指针占4个字节空间大小
//    cout << sizeof(int *) << endl;
//空指针：指针变量指向内存中编号为0的空间。用途：初始化（0~255是系统占用的不可访问）
//    int *p = NULL;
//野指针
//    int *p = (int *) 0x1100;
//访问会出错
//const修饰指针
//常量指针const int * p=&a;
//指向可以改，指针指向的值不可以改
//p=&b;
//const修饰常量
//指针常量int * const p=&a;
// 指向不可以改，指针指向的值可以改
//*p=100;
//const即修饰指针又修饰常量
//指针的指向和指针指向的值都不可以更改const int * const p=&a;
//地址传递可以修饰形参
//结构体struct
//自定义数据类型
//    struct student s1 = {"张三", 18, 100};//通过.来访问结构体变量中的属性
//结构体数组
//    struct student stu[3]{
//            {"Z", 1, 2},
//            {"Z", 1, 2},
//            {"Z", 1, 2}
//    };
//结构体指针
//    student *p = &s1;//通过指针指向结构体变量
//    cout << p->name << p->age << p->score << endl;//结构体指针可以通过->操作符来访问结构体成员
// 嵌套结构体
//结构体做函数参数

//     return 0;
// }

////声明一个表示国际象棋棋盘的数组；该数组的类型应为枚举，该枚举定义了可能出现在棋盘方
////格中的棋子。
////提示：这个枚举包含枚举量 Rook、Bishop 等，从而限制了数组元素的取值范围。另外，别忘
////了棋盘方格也可能为空！
//int main() {
//    enum Square {
//        Empty = 0,
//        Pawn,
//        Rook,
//        Knight,
//        Bishop,
//        King,
//        Queen
//    };
//    Square chessBoard[8][8];
//    // Initialize the squares containing rooks
//    chessBoard[0][0] = chessBoard[0][7] = Rook;
//    chessBoard[7][0] = chessBoard[7][7] = Rook;
//    return 0;
//}
//int main() {
//    bool a1 = 0;
//    bool a2 = 0;
//    cout << "输入第一个bool值";
//    cin >> a1;
//    cout << "输入第二个bool值";
//    cin >> a2;
//    cout << endl;
//
//    cout << (a1 & a2) << " " << (a1 | a2) << (a1 ^ a2) << endl;

//斐波那契数列
//int main() {
//    const int numToCalulate = 5;
//    int num1 = 0;
//    int num2 = 1;
//    char wantmore = '\0';
//    cout << num1 << " " << num2 << " ";
//    do {
//        for (int couter = 0; couter < numToCalulate; couter++) {
//            cout << num1 + num2 << " ";
//            int temp = num2;
//            num2 = num1 + num2;
//            num1 = temp;
//
//        }
//        cout << endl << "是否继续";
//        cin >> wantmore;
//    } while (wantmore == 'y');
//    return 0;
//}
//．编写两个重载的函数，它们分别使用下述公式计算球和圆柱体的体积：
//Volume of sphere = (4 * Pi * radius * radius * radius) / 3
//Volume of a cylinder = Pi * radius * radius * height
// const double pi = 3.14;

// float volume(int radius);

// float volume(int radius, int height);

// int main() {
//     cout << "请输入半径：";
//     int r = 0;
//     cin >> r;
//     cout << endl;
//     cout << volume(r) << " " << endl;
//     cout << "请输入高度：";
//     int h = 0;
//     cin >> h;
//     cout << volume(r, h) << " " << endl;
//     return 0;
// }

// float volume(int radius) {
//     float volumeOfSphere = (4 * pi * radius * radius * radius) / 3;
//     return volumeOfSphere;
// }

// float volume(int radius, int height) {
//     float volumeOfCylinder = pi * radius * radius * height;
//     return volumeOfCylinder;
// }
//c++引用
//语法：数据类型 &别名=原名
// 引用传递形参会修饰实参
// int main(){
// int a=10;
// int &b=a;
// b=20; 
// return 0;

// }

//访问权限
//公共权限 public       类内类外都可以访问
//保护权限 protected    类外不可以访问 子类可以访问父类保护内容
//私有权限 private      类外不可以访问 子类不可以访问父类私有内容
