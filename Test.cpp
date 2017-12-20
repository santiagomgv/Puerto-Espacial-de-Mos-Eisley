/*
* C++ - Agenda con uso de struct
*
* Copyright 2014 Martin Cruz Otiniano 
*
* Site: martincruz.me
*/

#include <iostream>
#include <stdlib.h>

#define MAXCAD 50
#define MAX_V 100     // numero de vendedores
#define MAX_PV 100    // maximo de productos vendidos

using namespace std;
 
struct unProducto {
    char name_prod[MAXCAD];  // nombre del producto
    int  cantidad;
    int  precio  ;
    int  subtotal;
};
 
struct variosProductos {
    int numProd ;             // numero de productos por vendedor
    unProducto vp[MAX_PV];      //varios productos cada uno en una posicion del  vector
    int precioTotal ;
};
 
struct Vendedor {
    char nombre[MAXCAD]   ;
    char apellido[MAXCAD] ;
    char direccion[MAXCAD];
    int  DNI     ;
    variosProductos P  ;
};
 
struct Vendedor lista[MAX_V]; // creamos un array de tvendedores
struct Vendedor aux;
 
 
void registrar_productos(int nv, int np)
{
    // nv -> numero de vendedor
 
    for(int i=0; i<np; i++)
    {
        cout<<"\n\tProducto "<< i+1 <<endl;
        cin.ignore();
        cout<<"\t\tNombre   : " ;
        cin.getline( lista[nv].P.vp[i].name_prod, MAXCAD );
 
        //cin.ignore();
        cout<<"\t\tCantidad : ";
        cin>> lista[nv].P.vp[i].cantidad ;
 
        //cin.ignore();
        cout<<"\t\tPrecio   : ";
        cin>> lista[nv].P.vp[i].precio ;
 
        lista[nv].P.vp[i].subtotal = lista[nv].P.vp[i].cantidad * lista[nv].P.vp[i].precio ;  // subtotal = precio*cantidad
 
        if(lista[nv].P.vp[i].subtotal==0)
            cout<<"Subtotal 0";
 
        lista[nv].P.precioTotal = lista[nv].P.precioTotal +  lista[nv].P.vp[i].subtotal ;
 
    }
 
}
void registrar_vendedores(int n)
{
    int np ;  //  numero de productos por cada vendedor
    for(int i=0; i<n; i++)
    {
        cout<<"\nVENDEDOR "<< i+1 << "\n";
 
        cin.ignore();  cout << "   Nombres   : ";  cin.getline( lista[i].nombre, MAXCAD   );
        cin.ignore();  cout << "   Apellidos : ";  cin.getline( lista[i].apellido, MAXCAD );
        cin.ignore();  cout << "   Direccion : ";  cin.getline( lista[i].direccion, MAXCAD);
        cin.ignore();  cout << "   D N I     : ";  cin>> lista[i].DNI ;
 
        cout<<"\n   > Numero de productos: ";      cin>> lista[i].P.numProd ;
 
        registrar_productos( i ,lista[i].P.numProd );
    }
}
 
void datosVendedor(int x, int num)
{
    if(num>0)
    {
        cout<<endl<<endl;
        cout << "\t" << lista[x].nombre <<' '<< lista[x].apellido << endl;
        cout << "   DNI      :  "<< lista[x].DNI       << endl;
        cout << "   Direccion:  "<< lista[x].direccion << endl;
    }
    else
        cout<<"\n\tRegistro vacio..!";
 
}
 
void prodVendedor(int x, int num)
{
    if(num>0)
    {
        cout<<endl<<endl;
        cout << "   Productos de " << lista[x].nombre <<' '<< lista[x].apellido << endl<<endl;
 
        for(int i=0; i<lista[x].P.numProd; i++)
        {
            cout<<"\n   Producto "<< i+1                      <<endl;
            cout<<"\tNombre  : " << lista[x].P.vp[i].name_prod  <<endl;
            cout<<"\tCantidad: " << lista[x].P.vp[i].cantidad <<endl;
            cout<<"\tPrecio  : " << lista[x].P.vp[i].precio     <<endl;
            cout<<"\tSubtotal: " << lista[x].P.vp[i].subtotal <<endl ;
        }
        cout<<endl;
        cout<<"  ---------------------------"<<endl;
        cout<<"  PRECIO TOTAL:   "<< lista[x].P.precioTotal;
    }
    else
        cout<<"\n\tRegistro vacio..!";
 
}
 
