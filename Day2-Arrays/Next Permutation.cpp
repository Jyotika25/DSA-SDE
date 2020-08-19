class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int k,l;
        
        //step 1 : find index nums[i]<nums[i+1]
        for(k = n-2;k>=0;k--){
            if(nums[k]<nums[k+1])
                break;
        }
        //step 2 if thats last permutation simply reverse
        if(k<0){
            reverse(nums.begin(),nums.end());
        }
        //step 3 else:  find index nums[i] > nums[k]
        else{
            for(l=n-1;l>k;l--){
                if(nums[l]>nums[k])
                    break;
            }
            //step 4 swap those indexes
            swap(nums[l],nums[k]);
            //step 5 reverse all digits right of k to end
            reverse(nums.begin()+k+1,nums.end());
        }
        
    }
};
