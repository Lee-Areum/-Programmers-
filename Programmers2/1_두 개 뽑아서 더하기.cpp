#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> sum;
    for (int i = 0; i < numbers.size(); i++) {
        for (int k = i+1; k < numbers.size(); k++) {
            sum.insert(numbers[i] + numbers[k]);
        }
    }
    for (auto it = sum.begin(); it != sum.end(); it++) {
        answer.push_back(*it);
    }
    return answer;
}