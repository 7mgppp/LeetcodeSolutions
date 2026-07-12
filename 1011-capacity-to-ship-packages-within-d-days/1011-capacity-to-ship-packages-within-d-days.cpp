class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int max_load = 0;
        int ans = -1;
        for (int i = 0; i < weights.size(); i++) {
            max_load += weights[i];
        }

        int maxi = INT_MIN;
        for (int i = 0; i < weights.size(); i++) {
            maxi = max(maxi, weights[i]);
        }

        int low = maxi;
        int high = max_load;

        while (low <= high) {
            int mid = (low + high) / 2;
            int DaysR = 1;
            int currLoad = 0;
            for (int i = 0; i < weights.size(); i++) {
                if (currLoad + weights[i] > mid) {
                    DaysR++;
                    currLoad = weights[i];
                } else {
                    currLoad += weights[i];
                }
            }

            if (DaysR <= days) {
                high = mid - 1;
                ans = mid;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};