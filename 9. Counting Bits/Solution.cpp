class Solution {
public:
    //optimal solution - count set bits for each and store in vectot - TC is O(n)  
    vector<int> countBits(int n) 
    {
        vector<int>v;
        for(int i=0;i<=n;i++)
        {
            int count=__builtin_popcount(i);
            v.push_back(count);
        }
        return v;
    }
};
