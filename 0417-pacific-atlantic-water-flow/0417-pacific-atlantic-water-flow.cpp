class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        queue<pair<int, int>> paci;
        queue<pair<int, int>> atlant;
        vector<vector<bool>> paciVis(heights.size(),
                                     vector<bool>(heights[0].size(), false));
        vector<vector<bool>> atlantVis(heights.size(),
                                       vector<bool>(heights[0].size(), false));
        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[i].size(); j++) {
                if (i == 0 || j == 0) {
                    paci.push({i, j});
                    paciVis[i][j] = true;
                }
                if (i == heights.size() - 1 || j == heights[0].size() - 1) {
                    atlant.push({i, j});
                    atlantVis[i][j] = true;
                }
            }
        }

        while (!paci.empty()) {
            pair<int, int> node1 = paci.front();
            paci.pop();

            int r = node1.first;
            int c = node1.second;

            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};

            for (int k = 0; k < 4; k++) {
                int newRow = r + dr[k];
                int newCol = c + dc[k];

                if (newRow >= 0 && newRow < heights.size() && newCol >= 0 &&
                    newCol < heights[0].size() && !paciVis[newRow][newCol] &&
                    heights[newRow][newCol] >= heights[r][c]) {
                    paciVis[newRow][newCol] = true;
                    paci.push({newRow, newCol});
                }
            }
        }

        while (!atlant.empty()) {
            pair<int, int> node2 = atlant.front();
            atlant.pop();

            int r = node2.first;
            int c = node2.second;

            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};

            for (int k = 0; k < 4; k++) {
                int newRow = r + dr[k];
                int newCol = c + dc[k];

                if (newRow >= 0 && newRow < heights.size() && newCol >= 0 &&
                    newCol < heights[0].size() && !atlantVis[newRow][newCol] &&
                    heights[newRow][newCol] >= heights[r][c]) {

                    atlantVis[newRow][newCol] = true;
                    atlant.push({newRow, newCol});
                }
            }
        }

        vector<vector<int>> ans;

        for(int i =0; i<heights.size(); i++){
            for(int j = 0; j<heights[0].size(); j++){
                if(paciVis[i][j] && atlantVis[i][j]){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};