#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int right, left; 
    right = -2; left = -1;
    unordered_map<int, pair<int, int>> site;
    for (int i = 0; i < 3; i++) {
        for (int k = 1; k < 4; k++) {
            site[(3 * i) + k] = { i,k - 1 };
        }
    }
    site[-1] = { 3,0};
    site[-2] = { 3,2 };
    site[0] = { 3,1 };
    for (int num : numbers) {
        switch (num) {
        case 1: case 4: case 7:
            answer += "L";
            left = num;
            break;
        case 3 : case 6 : case 9 :
            answer += 'R';
            right = num;
            break;
        default:
            pair<int, int> go = site.find(num)->second;
            int lenLeft = max(site.find(left)->second.first,go.first) - min(site.find(left)->second.first,go.first);
            lenLeft += max(site.find(left)->second.second, go.second) - min(site.find(left)->second.second, go.second);
            int lenRight = max(site.find(right)->second.first, go.first) - min(site.find(right)->second.first, go.first);
            lenRight += max(site.find(right)->second.second, go.second) - min(site.find(right)->second.second, go.second);
            if (lenLeft == lenRight) {
                if (hand == "right") {
                    answer += "R";
                    right = num;
                }
                else {
                    answer += "L";
                    left = num;
                }
            }
            else if (lenLeft < lenRight) {
                answer += "L";
                left = num;
            }
            else {
                answer += "R";
                right = num;
            }
            break;
        }
    }

    return answer;
}