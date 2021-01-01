#include <iostream>

using namespace std;

int sudoku_board[9][9];
pair<int, int> blank_position[81];
int blank_cnt = 0;
int success_flag = 0;

void Fill_Sudoku_Board(int solving_blank);
bool Judge_Valid_Num(int x_pos, int y_pos, int num);

int main(){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cin >> sudoku_board[i][j];
			if(sudoku_board[i][j] == 0){
				blank_position[blank_cnt++] = make_pair(i, j);
			}
		}
	}
	Fill_Sudoku_Board(0);
	/*
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cout << sudoku_board[i][j] << " ";
		} cout << endl;
	}*/
}

void Fill_Sudoku_Board(int solving_blank){
	
	cout << solving_blank << endl;
	
	if(solving_blank == blank_cnt){
		success_flag = 1;
		return;
	}
	
	int x_pos = blank_position[solving_blank].first;
	int y_pos = blank_position[solving_blank].second;
	
	
	for(int k = 1; k <= 9; k++){
		if(Judge_Valid_Num(x_pos, y_pos, k)){
			sudoku_board[x_pos][y_pos] = k;
			Fill_Sudoku_Board(++solving_blank);
		}
		if(success_flag == 1) return;
	}
	
	return;
}

bool Judge_Valid_Num(int x_pos, int y_pos, int num){
	
	return true;
}
