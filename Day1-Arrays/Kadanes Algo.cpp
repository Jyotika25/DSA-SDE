//Time Complexity o(n)
//Space Complexity o(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int maxsum = INT_MIN;
        int currentsum = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            currentsum +=nums[i];
            maxsum = max(currentsum,maxsum);
            if(currentsum < 0)
                currentsum = 0;
        }
        return maxsum;
    }
};
