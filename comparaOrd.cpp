/* comparacion de dos metodos de ordenamientoordenamiento por insercion binaria y quisort										*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <windows.h>
using namespace std;
void InsercionBin(int[], int);
void QuickSort(int[],int);
void Reduce(int[],int,int);
void imprimir(int[],int);
int main(){
	
	SetConsoleOutputCP(CP_UTF8);
	
	 // Definir el tamaño del arreglo
    const int tamaño = 100000; // Puedes cambiar este valor
    int arreglo[tamaño];

    // Definir el rango de los números aleatorios
    int limite_inferior = 0; // Rango mínimo
    int limite_superior = 100000000; // Rango máximo
	
	int limite, tam;
	 cout<<"Ingrese la cantidad de números que desea generar : "; cin>>tam;
	 int array[tam];
	 cout<<"INGRESE EL NÚMERO MÁXIMO :"; cin>>limite;
	srand(time(0)); // Inicializa el generador de números aleatorios
	 //vamos generar los elementos aleatorios de un array
	 for(int i=0; i<tam;i++){
	 	array[i]=rand()%(limite+1);
	 }
	 //vamos a imprimir los elementos de array
	 cout<<"Los elementos  de ARRAY:\n ";
	 for(int i=0; i<tam;++i){
	 	cout<<array[i]<<" ";
	 }
	 
	int op;
	do{
	
	cout<<"\n\n\t-------MENU-------\n\n";
	cout<<"1.- Por inserción BINARIA\n";
	cout<<"2.- Por QUICKSORT\n";
	cout<<"3.- Salir del programa\n\n";
	cout<<"\nIngrese la opción: "; cin>>op;
	
	//copia del array 
	int arrayCopia[tam];
	for(int i=0;i<tam;i++){
		arrayCopia[i]=array[i];
	}
	switch(op){
		case 1:
			InsercionBin(arrayCopia,tam);
			imprimir(arrayCopia,tam);
			break;
		case 2:
			QuickSort(arrayCopia,tam-1);
			imprimir(arrayCopia,tam);
			break;
		case 3:
			cout<<"Saliendo del programa....";
			return 0;
			break;
		default	:
			cout<<"\nERROR\n";
		
	}
}while(op<4);
	
	return 0;
}

void imprimir(int A[],int n){
	for(int i=0;i<n;i++){
		cout<<A[i]<<" ";
	}
}


void InsercionBin(int A[],int n) {
	
	for (int i=1;i<n;i++) {
		int aux=A[i];
		int izq=0;
		int der=i-1;
		while (izq<=der) {
			int m=(izq+der)/2;
			if (aux<A[m]) {
				der=m-1;
			} else {
				izq=m+1;
			}
		}
		int j=i-1;
		while (j>=izq) {
			A[j+1]=A[j];
			j--;
		}
		A[izq]=aux; //insercion
	}

}
//----------------------------------------------------------------------------------
//Metodo quicksort
void QuickSort(int A[],int n) {
	Reduce(A,0,n);
}

void Reduce(int A[],int inicio,int final) {
	int izq=inicio;
	int der=final;
	int pos=izq;
	int cen=1;
	while (cen==1) {
		cen=0;
		//recorrido de derecha a izquierda
		while (A[pos]<=A[der] && pos!=der) {
			der--;
		}
		if (pos!=der) {
			int aux=A[pos];
			A[pos]=A[der];
			A[der]=aux;
			pos=der;
			//recorrido de izquierda a derecha
			while (A[pos]>=A[izq] && pos!=izq) {
				izq++;
			}
			if (pos!=izq) {
				aux=A[pos];
				A[pos]=A[izq];
				A[izq]=aux;
				pos=izq;
				cen=1;
			}
		}
		if (pos-1>inicio) {
			/*llamado recursivo a QuiqSort
			para el subarreglo derecho*/
			Reduce(A,inicio,pos-1);
		}
		if (pos+1<final) {
			/*llamado recursivo a quicksort para el
			subarreglo derecho*/
			Reduce(A,pos+1,final);
		}
	}
}