/*----------------------------------------------------------------
|	Autor:                                                        |
|	Fecha:                            Versión: 1.0	              |
|-----------------------------------------------------------------|
|	Descripción del Programa:                                     |
|  								                                  |
| ----------------------------------------------------------------*/

// Incluir E/S y Librerías Standard
#include <iostream>
#include <cstdlib>
using namespace std;

const char ENTER = '\n';

unsigned int Valor(char car);
bool Confirmar();

int main(){

bool salir = false;

do{

    char car;
	unsigned int arabigo = 0;
	unsigned int act,sig;
	system("CLS");
	cout << "Introduzca un numero Romano: ";

	act=0;
	car = cin.get();
        while (car!=ENTER)
        {
            sig = Valor(car);
            if (act >= sig) 	arabigo+=act;
            else			arabigo-=act;

            car = cin.get();
            act = sig;
        }

	arabigo+=act;
	cout << "En decimal es " << arabigo << endl;

    salir = Confirmar();

}while(!salir);


	return 0;
}

bool Confirmar(){
    char si_no;
    cout << " \nQuiere salir del programa? (S o N): ";
    cin >> si_no;
    cin.ignore();
    si_no = toupper(si_no);

    if (si_no == 'S'){
        return true;
    }else{
        return false;
    }


}

unsigned int Valor(char car)
{
	unsigned int resultado = 0;

	switch(toupper(car))
	{
		case 'I': resultado = 1;
		          break;
		case 'V': resultado = 5;
		          break;
		case 'X': resultado = 10;
		          break;
		case 'L': resultado = 50;
		          break;
		case 'C': resultado = 100;
		          break;
		case 'D': resultado = 500;
		          break;
		case 'M': resultado = 1000;
		          break;
	}

	return resultado;
}
