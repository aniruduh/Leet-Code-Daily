#include <vector>
using namespace std;

vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    // Check if it's possible to construct the 2D array
    if (original.size() != m * n) {
        return {};
    }
    
    // Create the 2D array
    vector<vector<int>> result(m, vector<int>(n));
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = original[i * n + j];
        }
    }
    
    return result;
}