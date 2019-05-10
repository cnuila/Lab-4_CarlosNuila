#include<iostream>
#include<string>
using namespace std;

char** crearMatriz(int,int,string);
void printMatrix(char** matrix,int fila, int colum);
void freeMatrix(char**& matrix,int fila);
void Ejercicio1(char**,int,int);

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
                string primeraFila = "";
                while (primeraFila.size() < numColum){
                    cout << "Ingrese la primera fila: ";
                    primeraFila = "";
                    cin >> primeraFila;
                }
                int numFila = 0;
                while (numFila <= 0){
                    cout << "Ingrese el numero de filas:";
                    cin >> numFila;
                }
                char** matrix = NULL;
                matrix = crearMatriz(numFila,numColum,primeraFila);
                Ejercicio1(matrix, numFila,numColum);
                freeMatrix(matrix,numFila);
                break;
            }
    }
    cout << "¿Desea volver a hacerlo[s/n]?: ";
    cin >>  respuesta;
    }
    return 0;
}

void Ejercicio1(char** matrix, int fila, int colum){
    int contSeguro = 0;
   for (int i = 1; i < fila; i++){
        for (int j = 0; j < colum; j++){
            matrix[i][j] = '.';
            if (j != 0 || j != colum - 1){
                if (matrix[i-1][j] == '^' && matrix[i-1][j-1] == '^' && matrix[i-1][j+1] == '.'){
                    matrix[i][j] = '^';
                }
                if (matrix[i-1][j] == '^' && matrix[i-1][j-1] == '.' && matrix[i-1][j+1] == '^'){
                    matrix[i][j] = '^';
                }
                if (matrix[i-1][j] == '.' && matrix[i-1][j-1] == '^' && matrix[i-1][j+1] == '.'){
                    matrix[i][j] = '^';
                }
                if (matrix[i -1][j] == '.' && matrix[i-1][j-1] == '.' && matrix[i-1][j+1] == '^'){
                    matrix[i][j] = '^';
                } 
            }
            if (j == 0 || j == colum - 1){
                if (j == 0){
                    if (matrix[i-1][j] == '^' && matrix[i-1][j+1] == '^'){
                        matrix[i][j] = '^';
                    }
                    if (matrix[i-1][j] == '.' && matrix[i-1][j+1] == '^'){
                        matrix[i][j] = '^';
                    }
                }
                if (j == colum - 1){
                    if (matrix[i -1][j] == '^' && matrix[i-1][j-1] == '^'){
                        matrix[i][j] = '^';
                    }
                    if (matrix[i -1][j] == '.' && matrix[i-1][j-1] == '^'){
                        matrix[i][j] = '^';
                    }
                }
            }
        }
   }
   printMatrix(matrix,fila,colum);
   for (int i = 0; i < fila; i++){
       for (int j = 0; j < colum; j++){
            if (matrix[i][j] == '.'){
                contSeguro++;
            }
       }
   }
   cout << "El numero total de azulejos seguro es " << contSeguro << endl; 

}


char** crearMatriz(int fila, int column, string primeraFila){
    char** matrix = NULL;
    matrix = new char*[fila];
    for (int i = 0; i < fila; i++){
        matrix[i] = new char[column];
    }
    for (int i = 0; i < fila; i++){
        if (i == 0){
            for(int j = 0;j < primeraFila.size();j++){
                matrix[i][j] = primeraFila.at(j);
            }
        } else {
            for (int j = 0; j < column; j++){
                matrix[i][j] = ' ';
            }
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


