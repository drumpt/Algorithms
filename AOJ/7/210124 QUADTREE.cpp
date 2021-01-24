#include <iostream>
#include <string>
using namespace std;

int C;
string s;
char decompressed[MAX_SIZE][MAX_SIZE]

string verticalFlip(string::iterator& it) {
    char head = *it;
    ++it;
    if (head == 'b' || head == 'w') return string(1, head);
    string upperLeft = verticalFlip(it);
    string upperRight = verticalFlip(it);
    string lowerLeft = verticalFlip(it);
    string lowerRight = verticalFlip(it);
    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main(void) {
    cin >> C;
    for (int i = 0; i < C; ++i) {
        cin >> s;
        string::iterator it = s.begin();
        cout << verticalFlip(it) << endl;
    }
    return 0;
}