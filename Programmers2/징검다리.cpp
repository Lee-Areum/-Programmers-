#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(), rocks.end());
    rocks.push_back(distance);
    vector<int> dist = { rocks[0] };
    for (int i = 1; i < rocks.size(); i++) {
        dist.push_back(rocks[i] - rocks[i - 1]);
    }
    int left = *min_element(dist.begin(), dist.end());
    int right = *max_element(dist.begin(), dist.end());
    while (left <= right) {
        int mid = (left + right) / 2;
        int rest = n; //남은 삭제 개수
        bool flag = false; //삭제 개수를 넘은 경우
        vector<int> tmp; tmp.assign(dist.begin(), dist.end());
        for (int i = 0; i < tmp.size() - 1; i++) {
            if (tmp[i] < mid) {
                if (rest > 0) {
                    rest--;
                    tmp[i + 1] += tmp[i];
                    tmp.erase(tmp.begin() + i);
                    i--;
                }
                else {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) {
            right = mid - 1;
            continue;
        }
        for (int i = tmp.size() - 1; i > 0; i--) {
            if (tmp[i] < mid) {
                if (rest > 0) {
                    rest--;
                    tmp[i - 1] += tmp[i];
                    tmp.erase(tmp.begin() + i);
                    i++;
                }
                else {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) {
            right = mid - 1;
        }
        else {
            answer = mid;
            left = mid + 1;
        }
    }
    return answer;
}