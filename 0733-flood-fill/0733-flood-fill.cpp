class Solution {
private:
    void dfs(int i, int j, vector<vector<int>>& image,int originalColor,
         int newColor){
        //base case
        if(i < 0 || j< 0 || i >= image.size() || j >= image[0].size()){
            return;
        }

        if(image[i][j] != originalColor){
            return;
        }

        //visted
        image[i][j] = newColor;

        //visit neighbours
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for(int k =0; k<4; k++){
            dfs(i + dr[k], j + dc[k], image, originalColor,
    newColor);
        }

    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if (originalColor == color)
            return image;
        
        dfs(sr, sc, image, originalColor, color);

        return image;

    }

        
};