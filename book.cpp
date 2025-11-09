// 还没加删除、修改功能，能跑通
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// 基类：所有图书的共同属性
class Book {
protected:
    int id_;         // 图书ID，用来区分不同书
    string name_;    // 图书名字
    double price_;   // 图书价格

public:
    // 初始化信息
    Book(int id, string name, double price)
        : id_(id), name_(name), price_(price) {}

    // 虚析构函数
    virtual ~Book() {}

    // 纯虚函数
    virtual void showInfo() const = 0;

    // 获取ID
    int getId() const { return id_; }
};

// 派生类：普通图书
class NormalBook : public Book {
public:
    // 构造函数：调用基类的构造函数初始化
    NormalBook(int id, string name, double price)
        : Book(id, name, price) {}

    // 重写纯虚函数
    void showInfo() const override {
        cout << "类型：普通图书"
             << " | ID：" << id_
             << " | 书名：" << name_
             << " | 价格：" << price_ << "元" << endl;
    }
};

// 派生类：借阅图书
class BorrowBook : public Book {
private:
    int borrow_days_; // 额外属性：能借几天

public:
    // 构造函数,初始化自己的参
    BorrowBook(int id, string name, double price, int days)
        : Book(id, name, price), borrow_days_(days) {}

    // 重写纯虚函数
    void showInfo() const override {
        cout << "类型：借阅图书"
             << " | ID：" << id_
             << " | 书名：" << name_
             << " | 价格：" << price_ << "元"
             << " | 可借：" << borrow_days_ << "天" << endl;
    }
};

// 图书管理类：负责添加、查询、显示图书
class BookManager {
private:
    // 5个基类指针，最多存5本书
    Book* books_[5];
    int count_; // 记录已经添加了几本书

public:
    // 初始化
    BookManager() : count_(0) {
        for (int i = 0; i < 5; ++i) {
            books_[i] = nullptr;
        }
    }


    ~BookManager() {
        for (int i = 0; i < 5; ++i) {
            if (books_[i] != nullptr) {
                delete books_[i];
                books_[i] = nullptr;
            }
        }
    }

    // 添加图书：
    void addBook(Book* book) {
        // 先检查是不是满了
        if (count_ >= 5) {
            cout << "书架满了，最多放5本书！" << endl;
            delete book; // 满了就释放
            return;
        }
        // 把图书对象的地址存到指针里
        books_[count_] = book;
        count_++;
        cout << "添加成功！" << endl;
    }

    // 显示所有图书：自动区分普通和借阅图书
    void showAllBooks() const {
        cout << "\n===== 我的图书清单 =====" << endl;
        if (count_ == 0) {
            cout << "还没添加图书！" << endl;
            return;
        }

        for (int i = 0; i < count_; ++i) {
            cout << "第" << i+1 << "本：";
            books_[i]->showInfo(); 
        }
        cout << "========================" << endl;
    }

    // 按ID查询图书：输入ID找对应的书
    void findBook(int id) const {
        for (int i = 0; i < count_; ++i) {
            if (books_[i]->getId() == id) {
                cout << "\n找到！" << endl;
                books_[i]->showInfo();
                return;
            }
        }
        cout << "\n没找到ID为" << id << "的书！" << endl;
    }

    // todo：还没写的功能：
    // 1. 删除图书（按ID删除）
    // 2. 修改图书价格
    // 3. 检查ID是否重复
};

// 测试已写功能
int main() {
    BookManager myBooks;

    // 添加几本不同类型的书
    myBooks.addBook(new NormalBook(1, "C++入门", 59.9));
    myBooks.addBook(new BorrowBook(2, "Python编程", 45.8, 30));
    myBooks.addBook(new NormalBook(3, "数据结构", 69.0));
    myBooks.addBook(new BorrowBook(4, "计算机网络", 55.5, 15));
    myBooks.addBook(new NormalBook(5, "操作系统", 72.3));
    myBooks.addBook(new BorrowBook(6, "机器学习", 89.0, 20)); // 超过5本，添加失败

    // 显示所有书
    myBooks.showAllBooks();

    // 测试查询功能
    myBooks.findBook(2);  // 查询存在的借阅图书
    myBooks.findBook(10); // 查询不存在的书

    return 0;
}