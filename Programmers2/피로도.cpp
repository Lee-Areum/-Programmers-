#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    vector<int> indexs;
    for (int i = 0; i < dungeons.size(); i++) {
        indexs.push_back(i);
    }
    while (next_permutation(indexs.begin(), indexs.end())) {
        int left = k;
        int count = 0;
        for (int i : indexs) {
            if (left < dungeons[i][0])break;
            else {
                k -= dungeons[i][1];
                count++;
            }
        }
        answer = answer < count ? count : answer;
    }
    return answer;
}