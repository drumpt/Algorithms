#include <iostream>
#include <string>
#include <vector>
using namespace std;

int C;
int dx1[4] = {0, 1, 0, 1}; // x : down, y : right
int dy1[4] = {1, 0, 1, -1};
int dx2[4] = {1, 1, 1, 1};
int dy2[4] = {1, 1, 0, 0};

vector<string> gameboard;

bool isCoverable(int x, int y) {
    if (x < 0 || x >= gameboard.size() || y < 0 || y >= gameboard[0].size()) return false;
    return gameboard[x][y] == '.';
}

int numCover(vector<string>& s) {
    int startX = -1, startY = -1;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < s[0].size(); ++j) {
            if (s[i][j] == '.') {
                startX = i;
                startY = j;
                break;
            }
        }
        if (startX != -1) break;
    }
    if (startX == -1) return 1;
    int result = 0;
    for (int i = 0; i < 4; ++i) {
        if (isCoverable(startX, startY) && isCoverable(startX + dx1[i], startY + dy1[i]) && isCoverable(startX + dx2[i], startY + dy2[i])) {
            s[startX][startY] = s[startX + dx1[i]][startY + dy1[i]] = s[startX + dx2[i]][startY + dy2[i]] = '#';
            result += numCover(s);
            s[startX][startY] = s[startX + dx1[i]][startY + dy1[i]] = s[startX + dx2[i]][startY + dy2[i]] = '.';
        }
    }
    return result;
}

int main(void) {
    cin >> C;
    for (int H, W, c = 0; c < C; ++c) {
        cin >> H >> W;
        gameboard = vector<string>();
        for (int i = 0; i < H; ++i) {
            string row;
            cin >> row;
            gameboard.push_back(row);
        }
        cout << numCover(gameboard) << endl;
    }
    return 0;
}