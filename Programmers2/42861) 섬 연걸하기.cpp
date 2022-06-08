#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int parent[101];
bool comp(vector<int> n1, vector<int> n2) {
    if (n1[2] == n2[2]) {
        return n1[0] < n2[0];
    }
    return n1[2] < n2[2];
}

int getParent(int n) {
    if (parent[n] == n) {
        return n;
    }
    else {
        return getParent(parent[n]);
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for (int i = 0; i < 101; i++) {
        parent[i] = i;
    }
    sort(costs.begin(), costs.end(),comp);
    for (vector<int> c : costs) {
        int p1 = getParent(c[0]);
        int p2 = getParent(c[1]);
        if (p1 != p2) {
            answer += c[2];
            if (p1 < p2) {
                parent[p2] = p1;
            }
            else {
                parent[p1] = p2;
            }
        }
    }
    return answer;
}