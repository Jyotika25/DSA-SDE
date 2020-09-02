class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector <int> output;
        int size = nums.size();
        int diff;
        unordered_map <int,int> m;
        
        for(int i=0;i<size;i++){
        diff = target-nums[i];
            if(m.find(diff)!=m.end() && m.find(diff)->second!=i)
            {
                output.push_back(m.find(diff)->second);
                output.push_back(i);
               
                return output;
            }
            m[nums[i]]=i;
        }
        return output;
    }
};
