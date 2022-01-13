#include<bits/stdc++.h>

using namespace std;

// Ordenamiento bucket Sort
// Complejidad => 2m
// donde 'm' es la diferencia del valor mas chico al valor mas grande
#define MXN 110

int bucket[MXN];

int main(){
    int n, x; 
    cin >> n; 
    for(int i = 0; i < n; i++){
	cin >> x;
	bucket[x]++;
    }
    
    //bucket sort
    for(int i = 0; i < MXN; i++){
	while(bucket[i] > 0){
	    cout << i << " ";
	    bucket[i]--;
	}
    }

}
