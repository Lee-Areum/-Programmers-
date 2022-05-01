#include <string>
#include <vector>

using namespace std;

int check_one(int n) {
    int count = 0;
    while (n) {
        if (n % 2 == 1)count++;
        n /= 2;
    }
    return count;
}

int solution(int n) {
    int count = check_one(n);
    for (int i = n + 1; i < 2000000; i++) {
        if (count == check_one(i)) {
            return i;
        }
    }
}