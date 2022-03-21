#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool organize(pair<int, double> a, pair<int, double> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    else {
        return a.second > b.second;
    }
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    map<int, int> stage_count;
    vector<pair<int, float>> fail;
    for (int n : stages) {
        if (n <= N) {
            stage_count[n]++;
        }
    }
    int person = stages.size();
    for (int i = 1; i <= N; i++) {
        if (person > 0) {
            fail.push_back(make_pair(i, stage_count[i] / (float)person));
            person -= stage_count[i];
        }
        else {
            fail.push_back(make_pair(i, 0));
        }
    }

    sort(fail.begin(), fail.end(), organize);
    for (auto f : fail) {
        answer.push_back(f.first);
    }
    return answer;
}