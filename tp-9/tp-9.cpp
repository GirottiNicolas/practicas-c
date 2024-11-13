#include <iostream>
#include "Par.h"
#include "Fraccion.h"
using namespace std;


void printFromTo(char c1, char c2){
  for (int i = 0; c1+i <= c2; i++){
    cout << c1+i << ", " ;
  }
  cout << endl;
}

int fc(int n) {
  int x = 1;
  while(n > 0) {
    x = x * n;
    n--;
  }
  return x;
}

int ft(int n, int m){
  int i = 0;
  while(n <= m) {
    i += n;
    n++;
  }
  return i;
}

int ft2 (int n, int m){
  for (int i = n; i < m; n += i) {
    i++;
  }
  return n;
}

int ft3(int n, int m) {
  for (int i = n + 1; i <= m; i++) {  // El bucle comienza en n+1 y va hasta m
    n += i;  // Se acumula el valor de i en n
  }
  return n;  // Devuelve n, que contiene la suma total
}


//Propósito: imprime n veces un string s.
void printN(int n, string s){
  for (; n > 0; n--) {
    cout << s << endl;
  }
}

void printNR(int n, string s){
  if(n > 0){
    cout << s << endl;
    printNR(n-1,s);
  }
}


//Propósito: imprime los números desde n hasta 0, separados por saltos de línea.
void cuentaRegresiva(int n){
  while ( n>=0 ) {
    cout << n << endl;
    n--;
  }
}

void cuentaRegresivaR(int n){
  if (n >= 0){
     cout << n << endl; 
     cuentaRegresivaR(n-1);
  }
}

//Propósito: imprime los números de 0 hasta n, separados por saltos de línea.
void desdeCeroHastaN(int n){
  int m = 0;
  while (m <= n){
    cout << m << endl;
    m++;
  }
}

void desdeCeroHastaNR(int n){
  while (n >= 0){
    cout << n << endl;
    desdeCeroHastaNR(n-1);
  }
}

//Propósito: realiza la multiplicación entre dos números (sin utilizar la operación * de C++).
int mult(int n, int m){
  int i = 0;
  while (m > 0){
    i = i +n;
    m--;
  }
  return (i);  
}

int multR(int n, int m){
  if (m == 1){
    return(n);
  }
  return(n + multR(n, (m-1)) ) ;
}

//Propósito: imprime los primeros n char del string s, separados por un salto de línea.
//Precondición: el string tiene al menos n char.
void primerosN(int n, string s){
  for (int i = 0; i < n; i++) {
    cout << s[i] << endl;
  }
}

void primerosNR(int n, string s){
  while(n >= 0){
    cout << s[n] << endl;
    primerosNR((n-1), s );
  }
}

//Propósito: indica si un char c aparece en el string s.
bool pertenece(char c, string s){
  int i = 0;
  while (not (s[i] == '\0') && (c != s[i]) ) // Mientras que el caracter actual no sea vacio y c sea distinto del caracter actual
  {
    i++; // Avanzar en el string
  }
  return(c == s[i]);
}

string sinElPrimero( string s){
  int i = 0;
  while (s[i] != '\0'){
    s[i] = s[i+1]; // Mientras que el primer caracter del string no es vacio, sobreescribo el caracter actual por el siguiente
    i++;
  }
  return s;
}

bool perteneceR(char c, string s){
  if (s[0]  == '\0'){
    return false;
  }
  return(c == s[0] || perteneceR(c, sinElPrimero(s)) );
}

int unoSi(bool b){
  if (b){
    return 1;
  }
  return 0;  
}

//Propósito: devuelve la cantidad de apariciones de un char c en el string s
int apariciones(char c, string s) {
  int cant = 0;
  for (int i = 0; s[i] != '\0'; i++) {
    cant = cant + unoSi(c == s[i]);
  }
  return cant;
}

int aparicionesR(char c, string s){
  if (s[0] != '\0') {
    return(unoSi(s[0] == c) + aparicionesR(c, sinElPrimero(s)) );
  }
  return 0;  
}



int main() {
  cout << division(consFraccion(7,2)) << endl;
}


