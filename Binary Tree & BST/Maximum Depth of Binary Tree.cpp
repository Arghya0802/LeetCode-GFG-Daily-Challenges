// Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

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

int levelOrderTraversal(TreeNode *root)
{
    if(root == NULL)
        return 0 ;

    queue<TreeNode *> q ;
    q.push(root) ;

    int maxCnt = 0 ;

    while(!q.empty() )
    {
        int size = q.size() ;

        while(size--)
        {
            TreeNode *curr = q.front() ;
            q.pop() ;

            if(curr -> left != NULL)
                q.push(curr -> left) ;

            if(curr -> right != NULL)
                q.push(curr -> right) ;
        }

        maxCnt++ ;
    }

    return maxCnt ;
}

int findMaxDepth(TreeNode *root)
{
    if(root == NULL)
        return 0 ;

    int lh = findMaxDepth(root -> left)  ;
    int rh = findMaxDepth(root -> right) ;

    return 1 + max(lh , rh) ;    
}

public:
    int maxDepth(TreeNode* root) 
    {
        // int ans = findMaxDepth(root) ;

        int ans = levelOrderTraversal(root) ;   

        return ans ; 
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
