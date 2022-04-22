#include <string>
#include <vector>

using namespace std;

int uclid(int a, int b) { // 최대공약수
    if (a % b == 0) return b;
    else return uclid(b, a % b);
}

int solution(vector<int> arr) { //a*b = 최소공배수*최대공약수
    for (int i = 0; i < arr.size() - 1; i++) {
        int gcd = uclid(arr[i], arr[i + 1]);
        arr[i + 1] = (arr[i] * arr[i + 1]) / gcd;
    }
    return arr[arr.size() - 1];
}