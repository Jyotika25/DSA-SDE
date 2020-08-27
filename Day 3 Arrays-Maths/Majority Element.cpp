//Better approach
//tc: O(NlogN)
//sc: O(N)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        
        unordered_map <int ,int> map;
        
        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }
        
        for(int i=0;i<n;i++){
            if(map[nums[i]] > floor(n/2))
                return nums[i];
        }
        return -1;
        }
};


//Optimal Approach
//Moose Votimg algorithm
//tc: O(N)
//sc : O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
       int count =0;
    int candidate = 0;
    
        for(int num : nums){
            if(count == 0)
                candidate = num;
            if(num == candidate)
                count++;
            else
                count--;
        }
        
      return candidate;
        }
};
