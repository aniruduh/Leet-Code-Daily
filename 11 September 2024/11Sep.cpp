#include<bitset>
#include<iostream>
using namespace std;

class Solution {

public:
    int minBitFlips(int start, int goal) {
        return __builtin_popcount(start ^ goal);
    }


int main() {
    int start = 2, goal = 3;
    cout << minBitFlips(start, goal) << endl;
    return 0;
}
};