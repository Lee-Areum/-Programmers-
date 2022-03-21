#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end());
    int num = 0;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == num) {
            num++;
        }
        else {
            while (i < numbers.size() && numbers[i] != num) {
                answer += num;
                num++;
            }
            num++;
        }
    }
    for (; num < 10; num++) {
        answer += num;
    }
    return answer;
}