#include <vector>
#include <iostream>
using namespace std;

bool sosu(int a) {
    for (int i = 2; i < a; i++) {
        if (a % i == 0) return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;

    for (int i = 0; i < nums.size(); i++) {
        for (int k = i+1; k < nums.size(); k++) {
            for (int t = k+1; t < nums.size(); t++){
                if (sosu(nums[i] + nums[k] + nums[t])) {
                    answer++;
                }
            }
        }
    }

    return answer;
}