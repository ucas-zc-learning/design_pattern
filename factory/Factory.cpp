#include "Factory.h"

// 加法运算
double OperationAdd::getResult()
{
    return _number_a + _number_b;
}

// 减法运算
double OperationSub::getResult()
{
    return _number_a - _number_b;
}

// 乘法运算
double OperationMul::getResult()
{
    return _number_a * _number_b;
}

// 除法运算
double OperationDiv::getResult()
{
    return _number_a / _number_b;
}

// 工厂-创建操作对象
Operation *Factory::createOperation(char op_code)
{
    Operation *op = nullptr;
    switch (op_code) {
    case '+':
        op = new OperationAdd();
        break;
    case '-':
        op = new OperationSub();
        break;
    case '*':
        op = new OperationMul();
        break;
    case '/':
        op = new OperationDiv();
        break;
    default:
        std::cout<<"operation error!"<<std::endl;
        exit(1);
    }

    return op;
}

int main(int argc, char **argv)
{
    char op_code;
    double number_a, number_b;

    std::cout<<"Please input number a: ";
    std::cin>>number_a;
    std::cout<<"Please input operation: ";
    std::cin>>op_code;
    std::cout<<"Please input number b: ";
    std::cin>>number_b;

    Operation *op = Factory::createOperation(op_code);
    if (op == nullptr) {
        return -1;
    }
    op->setNumberA(number_a);
    op->setNumberB(number_b);

    std::cout<<"The result is:"<<op->getResult()<<std::endl;
}
