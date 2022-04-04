#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = min(a,b);
    for (int n = answer + 1; n <= max(a,b); n++) {
        answer += n;
    }
    return answer;
}