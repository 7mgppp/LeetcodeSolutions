class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        vector<vector<int>> dist(mat.size(), vector<int>(mat[0].size(), -1));
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        int dr[] = {0, 0, -1, 1};
        int dc[] = {1, -1, 0, 0};

        while (!q.empty()) {
            pair<int, int> node = q.front();
            q.pop();
            int r = node.first;
            int c = node.second;

            for (int k = 0; k < 4; k++) {
                int newRow = r + dr[k];
                int newCol = c + dc[k];

                if (newRow >= 0 && newRow < mat.size() && newCol >= 0 &&
                    newCol < mat[0].size() && dist[newRow][newCol] == -1) {
                    q.push({newRow, newCol});
                    dist[newRow][newCol] = dist[r][c] + 1;
                }
            }
        }
        return dist;
    }
};