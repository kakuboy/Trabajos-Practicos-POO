#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

/*1. Realice una función que retorne una matriz de números enteros (aleatorios) de n
filas y m columnas, siendo n y m parámetros.*/
int** matrizNumerosAleatorios(int fila, int col);

/*2. Realice una función que sume todos los elementos de 2 matrices de n filas y m
columnas, siendo n y m parámetros.*/
void sumaDeMatrices(int, int);

/*3. Realice una función que llene una matriz de n filas y m columnas con un número
pasado por parámetro.*/
void llenarMatriz(int);

/*4. Realice una función que rote una matriz de n filas y m columnas siendo n y m
parámetros.*/
void rotarMatriz(int,int);

/*5. Realice una función que llene una matriz de n por m (siendo n y m parámetros) con 2
números, de forma aleatoria. Los dos números puede definirlos usted.*/
void llenarMatriz2Numeros(int,int);

/*6. Realice una función que dada una matriz de n por m (siendo n y m parámetros) llena
de 2 números, valide que la matriz no tenga áreas cerradas. Se considera que una
matriz de dos números tiene un área cerrada cuando a partir de un número
(​ ubicación ij ​ ), no puedo acceder al espacio de números que le corresponde,
avanzando hacia cualquiera de los 4 costados. Es decir, a través de un casillero n​ ij​ ,
que está completo por un ​ número i, ​ debo poder moverme a otro casillero que
también tenga ese mismo número i.*/
bool validarAreas(int mat[100][100],int nfila,int ncolumna);

/*7. Realice una función que genere una matriz de n por m (siendo n y m parámetros)
llena de 2 números y la matriz no debe tener áreas cerradas.*/
void matrizSinAreasCerradas(int,int);


int main()
{
    int fila = 3;
    int columna = 2;

    cout<<"Ejercicio 1."<<endl;
    int** matriz = matrizNumerosAleatorios(fila,columna);

    cout<<"Matriz Aleatoria: "<<endl;
    for (int i=0;i<fila;i++) {
        for (int j=0;j<columna;j++) {
            cout<<matriz[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"-------------------------------------------------------"<<endl;
    cout<<"Ejercicio 2."<<endl;
    cout<<"Suma de matrices: "<<endl;
    sumaDeMatrices(fila,columna);
    cout<<"-------------------------------------------------------"<<endl;
    cout<<"Ejercicio 3."<<endl;
    cout<<"Llenar matriz."<<endl;
    llenarMatriz(10);
    cout<<"-------------------------------------------------------"<<endl;
    cout<<"Ejercicio 4."<<endl;
    rotarMatriz(fila,columna);
    cout<<"-------------------------------------------------------"<<endl;
    cout<<"Ejercicio 5."<<endl;
    cout<<"Llenar matriz con 2 numeros:"<<endl;
    llenarMatriz2Numeros(fila,columna);

    cout<<"-------------------------------------------------------"<<endl;
    cout<<"Ejercicio 6."<<endl;
    int matA[100][100];
    bool resultado = true;

    for (int i=0;i<fila;i++) {
        for (int j=0;j<columna;j++) {
            matA[i][j] = rand()% 2;
            cout<<matA[i][j]<<" ";
        }
        cout<<"\n";
    }

    resultado = validarAreas(matA,fila,columna);

    if(resultado == true){
        cout<<"Matriz no tiene areas cerradas."<<endl;
    }
    else {
        cout<<"Matriz tiene areas cerradas."<<endl;
    }

    cout<<"-------------------------------------------------------"<<endl;
    cout<<"Ejercicio 7."<<endl;
    matrizSinAreasCerradas(fila,columna);



    return 0;
}

int** matrizNumerosAleatorios(int fila, int col){
    srand(time(nullptr));
    int** aux = nullptr;
    aux = new int*[fila];

    for (int i=0;i<fila;i++) {
        aux[i] = new int[col];
        for (int j=0;j<col;j++) {
            aux[i][j] = 1 + rand()% 10;
        }
    }

    return aux;
}


void sumaDeMatrices(int nfilas, int mcolumnas){
    int aux;
    int m[100][100];
    int p[100][100];
    int t[100][100];
    for (int i=0;i<nfilas;i++) {
        for (int j=0;j<mcolumnas;j++) {
            aux = 1 + rand()%25;
            m[i][j] = aux;
        }
    }

    for (int i=0;i<nfilas;i++) {
        for (int j=0;j<mcolumnas;j++) {
            aux = 1 + rand()%25;
            p[i][j] = aux;
        }
    }

    for (int i=0;i<nfilas;i++) {
        for (int j=0;j<mcolumnas;j++) {
            t[i][j] = m[i][j] + p[i][j];
            cout<<t[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void llenarMatriz(int p){
    int m[100][100];
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            m[i][j] = p;
            cout<<m[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void rotarMatriz(int nfila, int ncolumna){
    int mat[50][50];
    int mat2[50][50];
    int t=0;

    cout<<"Matriz Original:"<<endl;
     for(int i=0;i<nfila;i++){
         for(int j=0;j<ncolumna;j++){
             mat[i][j] = t;
             t++;
             mat2[j][i] = mat[i][j];
             cout<<mat[i][j]<<" ";
         }
         cout<<"\n";
     }

     cout<<endl;

     cout<<"Matriz Rotada:"<<endl;

     for(int i=0;i<ncolumna;i++){
         for(int j=0;j<nfila;j++){
              cout<<mat2[i][j]<<" ";
         }
         cout<<"\n";
     }
}

void llenarMatriz2Numeros(int nfila,int ncolumna){
    int mat[100][100];
    int aux = rand()% 100;
    int aux2 = rand()% 100;
    int x;

    for (int i=0;i<nfila;i++) {
        for (int j=0;j<ncolumna;j++) {
            x=rand()%2;
            if(x==1)
            mat[i][j] = aux;
            else mat[i][j] = aux2;
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }
}

bool validarAreas(int mat[100][100], int nfila, int ncolumna){
    bool resultado = true;

    for(int i=0;i<nfila;i++){
        for(int j=0;j<ncolumna;j++){
            resultado = resultado && (mat[i][j] == mat[i][j-1] || mat[i][j] == mat[i][j+1] || mat[i][j] == mat[i-1][j] || mat[i][j] == mat[i+1][j]);
        }
    }

    if(resultado == false){
        return false;
    }
    else{
        return true;
    }

}

void matrizSinAreasCerradas(int nfila,int ncolumna){
    int mat[100][100];
    bool resultado = true;

    for (int i=0;i<nfila;i++) {
        for (int j=0;j<ncolumna;j++) {
            mat[i][j] = rand()% 2;
        }
    }

    resultado = resultado && validarAreas(mat,nfila,ncolumna);

    if(resultado == true){
        cout<<"Esta matriz no tiene areas cerradas."<<endl;
        for (int i=0;i<nfila;i++) {
            for (int j=0;j<ncolumna;j++) {
                cout<<mat[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    else {
        cout<<"La matriz cuenta con areas cerradas."<<endl;
        exit(1);
    }
}







