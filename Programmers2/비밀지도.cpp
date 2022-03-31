#include <string>
#include <vector>

using namespace std;

string TenToTwo(int n, int N) {
    string tmp;
    while (n > 1) {
        tmp = to_string(n % 2) + tmp;
        n /= 2;
    }
    tmp = to_string(n) + tmp;
    if (tmp.size() < N) {
        string zero = "000000000000000";
        tmp = zero.substr(0, N - tmp.size()) + tmp;
    }
    return tmp;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int i = 0; i < arr1.size(); i++) {
        string n1 = TenToTwo(arr1[i], n);
        string n2 = TenToTwo(arr2[i], n);
        string tmp;
        for (int k = 0; k < n1.size(); k++) {
            if (n1[k] == '1' || n2[k] == '1')
                tmp.push_back('#');
            else tmp.push_back(' ');
        }
        answer.push_back(tmp);
    }
    return answer;
}