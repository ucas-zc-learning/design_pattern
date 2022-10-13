#include "CashStrategy.h"

double CashNormal::acceptCash(double money)
{
    return money;
}

double CashRebate::acceptCash(double money)
{
    return money * _M_rebate;
}

double CashReturn::acceptCash(double money)
{
    return money >= _M_condition ? 
        money - ((int)money / (int)_M_condition) * _M_return : money;
}

// 通过构造函数，传入具体的收费策略
CashContext::CashContext(CashSuper *obj)
{
    _M_cs = obj;
}

CashContext::CashContext(char op_code)
{
    switch (op_code)
    {
    case 'n':
        _M_cs = new CashNormal();
        break;
    case 'r':
        _M_cs = new CashRebate(0.8);
        break;
    case 't':
        _M_cs = new CashReturn(300, 100);
        break;
    default:
        _M_cs = nullptr;
        break;
    }
}

CashContext::~CashContext()
{
    if (_M_cs != nullptr) {
        delete _M_cs;
        _M_cs = nullptr;
    }
}

// 根据收费策略的不同，获得计算结果
double CashContext::GetResult(double money)
{
    return _M_cs != nullptr ? _M_cs->acceptCash(money) : 0;
}


int main(int argc, char** argv)
{
    std::vector<int> vec_num = {1, 2, 5, 4, 10};
    std::vector<double> vec_price = {10.0, 20.0, 15.0, 25.0, 30.0};

    double total = 0.0;
    for (int i = 0; i < vec_num.size(); ++i) {
        total += vec_num[i] * vec_price[i];
    }

    char op_code;
    std::cout<<"please select strategy ('n' means normal, 'r' means rebate, 't' means return):";
    std::cin>>op_code;

    // 不结合工厂模式
    CashContext *cs = nullptr;
    switch (op_code)
    {
    case 'n':
        cs = new CashContext(new CashNormal());
        break;
    case 'r':
        cs = new CashContext(new CashRebate(0.8));
        break;
    case 't':
        cs = new CashContext(new CashReturn(300, 100));
        break;
    default:
        break;
    }

    double ret = cs->GetResult(total);
    std::cout<<"Final total price is : "<<ret<<" , and original total price is : "<<total<<std::endl;

    if (cs != nullptr) {
        delete cs;
        cs = nullptr;
    }

    // 结合工厂模式
    cs = new CashContext(op_code);
    ret = cs->GetResult(total);
    std::cout<<"Final total price is : "<<ret<<" , and original total price is : "<<total<<std::endl;

    if (cs != nullptr) {
        delete cs;
        cs = nullptr;
    }
    
    return 0;
}