class Solution {
public:
    //recursive - recursively swapping left & right children - TC=O(n), SC=O(n) using recursion stack
    TreeNode* invertTree(TreeNode* root) 
    {
        if(root==NULL)
        {
            return NULL;
        }
        //swap left and right child
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
        
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
    
    //iterative - iteratively swapping left & right nodes and also storing next level nodes in queue - TC=O(n), SC=O(n)
    TreeNode* invertTree(TreeNode* root) 
    {
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* temp=st.top();
            st.pop();
            //if we reach to NULL then we will continue for other nodes if any in that level
            if(temp==NULL)
            {
                continue;
            }
            //push left and right nodes into queue for traversals
            st.push(temp->left);
            st.push(temp->right);
            //then swap them
            swap(temp->left,temp->right);
        }
        return root;
    }
};
