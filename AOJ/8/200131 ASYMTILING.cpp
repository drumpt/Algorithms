#include <iostream>
#include <vector>
using namespace std;

vector<int> num_tiles(101, 0);
vector<int> n(50, 0);
int C;

// use memoization for avoiding redundant calculation
int get_num_tiles(int n) {
    if (n <= 2) return n;
    else if (num_tiles.at(n) == 0) {
        num_tiles[n] = (get_num_tiles(n - 1) + get_num_tiles(n - 2)) % 1000000007;
        return num_tiles[n];
    } else return num_tiles[n];
}

int modulo(int value, unsigned int m) {
    int mod = value % (int) m;
    if (value < 0) {
        mod += m;
    } return mod;
}

int main(void) {
    cin >> C;
    for (int i = 0; i < C; i++) {
        cin >> n[i];
    }
    for (int i = 0; i < C; i++) {
        if (n[i] <= 2) cout << 0 << endl;
        else if (n[i] % 2 == 0) {
            cout << modulo(get_num_tiles(n[i]) - get_num_tiles(n[i] / 2) - get_num_tiles(n[i] / 2 - 1), 1000000007) << endl;
        } else cout << modulo(get_num_tiles(n[i]) - get_num_tiles((n[i] - 1) / 2), 1000000007) << endl;
    }
    return 0;
}
