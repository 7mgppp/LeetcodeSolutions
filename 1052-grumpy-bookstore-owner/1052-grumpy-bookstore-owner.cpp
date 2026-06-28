class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        int left = 0;
        int count = 0;
        int satisfied = 0;

        for (int i = 0; i < customers.size(); i++) {
            if (grumpy[i] == 0)
                satisfied += customers[i];
        }

        for(int i = 0; i<minutes; i++){
            if(grumpy[i] == 1){
                count+=customers[i];
            }
        }

        int maxi = count;

        for(int i = minutes; i< customers.size(); i++){
            if(grumpy[left] == 1){
            count -= customers[left];
            }
            left++;
            if(grumpy[i] == 1){
                count+=customers[i];
            }

            maxi = max(maxi, count);

        }

        maxi = max(maxi, count);

        return  satisfied + maxi;
        
    }
};