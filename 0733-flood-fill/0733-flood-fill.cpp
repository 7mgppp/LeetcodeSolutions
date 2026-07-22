class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {

        int originalColor = image[sr][sc];

        if (originalColor == color) {
            return image;
        }

        queue<pair<int, int>> q;
        q.push({sr, sc});

        image[sr][sc] = color;

        while (!q.empty()) {
            pair<int, int> node = q.front();
            q.pop();

            int r = node.first;
            int c = node.second;

            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};

            for (int i = 0; i < 4; i++) {
                int NewRow = r + dr[i];
                int NewCol = c + dc[i];

                if (NewRow >= 0 && NewRow < image.size() && NewCol >= 0 && NewCol < image[0].size() &&image[NewRow][NewCol] == originalColor) {
                    image[NewRow][NewCol] = color;
                    q.push({NewRow, NewCol});
                }
            }
        }

        return image;
    }
};