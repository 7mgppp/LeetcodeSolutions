class Solution {
private:
    void dfs(int i, int j, vector<vector<char>>& grid){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()){
            return;
        }
        if(grid[i][j] == '0'){
            return;
        }

        //mark as visited;
        grid[i][j] = '0';

        //visit neighbours
        int dr[] = {0 ,0, -1, 1};
        int dc[] = {-1, 1, 0, 0};
        for(int k =0; k<4; k++){
            dfs(i + dr[k], j + dc[k], grid);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i =0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    dfs(i, j, grid);
                    count++;
                }
            }
            
            
        }
        return count;


        
    }
};