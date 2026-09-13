class Solution {
private:
    void bfs(vector<vector<char>>& board, int r, int c) {
        queue<pair<int, int>> q;
        q.push({r, c});

        board[r][c] = 'S';

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            auto [row, col] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {

                int nr = row + dr[k];
                int nc = col + dc[k];

                if (nr >= 0 && nr < board.size() && nc >= 0 &&
                    nc < board[0].size() && board[nr][nc] == 'O') {

                    board[nr][nc] = 'S';
                    q.push({nr, nc});
                }
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if((i == 0 || j == 0|| i == board.size()-1 || j == board[0].size()-1) && board[i][j]=='O'){
                    bfs(board, i, j);
                }
            }
        }

        for(int i =0; i<board.size(); i++){
            for(int j =0; j<board[0].size(); j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }

                else if(board[i][j] == 'S'){
                    board[i][j] = 'O';
                }
            }
        }

        
    }
};