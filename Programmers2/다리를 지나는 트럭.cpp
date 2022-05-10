#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int i = 0,nowWeight = 0;
    vector<pair<int, int>> v;
    while (i < truck_weights.size() || !v.empty()) {
        if (!v.empty() && v[0].first <= 0) {
            nowWeight -= v[0].second;
            v.erase(v.begin());
        }
        if (i < truck_weights.size() && nowWeight + truck_weights[i] <= weight) {
            nowWeight += truck_weights[i];
            v.push_back({ bridge_length,truck_weights[i++] });
        }
        for (int k = 0; k < v.size(); k++) {
            v[k].first -= 1;
        }
        answer++;
    }
    return answer;
}