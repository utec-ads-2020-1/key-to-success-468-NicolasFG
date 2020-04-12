#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int lectura()
{
    int Entrada;
    cin >> Entrada;
    return Entrada;
}

class Key{

public:
    char caracter;
    int encrypt;

    Key(char caracter) : caracter(caracter), encrypt(1) {}

    bool operator < (const Key & other) const {
        return encrypt < other.encrypt;
    }
};

void maquina1(string Entrada, vector<Key> & Contenedor)
{
    int posicion = 0;
    sort(Entrada.begin(), Entrada.end());
    Contenedor.clear();
    Contenedor.emplace_back(Entrada[0]);

    for (auto it = Entrada.begin() +1 ; it != Entrada.end(); it++){
        if (*it != Contenedor[posicion].caracter){
            Contenedor.emplace_back(*it);
            posicion++;
        }
        else{
            Contenedor[posicion].encrypt++;
        }
    }
    sort(Contenedor.begin(), Contenedor.end());
}

void maquina2(map<char,char> T_O, string s2, vector<Key> vec1, vector<Key> vec2  )
{
    for (int i = 0; i < vec1.size(); i++)
    {
        T_O[vec2[i].caracter] = vec1[i].caracter;
    }

    for (char & it2 : s2)
    {
        it2 = T_O[it2];
    }

    cout << s2 << '\n';
}


int main()
{
    string Entrada_sin_encriptar, Entrada_encriptada, Separador;
    auto Casos = lectura();
    map<char, char> Traductor_Original;
    vector<Key> sin_encriptar, encriptado;

    while (Casos--)
    {
        //cout << "\n";
        cout << Separador;
        //cout << Separador;
        Separador = "\n";
        //cout << "\n";
        //cout << "\n";

        cin >> Entrada_sin_encriptar;
        cin >> Entrada_encriptada;

        maquina1(Entrada_sin_encriptar, sin_encriptar);
        maquina1(Entrada_encriptada, encriptado);
        maquina2(Traductor_Original, Entrada_encriptada, sin_encriptar, encriptado);

    }
}