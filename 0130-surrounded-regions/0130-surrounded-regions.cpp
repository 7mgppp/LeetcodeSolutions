class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0)); 

        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O' && visited[0][j] == 0) { 
                q.push({0, j});
                visited[0][j] = 1;
            }
            
            if (board[n - 1][j] == 'O' && visited[n - 1][j] == 0) {
                q.push({n - 1, j});
                visited[n - 1][j] = 1;
            }
        }

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && visited[i][0] == 0) {
                q.push({i, 0});
                visited[i][0] = 1;
            }
            
            if (board[i][m - 1] == 'O' && visited[i][m - 1] == 0) {
                q.push({i, m - 1});
                visited[i][m - 1] = 1;
            }
        }

        //BFS

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = r + dr[i];
                int ncol = c + dc[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && board[nrow][ncol] == 'O' && visited[nrow][ncol] == 0) {
                    visited[nrow][ncol] = 1; 
                    q.push({nrow, ncol});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'O' && visited[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
