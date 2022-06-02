#include <iostream>
#include <string>
using namespace std;

bool isPal(string& str,int front,int n) {
    int end = front + n - 1;
    for (int j = 0; j < n/2; j++) {
        if (str[j+front] != str[end - j]) {
            return false;
        }
    }
    return true;
}

int solution(string s)
{
    for (int i = s.size(); i > 1; i--) {
        for (int k = 0; k <= s.size() - i; k++) {
            if (isPal(s,k,i)) return i;
        }
    }
    return 1;
}