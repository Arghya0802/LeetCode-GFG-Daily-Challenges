// Link: https://leetcode.com/problems/binary-tree-preorder-traversal/description/

// I have used Iterative Pre-Order to calculate the Pre-Order Traversal for the Binary Tree
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> ans ;

        if(root == NULL)
            return ans ;    
    
        stack<TreeNode *> st ;
        
        st.push(root) ;

        while(st.empty() == false)
        {
            TreeNode *currNode = st.top() ;
            st.pop() ;

            ans.push_back(currNode -> val) ;

            if(currNode -> right != NULL)
                st.push(currNode -> right) ;

            if(currNode -> left != NULL)
                st.push(currNode -> left) ;

        }

        return ans ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
