#include<iostream>
using namespace std;

int main(){
    char respuesta = 'S';
    while (respuesta == 'S' || respuesta == 's'){
    int opcion = 0;
    while(opcion <= 0 || opcion > 2){
        cout << "Menu" <<endl
        << "1)Ejercicio 1" <<endl
        << "2)Salir" <<endl
        << "Ingrese su opcion: ";
        cin >> opcion;
    }
    switch(opcion){
        case 1:
            {
                int numColum = 0;
                while (numColum <= 0){
                    cout << "Ingrese el numero de columnas que utilizara:";
                    cin >> numColum;
                }
                char* temp = new char[numColum];
                char caracterTemp = ' ';
                for (int i = 0; i < numColum; i++){
                    cout << "Ingrese el caracter:";
                    cin >> caracterTemp;
                    temp[i] = caracterTemp;
                }
                int numFila = 0;
                while (numFila <= 0){
                    cout << "Ingrese el numero de filas:";
                    cin >> numFila;
                }
                char** matrix = NULL;
                break;
            }
    }
    cout << "¿Desea volver a hacerlo[s/n]?: ";
    cin >>  respuesta;
    }
    return 0;
}

char** crearMatriz(int size){
}

