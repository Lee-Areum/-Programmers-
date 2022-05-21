#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check[600][600][4] = { false }; //각 노드의 뱡향 간 여부
vector<int> y = { 0,1,0,-1 }; //세로  {y,x}
vector<int> x = { 1,0,-1,0 }; //가로
int n, m;

int Circle(vector<string>& grid, pair<int, int> node, int path, int count) {
	if (check[node.first][node.second][path]) {
		return count;
	}
	check[node.first][node.second][path] = true;
	switch (grid[node.first][node.second])
	{
	case 'L':
		path = (path == 3) ? 0 : path + 1;
		break;
	case 'R':
		path = (path == 0) ? 3 : path - 1;
		break;
	}
	node = { node.first + y[path], node.second + x[path] };
	if (node.first < 0) {
		node.first = n - 1;
	}if (node.first > n - 1) {
		node.first = 0;
	}if (node.second < 0) {
		node.second = m - 1;
	}if (node.second > m - 1) {
		node.second = 0;
	}
	count = Circle(grid, node, path, count + 1);
	return count;
}

vector<int> solution(vector<string> grid) {
	vector<int> answer;
	n = grid.size();
	m = grid[0].size();
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			for (int t = 0; t < 4; t++) {
				int n = Circle(grid, { i,k }, t, 0);
				if (n > 0) {
					answer.push_back(n);
				}
			}
		}
	}
	sort(answer.begin(), answer.end());
	return answer;
}