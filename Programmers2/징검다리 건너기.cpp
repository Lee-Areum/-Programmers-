#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool check(vector<int> &stones, int K, int mid) {
    int count = 0;
    for (int i = 0; i < stones.size(); i++) {
        if (stones[i] < mid) {
            count++;
        }
        else {
            count = 0;
        }
        if (count == K) return false;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int left = 1, right = *max_element(stones.begin(), stones.end());
    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(stones,k,mid)) {
            answer = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return answer;
}