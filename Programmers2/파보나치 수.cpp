#include <string>
#include <vector>

using namespace std;

vector<int> pa(100000);

int solution(int n) {
    pa[0] = 0; pa[1] = 1;
    for (int i = 2; i <= n; i++) {
        pa[i] = (pa[i - 1] + pa[i - 2]) %1234567;
    }
    return pa[n] % 1234567;
}