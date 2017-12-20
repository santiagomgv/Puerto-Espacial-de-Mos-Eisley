#include <iostream>
#include <cstdlib>
#include <array>

using namespace std;

const int MAXPER = 100;
struct TPersona
{
	string nombre;
	string telefono;
};

typedef array <TPersona,MAXPER> TLista;
struct TAgenda
{
	int numPersonas;
	TLista lista;
};

char Menu();
bool Confirmar();

void LeerPersona(TPersona &p);
void EscribirPersona(const TPersona &p);
void CrearAgenda(TAgenda &a);
void DestruirAgenda(TAgenda &a);
bool AgendaLlena(const TAgenda &a);
void ListarAgenda(const TAgenda &a);
void IndicePersona(const TAgenda &a, const string &tlfno, int &i, bool &encontrado);
void InsertarPersona(TAgenda &a, const TPersona &p, bool &ok);
void BuscarPersona(const TAgenda &a, const string &tlfno, TPersona &p, bool &encontrado);
void ListarTelefonosPersona(const TAgenda &a, const string &nombre);
void BorrarPersona(TAgenda &a, const string &tlfno);



// Programa Principal
int main(){
	TAgenda a;
	TPersona p;
	bool ok,salir;
	string s;

	CrearAgenda(a);
	salir = false;

	while(!salir)
	{
		switch(Menu())
		{
			case 'A': LeerPersona(p);
					  InsertarPersona(a,p,ok);
					  if (ok) cout << "Persona Insertada Correctamente." << endl;
                        else	  cout << "Error al Insertar Persona." << endl;
					  break;

			case 'B': cout << "Nombre: ";
					  getline(cin,s);
					  ListarTelefonosPersona(a,s);
					  break;

			case 'C': cout << "Telefono: ";
					  getline(cin,s);
					  BuscarPersona(a,s,p,ok);
					  if (ok) EscribirPersona(p);
                        else    cout << "Persona No encontrada." << endl;
					  break;

			case 'D': cout << "Telefono: ";
					  getline(cin,s);
					  BorrarPersona(a,s);
					  if (ok) EscribirPersona(p);
                        else    cout << "Persona No encontrada." << endl;
					  break;

			case 'E': ListarAgenda(a);
					  break;

			case 'X': salir = Confirmar();
					  break;
		}
	}

	DestruirAgenda(a);

  	return 0;
}
char Menu(){
	char opcion;

    cout << endl <<"   MENU" << endl;
    cout <<"   ====" << endl;
    cout << endl;
    cout <<"  A. Introducir Contacto." << endl;
    cout <<"  B. Consultar telefono(s)." << endl;
	cout <<"  C. Consultar Nombre(s)." << endl;
    cout <<"  D. Borrar Contacto" << endl;
    cout <<"  E. Listado Completo de la Agenda." << endl;
    cout <<"  X. Salir del Programa" << endl;
    cout << endl << "Introduzca su opcion: ";

    cin>> opcion;
    opcion = toupper(opcion);
    cin.ignore(); // Ignoramos el ENTER

    return opcion;
}
bool Confirmar(){
  char car;

  cout << "¿Esta seguro de salir (S/N)?";
  cin >> car;
  car = toupper(car);

  return (car=='S');
}
void LeerPersona(TPersona &p){
	cout << "Nombre: ";
	getline(cin,p.nombre);
	cout << "Telefono: ";
	getline(cin,p.telefono);
}

void EscribirPersona(const TPersona &p)
{
	cout << endl << "\tNombre: " << p.nombre << endl;
	cout << "\tTelefono: " << p.telefono << endl;
}

void CrearAgenda(TAgenda &a)
{
    a.numPersonas = 0;
}

void DestruirAgenda(TAgenda &a)
{
    a.numPersonas = 0;
}

bool AgendaLlena(const TAgenda &a)
{
    return a.numPersonas >= MAXPER;
}

void ListarAgenda(const TAgenda &a)
{
    for (int i = 0; i < a.numPersonas; i++){
        EscribirPersona(a.lista[i]);
    }
}

void IndicePersona(const TAgenda &a, const string &tlfno, int &i, bool &encontrado){

    i = 0;
    encontrado = false;

    while ( i < a.numPersonas && !encontrado){

        if (a.lista[i].telefono == tlfno){
            encontrado = true;
        }else{
            i++;
        }
    }

}
void InsertarPersona(TAgenda &a, const TPersona &p, bool &ok){

    int i;
    ok = !AgendaLlena(a);

    if (ok){
        {
            IndicePersona(a, p.telefono, i, ok);

            if(ok){
                a.lista[a.numPersonas] = p;
                ++a.numPersonas;
            }
        }
    }
}

void BuscarPersona(const TAgenda &a, const string &tlfno, TPersona &p, bool &encontrado){
    int i;
    IndicePersona(a, tlfno, i, encontrado);
    if(encontrado){
        p = a.lista[i];
    }
}
void ListarTelefonosPersona(const TAgenda &a, const string &nombre){

    for (int i = 0; i < a.numPersonas;i++){

        if (a.lista[i].nombre == nombre){
           EscribirPersona(a.lista[i]);
        }
    }

}
void BorrarPersona(TAgenda &a, const string &tlfno){

    int i;
    bool encontrado;

    IndicePersona(a, tlfno, i,  encontrado);
    if(encontrado){
        a.lista[i] = a.lista[a.numPersonas-1];
        --a.numPersonas;
    }

}

