#include <iostream>
#include <vector>

using namespace std;

int already_planted_tree;
vector<int> location_of_tree;
vector<int> difference_in_location;

void Make_Difference_In_Numbers(){
	for(int i = 0; i < already_planted_tree - 1; i++){
		difference_in_location.push_back(location_of_tree[i + 1] - location_of_tree[i]);
	}
}

int Find_GCD(int x, int y){
	cout << x << y << endl;
	if()
}

void Find_Required_Minimum_Tree(){
	int gcd = difference_in_location[0];
	for(int i = 0; i < already_planted_tree - 1; i++){
		gcd = Find_GCD(gcd, difference_in_location[i + 1]);
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
	Find_Required_Minimum_Tree();
}
