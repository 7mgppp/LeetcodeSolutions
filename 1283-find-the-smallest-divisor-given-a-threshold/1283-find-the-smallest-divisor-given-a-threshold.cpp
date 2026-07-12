class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {

        int maxi = INT_MIN;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
        }

        int low = 1;
        int high = maxi;

        while (low <= high) {
            int mid = (low + high) / 2;
            int sum = 0;

            for (int i = 0; i < nums.size(); i++) {
                int addend = ceil((double)nums[i] / mid);
                sum += addend;
            }

            if (sum <= threshold) {
                ans = mid;
                high = mid - 1;
            }

            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};