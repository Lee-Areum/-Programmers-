#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<vector<int>> result;

int draw(int n, pair<int, int> start, pair<int, int> end) {
    for (int i = start.first; i <= end.first; i++) {
        result[i][start.second] = n++;
    }
    for (int i = start.second + 1; i <= end.second; i++) {
        result[end.first][i] = n++;
    }
    int height = end.first - 1;
    for (int i = end.second - 1; i > start.second; i--, height--) {
        result[height][i] = n++;
    }
    return n;
}

vector<int> solution(int n) {
    vector<int> answer;
    for (int i = 1; i <= n; i++) {
        vector<int> tmp;
        for (int k = 0; k < i; k++) {
            tmp.push_back(0);
        }
        result.push_back(tmp);
    }
    pair<int, int> start, end;
    int num = 1;
    start = { 0,0 }; end = { n - 1,n - 1 };
    while (start <= end) {
        if (start == end) {
            result[start.first][start.second] = num;
            break;
        }
        num = draw(num, start, end);
        start.first += 2; start.second += 1;
        end.first -= 1; end.second -= 2;
    }

    for (int i = 0; i < n; i++) {
        for (int k = 0; k <= i; k++) {
            answer.push_back(result[i][k]);
        }
    }
    return answer;
}