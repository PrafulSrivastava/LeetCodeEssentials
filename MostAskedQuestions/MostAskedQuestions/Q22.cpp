#pragma once
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>

using namespace std;
#define ROW 0
#define COLUMN 1
struct comp {
	bool operator()(const int& a, const int& b) const {
		return a < b;
	}
};

// Q22 : https://leetcode.com/problems/minimum-absolute-difference/
class Q22 {
public:
	static pair<int, int> get_rook_position(vector<vector<char>>& board) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board[i][j] == 'R') {
					return {i,j};
				}
			}
		}
		return { -1,-1 };
	}
	static bool can_consume_before(vector<vector<char>>& board, pair<int, int> & rook_pos, int start, int end, int row_or_col) {

		for (int i = end - 1; i >= start; i--) {
			if (row_or_col) {
				if (board[rook_pos.first][i] == 'p') {
					return true;
				}
				else if (board[rook_pos.first][i] == 'B') {
					return false;
				}
			}
			else {
				if (board[i][rook_pos.second] == 'p') {
					return true;
				}
				else if (board[i][rook_pos.second] == 'B') {
					return false;
				}
			}
		}
		return false;
	}
	static bool can_consume_after(vector<vector<char>>& board, pair<int, int>& rook_pos, int start, int end, int row_or_col) {

		for (int i = start; i < end; i++) {
			if (row_or_col) {
				if (board[rook_pos.first][i] == 'p') {
					return true;
				}
				else if (board[rook_pos.first][i] == 'B') {
					return false;
				}
			}
			else {
				if (board[i][rook_pos.second] == 'p') {
					return true;
				}
				else if (board[i][rook_pos.second] == 'B') {
					return false;
				}
			}
		}
		return false;
	}
	static int numRookCaptures(vector<vector<char>>& board) {
		auto rook_pos = get_rook_position(board);
		int c = 0;
		if (rook_pos.first > 0) {
			
			if (can_consume_before(board, rook_pos, 0, rook_pos.second, COLUMN))
				c++;
			if (can_consume_after(board, rook_pos, rook_pos.second, 8, COLUMN))
				c++;
			if (can_consume_before(board, rook_pos, 0, rook_pos.first, ROW))
				c++;
			if (can_consume_after(board, rook_pos, rook_pos.first, 8, ROW))
				c++;
		}
		return c;
	}
	static void init() {
		vector<vector<char>> board = {  {'.','.','.','.','.','.','.','.'},
										{'.','.','.','p','.','.','.','.'},
										{'.','.','.','R','.','.','.','p'},
										{'.','.','.','.','.','.','.','.'},
										{'.','.','.','.','.','.','.','.'},
										{'.','.','.','p','.','.','.','.'},
										{'.','.','.','.','.','.','.','.'},
										{'.','.','.','.','.','.','.','.'} };
		auto res = Q22::numRookCaptures(board);
		cout << "Result : " << res << endl;
	}
};