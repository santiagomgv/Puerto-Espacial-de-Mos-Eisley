#include <iostream>
#include <array>
#include <cstdlib>

using namespace std;

const  int TAM = 10;

typedef array <double, TAM> TArray;

void LeerArray(TArray &a);
void EscribirArray(TArray &a);

int Maximo (const TArray &a);
int Minimo (const TArray &a);
int Media(const TArray &a);


int main (){
    TArray a;

    cout << "Introduce: " << endl;
    LeerArray(a);

    cout << "Los numeros son: " << endl;
    EscribirArray(a);


    cout << endl << "El mayor es: " << Maximo(a) << endl;
    cout << endl << "El menor es: " << Minimo(a) << endl;
    cout << endl << "La media es: " << Media(a) << endl;


return 0;

}

void LeerArray(TArray &a){

    for (unsigned int i=0; i < TAM; ++i){
        cout << "Numero["<< i <<"]=" << endl;
        cin >> a[i];
        cin.ignore();
    }
}


void EscribirArray(TArray &a){

    for (unsigned int i=0; i < TAM; ++i){
        cout << "\tNumeros["<< i <<"]=" << a[i] << endl;
    }

}

int Maximo (const TArray &a){
int Max = 0;

    Max  = a[0];

    for (unsigned int i=0; i < TAM; ++i){
       if (a[i]> Max  ){
        Max  = a[i];
       }

    }

    return Max;
}

int Minimo (const TArray &a){
int Min;

    Min = a[0];

    for (unsigned int i=0; i < TAM; ++i){
       if (a[i]< Min ){
        Min = a[i];
       }

    }

    return Min;

return Min = 0;
}
int Media(const TArray &a){

    double Media = 0;

    for (unsigned int i=0; i < TAM; ++i){
       Media = Media + a[i];
    }

    return Media/TAM;

}
