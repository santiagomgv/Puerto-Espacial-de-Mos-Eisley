//https://pastebin.com/Rx83eMaR

#include <iostream>
#include <array>
#include <cstdlib>
using namespace std;

const unsigned int MAX_ALUMNOS = 10;

typedef array <double, MAX_ALUMNOS> TNotas;
typedef unsigned int TNatural;


void LeerNotas(TNotas &notas);

void EscribirNotas(const TNotas &notas);

double MediaAritmetica(const TNotas &notas);

TNatural MayorMedia(const TNotas &notas);
TNatural MenoresMedia (const TNotas &notas);



int main (){


    TNotas notas;

    cout << "Introduce Notas" << endl;

    LeerNotas(notas);

    cout << "Las notas son: " << endl;

    EscribirNotas(notas);

    cout << endl << "La nota media es: " << MediaAritmetica(notas) << endl;
    cout << endl << "Hay " << MayorMedia(notas) << " notas mayores de la media" << endl;
    cout << endl << "Hay " << MenoresMedia(notas) << " notas menores que la media" << endl;



return 0;

}

void LeerNotas(TNotas &notas){

    for (unsigned int i=0; i < MAX_ALUMNOS; ++i){
        cout << "Nota["<< i <<"]=" << endl;
        cin >> notas[i];
        cin.ignore();
    }
}


void EscribirNotas(const TNotas &notas){

    for (unsigned int i=0; i < MAX_ALUMNOS; ++i){
        cout << "\tNota["<< i <<"]=" << notas[i] << endl;
    }

}

double MediaAritmetica(const TNotas &notas){

    double Media = 0;

    for (unsigned int i=0; i < MAX_ALUMNOS; ++i){
       Media = Media + notas[i];
    }

    return Media/MAX_ALUMNOS;
}

TNatural MayorMedia(const TNotas &notas){

    TNatural mayores = 0;
    double media = MediaAritmetica(notas);

    for (unsigned int i=0; i < MAX_ALUMNOS; ++i){

    if (notas[i] > media){
       ++mayores;
    }

    }
   return mayores;
}
TNatural MenoresMedia (const TNotas &notas){

    TNatural menores = 0;
    double media = MediaAritmetica(notas);

    for (unsigned int i=0; i < MAX_ALUMNOS; ++i){

    if (notas[i] < media){
       ++menores;
    }


    }
   return menores;
}
