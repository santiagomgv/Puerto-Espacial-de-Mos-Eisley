/*

    La Cantina del Puerto Espacial de Mos Eisley vende diferentes y exóticos tragos a hombres, Wookies, Hutts,
    Ewok, Moradores de las arenas, etc, pero nunca a droides. Para mejorar su servicio desea desarrollar una
    aplicación que permita a sus clientes realizar sus pedidos “on line” a través de sus dispositivos móviles.
    Para ello desarrolla un “carrito de la compra”. El carrito podrá contener como máximo 50 bebidas y de
    cada bebida se almacenará su código (número natural), nombre (cadena de caracteres), tipo de cliente
    (Hombre, Wookie, Hutt, Ewok, Morador_Arena), el número de unidades (número natural) y
    el precio en monedas (número natural).

*/

// Incluir E/S y Librerías Standard
#include <iostream>
#include <cstdlib>
#include <string>
#include <array>

using namespace std;
//----------------  Zona de Declaración de Constantes ----------------

const int BEBIDAS_MAX_CARRITO = 50;

// ---------------- Zona de Declaración de Tipos ----------------

enum TCliente{ hombre, wookie, hutt, ewook, morador_arena };

struct TBebida{
    int Codigo_Bebida;
    TCliente cliente;
    string Nombre_Bebida;
    int Numero_Unidades;
    int Precio_Unidades;
};

struct TBebidas_Nodo{

    TBebida bebida;
    bool espacio_vacio;

};

typedef array <TBebidas_Nodo,BEBIDAS_MAX_CARRITO> TCarrito; //------------- Array principal ----------------

// ---------------- Zona de Cabeceras de Procedimientos y Funciones ----------------

char Menu();
char Menu_Insertar_bebida_carrito();
int  MenuAll();
void pausa();

void Inicia_carrito(TCarrito &carrito);
void Borra_carrito(TCarrito &carrito);
void Visualizar_bebidas(const TCarrito &carrito);
void Leer_bebidas(TBebida &bebida);
void Escribir_bebida(const TBebida &bebida);


void Indice_Bebida(const TCarrito &carrito, const int &codigo, int &i, bool &encontrada);
void Insertar_Bebidas(TCarrito &carrito, const TBebida &bebida, bool &correcto);
void Cambiar_numero_unidades(TCarrito &carrito, const int &codigo, TBebida &bebida, bool &encontrada);
void Borrar_Bebida(TCarrito &carrito, const int &codigo);
void Pagar_cuenta(TCarrito &carrito);

bool Carrito_Lleno(const TCarrito &carrito);
bool ConfirmarSalir(TCarrito &carrito);
bool ConfirmarPago(TCarrito &carrito);


TCliente LeeCliente();
TCliente Siguiente (TCliente client);

string Cliente2Cadena(TCliente client);
string Mayusculas(string entrada);

void Cadena2Cliente(string entrada, TCliente &client, bool &ok);

//---------------- Programa Principal ----------------
int main(){

 MenuAll();

}

// ----------------  Implementación de Procedimientos y Funciones ----------------
int MenuAll(){

 bool salir = false;
 bool correcto;
 bool encontrada;
 char opcion;
 int codigo;

 TBebida bebida;
 TCarrito carrito;

 Inicia_carrito(carrito);


  while(!salir){

    opcion = Menu();

        switch(opcion)
            {

                case 'A':
                    system("clear");
                    system("cls");
                    cout << endl << "    INSERTAR BEBIDA" << endl;
                    cout << "============================" << endl;
                    Leer_bebidas(bebida);
                    Insertar_Bebidas(carrito,bebida,correcto);
                        if (correcto){
                                  cout << endl << "Bebida insertada correctamente." << endl;
                            } else if (!correcto) {
                                  cout << endl << "Error al insertar la bebida.";
                        }
                    pausa();
                    break;

                case 'B':
                    system("clear");
                    system("cls");
                    Visualizar_bebidas(carrito);
                    pausa();
                    break;

                case 'C':
                    system("clear");
                    system("cls");
                    cout << "Codigo de la Bebida: "; cin >> codigo;
                    Cambiar_numero_unidades(carrito,codigo,bebida,encontrada);

                    pausa();
                    break;

                case 'D':
                    system("clear");
                    system("cls");
                    Pagar_cuenta(carrito);
                    salir = ConfirmarPago(carrito);
                    break;

                case 'X':
                    system("clear");
                    system("cls");
                    salir = ConfirmarSalir(carrito);

                    break;

                default:
                    system("clear");
                    system("cls");
                    cout << endl <<"\tOpcion Incorrecta ..." << endl;
                    pausa();
                    break;
            }

        }
  return 0;
}

