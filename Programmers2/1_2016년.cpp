#include <string>
#include <vector>

using namespace std;

int month[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
string day[] = { "FRI","SAT","SUN","MON","TUE","WED","THU"};
string solution(int a, int b) {
    string answer = "";
    int date = 0;
    for (int i = 0; i < a - 1; i++) {
        date += month[i];
    }
    date += b;
    return day[(date-1)%7];
}