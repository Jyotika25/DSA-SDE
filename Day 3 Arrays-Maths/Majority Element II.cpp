// brute approach 
//tc : O(NlogN)
//sc : O(N)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<int> result;
       
        for(auto it : m){
            if(it.second > floor(nums.size()/3))
                result.push_back(it.first);
        }
    return result;
    }
};


//optimised approach : moore Voting Algo extension
//tc: O(N) + O(N)
//sc : O(1)


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = -1,num2 =-1,c1=0,c2=0;
        
        for(int i=0;i<nums.size();i++){
            if(num1 == nums[i]) c1++;
            else if(num2 == nums[i])    c2++;
            else if(c1==0){
                num1 = nums[i];
                c1 = 1;
            }
            else if(c2==0){
                num2 = nums[i];
                c2 = 1;
            }
            else{
                c1--;
                c2--;
            }
        }
        
        vector<int> ans;
        c1=0;
        c2=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] == num1) c1++;
            else if(nums[i] == num2)    c2++;
        }
        
        if(c1>nums.size()/3)
            ans.push_back(num1);
        if(c2>nums.size()/3)
            ans.push_back(num2);
        
        return ans;   
        
    }
};
