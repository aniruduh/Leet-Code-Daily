#include <vector>
#include <algorithm>
using namespace std;

int maximumDifference(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return -1;

    int min_value = nums[0];
    int max_diff = -1;

    for (int j = 1; j < n; ++j) {
        if (nums[j] > min_value) {
            max_diff = max(max_diff, nums[j] - min_value);
        } else {
            min_value = min(min_value, nums[j]);
        }
    }

    return max_diff;
}
