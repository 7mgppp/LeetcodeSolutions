class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count = 0;
        int maxi = 0;
        for(int i =0; i<grid.size(); i++){
            for(int j = 0; j<grid[i].size(); j++){
                if(grid[i][j] == 1){
                    count = 1;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    grid[i][j] = 0;

                    while(!q.empty()){
                        pair<int, int> node = q.front();
                        q.pop();
                        int r = node.first;
                        int c = node.second;

                        int dr[] = {1, -1, 0, 0};
                        int dc[] = {0, 0, -1, 1};

                        for(int k = 0; k<4; k++){
                    
                            int newRow = r + dr[k];
                            int newCol = c + dc[k];

                            if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() && grid[newRow][newCol] == 1){
                                q.push({newRow,newCol});
                                grid[newRow][newCol] = 0;
                                count++;
                            }
                        }
                    }
                    maxi = max(count, maxi);

                }

            }
        }
        
        return maxi;
        
    }
};