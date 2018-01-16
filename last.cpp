/*
La Cantina del Puerto Espacial de Mos Eisley vende diferentes y exóticos tragos a hombres, Wookies, Hutts,
Ewok, Moradores de las arenas, etc, pero nunca a droides. Para mejorar su servicio desea desarrollar una
aplicación que permita a sus clientes realizar sus pedidos “on line” a través de sus dispositivos móviles.
Para ello desarrolla un “carrito de la compra”. El carrito podrá contener como máximo 50 bebidas y de
cada bebida se almacenará su código (número natural), nombre (cadena de caracteres), tipo de cliente
(Hombre, Wookie, Hutt, Ewok, Morador_Arena), el número de unidades (número natural) y
el precio en monedas (número natural).
*/


#include <iostream> //----------------  E/S estándard ----------------
#include <cstdlib> // ---------------- Librería estándard ----------------
#include <array>
#include <string>
using namespace std;
//----------------  Zona de Declaración de Constantes ----------------

const int BEBIDAS_MAX_CARRITO = 50;

// ---------------- Zona de Declaración de Tipos ----------------

enum { Hombre, Wookie, Hutt, Ewook, Morador_Arena };

struct TCliente{

    int Codigo_Bebida;
    int Numero_Unidades;
    int Precio_Unidades;
    string Nombre_Bebida;
    string Nombre_Cliente;

};

struct TBebidas{

    TCliente cliente;
    bool espacio_libre;

};

typedef array <TBebidas,BEBIDAS_MAX_CARRITO> TCarrito;

// ---------------- Zona de Cabeceras de Procedimientos y Funciones ----------------

char Menu();
char Menu_Insertar_bebida_carrito();

int MenuAll();

void inicia(TCarrito &carrito);


void Insertar_bebida_carrito(TCliente &cliente);

void Menu_Insertar_bebida_carrito();
 
void Listar_todos_productos_carrito();
void Cambiar_numero__unidades();
void Pagar_cuenta();
void pausa();

bool ConfirmarSalir();
bool ConfirmarPago();

//---------------- Programa Principal ----------------
int main()
{

 MenuAll();

}

// ----------------  Implementación de Procedimientos y Funciones ----------------
int MenuAll(){
//----------------  Zona de Declaración de Variables del Programa principal----------------
 bool salir = false;
 char opcion;
 TCarrito carrito;
 TCliente cliente;
 
 inicia(carrito);

  while(!salir){

    opcion = Menu();

        switch(opcion)
            {

                case 'A':
                    Menu_Insertar_bebida_carrito();
                    Insertar_bebida_carrito(cliente);
                    break;

                case 'B':
                    system("cls");
                    cout << "\t B. Listar todas las bebidas del carrito." << endl;
                    pausa();
                    break;

                case 'C':
                    system("cls");
                    cout << "\t C. Cambiar numero de unidades de una bebida." << endl;
                    pausa();
                    break;

                case 'D':
                    salir = ConfirmarPago();
                    break;

                case 'X':
                    system("cls");
                    salir = ConfirmarSalir();

                    break;

                default:
                    system("cls");
                    cout << "\tOpcion Incorrecta ..." << endl;
                    pausa();
                    break;

            }

        }
    return 0;
}
char Menu()
    {
        char opcion;
        system("cls");
        // Mostrando el Menú
            cout << "=========================================================" << endl;
            cout << endl << "    Elaborado Por : Santiago Manuel Gonzalez Valdes" << endl;
            cout << "        Fecha: 01/01/2018 Especialidad: GITM" << endl;
            cout << endl << endl; // 2 saltos de líneas
            cout << "\tCantina del Puerto Espacial de Mos Eisley" << endl;

            cout << "=========================================================" << endl;
            cout << "A. Insertar una bebida al carrito." << endl;
            cout << "B. Listar todas las bebidas del carrito." << endl;
            cout << "C. Cambiar numero de unidades de una bebida." << endl;
            cout << "D. Pagar la cuenta." << endl;
            cout << "X. Salir del Programa" << endl;
            cout << "=========================================================" << endl;

            cout << endl << "Introduzca una opcion:  ";
            cin >> opcion;
            cin.ignore(); // Ignoramos el ENTER
            opcion = toupper(opcion); // ----------------  Paso opcion a mayúsculas ----------------

         return opcion;
    }

void Insertar_bebida_carrito(TCliente &cliente)
    {
            system("cls");
            cout << endl <<  " Insertando una bebida al carrito." << endl;
            cout << " ==================================" << endl;
            cout << " Codigo de la bebida: " << endl;
            cin >> 
            cout << " Nombre de la bebida: " << endl;
            cout << " Cliente: " << endl;;
            cout << " Numero de Unidades: " << endl;
            cout << " Precio de la Unidad: " << endl << endl;
            pausa();

    }


void Insertar_bebida_carrito(TCliente &cliente){

	cout <<"Introduzca Matricula coche:";
	getline(cin,coche.matricula);
    cout <<"Introduzca nombre conductor:";
	getline(cin,coche.nombre);
}    
    
}
void Listar_todos_productos_carrito(){
}
void Cambiar_numero__unidades(){
}
void Pagar_cuenta(){
}

void inicia(TCarrito &carrito){
	for(int i=0; i < BEBIDAS_MAX_CARRITO; ++i) carrito[i].espacio_libre = true;
}

void pausa(){
        cout << "Pulse 2 veces una tecla para continuar...";
        getwchar();
        getwchar();
    }
bool ConfirmarSalir(){
        char si_no;

            cout << endl;
            cout << "Esta seguro (S/N)? "; cin >> si_no;
            cin.ignore(); // ---------------- Ignoramos el ENTER ----------------
            si_no = toupper(si_no);

        return (si_no=='S');
    }
bool ConfirmarPago(){
        char si_no_pagar;

            cout << endl;
            cout << "Desea pagar y vaciar el carrito(S/N)?:  ";
            cin >> si_no_pagar;
            cin.ignore(); // ---------------- Ignoramos el ENTER ----------------
            si_no_pagar = toupper(si_no_pagar);

        if (si_no_pagar == 'N' && si_no_pagar == 'N'){

            cout << "Continue comprando." << endl;
            system("PAUSE");
            return (si_no_pagar == 'NO');

        }
        else if (si_no_pagar == 'SI' && si_no_pagar == 'S'){
            return (si_no_pagar == 'SI');

        }

    }
