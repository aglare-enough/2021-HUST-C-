#include "stack.h"
STACK::STACK(int m) :QUEUE(m), q(m) {}

STACK::STACK(const STACK& s) : QUEUE((QUEUE&)s), q(s.q) {}

STACK::STACK(STACK&& s) noexcept :QUEUE((QUEUE&&)s), q((QUEUE&&)s.q) {}

int STACK::size() const noexcept
{
    return QUEUE::size() + q.size();
}

STACK::operator int() const noexcept
{
    return QUEUE::operator int() + q.operator int();
}

STACK& STACK::operator<<(int e)
{
    if (QUEUE::operator int() < QUEUE::size() - 1)
    {
        QUEUE::operator<<(e);
        return *this;
    }
    else if (q.operator int() < q.size() - 1)
    {
        q << e;
        return *this;
    }
    else
    {
        throw("STACK is full!");
    }
}

STACK& STACK::operator>>(int& e)
{     
    if (q.operator int()){
        int sizebase = q.operator int(), tmp = 0;
        for (int i = 0; i < sizebase - 1; i++){
            q >> tmp;
            q << tmp;
        }
        q >> e;
        return *this;
    }else if (QUEUE::operator int()){
        int sizebase = QUEUE::operator int(), tmp = 0;
        for (int i = 0; i < sizebase - 1; i++){
            QUEUE::operator>>(tmp);
            QUEUE::operator<<(tmp);
        }
        QUEUE::operator>>(e);
        return *this;
    }else{
        throw("STACK is empty!");
    }
}

STACK& STACK::operator=(const STACK& s)
{
    QUEUE::operator=((QUEUE&)s);
    q.operator=((QUEUE&)s.q);
    return *this;
}

STACK& STACK::operator=(STACK&& s) noexcept
{
    QUEUE::operator=((QUEUE&&)s);
    q.operator=((QUEUE&&)s.q);
    return *this;
}

char* STACK::print(char* b) const noexcept
{

    char t[100];
    b = QUEUE::print(b);
    if (q.size()) strcat(b, ",");
    q.print(t);
    strcat(b,t);
    return b;
}

STACK::~STACK() noexcept
{
    QUEUE::~QUEUE();
    q.~QUEUE();
}