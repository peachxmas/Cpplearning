#include <iostream>
using namespace std;
class Calculator
{
private:
    int num_;
public:
    Calculator(int init_num=0):num_(init_num){}
    int getResult() const{return num_;}
    //+
    Calculator operator+(const Calculator& other)const
    {
        return Calculator(this->num_+other.num_);
    }
    // -
    Calculator operator-(const Calculator& other) const {
        return Calculator(this->num_ - other.num_);
    }

    // *
    Calculator operator*(const Calculator& other) const {
        return Calculator(this->num_ * other.num_);
    }

    // /（处理除数为0）
    Calculator operator/(const Calculator& other) const {
        if (other.num_ == 0) {
            cout << "错误：除数不能为0，结果保持原数" << endl;
            return Calculator(this->num_); 
        }
        return Calculator(this->num_ / other.num_);
    }

    // >
    bool operator>(const Calculator& other) const {
        return this->num_ > other.num_;
    }

    // <
    bool operator<(const Calculator& other) const {
        return this->num_ < other.num_;
    }

    // ==
    bool operator==(const Calculator& other) const {
        return this->num_ == other.num_;
    }
};
int main()
{
    // 初始化
    Calculator calc1(20), calc2(5);
    cout << "初始值：calc1=" << calc1.getResult() << ", calc2=" << calc2.getResult() << endl;

    // 测试加减乘除
    Calculator add_res = calc1 + calc2;
    cout << "calc1 + calc2 = " << add_res.getResult() << endl;

    Calculator sub_res = calc1 - calc2;
    cout << "calc1 - calc2 = " << sub_res.getResult() << endl;

    Calculator mul_res = calc1 * calc2;
    cout << "calc1 * calc2 = " << mul_res.getResult() << endl;

    Calculator div_res = calc1 / calc2;
    cout << "calc1 / calc2 = " << div_res.getResult() << endl;

    // 测试除数为0
    Calculator zero_calc(0);
    Calculator err_res = calc1 / zero_calc;
    cout << "calc1 / 0 → 结果：" << err_res.getResult() << endl;

    // 测试比较运算符
    cout << "calc1 > calc2? " << (calc1 > calc2 ? "是" : "否") << endl;
    cout << "calc1 == calc2? " << (calc1 == calc2 ? "是" : "否") << endl;

    return 0;

}