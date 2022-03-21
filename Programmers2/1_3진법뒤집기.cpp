#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    string num_3 = "";
    while (n / 3 > 0) {
        num_3 = to_string(n % 3) + num_3;
        n /= 3;
    }
    num_3 = to_string(n % 3) + num_3;
    int cal_num = 1;
    for (int i = 0; i < num_3.size();i++) {
        string tmp;
        tmp += num_3[i];
        answer += cal_num * stoi(tmp);
        cal_num *= 3;
    }
    return answer;
}