void mostrar_productos(int nv)
{
    cout<<"   Productos: \n\n";
    for(int i=0; i<lista[nv].P.numProd; i++)
    {
        cout<<"\t- " << lista[nv].P.vp[i].name_prod <<endl ;
    }
}
 
void mostrar_vendedores(int num)
{
    if( num>0)
    {
        cout<<"\n\nMostrando lista de Vendedores\n";
        for(int i=0; i<num; i++)
        {
            cout<<endl<<endl;
            cout<< i+1<<". "<< lista[i].nombre <<' '<< lista[i].apellido << endl;
            cout << "   DNI      :  "<< lista[i].DNI       << endl;
            cout << "   Direccion:  "<< lista[i].direccion << endl;
 
            mostrar_productos( i );
            cout<<endl;
 
        }
    }
    else
        cout<<"\n\tRegistro vacio..!";
}
 
void eliminar_vendedor( int x, int &num)
{
    if(num>0)
    {
        for(int i=x; i<num-1; i++)
            lista[i] = lista[i+1];
 
        num--;
    }
    else
        cout<<"\n\tRegistro vacio..!";
 
}
 
void buscar_vendedor( int num)
{
    int band = 0;
 
    if(num>0)
    {
        for(int i=0; i<num; i++)
        {
            if(lista[i].DNI==aux.DNI)
            {
                cout<<"\n\n La direccion de "<<lista[i].nombre<<" "
                    <<lista[i].apellido<<" es : "
                    <<lista[i].direccion <<endl ;
                band = 1 ;
                break;
            }
        }
    }
    else
        cout<<"\n\tRegistro vacio..!";
 
    if(band==0)
        cout<<"\n\n\tEl vendedor no fue encontrado..! :S"<<endl;
 
}
 
void menu1()
{
    cout<<"\n\t\tREGISTRO DE VENDEDORES\n\n";
    cout<<" 1. Registrar vendedores                       "<<endl;
    cout<<" 2. Mostrar registro de vendedores y productos "<<endl;
    cout<<" 3. Mostrar datos de un vendedor               "<<endl;
    cout<<" 4. Mostrar productos vendidos de un vendedor  "<<endl;
    cout<<" 5. Eliminar vendedor del registro             "<<endl;
    cout<<" 6. Buscar direccion de vendedor por DNI       "<<endl;
    cout<<" 7. Salir                                      "<<endl;
 
    cout<<"\n Ingrese opcion : ";
}
 
/*                      funcion principal
------------------------------------------------------------------------------*/
 
int main()
{
    int num=0;  // numero de vendores
    int op;   // opcion del menu
    int num_vendedor ;
   
    system("color 0b");
 
    do
    {
        menu1();  cin>> op;
 
        switch(op)
        {
            case 1:
                cout<<"\n Numero de vendedores: ";
                cin>> num;
                registrar_vendedores(num);  cout<<endl;
                break;
 
            case 2:
                mostrar_vendedores(num);
                break;
 
            case 3:
                cout<<"\n Ingrese numero de vendedor: ";
                cin>> num_vendedor ;
                datosVendedor( num_vendedor-1, num);
                break;
 
            case 4:
                cout<<"\n Ingrese numero de vendedor: ";
                cin>> num_vendedor ;
                prodVendedor( num_vendedor-1, num);
                break;
 
            case 5:
                cout<<"\n Ingrese numero de vendedor: ";
                cin>> num_vendedor ;
                eliminar_vendedor( num_vendedor-1, num);
                cout<<"\n\n\t\tVendedor eliminado ..!"<<endl;
                break;
 
            case 6:
                cout<<"\n Ingrese numero de DNI: ";
                cin>> aux.DNI;
                buscar_vendedor(num);
                break;
 
        }
       
        cout<<endl<<endl;
        system("pause");  system("cls");
 
    } while(op != 7);
 
 
    return 0;
}
