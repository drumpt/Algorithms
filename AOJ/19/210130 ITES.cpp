#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int C, N, K;
struct RNG {
    unsigned int signal;
    RNG() : signal(1983u) {}
    unsigned next() {
        unsigned int out = signal % 10000u + 1;
        signal = signal * 214013u + 2531011u;
        return out;
    }
};

int numPartialSum(int N, int K) {
    deque<int> context;
    RNG rng;
    int sum = 0, result = 0;
    for(int i = 0; i < N; ++i) {
        auto signal = rng.next();
        context.push_back(signal);
        sum += signal;
        while(sum > K && !context.empty()) {
            sum -= context.front();
            context.pop_front();
        }
        if(sum == K) result++;
    }
    return result;
}

int main(void) {
    cin >> C;
    while(C--) {
        cin >> K >> N;
        cout << numPartialSum(N, K) << endl;
    }
    return 0;
}