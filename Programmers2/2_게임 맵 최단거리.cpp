#include<vector>
#include<stack>
using namespace std;

vector<pair<int,int>> direction = { {1,0},{0,1},{-1,0},{0,-1} };
stack<Location> s_location;
int M,N;

typedef struct{
    pair<int, int> n; //�� �� �ִ� node
    int dir; //�����ϴ� ����
    vector<vector<int>> maps; //������ map ����
    int length; //�ش� node������ �Ÿ�
}Location;

void searchToGo(pair<int,int> n, vector<vector<int>> maps,int length) {
    pair<int, int> now = {n.first,n.second};
    for (int i = 0; i < direction.size(); i++) {
        int x = now.second + direction[i].second;
        int y = now.first + direction[i].first;
        if (x >= 0 && x < M && y >= 0 && y<N) {
            if (maps[y][x]) {
                Location tmp = { {y,x},i, maps,length };
                s_location.push(tmp);
            }
        }
    }
}

int solution(vector<vector<int>> maps) //n x m
{
    int answer = 10000;
    N = maps.size(); M = maps[0].size();
    maps[0][0] = 0;
    searchToGo({ 0,0 },maps,1);
    while (!s_location.empty()) {
        Location now = s_location.top();
        s_location.pop();
        now.maps[now.n.first][now.n.second] = 0;
        now.length += 1;
        if (now.n.first == N && now.n.second == M) { //�� ������ ���
            answer = min(answer, now.length);
        }
        else {
            searchToGo({now.n}, now.maps, now.length);
        }
    }
    if (answer == 10000) return -1;
    return answer;
}