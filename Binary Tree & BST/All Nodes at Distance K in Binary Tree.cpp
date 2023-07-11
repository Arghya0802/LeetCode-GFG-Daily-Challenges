// Link:  https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:

void buildParentMap(TreeNode *root , TreeNode *parent , unordered_map<TreeNode* , TreeNode*> &map)
{
    if(!root)  return ;
    
    map[root] = parent ;

    buildParentMap(root -> left , root , map) ;

    buildParentMap(root -> right , root , map) ;

    return ;
}

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        unordered_map<TreeNode * ,TreeNode *> parentsMap ;

        TreeNode *dummy = new TreeNode(-1) ;

        buildParentMap(root , dummy , parentsMap) ;    

        vector<int> ans ; unordered_set<TreeNode*> visited ;

        queue<pair<TreeNode *, int> > q ;   q.push(make_pair(target , 0) ) ;
        
        visited.insert(target) ;

        while(!q.empty() )
        {
            auto node = q.front().first ;  int dist = q.front().second ;
            q.pop() ;

            if(dist == k)  ans.push_back(node -> val) ;

            if(dist > k)  continue ;

            if(node && node -> left && visited.find(node -> left) == visited.end() ) 
            {
                visited.insert(node -> left) ;  q.push(make_pair(node -> left , dist + 1) ) ;
            }

            if(node && node -> right != NULL && visited.find(node -> right) == visited.end() )
            {
                visited.insert(node -> right) ; q.push(make_pair(node -> right , dist + 1) ) ;
            }

            auto parent = parentsMap[node] ;

            if(parent -> val != -1 && visited.find(parent) == visited.end() )
            {
                visited.insert(parent) ;  q.push(make_pair(parent , dist + 1) ) ;
            }
        }

        return ans ;
    }
};

// Time Complexity:  O(N + K)
// Space Complexity: O(N)
