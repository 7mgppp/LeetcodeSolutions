class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi = 0;
        int l = 0;
        int r = height.size() - 1;

        while (l < r) {
            int area = min(height[l], height[r]) * (r - l);
            maxi = max(maxi, area);

            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return maxi;
    }
};