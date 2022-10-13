#ifndef __CASH_STRATEGY_H__
#define __CASH_STRATEGY_H__

#include <iostream>
#include <vector>


// 基类
class CashSuper
{
public:
    CashSuper() {}
    ~CashSuper() {}

    virtual double acceptCash(double money) = 0;
};

// 未采用任何策略的类
class CashNormal : public CashSuper
{
public:
    CashNormal() {}
    ~CashNormal() {}

    double acceptCash(double money);
};

// 支持打折计算的类
class CashRebate : public CashSuper
{
private:
    double _M_rebate;

public:
    CashRebate() {}
    CashRebate(double rebate) : _M_rebate(rebate)
    {}
    ~CashRebate() {}

    double acceptCash(double money);
};

// 支持满减计算的类
class CashReturn : public CashSuper
{
private:
    double _M_condition;
    double _M_return;

public:
    CashReturn() {}
    CashReturn(double condition, double ret) : _M_condition(condition), _M_return(ret)
    {}
    ~CashReturn() {}

    double acceptCash(double money);
};

class CashContext
{
private:
    /* data */
    CashSuper *_M_cs;
public:
    CashContext(CashSuper *obj);
    CashContext(char op_code);
    ~CashContext();

    double GetResult(double money);
};

#endif