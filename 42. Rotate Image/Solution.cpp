class Solution {
public:
    //optimal - transpose of matrix + reverse each row - TC=O(n^2), SC=O(1)
    void rotate(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        //do transpose of the matrix
        for(int i=0;i<n;i++)
        {
            //loop upto i because other elements will automatically get swapped
            for(int j=0;j<i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //then reverse each row i.e take mirror image about vertical line
        for(int i=0;i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
