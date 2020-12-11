#include <iostream>
#include <algorithm>

using namespace std;	

int GCD(int x, int y){
	int i = 2;
	int temp = 0;
	while(i <= min(x, y)){
		if(x % i == 0 && y % i == 0){
			if(temp < i){
				temp = i;
			}
		}
		i++;
	}
	if(temp == 0) return 1;
	else return temp;
}

int LCM(int x, int y){
	int gcd = GCD(x, y);
	return gcd * (x / gcd) * (y / gcd);
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int x, y;
	cin >> x >> y;
	
	cout << GCD(x, y) << "\n" << LCM(x, y) << "\n";
}
/*
나눌 때 0으로 나누는 거 항상 조심
*/

//*****************유클리드 호제법*****************

#include <iostream>
#include <algorithm>

using namespace std;	

int GCD (int a, int b){
	int r = a % b;
	if(r == 0){
		return b;
	}
	else{
		return GCD(b, r);
	}
}

int LCM(int x, int y){
	int gcd = GCD(x, y);
	return gcd * (x / gcd) * (y / gcd);
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int x, y;
	cin >> x >> y;
	
	int a = max(x, y);
	int b = min(x, y);
	
	cout << GCD(a, b) << "\n" << LCM(a, b) << "\n";
}
