#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    for (int n : arr) {
        answer += n;
    }
    answer /= arr.size();
    return answer;
}
//accumulate : 배열의 합


//https://programmers.co.kr/learn/courses/30/lessons/12944