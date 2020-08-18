/* Approach 1: using sort(nums.begin(),nums.end())
time complexity = O(NlognN)
space complexity = 0(1)
*/

//approach 2 : Two Pass
//time complexity = 0(N) + O(N) = O(2N)
//Space complexity = O(1)

class Solution {
public:
    void sortColors(vector<int>& arr) {
      int count0=0,count1=0,count2=0;
        int n = nums.size();
      //pass 1 O(n)
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                count0++;
            else if(nums[i]==1)
                count1++;
            else
                count2++;
        }
        nums.clear();
        //pass 2 O(n)
        for(int i=0;i<count0;i++)
            nums.push_back(0);
        for(int i=0;i<count1;i++)
            nums.push_back(1);
        for(int i=0;i<count2;i++)
            nums.push_back(2);
            
        return;
       
    }
};

/*
Approach 3 : Dutch flag algorithm : Optimal Approach
time complexity = O(N)
space complexity = O(1)

elements on left of low  =0
element from low+1 to mid-1 = 1
element from right of high = 2
*/

class Solution{
  public:
    void sortColors(vector<int>& nums){
        int n = nums.size();
        int low =0;
        int mid =0;
        int high = n-1;
         
        
        while(mid<=high){
            switch(nums[mid]){
                case 0 :
                    swap(nums[low++] , nums[mid++]);   
                    break;
                case 1 :
                    mid++;
                    break;
                case 2 : 
                    swap(nums[mid] , nums[high--]);
                    break;
            }
        }
        return;
    }
};
 
      
