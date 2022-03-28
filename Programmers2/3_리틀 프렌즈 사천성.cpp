#include <string>
#include <vector>
#include <map>

using namespace std;

bool check_right(vector<string> board, pair<int, int> n1, pair<int, int>n2, char c) { // ���� ���������� �̵�
    for (int x = n1.second + 1; x <= n2.second; x++) { //��
        if (board[n1.first][x] != '.' && board[n1.first][x] != c) { //������� ������
            return false;
        }
    }
    return true;
}

bool check_down(vector<string> board, pair<int, int> n1, pair<int, int>n2, char c) {//���� �Ʒ��� �̵�
    for (int y = n1.first + 1; y <= n2.first; y++) { //��
        if (board[y][n1.second] != '.' && board[y][n1.second] != c) //������� ������
            return false;
    }
    return true;
}

bool check_up(vector<string> board, pair<int, int> n1, pair<int, int>n2, char c) {//���� ���� �̵�
    for (int y = n1.first - 1; y >= n2.first; y--) { //��
        if (board[y][n1.second] != '.' && board[y][n1.second] != c) //������� ������
            return false;
    }
    return true;
}

bool arrange(vector<string> board, pair<int, int> n1, pair<int, int>n2, char c) { //�з�
    if (n1.second > n2.second) { //�Ʒ��� �ִ� Ÿ���� ���� �ִ� Ÿ�Ϻ��� ���� ���� �ִ� ���
        //ù��° ����� ��: ������->��
        if (check_right(board, n2, { n2.first,n1.second }, c))
            if (check_up(board, { n2.first,n1.second }, n1, c))
                return true;
        //�ι�° ����� �� : ��->������
        if (check_up(board, n2, { n1.first,n2.second }, c))
            if (check_right(board, { n1.first,n2.second }, n1, c))
                return true;
    }
    else {
        //ù��° ����� �� : ������ -> �Ʒ�
        if (check_right(board, n1, { n1.first,n2.second }, c)) {
            if (check_down(board, { n1.first,n2.second }, n2, c)) {
                return true;
            }
        }
        //�ι�° ����� �� : �Ʒ� -> ������
        if (check_down(board, n1, { n2.first,n1.second }, c))
            if (check_right(board, { n2.first,n1.second }, n2, c))
                return true;
    }
    return false;
}

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
string solution(int m, int n, vector<string> board) { //m : �� n: ��
    string answer = "";
    map<char, vector<pair<int, int>>> mTileIndexs;
    for (int k = 0; k < m; k++) { //�� Ÿ�� ��ġ ����
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
            if (arrange(board, n1, n2, it->first)) { // ������ ������ ���
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