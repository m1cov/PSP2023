#include <iostream>

using namespace std;

inline float Plostina(float dolzina) { return dolzina * dolzina; }
inline float Plostina(float dolzina, float pi) { return (dolzina * dolzina / 4 * pi); }

int main()
{

    const float pi = 3.14159;
    float dolzina;

    cout << "Vnesi ja dolzinata na stranata" << endl;
    cin >> dolzina;

    cout << "Razlikata vo plostinite e " << Plostina(dolzina) - Plostina(dolzina, pi) << endl;

    return 0;
}