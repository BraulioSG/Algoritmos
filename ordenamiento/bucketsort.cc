#include<bits/stdc++.h>

using namespace std;

// Ordenamiento bucket Sort
// Complejidad => 2m
// donde 'm' es la diferencia del valor mas chico al valor mas grande
#define N 10

int bucket[N];

int main(){
    int n, x; 
    cin >> n; 
    for(int i = 0; i < n; i++){
	cin >> x;
	bucket[x]++;
    }
    //suponiendo el input => 1 5 7 8 1 3 5 1
    //idx    |0|1|2|3|4|5|6|7|8|9|
    //bucket |0|2|0|1|0|2|0|1|1|0|
    
    //bucket sort
    //para cada elemento en bucket
    //imprime i -> bucket[i] numero de veces;
    //1135578
    for(int i = 0; i < N; i++){
	while(bucket[i] > 0){
	    cout << i << " ";
	    bucket[i]--;
	}
    }

}
