#include <string>
#include <vector>
#include <map>

using namespace std;

bool check_right(vector<string> board, pair<int, int> n1, pair<int, int>n2, char c) { // 열을 오른쪽으로 이동
    for (int x = n1.second + 1; x <= n2.second; x++) { //열
        if (board[n1.first][x] != '.' && board[n1.first][x] != c) { //비어있지 않으면
            return false;
        }
    }
    return true;
}

bool check_down(vector<string> board, pair<int, int> n1, pair<int, int>n2, char c) {//행을 아래로 이동
    for (int y = n1.first + 1; y <= n2.first; y++) { //행
        if (board[y][n1.second] != '.' && board[y][n1.second] != c) //비어있지 않으면
            return false;
    }
    return true;
}

bool check_up(vector<string> board, pair<int, int> n1, pair<int, int>n2, char c) {//행을 위로 이동
    for (int y = n1.first - 1; y >= n2.first; y--) { //행
        if (board[y][n1.second] != '.' && board[y][n1.second] != c) //비어있지 않으면
            return false;
    }
    return true;
}

bool arrange(vector<string> board, pair<int, int> n1, pair<int, int>n2, char c) { //분류
    if (n1.second > n2.second) { //아래에 있는 타일이 위에 있는 타일보다 앞쪽 열에 있는 경우
        //첫번째 경우의 수: 오른쪽->위
        if (check_right(board, n2, { n2.first,n1.second }, c))
            if (check_up(board, { n2.first,n1.second }, n1, c))
                return true;
        //두번째 경우의 수 : 위->오른쪽
        if (check_up(board, n2, { n1.first,n2.second }, c))
            if (check_right(board, { n1.first,n2.second }, n1, c))
                return true;
    }
    else {
        //첫번째 경우의 수 : 오른쪽 -> 아래
        if (check_right(board, n1, { n1.first,n2.second }, c)) {
            if (check_down(board, { n1.first,n2.second }, n2, c)) {
                return true;
            }
        }
        //두번째 경우의 수 : 아래 -> 오른쪽
        if (check_down(board, n1, { n2.first,n1.second }, c))
            if (check_right(board, { n2.first,n1.second }, n2, c))
                return true;
    }
    return false;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(int m, int n, vector<string> board) { //m : 행 n: 열
    string answer = "";
    map<char, vector<pair<int, int>>> mTileIndexs;
    for (int k = 0; k < m; k++) { //각 타일 위치 저장
        string str = board[k];
        for (int i = 0; i < n; i++) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                mTileIndexs[str[i]].push_back({ k,i });
            }
        }
    }
    while (!mTileIndexs.empty()) {
        string tmp;
        for (auto it = mTileIndexs.begin(); it != mTileIndexs.end(); it++) {
            pair<int, int> n1, n2;
            n1 = it->second[0]; n2 = it->second[1];
            if (arrange(board, n1, n2, it->first)) { // 연결이 가능한 경우
                tmp += it->first;
                board[n1.first][n1.second] = '.';
                board[n2.first][n2.second] = '.';
                mTileIndexs.erase(it->first);
                break;
            }
        }
        if (tmp.empty()) return "IMPOSSIBLE";
        else {
            answer += tmp;
        }
    }

    return answer;
}