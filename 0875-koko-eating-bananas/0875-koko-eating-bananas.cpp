class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for (int i = 0; i < piles.size(); i++) {
            maxi = max(maxi, piles[i]);
            mini = min(mini, piles[i]);
        }
        long long int bananas = 0;

        long long int low = 1;
        long long int high = maxi;

        while (low <= high) {
            long long int mid = (low + high) / 2;
            long long int hrs = 0;
            for (int i = 0; i < piles.size(); i++) {
                hrs += ceil(double(piles[i]) / mid);
            }

            if (hrs <= h) {
                bananas = mid;
                high = mid - 1;
            }

            else {
                low = mid + 1;
            }
        }

        return bananas;
    }
};