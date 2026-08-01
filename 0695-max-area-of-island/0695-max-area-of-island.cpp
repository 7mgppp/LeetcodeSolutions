class Solution {
private:
    int dfs(int i, int j, vector<vector<int>>& grid) {

        int area = 1;
        // base condition
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return 0;
        }

        if (grid[i][j] == 0) {
            return 0;
        }

        // mark visited
        grid[i][j] = 0;

        // vist neighbours
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            area += dfs(i + dr[k], j + dc[k], grid);
        }

        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    maxi = max(maxi, dfs(i, j, grid));
                }
            }
        }

        return maxi;
    }
};