char Menu(){
        char opcion;
        system("clear");
        system("cls");


        // Mostrando el Menú
            cout << "=========================================================" << endl;
            cout << endl << "    Elaborado Por : Santiago Manuel Gonzalez Valdes" << endl;
            cout << "        Fecha: 22/01/2018 Especialidad: GITM" << endl;
            cout << endl << endl; // 2 saltos de líneas
            cout << "\tCantina del Puerto Espacial de Mos Eisley" << endl;

            cout << "=========================================================" << endl;
            cout << "A. Insertar una bebida al carrito." << endl;
            cout << "B. Listar todas las bebidas del carrito." << endl;
            cout << "C. Cambiar numero de unidades de una bebida." << endl;
            cout << "D. Pagar la cuenta." << endl;
            cout << "X. Salir del Programa" << endl;
            cout << "=========================================================" << endl;

            cout << endl << "Introduzca una opcion: ";
            cin >> opcion;
            cin.ignore(); // Ignoramos el ENTER
            opcion = toupper(opcion); // ----------------  Paso opcion a mayúsculas ----------------

         return opcion;
    }

void Inicia_carrito(TCarrito &carrito){
	for(int i=0; i < BEBIDAS_MAX_CARRITO; ++i){

        carrito[i].espacio_vacio = true;

	}
}

void Borra_carrito(TCarrito &carrito){
	for(int i=0; i < BEBIDAS_MAX_CARRITO; ++i){

        carrito[i].espacio_vacio = true;

	}
}

void Visualizar_bebidas(const TCarrito &carrito){

bool bandera;

cout << "    SU CARRITO CONTIENE  " << endl;
cout << "============================" << endl;
    for(int i=0; i < BEBIDAS_MAX_CARRITO; ++i){
        if (!carrito[i].espacio_vacio)
        {
            Escribir_bebida(carrito[i].bebida);
            bandera = true;
        }

	}
	if (bandera == false) cout << "   Su carrito esta vacio." << endl;
}

void Escribir_bebida(const TBebida &bebida){

	cout << endl << "Codigo de la bebida: " << bebida.Codigo_Bebida << endl;
    cout <<"Nombre de la bebida: " << bebida.Nombre_Bebida << endl;
    cout <<"Cliente: " << Cliente2Cadena(bebida.cliente) << endl;
    cout <<"Numero de Unidades: " << bebida.Numero_Unidades << endl;
    cout <<"Precio de la Unidad: " << bebida.Precio_Unidades << endl;

}

void Leer_bebidas(TBebida &bebida){

	cout << endl << "Codigo de la bebida: "; cin >> bebida.Codigo_Bebida; cin.ignore();

    cout <<"Nombre de la bebida: "; getline(cin,bebida.Nombre_Bebida,'\n');

    bebida.cliente = LeeCliente();

    cout <<"Numero de Unidades: "; cin >> bebida.Numero_Unidades; cin.ignore();
        while (bebida.Numero_Unidades < 0) {
            cout <<"Numero de Unidades tiene que ser positivo: ";
            cin >> bebida.Numero_Unidades; cin.ignore();
    }

    cout <<"Precio de la Unidad: "; cin >> bebida.Precio_Unidades; cin.ignore();
            while (bebida.Precio_Unidades < 0) {
            cout <<"Precio de la Unidad tiene que ser positivo: ";
            cin >> bebida.Precio_Unidades; cin.ignore();
    }

}

bool Carrito_Lleno(const TCarrito &carrito){
	bool lleno = true;
	int start = 0;

	while(start < BEBIDAS_MAX_CARRITO && lleno){
		lleno = !carrito[start].espacio_vacio;
            ++start;
	}

	return lleno;
}

void Indice_Bebida(const TCarrito &carrito, const int &codigo, int &i, bool &encontrada){
	encontrada = false;
	i=0;

	while(i < BEBIDAS_MAX_CARRITO && !encontrada)
	{
		if(!carrito[i].espacio_vacio && carrito[i].bebida.Codigo_Bebida == codigo) {
            encontrada = true;
		}
		else ++i;
	}
}

