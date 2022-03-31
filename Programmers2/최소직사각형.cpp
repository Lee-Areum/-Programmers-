#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int max_w = 0; int max_h = 0;
    for (auto num : sizes) {
        if (max_w < max(num[0], num[1]))
            max_w = max(num[0], num[1]);
        if (max_h < min(num[0], num[1]))
            max_h = min(num[0], num[1]);
    }
    return max_h * max_w;
}