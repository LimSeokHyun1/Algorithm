#include <iostream>
#include <cmath>
#include <vector>

#define MAX_NUM 1000001

using namespace std;

bool primenum[MAX_NUM] = {true, };
int even_intger;

void FindPrimeNum(){
	primenum[0] = false;
	primenum[1] = false;
	primenum[2] = true;
	primenum[3] = true;
	for(int i = 2; i < sqrt(MAX_NUM); i++){
		if(primenum[i] == true){
			for(int j = 2; i * j < MAX_NUM; j++){
				primenum[i * j] = false;
			}
		}
	}
}

void FindTwoPrimeNum(){
	for(int i = 2; i < MAX_NUM; i++){
		if(primenum[i] == true){
			if(primenum[even_intger - i] == true){
				cout << even_intger << " = " << i << " + " << even_intger - i << "\n";
				return;
			}
		}
	}
	cout << "Goldbach's conjecture is wrong.\n";
}

int main(){
	
	cin.tie(NULL);
	ios::sync_with_stdio(0);
	
	fill_n(primenum, MAX_NUM, true);
	FindPrimeNum();
	while(1){
		cin >> even_intger;
		if(even_intger == 0) break;
		FindTwoPrimeNum();
	}
}