void Insertar_Bebidas(TCarrito &carrito, const TBebida &bebida, bool &correcto){
	int i;
	correcto = !Carrito_Lleno(carrito);

	if (correcto)
	{
		Indice_Bebida(carrito, bebida.Codigo_Bebida, i, correcto);
		correcto=!correcto;

		if (correcto)
		{
			i=0;
			while(!carrito[i].espacio_vacio) ++i;
			carrito[i].espacio_vacio = false;
			carrito[i].bebida = bebida;
		}
	}else{
        cout << endl <<"Carrito lleno.";
	}
}

void Cambiar_numero_unidades(TCarrito &carrito, const int &codigo, TBebida &bebida, bool &encontrada){
    int i;
    int unidades;

	Indice_Bebida(carrito, codigo, i, encontrada);
	cout << endl << "Informacion de la Bebida " << endl;
    cout << "========================= " << endl;

	if (encontrada){

		bebida = carrito[i].bebida;
		Escribir_bebida(bebida);
		cout << endl << "Nuevo numero de unidades: ";
        cin >> unidades;
            if (unidades == 0){

                carrito[i].espacio_vacio = true;

                if (carrito[i].espacio_vacio == true) cout << endl << " Bebida borrada correctamente" << endl;


            }else{

                carrito[i].bebida.Numero_Unidades = unidades;
                cout << "El numero de unidades ha sido actualizado correctamente.";

            }
	} else {
        cout << "Bebida no encontrada." << endl;
    }
}

void Pagar_cuenta( TCarrito &carrito){

    int cuenta = 0;

	for(int i=0; i < BEBIDAS_MAX_CARRITO; ++i){
        if (!carrito[i].espacio_vacio)
        {
            cuenta = cuenta + (carrito[i].bebida.Numero_Unidades * carrito[i].bebida.Precio_Unidades);

        }
	}
	cout << "Precio total de la compra: " << cuenta << " monedas."<<endl;
}


TCliente Siguiente (TCliente client){
	return TCliente(int(client)+1);
}

string Cliente2Cadena(TCliente client){
	string res;

	switch(client)
	{
		case hombre:  res = "Hombre"; break;
		case wookie: res = "Wookie"; break;
		case hutt:  res = "Hutt"; break;
		case ewook: res = "Ewook"; break;
        case morador_arena: res = "Morador Arena";
	}

	return res;
}

void Cadena2Cliente(string entrada, TCliente &client, bool &ok){
	ok = false;
	client = hombre;

	while (client <= morador_arena && !ok)
	{
		if (Mayusculas(entrada)==Mayusculas(Cliente2Cadena(client))){
            ok = true;
		}else{

            client = Siguiente(client);

		}

	}

}

TCliente LeeCliente(){
  string entrada;
  TCliente cliente;
  bool ok;

  do
  {
	  cout << "Cliente: ";
	  getline(cin,entrada);
      Cadena2Cliente(entrada,cliente,ok);
      if (!ok) cout << "No vendemos a Droides. Introduzca uno de los siguientes (Hombre, Wookie, Hutt, Ewok, Morador_Arena)" << endl;

  } while(!ok);

  return cliente;
}

string Mayusculas(string entrada){
	string res = "";
	for(unsigned int i=0;i<entrada.length(); ++i)
	{
		res += toupper(entrada[i]);
	}

	return res;
}

void pausa(){

        cout << endl << "Pulse 2 veces una tecla para continuar...";

        getwchar();
        getwchar();
}


bool ConfirmarSalir(TCarrito &carrito){

        char si_no;

            cout << endl;
            cout << "Esta seguro (S/N)? "; cin >> si_no;
            cin.ignore(); // ---------------- Ignoramos el ENTER ----------------
            si_no = toupper(si_no);

        if (si_no == 'N'){

            system("PAUSE");
            return false;

        }
        else if (si_no == 'S'){
            Borra_carrito(carrito);
            return true;

        }

        return 0;
}

bool ConfirmarPago(TCarrito &carrito){

        char si_no_pagar;

            cout << endl;
            cout << "Desea pagar y vaciar el carrito(S/N)?:  ";
            cin >> si_no_pagar;
            cin.ignore(); // ---------------- Ignoramos el ENTER ----------------
            si_no_pagar = toupper(si_no_pagar);

        if (si_no_pagar == 'N'){

            cout << "Continue comprando." << endl;
            system("PAUSE");
            return false;

        }
        else if (si_no_pagar == 'S'){
            Borra_carrito(carrito);
            return true;

        }

    return 0;

}
