#include<bits/stdc++.h>

using namespace std;

int steps = 0; 
int nums[15] = {-1};

int fibonacci(int n){
    steps++;//agrega un paso cada que se llama a la función
    //Casos bases
    if(n == 0) return 1;
    if(n == 1) return 1;

    //Premisa f(n) = f(n-1) + f(n-2);

    return fibonacci(n-1) + fibonacci(n-2);
}

int fibonacci_memory(int n){
    steps++;//agrega un paso cada que se llama a la función

    //Casos base
    if(n == 0) return 1;
    if(n == 1) return 1;
    //revisa si hay un valor ya guardado
    //de lo contrario guarda el valor nums[n] = f(n-1) + f(n-2)
    //idx | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
    //nums| 1 | 1 | 2 | 3 | 5 | 8 |13 |21 |34 | 55|
    if(nums[n] == 0) nums[n] = fibonacci_memory(n-1) + fibonacci_memory(n-2);

    //regresa el valor guardado en nums[n]
    return nums[n]; 

}

int main(){
    fibonacci(10);//calcula el fibonacci de 10 
    cout << "steps: " << steps << endl; //imprime la cantidad de pasos ejecutados en f(10)
    //imprime los primeros 10 numeros de fibonacci
    for(int i = 0; i < 10; i++){
	cout << fibonacci(i) << " ";
    }
    cout << endl;

    steps = 0;
    fibonacci_memory(10); //calcula fibonacci de 10 pero con memorización
    cout << "steps: " << steps << endl;//imprime la cantidad de pasos en fm(10)
    for(int i = 0; i < 10; i++){
	cout << fibonacci_memory(i) << " ";
    }

    return 0;
}
