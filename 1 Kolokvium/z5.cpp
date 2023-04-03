#include <iostream>

using namespace std;

struct mag
{

    int list[100];
    int t;

    void init() { t = -1; }
    bool isFull() { return t >= 99; }
    bool isEmpty();

    void push(int p);
    int pop();
};

bool func(mag m)
{

    mag pom1, pom2 = m;
    pom1.init();

    while (!m.isEmpty())
        pom1.push(m.pop());

    while (!pom1.isEmpty())
        if (pom1.pop() != pom2.pop())
            return false;

    return true;
}

int main()
{
}