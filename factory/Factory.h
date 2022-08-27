#ifndef _FACTORY_H_
#define _FACTORY_H_

#include <iostream>

/** 基类 **/
class Operation
{
    public:
        // 构造函数
        Operation() {}
        // 析构函数
        ~Operation() {}

        // 获取操作数A
        double getNumberA()
        {
            return _number_a;
        }

        // 设置操作数A
        void setNumberA(double value)
        {
            _number_a = value;
        }

        // 获取操作数B
        double getNumberB()
        {
            return _number_b;
        }

        // 设置操作数B
        void setNumberB(double value)
        {
            _number_b = value;
        }

        // 获取计算结果
        virtual double getResult() = 0;

    public:
        // 操作数A
        double _number_a;
        // 操作数B
        double _number_b;
};

/** 加法类 **/
class OperationAdd : public Operation
{
    public:
        // 构造函数
        OperationAdd() {}
        // 析构函数
        ~OperationAdd() {}
        // 获取结果
        double getResult();
};

/** 减法类 **/
class OperationSub : public Operation
{
    public:
        // 构造函数
        OperationSub() {}
        // 析构函数
        ~OperationSub() {}
        // 获取结果
        double getResult();
};

/** 乘法类 **/
class OperationMul : public Operation
{
    public:
        // 构造函数
        OperationMul() {}
        // 析构函数
        ~OperationMul() {}
        // 获取结果
        double getResult();
};

/** 除法类 **/
class OperationDiv : public Operation
{
    public:
        // 构造函数
        OperationDiv() {}
        // 析构函数
        ~OperationDiv() {}
        // 获取结果
        double getResult();
};

/** 工厂类 **/
class Factory
{
    public:
        // 构造函数
        Factory() {}
        //
        ~Factory() {}
        // 创建操作对象接口
        static Operation *createOperation(char op_code);
};

#endif 
