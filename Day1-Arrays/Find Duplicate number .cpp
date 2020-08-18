//time complexity = O(n)
//space complexity = O(n)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> map;
        
        for(int i=0;i<nums.size();i++)
            map[nums[i]]++;
        
    for(int i=0;i<nums.size();i++)
        if(map[nums[i]]>1)
            return nums[i];
        
        return -1;
    }
};


//time complexity = O(n)
//Space complexity = O(1)

//Linked list cycle method
/*
keep slow and fast pointer
keep moving slow by 1  step
and fast by 2 steps
till they collide
after colllision
make fast pointer pointing to beginning
move fast and slow by 1 step each till they collide
this time collision of fast and slow give us duplicate element
return slow or fast
*/

class Solution{
    public:
    int findDuplicate(vector<int>& nums){
        int slow = nums[0];
        int fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
            
            
        fast = nums[0];
        
        while(slow!=fast){
            slow =nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
    
};
