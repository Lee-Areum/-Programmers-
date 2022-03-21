#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> go = { {1,0},{0,-1},{-1,0},{0,1} };
queue<pair<int, int>> q;
bool check_person(vector<vector<char>> places) {
    for (int k = 0; k < 5; k++) {
        for (int j = 0; j < 5; j++) {
            if (places[k][j] == 'P') {
                for (int i = 0; i < go.size(); i++) {
                    int x = k + go[i].first;
                    int y = j + go[i].second;
                    if (x < 0 || x >4 || y < 0 || y>4) {
                        continue;
                    }
                    if (places[x][y] == 'P') {
                        return false;
                    }
                    if (places[x][y] == 'O') {
                        q.push({ x,y });
                    }
                }
                while (!q.empty()) {
                    pair<int, int> tmp = q.front();
                    q.pop();
                    int x = tmp.first;
                    int y = tmp.second;
                    for (int i = 0; i < go.size(); i++) {
                        int xx = x + go[i].first;
                        int yy = y + go[i].second;
                        if (xx < 0 || xx >4 || yy < 0 || yy>4 || (xx == k && yy == j)) {
                            continue;
                        }
                        if (places[xx][yy] == 'P') {
                            int num = k > xx ? k - xx : xx - k;
                            num += j > yy ? j - yy : yy - j;
                            if (num <= 2) {
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (int i = 0; i < places.size(); i++) {
        vector<vector<char>> table;
        for (int k = 0; k < 5; k++) {
            vector<char> row;
            for (int t = 0; t < 5; t++) {
                row.push_back(places[i][k][t]);
            }
            table.push_back(row);
        }
        int n = check_person(table);
        answer.push_back(n);

    }
    return answer;
}