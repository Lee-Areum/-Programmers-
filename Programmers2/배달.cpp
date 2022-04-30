#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    vector<vector<pair<int, int>>> way(N + 1);
    vector<int> weight;
    stack<pair<int, int>> togo;
    int answer = 0;
    for (int i = 0; i <= N; i++) { //초기화
        weight.push_back(-1);
    }
    for (auto r : road) { //입력
        way[r[0]].push_back({ r[1],r[2] });
        way[r[1]].push_back({ r[0],r[2] });
    }
    togo.push({ 1,0 });
    while (!togo.empty()) {
        while (!togo.empty()) {
            auto tmp = togo.top();
            togo.pop();
            if (weight[tmp.first] < 0 || weight[tmp.first] > tmp.second) {
                weight[tmp.first] = tmp.second;
                for (auto go : way[tmp.first]) {
                    togo.push({ go.first,tmp.second + go.second });
                }
            }
        }
    }
    for (int i = 1; i < weight.size(); i++) {
        if (weight[i] <= K) {
            answer++;
        }
    }

    return answer;
}