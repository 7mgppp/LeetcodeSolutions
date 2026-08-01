class Solution {
private:
    void dfs(int i, int j, vector<vector<char>>& grid) {
        // define the base case
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return;
        }
        if (grid[i][j] == '0') {
            return;
        }

        // mark visited
        grid[i][j] = '0';

        // visit the neighbours
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {
            dfs(i + dr[k], j + dc[k], grid);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {

        int count = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(i, j, grid);
                }
            }
        }
        return count;
    }
};