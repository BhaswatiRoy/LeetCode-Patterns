class Solution {
public:
    //better - count frequencies of all elements and chcek if any is greater than floor of n/2 - TC=O(n), SC=O(n)
    int majorityElement(vector<int>& nums) 
    {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int n=nums.size();
        //floor value of n/2 is int n/2 so it stores nearest lower integer like 4 instead of 4.5
        int x=n/2;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second>x)
            {
                return it->first;
            }
        }
        return 0;
    }
    
    //optimal - Boyer Moore Algorithm - We elect a candidate for being the majority element and 
    //then if the element occurs, increase the possibility (count) of it being the real majority else decrease the possibility strength - TC=O(nlogn), SC+O(1)
    int majorityElement(vector<int>&nums) 
    {
        int count=0,majorityelem;
        for(int i=0;i<nums.size();i++)
        {
            if(count==0)
            {
                majorityelem=nums[i];
            }
            if(majorityelem==nums[i])
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return majorityelem;
    }
};
