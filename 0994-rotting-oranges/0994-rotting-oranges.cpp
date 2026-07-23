class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int min = 0;
        int fresh = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> node = q.front();
                q.pop();

                int r = node.first;
                int c = node.second;

                int dr[] = {0, 0, -1, 1};
                int dc[] = {1, -1, 0, 0};

                for (int k = 0; k < 4; k++) {
                    int newRow = r + dr[k];
                    int newCol = c + dc[k];

                    if (newRow >= 0 && newRow < grid.size() && newCol >= 0 &&
                        newCol < grid[0].size() && grid[newRow][newCol] == 1) {
                        q.push({newRow, newCol});
                        grid[newRow][newCol] = 2;
                        fresh--;
                    }
                }
            }
            if (!q.empty())
                min++;
        }
        if (fresh == 0)
            return min;
        return -1;
    }
};
