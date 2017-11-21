![picture alt](https://vignette.wikia.nocookie.net/clubpenguin/images/4/40/Puerto.png/revision/latest?cb=20130727165528&path-prefix=es "SantiagoMGVl")
 - - - -
Puerto-Espacial-de-Mos-Eisley
===============================
La Cantina del Puerto Espacial de Mos Eisley vende diferentes y exóticos tragos a hombres, Wookies, Hutts, Ewok, Moradores de las arenas, etc, pero nunca a droides. Para mejorar su servicio desea desarrollar una aplicación que permita a sus clientes realizar sus pedidos “on line” a través de sus dispositivos móviles. Para ello desarrolla un “carrito de la compra”. El carrito podrá contener como máximo 50 bebidas y de cada bebida se almacenará su código (número natural), nombre (cadena de caracteres), tipo de cliente (Hombre, Wookie, Hutt, Ewok, Morador_Arena), el número de unidades (número natural) y el precio en monedas (número natural).

```
Elaborado por: <Nombre> <Apellidos> Curso 1ºB
Fecha: DD/MM/AAAA Especialidad: <GIST/GISE/GISI/GITM>
Cantina del Puerto Espacial de Mos Eisley
=========================================
A. Insertar una bebida al carrito.
B. Listar todas las bebidas del carrito.
C. Cambiar número de unidades de una bebida.
D. Pagar la cuenta.
X. Salir del Programa.
Introduzca Opción: 
```

Descripción de las Opciones:
-----------------------------
#### A. Insertar una bebida al carrito.

Se deberá leer toda la información de la bebida siguiendo el siguiente formato:
```
Codigo de la bebida : 534
Nombre de la bebida : Accarrgm
Cliente : Wookie
Numero de Unidades : 4
Precio de la Unidad : 3
```
El tipo de cliente se leerá como una cadena de caracteres que habrá que convertir en un enumerado y
se reintentará la lectura hasta que la conversión sea correcta. Posteriormente, se insertará en la
estructura. Si ya hay 50 bebidas insertadas, se mostrará el correspondiente mensaje de error.

#### B. Listar todos los productos del carrito.
Se deberá mostrar la información de todos los productos almacenados en el carrito de la compra
siguiendo el siguiente formato:
```
SU CARRITO CONTIENE
====================
Codigo de la Bebida : 101
Nombre de la Bebida : Polvo de Cometa
Cliente de la Bebida : Ewok
Numero de Unidades : 3
Precio de la Unidad : 1

Codigo de la Bebida : 232
Nombre de la Bebida : Amarga de Tatooine
Cliente de la Bebida : Morador_Arena
Numero de Unidades : 2
Precio de la Unidad : 2

Codigo de la Bebida : 534
Nombre de la Bebida : Accarrgm
Cliente de la Bebida :
Numero de Unidades : 4
Precio de la Unidad : 3

Codigo de la Bebida : 334
Nombre de la Bebida : Flamígero
Cliente de la Bebida : Hombre
Numero de Unidades : 5
Precio de la Unidad : 5
```

#### C. Cambiar número de unidades de una Cerveza.
Se deberá preguntar el código de la cerveza. Si lo encontramos en el carrito mostraremos toda la
información y preguntaremos el nuevo número de unidades. Ejemplo:
```
Codigo de la Bebida : 334             |  Codigo de la Bebida : 1234
Informacion de la Bebida              |  Informacion de la Bebida
=========================             |  =========================
Codigo de la Bebida : 334             | Bebida no encontrada.
Nombre de la Bebida : Flamígero       |
Cliente de la Bebida : Hombre         |
Numero de Unidades : 5                |
Precio de la Unidad : 5               |
Nuevo numero de unidades : 8          |
El numero de unidades ha sido         |
actualizado.
```
Si el nuevo número de unidades introducido por el usuario es 0, la cerveza se borrará del carrito de la
compra.
Como ayuda para hacer esta opción podéis primero implementar estos dos algoritmos auxiliares:
  * Un algoritmo para **buscar** una bebida en el carrito de la compra dado su código.
  * Un algoritmo para **borrar** una bebida del carrito de la compra dado su código.

#### D. Pagar la cuenta.
Se deberá mostrar el precio total de la compra, calculando el precio total de cada cerveza en base al
número de unidades compradas y al precio de cada unidad.
```
Precio total de la compra : 59 monedas
```
Posteriormente se le preguntará al cliente si desea pagar y borrar el carrito de la compra o desea
continuar comprando. Ejemplo:
```
Desea pagar y vaciar el carrito   |   Desea pagar y vaciar el carrito: N
(S/N)?: s                         |   Continúe comprando.
Gracias por su Compra.            |


