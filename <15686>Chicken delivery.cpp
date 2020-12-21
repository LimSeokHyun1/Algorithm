#include <iostream>
#include <cstring>
#include <vector>

#define INF		987654321

using namespace std;

int city_board[50][50];
vector<pair<int, int>> chicken_restaurant_info;
vector<pair<int, int>> house_info;
int house_chicken_distance[100][13];
int choosen_chicken_restaurant[13];
int city_size, max_num_chicken_restaurant, city_info, chicken_restaurant_num, result = INF, result_temp;

void Set_Distance();
void Choose_Chicken_restaurant(int depth, int start);
int Calculate_Distance();

int main(){
	cin >> city_size >> max_num_chicken_restaurant;
	memset(city_board, 0, sizeof(city_board));
	
	for(int i = 0; i < city_size; i++){
		for(int j = 0; j < city_size; j++){
			cin >> city_info;
			if(city_info == 1){
				house_info.push_back(make_pair(i, j));
			}
			else if(city_info == 2){
				chicken_restaurant_num++;
				chicken_restaurant_info.push_back(make_pair(i, j));
			}
			city_board[i][j] = city_info;
		}
	}
	Set_Distance();
	Choose_Chicken_restaurant(0, 0);
	cout << result << "\n";

}

void Set_Distance(){
	for(int i = 0; i < house_info.size(); i++){
		for(int j = 0; j < chicken_restaurant_info.size(); j++){
			house_chicken_distance[i][j] = abs(house_info[i].first - chicken_restaurant_info[j].first) + abs(house_info[i].second - chicken_restaurant_info[j].second);
		}
	}
	
	/*
	for(int i = 0; i < house_info.size(); i++){
		for(int j = 0; j < chicken_restaurant_info.size(); j++){
			cout << house_chicken_distance[i][j] << " ";
		}cout << endl;
	}
	*/
}

void Choose_Chicken_restaurant(int depth, int start){
	if(depth == max_num_chicken_restaurant){
		result_temp = Calculate_Distance();
		if(result > result_temp) result = result_temp;
		return;
	}
	for(int i = start; i < chicken_restaurant_num; i++){
		choosen_chicken_restaurant[depth] = i;
		Choose_Chicken_restaurant(depth + 1, i + 1);
	}
}
	
int Calculate_Distance(){
	int min_distance;
	int distance_sum = 0;
	/*
	for(int i = 0; i < max_num_chicken_restaurant; i++){
		cout << choosen_chicken_restaurant[i] << " ";
	}
	cout << endl;*/
	
	for(int i = 0; i < house_info.size(); i++){
		min_distance = INF;
		for(int j = 0; j < max_num_chicken_restaurant; j++){
			if(min_distance > house_chicken_distance[i][choosen_chicken_restaurant[j]]){
				min_distance = house_chicken_distance[i][choosen_chicken_restaurant[j]];
			}
		}
		distance_sum += min_distance;
	}
	return distance_sum;
}
