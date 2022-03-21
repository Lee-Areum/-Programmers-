#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<map<string, int>> ordered_count(20);
string cArr[50] = {};
int r = 2; // nCr

void combination(string order, int depth, int next) {
    if (depth == r) {
        string list = cArr[0];
        for (int i = 1; i < r; i++) {
            list += cArr[i];
        }
        ordered_count[r][list]++;
        return;
    }
    for (int i = next; i < order.size(); i++) {
        cArr[depth] = order[i];
        combination(order, depth + 1, i + 1);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for (string order : orders) {
        sort(order.begin(), order.end());
        for (int num : course) {
            r = num;
            combination(order, 0, 0);
        }
    }
    for (int num : course) {
        int max_count = 0;
        vector<string> candidate;
        for (auto tmp : ordered_count[num]) {
            if (tmp.second >= 2 && max_count <= tmp.second) {
                if (max_count < tmp.second) candidate.clear();
                max_count = tmp.second;
                candidate.push_back(tmp.first);
            }
        }
        answer.insert(answer.end(),candidate.begin(),candidate.end());
    }
    sort(answer.begin(), answer.end());
    return answer;
}