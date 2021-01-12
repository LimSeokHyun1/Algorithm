#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
char* natural_numbers;
vector<int> prime_numbers;
int given_num, two_thirds, result = 0;

void Dynamic_Allocation(){
	two_thirds = given_num;
	natural_numbers = new char[two_thirds]; 
	for(int i = 0; i < two_thirds; i++){
		natural_numbers[i] = '1';
	}
}

void Is_Given_Num_Prime(){
	if(given_num == 1) return;
	else if(given_num == 2){
		result++;
		return;
	}
	else if(given_num == 3){
		result++;
		return;
	}
	
	for(int i = 2; i <= sqrt(given_num); i++){
		if(given_num % i == 0) return;
	}
	result++;
}

void Find_Prime_Num_And_Make_Vector(){
	natural_numbers[0] = '0';
	natural_numbers[1] = '0';
	natural_numbers[2] = '1';
	if(sqrt(two_thirds) >= 2){
		for(int i = 2; i < sqrt(two_thirds); i++){
			if(natural_numbers[i] == '1'){
				for(int j = 2; i * j <= two_thirds; j++){
					natural_numbers[i * j] = '0';
				}
			}
		}
	}
	for(int i = 0; i < two_thirds; i++){
		if(natural_numbers[i] == '1'){
			prime_numbers.push_back(i);
		}
	}
}

void Find_Continuous_Sum_Of_Prime_Num(){
	
	if(prime_numbers.size() == 0) return;
	
	int num_of_prime_num = prime_numbers.size() - 1;
	int start = 0, end = 0;
	int sum = prime_numbers[start];	
	while(1){
		if(sum == given_num){
			result++;
		}
		if(end == num_of_prime_num){
			if(sum < given_num || start == num_of_prime_num)
				break;
		}
		if(sum < given_num){
			end++;
			sum += prime_numbers[end];
		}
		else{
			sum -= prime_numbers[start];
			start++;
		}
	}
}

int main(){
	cin >> given_num;
	Dynamic_Allocation();
	Is_Given_Num_Prime();
	Find_Prime_Num_And_Make_Vector();
	Find_Continuous_Sum_Of_Prime_Num();
	cout << result << endl;
}
