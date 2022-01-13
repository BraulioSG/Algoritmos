#include<bits/stdc++.h>

using namespace std;
int n = 10;
int pasos = 0; 
int a[] = {9,8,7,6,5,4,3,2,1,0};


void iniciarArreglo(int escenario);

void imprimirArreglo(){
    for (int i = 0; i < n; i++){
	cout << a[i] << " ";
    }

    cout << "\n";
}

void bubblesort(){
    //bubble sort basico (menor a mayor)
    //para cada posición en el arreglo
    //movemos el numero mas grande hasta el
    //final del arreglo
    for(int i = 0; i < n; i++){
	for(int j = 0; j < n-1; j++){
	    pasos++;
	    if(a[j] > a[j+1]){
		int temp = a[j];
		a[j] = a[j+1];
		a[j+1] = temp;
	    }
	}
    }
}

void bubblesort_opt(){
    for(int i = 0; i < n; i++){
	//optimización de '-i' para 
	//ahorrar pasos
	for(int j = 0; j < n-1-i; j++){
	    pasos++;
	    if(a[j] > a[j+1]){
		int temp = a[j];
		a[j] = a[j+1];
		a[j+1] = temp;
	    }
	}
    }
}

void bubblesort_while(){
    int cambios = 0;
    int vuelta = 0;
    do{
	cambios = 0;
	for(int i = 0; i < n - 1 - vuelta; i++){
	    pasos++;
	    if(a[i] > a[i+1]){
		int temp = a[i];
		a[i] = a[i+1];
		a[i+1] = temp;
		cambios++;
	    }
	}
	vuelta ++;
    }while(cambios > 0);
    //similar al bubblesort_opt, sin embargo
    //cuando no dectecte cambios, significa que
    //el arreglo ya esta ordenado, ahorrando unos
    //pasos en algunas ocaciones
}

int main(){
    srand(time(NULL));

    cout << "---MEJOR CASO--------------------------\n";
    cout << "Arreglo inicial: ";
    iniciarArreglo(1);
    imprimirArreglo();

    cout << "\nArreglo usando bubble sort basico\n";
    bubblesort();
    cout << "pasos: " << pasos << endl;
    imprimirArreglo();
    pasos = 0;

    cout << "\nArreglo usando bubble con optimizacion\n";
    bubblesort_opt();
    cout << "pasos: " << pasos << endl;
    imprimirArreglo();
    pasos = 0;

    cout << "\nArreglo usando bubble con while\n";
    bubblesort_while();
    cout << "pasos: " << pasos << endl;
    imprimirArreglo();
    pasos = 0;

    cout << "---PEOR CASO--------------------------\n";
    cout << "Arreglo inicial: ";
    iniciarArreglo(2);
    imprimirArreglo();

    cout << "\nArreglo usando bubble sort basico\n";
    iniciarArreglo(2);
    bubblesort();
    cout << "pasos: " << pasos << endl;
    imprimirArreglo();
    pasos = 0;

    cout << "\nArreglo usando bubble con optimizacion\n";
    iniciarArreglo(2);
    bubblesort_opt();
    cout << "pasos: " << pasos << endl;
    imprimirArreglo();
    pasos = 0;

    cout << "\nArreglo usando bubble con while\n";
    iniciarArreglo(2);
    bubblesort_while();
    cout << "pasos: " << pasos << endl;
    imprimirArreglo();
    pasos = 0;
    
    cout << "---RANDOM CASO--------------------------\n";

    cout << "\nArreglo usando bubble sort basico\n";
    iniciarArreglo(3);
    imprimirArreglo();
    bubblesort();
    cout << "pasos: " << pasos << endl;
    imprimirArreglo();
    pasos = 0;

    cout << "\nArreglo usando bubble con optimizacion\n";
    iniciarArreglo(3);
    imprimirArreglo();
    bubblesort_opt();
    cout << "pasos: " << pasos << endl;
    imprimirArreglo();
    pasos = 0;

    cout << "\nArreglo usando bubble con while\n";
    iniciarArreglo(3);
    imprimirArreglo();
    bubblesort_while();
    cout << "pasos: " << pasos << endl;
    imprimirArreglo();
    pasos = 0;
    

    return 0; 
}

void iniciarArreglo(int escenario){
    switch(escenario){
	case 1:
	    //mejor caso, los numeros ya estan ordenados
	    for(int i = 0; i < n; i++) a[i] = i+1;
	    break;
	case 2:
	    //peor caso, los numeros estan ordenados al reves
	    for(int i = 0; i < n; i++) a[i] = 10-i;
	    break;
	case 3:
	    for(int i = 0; i < n; i++) a[i] = rand()%100 + 1;
	    break;
	default:
	    cout << "escenario no existe";
	    break;

    }
}
