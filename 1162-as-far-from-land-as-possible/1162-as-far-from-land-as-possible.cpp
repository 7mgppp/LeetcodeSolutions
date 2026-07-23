class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int dist = -1;
        int land = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    land++;
                }
            }
        }

        if (land == 0 || land == grid.size() * grid[0].size())
            return -1;

        int dr[] = {0, 0, -1, 1};
        int dc[] = {1, -1, 0, 0};

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> node = q.front();
                q.pop();
                int r = node.first;
                int c = node.second;

                for (int k = 0; k < 4; k++) {
                    int newRow = r + dr[k];
                    int newCol = c + dc[k];

                    if (newRow >= 0 && newRow < grid.size() && newCol >= 0 &&
                        newCol < grid[0].size() && grid[newRow][newCol] == 0) {
                        q.push({newRow, newCol});
                        grid[newRow][newCol] = 1;
                    }
                }
            }
            dist++;
        }
        return dist;
    }
};