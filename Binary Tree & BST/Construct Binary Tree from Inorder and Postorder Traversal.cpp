// Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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

TreeNode *createTree(int &currIndex , int low , int high , vector<int> &postOrder , unordered_map<int , int> &map)
{
    if(currIndex == -1)
        return NULL ;

    if(low > high)
        return NULL ;

    int node = postOrder[currIndex] ;
    currIndex-- ;
    
    TreeNode *root = new TreeNode(node) ;
    int mid = map[node] ;

    root -> right = createTree(currIndex , mid + 1 , high , postOrder , map) ;
    
    root -> left = createTree(currIndex , low , mid - 1 , postOrder , map) ;

    return root ;
}

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        int n = inorder.size() ;
        unordered_map<int , int> map ;    

        for(int i = 0 ; i < n ; i++)
        {
            int node = inorder[i] ;

            map[node] = i ;
        }

        int i = n - 1 ;
        return createTree(i , 0 , n - 1 , postorder , map) ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
