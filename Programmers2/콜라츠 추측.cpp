#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    while (num != 1 && answer < 500) {
        if (num % 2 == 1) {//Ȧ��
            num = num * 3 + 1;
        }
        else { //¦��
            num /= 2;
        }
        answer++;
    }
    if (answer == 500) return -1;
    return answer;
}

//https://programmers.co.kr/learn/courses/30/lessons/12943