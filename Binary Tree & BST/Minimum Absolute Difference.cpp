// Link:  https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/

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

int ans = INT_MAX ;  TreeNode *prev = NULL ;

void minDiffBST(TreeNode *root)
{
    if(!root)  return  ;  

    minDiffBST(root -> left) ;

    if(prev != NULL)  ans = min(ans , abs(prev -> val - root -> val) ) ;

    prev = root ;  minDiffBST(root -> right) ;  

    return ;
} 

public:
    int getMinimumDifference(TreeNode* root) 
    {
        minDiffBST(root) ; return ans ;   
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
