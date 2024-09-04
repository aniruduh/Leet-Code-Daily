class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int x = 0, y = 0, dir = 0; 
    int maxDistSq = 0;

    unordered_set<string> obstacleSet;
    for (const auto& obstacle : obstacles) {
        obstacleSet.insert(to_string(obstacle[0]) + "," + to_string(obstacle[1]));
    }
    for (int cmd : commands) {
        if (cmd == -2) {
            dir = (dir + 3) % 4; 
        } else if (cmd == -1) {
            dir = (dir + 1) % 4;
        } else {
            for (int i = 0; i < cmd; ++i) {
                int nextX = x + directions[dir].first;
                int nextY = y + directions[dir].second;
                string nextPos = to_string(nextX) + "," + to_string(nextY);
                if (obstacleSet.find(nextPos) == obstacleSet.end()) {
                    x = nextX;
                    y = nextY;
                    maxDistSq = max(maxDistSq, x * x + y * y);
                } else {
                    break;
                }
            }
        }
    }
    return maxDistSq;
    }
};