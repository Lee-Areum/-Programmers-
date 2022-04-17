#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> list;
int result[] = { 0,0 };
void check(pair<int, int> start, int len) {
    if (len == 1) {
        result[list[start.first][start.second]]++;
        return;
    }
    int last = list[start.first][start.second];
    for (int i = start.first; i < start.first + len; i++) {
        for (int k = start.second; k < start.second + len; k++) {
            if (last != list[i][k]) {
                check(start, len / 2);
                check({ start.first,start.second + len / 2 }, len / 2);
                check({ start.first + len / 2 ,start.second }, len / 2);
                check({ start.first + len / 2 ,start.second + len / 2 }, len / 2);
                return;
            }
        }
    }
    result[last]++;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    list.assign(arr.begin(), arr.end());
    check({ 0,0 }, arr.size());
    return { result[0],result[1] };
}