#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<pair<int, int>>check = { {0,0},{0,1},{1,0},{1,1} };
stack<pair<int, int>> s;

void check4(int m, int n, vector<string>& board) {
    stack<pair<int, int>> tmp;
    for (int i = 0; i < m - 1; i++) {
        for (int k = 0; k < n - 1; k++) {
            bool tag = true;
            char c = board[i][k];
            if (c != '.') {
                for (int t = 0; t < 4; t++) {
                    if (c != board[i + check[t].first][k + check[t].second]) {
                        tag = false;
                        break;
                    }
                }
                if (tag) {
                    s.push({ i,k });
                    tmp.push({ i,k });
                }
            }
        }
    }
    while (!tmp.empty()) {
        int i = tmp.top().first, k = tmp.top().second;
        tmp.pop();
        for (int t = 0; t < 4; t++) {
            board[i + check[t].first][k + check[t].second] = '.';
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    check4(m, n, board);
    while (!s.empty()) {
        while (!s.empty()) {
            int x = s.top().first, y = s.top().second;
            s.pop();
            for (int i = 0; i < 2; i++) {
                int num = 0;
                for (int k = x; k < m && board[k][y + i] == '.'; k++, num++);
                for (int k = x - 1; k >= 0 && board[k][y + i] != '.'; k--) {
                    if (board[k + num][y + i] == '.') {
                        board[k + num][y + i] = board[k][y + i];
                        board[k][y + i] = '.';
                    }
                }
            }
        }
        check4(m, n, board);
    }
    for (int i = 0; i < m; i++) {
        for (int k = 0; k < n; k++) {
            if (board[i][k] == '.') {
                answer++;
            }
        }
    }

    return answer;
}