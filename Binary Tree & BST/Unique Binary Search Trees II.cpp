// Link:  https://leetcode.com/problems/unique-binary-search-trees-ii/description/

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

vector<TreeNode *> uniqueBST(int left , int right)
{
    if(left == right)  return {new TreeNode(left)} ;

    if(left > right)  return {NULL} ;

    vector<TreeNode *> ans ;

    for(int i = left ; i <= right ; i++)
    {
        vector<TreeNode *> leftNodes = uniqueBST(left , i - 1) ;

        vector<TreeNode *> rightNodes = uniqueBST(i + 1 , right) ;

        for(auto left : leftNodes)
        {
            for(auto right : rightNodes)
            {
                TreeNode *root = new TreeNode(i) ;

                root -> left = left ;  root -> right = right ;

                ans.push_back(root) ;
            }
        }
    }

    return ans ;
}

public:
    vector<TreeNode*> generateTrees(int n) 
    {
        return uniqueBST(1 , n) ;
    }
};

// Time Complexity:  O(Exponential)
// Space Complexity: O(Exponential)
