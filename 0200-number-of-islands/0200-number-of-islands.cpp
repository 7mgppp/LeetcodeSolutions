class Solution {

public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    count++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = '0';

                    while (!q.empty()) {
                        pair<int, int> node = q.front();
                        q.pop();

                        int r = node.first;
                        int c = node.second;

                        int dr[] = {1, -1, 0, 0};
                        int dc[] = {0, 0, -1, 1};

                        for (int k = 0; k < 4; k++) {
                            int newrow = r + dr[k];
                            int newcol = c + dc[k];

                            if (newrow >= 0 && newrow < grid.size() &&
                                newcol >= 0 && newcol < grid[0].size() &&
                                grid[newrow][newcol] == '1') {
                                grid[newrow][newcol] = '0';
                                q.push({newrow, newcol});
                            }
                        }
                    }

                }
            }
        }

        return count;
    }
};