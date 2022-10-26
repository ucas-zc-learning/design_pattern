#include "decorator.h"

void Finery::Decorate(Person *component)
{
    this->_M_component = component;
}

void Finery::show()
{
    if (_M_component != nullptr) {
        _M_component->show();
    }
}

void TShirt::show()
{
    std::cout<<"T恤 ";
    Finery::show();
}

void BigTrouser::show()
{
    std::cout<<"垮裤 ";
    Finery::show();
}

void Sneaker::show()
{
    std::cout<<"破球鞋 ";
    Finery::show();
}

void Suit::show()
{
    std::cout<<"西装 ";
    Finery::show();
}

void Tie::show()
{
    std::cout<<"领带 ";
    Finery::show();
}

void LeatherShoes::show()
{
    std::cout<<"皮鞋 ";
    Finery::show();
}

int main(int argc, char **argv)
{
    Person p("小明");

    std::cout<<"第一种装扮："<<std::endl;
    Sneaker s;
    BigTrouser bt;
    TShirt ts;

    // 装饰的过程
    s.Decorate(&p);
    bt.Decorate(&s);
    ts.Decorate(&bt);
    ts.show();

    std::cout<<"第二种装扮："<<std::endl;
    LeatherShoes ls;
    Tie t;
    Suit su;

    // 装饰的过程
    ls.Decorate(&p);
    t.Decorate(&ls);
    su.Decorate(&t);
    su.show();

    return 0;
}