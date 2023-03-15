// Link: https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/

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
using pp = pair<TreeNode * , int> ;

class Solution {
private:

int bfs(TreeNode *root)
{
    int ans = 0 ;

    queue<TreeNode *> q ;
    q.push(root) ;

    while(!q.empty() )
    {
        int size = q.size() ;

        while(size--)
        {
            TreeNode *node = q.front() ;
            q.pop() ;

            if(node -> left)
                q.push(node -> left) ;

            if(node -> right)
                q.push(node -> right) ;
        }

        ans += 1 ;
    }

    return ans ;
}

public:
    bool isCompleteTree(TreeNode* root) 
    {
        int n = bfs(root) ;

        int levels = 0 ;
        ll totalCnt = 1 ;    

        queue<pp> q ;

        q.push({root , 0}) ;

        while(!q.empty() )
        {
            int size = q.size() ;
            int cnt = 0 ;

            while(size--)
            {
                TreeNode *node = q.front().first ;
                int pos = q.front().second ;
                q.pop() ;

                if(cnt != pos)
                    return false ;

                if(node -> left)
                    q.push( {node -> left , cnt * 2} ) ;

                if(node -> right)
                    q.push( {node -> right , cnt * 2 + 1} ) ;

                cnt++ ;
            }
            
            if(levels == n - 1)
                continue ;

            if(totalCnt != cnt)
                return false ;

            totalCnt *= 2 ;
            levels++ ;
        }

        return true ;
    }
};

// Time Complexity:  O(2 * N)
// Space Complexity: O(N)
