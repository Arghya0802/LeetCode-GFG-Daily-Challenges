// Link: https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/

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

void inOrder(TreeNode *root , vector<int> &nums)
{
    if(!root)
        return ;

    inOrder(root -> left , nums) ;

    nums.push_back(root -> val) ;

    inOrder(root -> right , nums) ;

    return ;
}

public:
    int minDiffInBST(TreeNode* root) 
    {
        vector<int> nums ;

        inOrder(root , nums) ;

        int n = nums.size() ;

        int ans = INT_MAX ;

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i + 1 ; j < n ; j++)
            {
                int val = abs(nums[i] - nums[j]) ;

                ans = min(ans , val) ;
            }
        }

        return ans ;    
    }
};
