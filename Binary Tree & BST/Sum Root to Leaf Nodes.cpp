// Link: https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

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

void preOrder(TreeNode *root , string &s , int &ans)
{
    if(!root)
        return ;

    if(root -> left == NULL && root -> right == NULL)
    {
        s += to_string(root -> val) ;

        ans += stoi(s) ;

        s.pop_back() ;
        
        return ;
    }

    s += to_string(root -> val) ;

    preOrder(root -> left , s , ans) ;
    preOrder(root -> right , s , ans) ;
    
    s.pop_back() ;

    return ;
}

public:
    int sumNumbers(TreeNode* root) 
    {
        int ans = 0 ;

        string s = "" ;

        preOrder(root , s , ans) ;

        return ans ;    
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N) [Stack Space + Ans string]
