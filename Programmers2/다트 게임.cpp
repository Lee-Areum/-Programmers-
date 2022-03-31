#include <string>
#include <cctype>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int backnum = 0;
    for (int i = 0; i < dartResult.size(); i++) {
        string tmp; tmp = dartResult[i];
        if (isdigit(dartResult[i + 1])) {
            tmp += dartResult[i + 1];
            i++;
        }
        int num = stoi(tmp);
        switch (dartResult[++i])
        {
        case 'D':
            num *= num;
            break;
        case 'T':
            num = num * num * num;
            break;
        }
        if (i + 1 < dartResult.size()) {
            if (dartResult[i + 1] == '*') {
                answer += backnum;
                num *= 2;
                i++;
            }
            else if (dartResult[i + 1] == '#') {
                num *= -1;
                i++;
            }
        }
        answer += num;
        cout << "num : " << num << endl;
        backnum = num;
    }
    return answer;
}