#include<bits/stdc++.h>

using namespace std;

#define N 25

int a[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int pasos = 0;

int buscar(int x){
    //La busqueda binaria solo funciona
    //con arreglos ya ordenados

    //indice maximo
    int max = N-1;
    //indice minimo
    int min = 0;

    //si x esta afuera de los limites entonces
    //no se encuentra en el arreglo
    if(x < a[min] || x > a[max]){
	pasos++;
	return -1;
    }

    while(min<=max){
	pasos++;
	//indice que esta entre al maximo y el minimo
	int mitad = (max+min)/2;
	
	for(int i = min; i < max+1; i++) cout << a[i] << " ";
	cout << endl;

	//si el valor a la mitad es igual a x
	//entonces regresamos el indice de la mitad
	if(a[mitad] == x) return mitad;

	else{
	    //si la el valor en la pocicion de la
	    //mitad es mayor que x, entonces el maximo
	    //es un indice menos al de la mitad
	    if(a[mitad] > x){
		max = mitad - 1; 
	    }
	    //de otra forma el valor de la mitad es menor
	    //que x, entonces el minimo es un indece mayor
	    //que la mitad
	    else{
		min = mitad + 1;
	    }
	}
    }

    //si al final no se encontró ninguna coincidencia
    //regresa -1
    return -1;
}

int main(){
    int x = 97;
    cout << "arreglo inicial: ";
    for(int i = 0; i < N; i++) cout << a[i] << " ";
    cout << "\n"; 
    cout << "buscar el peor caso (97)\n";
    cout << "busqueda binaria: \n";
    cout << "idx: " <<  buscar(x) << "\n";
    cout << "pasos: " << pasos << "\n\n";
    pasos = 0;
    cout << "busqueda regular: \n";
    for(int i = 0; i < N; i++){
	pasos++;
	for(int j = 0; j < pasos; j++) cout << a[j];
	cout << endl;
	if(a[i] == x){
	    cout << "idx: " << i;
	    break;
	}
    }
    cout << "\npasos: " << pasos << "\n";



    return 0;
}
