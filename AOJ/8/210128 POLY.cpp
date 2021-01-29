#include <iostream>
#include <cstring> // memset
using namespace std;

int C;
int cache[101][101];

int numPolyominoWithConstraint(int n, int bottommost_squares) {
    int& ret = cache[n][bottommost_squares];
    if(ret != -1) return ret;
    ret = 0;
    if(n == bottommost_squares) return ret = 1;
    if(bottommost_squares == 0) return ret = 0;
    for(int i = 1; i <= n - bottommost_squares; ++i) {
        ret = (ret + (bottommost_squares + i - 1) * numPolyominoWithConstraint(n - bottommost_squares, i)) % 10000000;
    }
    return ret;
}

int numPolyomino(int n) {
    int result = 0;
    for(int i = 1; i <= n; ++i) {
        result = (result + numPolyominoWithConstraint(n, i)) % 10000000;
    }
    return result;
}

int main(void) {
    cin >> C;
    memset(cache, -1, sizeof(cache));
    while(C--) {
        int n;
        cin >> n;
        cout << numPolyomino(n) << endl;
    }
    return 0;
}