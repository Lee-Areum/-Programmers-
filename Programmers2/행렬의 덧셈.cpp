#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    for (int i = 0; i < arr1.size(); i++) {
        vector<int> tmp;
        for (int k = 0; k < arr1[0].size(); k++) {
            tmp.push_back(arr1[i][k] + arr2[i][k]);
        }
        answer.push_back(tmp);
    }
    return answer;
}

//https://programmers.co.kr/learn/courses/30/lessons/12950