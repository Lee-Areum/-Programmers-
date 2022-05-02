#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    while (left <= right) {
        long long num = max(left / n, left % n);
        answer.push_back(num + 1);
        left++;
    }
    return answer;
}