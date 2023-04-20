// Link:

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

using ll = long long int ;
using pp = pair<TreeNode * , ll> ;

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) 
    {
        if(!root)  return 0 ;

        queue<pp> q ;

        ll maxCnt = 0 ;
        q.push({root , 0}) ;

        while(!q.empty() )
        {
            int size = q.size() ;
            ll minVal = q.front().second ;

            ll leftNode = INT_MAX , rightNode = 0 ;

            for(int i = 0 ; i < size ; i++)
            {
                TreeNode *node = q.front().first ;
                ll value = q.front().second ; q.pop() ;

                value -= minVal ;

                leftNode = min(value , leftNode) ;
                rightNode = value ;

                if(node -> left)
                    q.push({node -> left , 2 * value}) ;

                if(node -> right)
                    q.push({node -> right , 2 * value + 1}) ;
            }

            maxCnt = max(maxCnt , rightNode - leftNode + 1) ;
        }
        
        return maxCnt ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
