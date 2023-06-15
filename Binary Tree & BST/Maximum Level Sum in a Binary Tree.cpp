// Link: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/

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
public:
    int maxLevelSum(TreeNode* root) 
    {
        if(root == NULL)  return 0 ;

        queue<TreeNode *> q ;  q.push(root) ;  
        
        int maxSum = INT_MIN ;  int minLvl = INT_MIN ;  int lvl = 0 ;
        
        while(!q.empty() ) 
        {
            int size = q.size() ;  int sum = 0 ;

            while(size--)
            {
                TreeNode *node = q.front() ;  q.pop() ;

                sum += node -> val ;

                if(node -> left)   q.push(node -> left) ;

                if(node -> right)   q.push(node -> right) ;
            }
            
            lvl++ ;

            if(sum > maxSum)
            {
                maxSum = sum ;  minLvl = lvl ;
            }

        }

        return minLvl ;
    }
};

// Time Compleixty:  O(N)
// Space Complexity: O(N)
