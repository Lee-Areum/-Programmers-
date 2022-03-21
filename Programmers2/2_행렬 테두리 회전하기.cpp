#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int normal[101][101] = { 0 };
    int plus[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
    for (int i = 1; i <= rows; i++) {
        for (int k = 1; k <= columns; k++) {
            normal[i][k] = (i - 1) * columns + k;
        }
    }

    for (auto query : queries) {
        int h = query[2] - query[0]; //높이
        int w = query[3] - query[1]; //너비
        int x, y,tmp,minest;
        x = query[0]; y = query[1]; 
        tmp = normal[x][y];
        minest = tmp;
        for (int i = 0; i < 4; i++) {
            int top;
            if (i % 2 == 0)
                top = w;
            else
                top = h;
            for (int k = 0; k < top; k++) {
                x += plus[i][0]; y += plus[i][1];
                int num = normal[x][y];
                normal[x][y] = tmp;
                tmp = num;
                if (minest > tmp) minest = tmp;
            }
        }
        answer.push_back(minest);
    }

    return answer;
}