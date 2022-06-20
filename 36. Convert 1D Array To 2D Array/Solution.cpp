class Solution {
public:
    //brute - normally store elements in 2d array by iterating via 2 nested loops - TC=O(n^2), SC=O(n^2)
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) 
    {
        //if the sizes of 1d & 2d vectors don't match then not possible to convert them
        if(m*n!=original.size())
        {
            return {};
        }
        vector<vector<int>>v;
        vector<int>temp;
        //m rows and n columns so n elements in 1 row
        for(int i=0;i<m*n;)
        {
            for(int j=0;j<n;j++)
            {
                temp.push_back(original[i]);
                i++;
            }
            v.push_back(temp);
            temp.clear();
        }
        return v;
    }
    
    //better - traverse 1d vector and use formula i/n & i%n to fill into 2d matrix - TC=O(n), SC=O(n^2)
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) 
    {
        if(m*n!=original.size())
        {
            return {};
        }
        vector<vector<int>>ans(m,vector<int>(n));
        for(int i=0;i<original.size();i++)
        {
            //rows of 2d matrix is denoted by i/n for i index in 1d vector
            int row=i/n;
            //columns of 2d matrix is denoted by i/n for i index in 1d vector
            int col=i%n;
            ans[row][col]=original[i];
        }
        return ans;
    }
};
