// Link: https://leetcode.com/problems/symmetric-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:

bool isSameTree(TreeNode *p , TreeNode *q)
{
    if(p == NULL && q == NULL)
        return true ;

    if(p == NULL || q == NULL)
        return false ;

    if(p -> val != q -> val)
        return false ;

    bool leftAns  = isSameTree(p -> left , q -> right) ;
    bool rightAns = isSameTree(p -> right , q -> left) ;

    return leftAns && rightAns ;
}

public:
    bool isSymmetric(TreeNode* root) 
    {
        return isSameTree(root -> left , root -> right) ;   
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
