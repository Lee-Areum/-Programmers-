#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool check_person(vector<vector<char>> table, pair<int,int> n1) {
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (int i = 0; i < places.size(); i++) {
        cout << i << " ";
        vector<vector<char>> table;
        for (int k = 0; k < 5; k++) {
            vector<char> row;
            for (int t = 0; t < 5; t++) {
                row.push_back(places[i][k][t]);
            }
            table.push_back(row);
        }
        for (int k = 0; k < 5; k++) {
            for (int j = 0; j < 5; j++) {
                if (table[k][j] == 'P') {
                    int n = check_person(table, { k,j });
                }
            }
        }
        answer.push_back(n);
    }
    return answer;
}