
class Solution {
public:
    //better - sorting and then comparing adjacent elements - TC=O(nlogn), SC=O(1)
    int singleNumber(vector<int>& nums) 
    { 
       sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i+=2)
        {
            if(nums[i]!=nums[i-1])
                return nums[i-1];
        }
        return nums[nums.size()-1];
    }
    
    //optimal - using map to store frequency and checking if any has frequency not equal to 2 - TC=O(n), SC=O(n)
    int singleNumber(vector<int>& nums) 
    {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second!=2)
            {
                return it->first;
            }
        }
        return 0;
    }
};
