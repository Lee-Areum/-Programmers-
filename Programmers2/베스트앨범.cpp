#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool comp(pair<string, int> n1, pair<string, int> n2) {
    return n1.second > n2.second;
}

bool compsong(pair<int, int> n1, pair<int, int> n2) {
    return n1.first > n2.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> sum;
    map<string, vector<pair<int, int>>> songs;
    for (int i = 0; i < genres.size(); i++) {
        sum[genres[i]] += plays[i];
        songs[genres[i]].push_back({plays[i],i});
    }
    vector<pair<string, int>> vSum(sum.begin(),sum.end());
    sort(vSum.begin(), vSum.end(), comp);
    for (auto p : vSum) {
        vector<pair<int, int>> list = songs[p.first];
        sort(list.begin(), list.end(), compsong);
        answer.push_back(list[0].second);
        if (list.size() > 1) {
            answer.push_back(list[1].second);
        }
    }
    return answer;
}