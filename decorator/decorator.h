#ifndef __DECORATOR_H__
#define __DECORATOR_H__

#include <iostream>
#include <string>

class Person
{
private:
    std::string _M_name;
public:
    Person() {}
    Person(std::string name) : _M_name(name) {}
    ~Person() {}

    virtual void show()
    {
        std::cout<<"装扮的"<<_M_name<<std::endl;
    }
};

// 服饰类
class Finery : public Person
{
protected:
    Person *_M_component;

public:
    Finery() {}
    ~Finery() {}

    void Decorate(Person *component);
    void show();
};

// 具体的服饰类
class TShirt: public Finery
{
public:
    TShirt() {}
    ~TShirt() {}

    void show();
};

class BigTrouser: public Finery
{
public:
    BigTrouser() {}
    ~BigTrouser() {}

    void show();
};

class Sneaker: public Finery
{
public:
    Sneaker() {}
    ~Sneaker() {}

    void show();
};

class Suit: public Finery
{
public:
    Suit() {}
    ~Suit() {}

    void show();
};

class Tie: public Finery
{
public:
    Tie() {}
    ~Tie() {}

    void show();
};

class LeatherShoes: public Finery
{
public:
    LeatherShoes() {}
    ~LeatherShoes() {}

    void show();
};

#endif