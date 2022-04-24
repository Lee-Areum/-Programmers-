#include <string>
#include <vector>

using namespace std;
int max_score = 0;
vector<int> apeach, answer;

int is_win(vector<int>& lion) {
    int score = 0;
    for (int i = 0; i < lion.size(); i++) {
        if (lion[i] > 0 || apeach[i] > 0) {
            if (lion[i] > apeach[i]) {
                score += (10 - i);
            }
            else {
                score -= (10 - i);
            }
        }
    }
    return score;
}

void check(int n, int i, vector<int> visited) {
    if (n <= 0 || i < 0) {
        int score = is_win(visited);
        if (score > max_score) {
            if (n > 0) {
                visited[10] = n;
            }
            answer.assign(visited.begin(), visited.end());
            max_score = score;
        }
        return;
    }
    for (int k = i; k >= 0; k--) {
        if (n > apeach[k]) {
            vector<int> tmp;
            tmp.assign(visited.begin(), visited.end());
            tmp[k] = apeach[k] + 1;
            check(n - (apeach[k] + 1), k - 1, tmp); //이길경우
        }
        check(n, k - 1, visited); //질경우
    }
}


vector<int> solution(int n, vector<int> info) {
    apeach.assign(info.begin(), info.end());
    vector<int> tmp(11);
    check(n, 9, tmp);
    if (max_score <= 0) return { -1 };
    return answer;
}