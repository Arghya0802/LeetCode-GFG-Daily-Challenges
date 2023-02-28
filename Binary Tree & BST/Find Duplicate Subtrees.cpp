// Link: https://leetcode.com/problems/find-duplicate-subtrees/description/

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

string dfs(TreeNode *root , unordered_map<string , int> &map , vector<TreeNode *> &ans)
{
    if(root == NULL)
        return "-" ;

    string leftPart =  dfs(root -> left  , map , ans) ;

    string rightPart = dfs(root -> right , map , ans) ;

    string rootStruct = to_string(root -> val) + "-" + leftPart + "-" + rightPart ;

    if(map[rootStruct] == 1)
        ans.push_back(root) ;

    map[rootStruct] += 1 ;

    return rootStruct ;
}

public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        vector<TreeNode *> ans ;

        if(!root)
            return ans ;

        unordered_map<string , int> map ;

        dfs(root , map , ans) ;    

        return ans ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
