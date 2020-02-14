#include <iostream>
#include <vector>
using namespace std;

vector<int> A(1001, 0);
int n;

void calculate(int n) {
    if (n <= 1) {
        A[n] = 1;
    } else {
        int result = 1;
        while (true) {
            bool is_possible = true;
            for (int i = 1 ; i <= n / 2; i++) {
                if (A[n - 2 * i] == 0) calculate(n - 2 * i);
                if (A[n - i] == 0) calculate(n - i);
                if (result + A[n - 2 * i] == 2 * A[n - i]) {
                    is_possible = false;
                    break;
                }
            }
            if (is_possible == true) {
                A[n] = result;
                break;
            } else {
                result += 1;
                continue;
            }
        }
    }
}

int main(void) {
    cin >> n;
    calculate(n);
    cout << A[n] << endl;
    return 0;
}