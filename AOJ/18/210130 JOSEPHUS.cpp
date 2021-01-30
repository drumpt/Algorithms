#include <iostream>
#include <list>
using namespace std;

int C, N, K;

void josephus(int n, int k) {
    list<int> soldiers;
    for(int i = 1; i <= n; ++i) {
        soldiers.push_back(i);
    }
    list<int>::iterator soldier_to_suicide = soldiers.begin();
    while(n > 2) {
        soldier_to_suicide = soldiers.erase(soldier_to_suicide);
        if(soldier_to_suicide == soldiers.end()) soldier_to_suicide = soldiers.begin();
        for(int i = 0; i < k - 1; ++i) {
            soldier_to_suicide++;
            if(soldier_to_suicide == soldiers.end()) soldier_to_suicide = soldiers.begin();
        }
        --n;
    }
    cout << soldiers.front() << " " << soldiers.back() << endl;
}

int main(void) {
    cin >> C;
    while(C--) {
        cin >> N >> K;
        josephus(N, K);
    }
    return 0;
}