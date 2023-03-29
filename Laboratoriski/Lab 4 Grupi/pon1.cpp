#include <iostream>
#define MAX 50

using namespace std;

struct student
{

    string ime;
    int indeks, poeni;

    void pechati()
    {
        cout << ime << " " << indeks << " " << poeni << endl;
    }
};

struct queue
{

    student list[MAX];
    int f, r;

    inline void init() { f = r = -1; }
    inline bool isFull() { return r >= MAX - 1; }
    inline bool isEmpty() { return r - f < 0; }

    void queueOverflow()
    {

        cout << "QUEUEOVERFLOW" << endl;
        exit(-1);
    }

    void queueUnderflow()
    {

        cout << "QUEUEUNDERFLOW" << endl;
        exit(-1);
    }

    void enqueue(student s)
    {

        if (isFull())
            queueOverflow();

        if (f == -1)
            f = 0;

        list[++r] = s;
    }

    student dequeue()
    {

        if (isEmpty())
            queueUnderflow();

        return list[f++];
    }

    student peek()
    {

        if (isEmpty())
            queueUnderflow();

        return list[f];
    }
};

void sort(queue &s, queue &p, queue &n)
{

    while (!s.isEmpty())
    {

        if (s.peek().poeni > 50)
            p.enqueue(s.dequeue());
        else
            n.enqueue(s.dequeue());
    }
}

int main()
{

    queue studenti, polozeni, nepolozeni;
    student pom;
    char c;
    int i = 1;

    studenti.init();
    polozeni.init();
    nepolozeni.init();

    while (1)
    {

        cout << "Vnesete podatoci za studentot " << i << endl;
        cin >> pom.ime >> pom.indeks >> pom.poeni;

        studenti.enqueue(pom);
        cout << endl;

        cout << "Vnesete . za kraj na vnesuvanjeto" << endl;
        cin >> c;

        if (c == '.')
            break;

        i++;
    }

    sort(studenti, polozeni, nepolozeni);

    cout << "Polozeni studenti:" << endl;
    while (!polozeni.isEmpty())
        polozeni.dequeue().pechati();

    cout << "Nepolozeni studenti:" << endl;
    while (!nepolozeni.isEmpty())
        nepolozeni.dequeue().pechati();

    return 0;
}