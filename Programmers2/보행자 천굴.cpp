#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    int dp[600][600] = { 0 };
    dp[1][1] = 1;
    for (int i = 1; i <= m; i++) {
        for (int k = 1; k <= n; k++) {
            if (city_map[i - 1][k - 1] == 1) {
                dp[i][k] = 0;
            }
            else if (city_map[i - 1][k - 1] == 0) {
                dp[i][k] += dp[i - 1][k];
                dp[i][k] += dp[i][k - 1];
            }
            else {
                int go;
                for (go = i + 1; go <= m; go++) {
                    if (city_map[go - 1][k - 1] == 1) break;
                    else if (city_map[go - 1][k - 1] == 0) {
                        dp[go][k] += dp[i - 1][k];
                        break;
                    }
                }
                for (go = k + 1; go <= n; go++) {
                    if (city_map[i - 1][go - 1] == 1) break;
                    else if (city_map[i - 1][go - 1] == 0) {
                        dp[i][go] += dp[i][k - 1];
                        break;
                    }
                }
                dp[i][k] = 0;
            }
            dp[i][k] %= MOD;
        }
    }
    return dp[m][n];
}