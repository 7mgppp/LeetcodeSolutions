class Solution {
    
    int dfs(int i, int j, vector<vector<int>>& grid) {
        int area = 1;
        // base condition
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return 0;
        }
        if (grid[i][j] == 0) {
            return 0;
        }

        // visied
        grid[i][j] = 0;

        int dr[] = {0, 0, -1, 1};
        int dc[] = {-1, 1, 0, 0};
        for (int k = 0; k < 4; k++) {
            area+= dfs(i + dr[k], j + dc[k], grid);
        }

        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi = 0;
        for(int i =0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                   int currArea = dfs(i, j, grid);
                    maxi = max(maxi, currArea);
                }
            }
        }

        return maxi;

    }
};