class Solution {
public:
  //brute - running 2 nested loops to check - TC=O(n^2), SC=O(1)
    bool containsDuplicate(vector<int>& nums) 
    {
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                if(nums[i]==nums[j])
                {
                    return true;
                }
            }
        }
        return false;
    }
    
    //better - sorting and comparing adjacents - O(nlogn), SC=O(1)
    bool containsDuplicate(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
            {
                return true;
            }
        }
        return false;
    }
    
    //Optimal - using maps to store frequency - O(n), SC=O(n)
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second>=2)
            {
                return true;
            }
        }
        return false;
    }
};
