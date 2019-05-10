#include<iostream>
using namespace std;

char** crearMatriz(int,int,char*);
void printMatrix(char** matrix,int fila, int colum);
void freeMatrix(char**& matrix,int fila);

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
                cout << "Ingrese la primera fila: ";
                cin >> temp;
                int numFila = 0;
                while (numFila <= 0){
                    cout << "Ingrese el numero de filas:";
                    cin >> numFila;
                }
                char** matrix = NULL;
                matrix = crearMatriz(numFila,numColum,temp);
                printMatrix(matrix,numFila,numColum);
                freeMatrix(matrix,numFila);
                delete[] temp;
                break;
            }
    }
    cout << "¿Desea volver a hacerlo[s/n]?: ";
    cin >>  respuesta;
    }
    return 0;
}

char** crearMatriz(int fila, int column, char* array){
    char** matrix = NULL;
    matrix = new char*[size];
    for (int i = 0; i < fila; i++){
        if (i == 0)
            matrix[i] = array;
        matrix[i] = new char[column];
    }
    for (int i = 1; i < fila; i++){
        for (int j = 0; j < column; j++){
            cout << matrix[i][j] = ' ';
        }
    }
    return matrix;
}

void printMatrix(char** matrix,int fila, int colum){
    for (int i = 0; i < fila; i++){
        for  (int j = 0; j < colum; j++){
            cout << matrix[i][j] << " ";
        }
        cout<<endl;
    }
}

void freeMatrix(char**& matrix,int fila){
    for (int i = 0; i < fila; i++){
        if (matrix[i] != NULL){
            delete[] matrix[i];
            matrix[i] = NULL;
        }
    }
    if (matrix != NULL){
        delete[] matrix;
        matrix = NULL;
    }
}


