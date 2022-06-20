class Solution {
public:
    //better - sorting & comparing value at index i with index i - TC=O(nlogn), SC=O(1)
    int missingNumber(vector<int>& nums) 
    {
        int val;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=i)
            {
                val=i;
                break;
            }
        }
        return val;
    }
  
    //optimal - using mathematical formula for calculating actual sum then compare with computed sum - Tc=O(n), SC=O(1)
    int missingNumber(vector<int>& nums) 
    {
        int sum=0,n=nums.size();
        //actual sum calculated by formula
        int actualsum=(n*(n+1))/2;
        
        //calculate sum by traversing through the vector
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        
        //the difference between actual & computed sum is the missing number
        return actualsum-sum;
    }
};
