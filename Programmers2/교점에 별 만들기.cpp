#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<vector<long long>> stars;
    long long minX = 200000, maxX = -200000, minY = 200000, maxY = -200000;
    for (int i = 0; i < line.size(); i++) {
        for (int k = i + 1; k < line.size(); k++) {
            vector<int> n1 = line[i], n2 = line[k];
            long long a =line[i][0], b = line[i][1], c = line[k][0], 
                d = line[k][1], e = line[i][2], f = line[k][2];
            long long mod = a * d*1LL - b*c*1LL; //AD - BC
            long long bfed = b * f*1LL - e * d*1LL;
            long long ecaf = e * c - a * f;
            if (mod == 0) continue;
            if (bfed % mod || ecaf%mod) {
                continue;
            }
            long long x = bfed / mod, y = ecaf / mod;
            stars.push_back({ x,y });
            minX = min(minX, x); minY = min(minY, y);
            maxX = max(maxX, x); maxY = max(maxY, y);
        }
    }
    string row = string(maxX - minX + 1, '.');
    vector<string> answer(maxY - minY + 1, row);
    for (auto star : stars) {
        answer[abs(star[1] - maxY)][abs(star[0] - minX)] = '*';
    }
    return answer;
}