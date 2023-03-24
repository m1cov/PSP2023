/*Да се напише функција која како аргументи прима две две структури магацин. Во функцијата треба
елементите од првиот магацинот да се прераспределат согласно со вредноста на иста позиција
запишана во вториот магацин. На пример ако во вториот магацин на позиција 2 има елемент со
вредност 3, во излезниот магацин на позиција 2 ќе биде третиот елемент во првиот магацин.

Притоа, за решавање на задачата може да ја користите само променливи од тип структура магацин,
односно функциите кои структурата ги има (init, push, peek, pop, isEmpty, isFull). За да ја решите
задачата потребно е пополнувањето да го правите во помошен магацин. Имено, треба да имате и
помошна функција која на влез ќе го добива првиот магацин по вредност и позицијата која се вади
од вториот магацин. Таа функција на излез треба да го врати елементот на позицијата која е
добиена на влез (внатре во функцијата влезниот магацин треба да се празни, но бидејќи е предаден
по вредност истиот нема да биде променет надвор од помошната фунција). Според треб да се
празни вториот магацин и за секој изнесен елемент да се повикува помошната функција, а
добиената вредност од помошната функција да се става во нов помошен магацин. По празнењето
на вториот магацин во помошниот магацин елементите би биле во обратен редослед, па со
празнење на помошниот магацин и постепено полнење на првиот магацин (кој пред полнењето
треба да се реиницијализира) во него би се добиле елементите во саканиот редослед. Кодовите за
магацинот и за функциите на магацинот исто така треба да ги напишете како дел од задачата.

Магацин 1 на влез: 7 1 2 1 5 1 5  1 3 5 2 4 6 7
Магацин 1 на излез: 7 2 5 1 1 1 5


*/
// TODO: Resi
#include <iostream>

using namespace std;

const int stackSize = 100;

struct stack
{

    int list[stackSize];
    int top;

    inline void init() { top = -1; }
    inline bool isFull() { return top >= stackSize - 1; }
    inline bool isEmpty() { return top < 0; }

    void push(int e)
    {

        if (isFull())
        {
            cout << "STACKOVERFLOW";
            exit(-1);
        }

        list[++top] = e;
    }

    int peek()
    {

        if (isEmpty())
        {

            exit(-1);
        }

        return list[top];
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "STACKUNDERFLOW";
            exit(-1);
        }

        return list[top--];
    }
};

int getElem(stack m, int poz)
{
    int elem;
    int i = 0;

    while (!m.isEmpty() && i < poz)
    {
        elem = m.pop();
        i++;
    }

    return elem;
}

void func(stack &m1, stack m2)
{

    stack temp1, temp2, pom;

    temp1.init();
    temp2.init();
    pom.init();

    while (!m1.isEmpty())
    {
        temp1.push(m1.pop());
        temp2.push(m2.pop());
    }

    while (!temp2.isEmpty())
    {

        pom.push(getElem(temp1, temp2.pop()));
    }

    while (!pom.isEmpty())
    {
        m1.push(pom.pop());
    }
}

int main()
{
    stack s1, s2;
    int count, element;

    s1.init();
    s2.init();

    cout << "Vnesete kolku elementi da ima magacinot:";
    cin >> count;
    cout << "Vnesete gi elementite vo magacinot 1" << endl;

    for (int i = 0; i < count; i++)
    {
        cin >> element;
        s1.push(element);
    }

    cout << "Vnesete gi elementite vo magacinot 2" << endl;

    for (int i = 0; i < count; i++)
    {
        cin >> element;
        s2.push(element);
    }

    func(s1, s2);

    while (!s1.isEmpty())
        cout << s1.pop() << endl;
}