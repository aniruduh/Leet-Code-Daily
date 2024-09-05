#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    int m = rolls.size();
    int total_sum = mean * (n + m); 
    int observed_sum = accumulate(rolls.begin(), rolls.end(), 0);  
    int missing_sum = total_sum - observed_sum;  
    
    // Check if it's possible to achieve the missing sum
    if (missing_sum < n || missing_sum > 6 * n) {
        return {};  
    }
    vector<int> result(n, 1); 
    missing_sum -= n; 

    for (int i = 0; i < n && missing_sum > 0; ++i) {
        int add = min(5, missing_sum);  
        result[i] += add;
        missing_sum -= add;
    }
    return result;
}

int main() {
    vector<int> rolls = {3, 2, 4, 3};
    int mean = 4;
    int n = 2;

    vector<int> missing = missingRolls(rolls, mean, n);
    for (int x : missing) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
