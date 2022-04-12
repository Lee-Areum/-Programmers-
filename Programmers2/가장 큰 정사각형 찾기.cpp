#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    bool one = false;
    if (board.size() == 1 && board[0].size() == 1) {
        return board[0][0];
    }
    for (int i = 1; i < board.size(); i++) {
        for (int k = 1; k < board[0].size(); k++) {
            vector<int> tmp = { board[i - 1][k] ,board[i][k - 1] ,board[i - 1][k - 1] };
            if (*max_element(tmp.begin(), tmp.end())) one = true;
            int minest = (*min_element(tmp.begin(), tmp.end())) + 1;
            board[i][k] = board[i][k] == 0 ? 0 : minest;
            if (answer < board[i][k]) answer = board[i][k];
        }
    }
    if (answer == 0 && one) return 1;
    return answer * answer;
}