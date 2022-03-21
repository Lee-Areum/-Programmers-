#include <string>
#include <vector>
#include <stack>

#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> buckets;
    for (int n : moves) {
        int top = 0;
        for (; top < board.size(); top++) {
            if (board[top][n - 1] != 0) break;
        }
        if (top < board.size()) {
            if (!buckets.empty() && buckets.top() == board[top][n - 1]) {
                answer += 2;
                buckets.pop();
            }
            else {
                buckets.push(board[top][n - 1]);
            }
            board[top][n - 1] = 0;
        }
    }

    return answer;
}