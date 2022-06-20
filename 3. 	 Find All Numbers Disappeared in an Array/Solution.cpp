class Solution {
public:
    //better - using maps to store frequency and then checking if any element is not in map - TC-O(n), SC-O(n)
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        unordered_map<int,int>mp;
        //store the elements between 1 to n which are in the vector 
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        vector<int>ans;
        int n=nums.size();
        //looping from 1 to n
        for(int j=1;j<=n;j++)
        {
            //if the value j is not in the map 
            if(mp.find(j)==mp.end())
            {
                //then push it in the ans
                ans.push_back(j);
            }
        }
        return ans;
    }
};
