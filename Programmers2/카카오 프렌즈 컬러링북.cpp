#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
bool check[100][100] = { false };
vector<vector<int>> pictures;
int M, N;
int xs[] = { 0,-1,0,1 };
int ys[] = { -1,0,1,0 };

int dfs(int num, int i, int k) {
    check[i][k] = true;
    int count = 1;
    for (int n = 0; n < 4; n++) {
        int x = i + xs[n];
        int y = k + ys[n];
        if (x < 0 || y < 0 || x >= M || y >= N || check[x][y] || pictures[x][y] != num) continue;
        count += dfs(num, x, y);
    }
    return count;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> answer(2);
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    M = m; N = n; pictures = picture;
    memset(check, 0, sizeof(check));
    for (int i = 0; i < m; i++) {
        for (int k = 0; k < n; k++) {
            if (!check[i][k] && picture[i][k] != 0) {
                int count = dfs(picture[i][k], i, k);
                number_of_area += 1;
                max_size_of_one_area = max(max_size_of_one_area, count);
            }
        }
    }
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}