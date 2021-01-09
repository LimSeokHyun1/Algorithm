#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int already_planted_tree, required_tree = 0;
vector<int> location_of_tree;
vector<int> difference_in_location;

void Make_Difference_In_Numbers(){
	sort(location_of_tree.begin(), location_of_tree.end());
	for(int i = 0; i < already_planted_tree - 1; i++){
		difference_in_location.push_back(abs(location_of_tree[i + 1] - location_of_tree[i]));
	}
	sort(difference_in_location.begin(), difference_in_location.end());
}

int Find_GCD(int x, int y){
	int r = y % x;
	if(r == 0) return x;
	return Find_GCD(r, x);
}

void Find_Required_Tree_Num(){
	int gcd = difference_in_location[0];
	for(int i = 0; i < already_planted_tree - 2; i++){
		if(difference_in_location[i + 1] % gcd != 0){
			gcd = Find_GCD(gcd, difference_in_location[i + 1]);
		}
	}
	
	for(int i = 0; i < already_planted_tree - 1; i++){
		if(difference_in_location[i] > gcd){
			required_tree += (difference_in_location[i] / gcd) - 1;
		}
	}
}

int main(){
	cin >> already_planted_tree;
	int tree_position;

	for(int i = 0; i < already_planted_tree; i++){
		cin >> tree_position;
		location_of_tree.push_back(tree_position);
	}
	Make_Difference_In_Numbers();
	Find_Required_Tree_Num();
	cout << required_tree << endl;
}
