// Link: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description/

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
int maxSteps = 0 ;

void dfs(TreeNode *root , bool isLeft , int steps)
{
    if(!root)  return ;
    
    maxSteps = max(maxSteps , steps) ;

    if(isLeft == true)
    {
        dfs(root -> right , false , steps + 1) ;
        dfs(root -> left , true , 1) ;
    }

    else
    {
        dfs(root -> left , true , steps + 1) ;
        dfs(root -> right , false , 1) ;
    }

    return ;
}

public:
    int longestZigZag(TreeNode* root) 
    {
        dfs(root , true , 0) ;
        dfs(root , false , 0) ;

        return maxSteps ;        
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(H)
