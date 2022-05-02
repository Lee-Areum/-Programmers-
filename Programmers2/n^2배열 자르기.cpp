#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    vector<vector<int>> list;
    for (int i = 0; i < n; i++) {
        vector<int> tmp(n);
        for (int k = 0; k < n; k++) {
            tmp.push_back(0);
        }
        list.push_back(tmp);
    }
    list[0][0] = 1;
    for (int i = 1; i < n; i++) {
        for (int k = 0; k < i; k++) {
            list[k][i] = list[i][k] = i + 1;
        }
        list[i][i] = i + 1;
    }
    while (left >= right) {
        answer.push_back(list[(left-1) / n][left % n]);
        left++;
    }

    return answer;
}