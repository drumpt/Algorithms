#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

const int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
const int dy[9] = {-1, 0, 1, -1, 0, 1, -1, 1};
string board[5];
int cache [11][5][5];
int C, N;

bool findWord(const string& s, int x, int y) {
    if (x < 0 || y < 0 || x > 4 || y > 4) return false;
    if (board[x][y] != s[0]) return false;
    if (s.length() == 1) return true;
    if (cache[s.length()][x][y] == 1) return true;
    else if (cache[s.length()][x][y] == -1) return false;
    bool flag = false;
    for (int i = 0; i < 8; ++i) {
        if (s[0] == board[x][y] && findWord(s.substr(1), x + dx[i], y + dy[i])) {
            flag = true;
        }
    }
    cache[s.length()][x][y] = (flag == true ? 1 : -1);
    return flag;
}

int main(void) {
    cin >> C;
    while (C > 0) { // test cases
        for (int i = 0; i < 5; ++i) {
            cin >> board[i];
        }
        cin >> N;
        vector<string> s;
        for (int i = 0; i < N; ++i) { // words in this board
            string row;
            cin >> row;
            s.push_back(row);
        }
        for (int i = 0; i < N; ++i) {
            memset(cache, 0, sizeof(int) * 11 * 5 * 5);
            bool flag = false;
            for (int x = 0; x < 5; ++x) {
                for (int y = 0; y < 5; ++y) {
                    if (findWord(s[i], x, y)) {
                        flag = true;
                        break;
                    }
                }
                if (flag) break;
            }
            cout << s[i] << " " << (flag ? "YES" : "NO") << endl;
        }
        C--;
    }
    return 0;
}