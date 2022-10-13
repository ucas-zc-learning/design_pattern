#include "CashFactory.h"

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

// 创建工厂对象
CashSuper * CashFactory::createCashAccept(char op_code)
{
    CashSuper *obj = nullptr;
    switch (op_code)
    {
    case 'n':
        obj = new CashNormal();
        break;
    case 'r':
        obj = new CashRebate(0.8);
        break;
    case 't':
        obj = new CashReturn(300.0, 100.0);
        break;
    default:
        break;
    }

    return obj;
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

    CashSuper *obj = CashFactory::createCashAccept(op_code);
    double ret = obj->acceptCash(total);
    std::cout<<"Final total price is : "<<ret<<" , and original total price is : "<<total<<std::endl;

    return 0;
}