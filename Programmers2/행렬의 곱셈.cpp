#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    for (int i = 0; i < arr1.size(); i++) {
        vector<int> tmp;
        for (int k = 0; k < arr2[0].size(); k++) {
            int n = 0;
            for (int x = 0; x < arr2.size(); x++) {
                n += (arr1[i][x] * arr2[x][k]);
            }
            tmp.push_back(n);
        }
        answer.push_back(tmp);
    }
    return answer;
}