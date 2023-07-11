// Link:  https://leetcode.com/problems/minimum-depth-of-binary-tree/

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

int minimumDepth(TreeNode *root)
{
    if(!root)  return INT_MAX ;

    if(!root -> left && !root -> right)  return 1 ;

    int lh = minimumDepth(root -> left) ;  
    int rh = minimumDepth(root -> right) ;

    return 1 + min(lh , rh) ;    
}

public:
    int minDepth(TreeNode* root) 
    {
        int ans = minimumDepth(root) ;

        return  ans == INT_MAX ? 0 : ans ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N) [ Recusive Stack Space]
