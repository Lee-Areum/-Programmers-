#include <vector>
#include <queue>
using namespace std;
//1,0 0,1 0,-1 -1,0
vector<int> x = { 1,0,0,-1 };
vector<int> y = { 0,1,-1,0 };
int n, m;

int solution(vector<vector<int>> maps)
{
	int answer = 0;
	queue<pair<int, int>> q;
	n = maps.size(); m = maps[0].size();
	q.push({ 0,0 });
	while (!q.empty()) {
		int nowx = q.front().first;
		int nowy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = nowx + x[i];
			int ny = nowy + y[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && maps[nx][ny] == 1) {
				maps[nx][ny] = maps[nowx][nowy] + 1;
				q.push({ nx,ny });
			}
		}
	}
	return maps[n - 1][m - 1] > 1 ? maps[n - 1][m - 1] : -1;
}