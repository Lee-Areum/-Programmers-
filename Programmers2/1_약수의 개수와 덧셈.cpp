#include <string>
#include <vector>

using namespace std;

bool find_Measure(int num) {
    int count = 0;
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            count++;
        }
    }
    return (count % 2 == 0);
}

int solution(int left, int right) {
    int answer = 0;
    for (int i = left; i <= right; i++) {
        if (find_Measure(i)) {
            answer += i;
        }
        else {
            answer -= i;
        }
    }
    return answer;
}