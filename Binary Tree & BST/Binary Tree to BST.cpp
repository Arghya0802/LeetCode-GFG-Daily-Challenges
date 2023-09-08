// Link:  https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1

/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 
*/

class Solution{
    private:
    vector<int> ans ;
    
    void preOrder(Node *root)
    {
        if(!root)  return ;
        
        ans.push_back(root -> data) ;
        
        preOrder(root -> left) ;  preOrder(root -> right) ;
    }
    
    Node *convertBST(int low , int high)
    {
        if(low > high)   return NULL ;
        
        if(low == high)  
        {
            Node *leaf = new Node(ans[low]) ;  return leaf ;
        }
        
        int mid = low + (high - low) / 2 ;
        
        Node *root = new Node(ans[mid]) ;
        
        root -> left  = convertBST(low , mid - 1) ;
        
        root -> right = convertBST(mid + 1 , high) ;
        
        return root ;
    }
    
    void inOrder(Node *root , int &i)
    {
        if(!root) return ;
        
        inOrder(root -> left , i) ;
        
        root -> data = ans[i] ;  i++ ;
        
        inOrder(root -> right , i) ;
        
        return ;
    }
    
    public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node *binaryTreeToBST (Node *root)
    {
        preOrder(root) ;  sort(ans.begin() , ans.end() ) ;
        
        return convertBST(0 , ans.size() - 1) ;
        
        // int ind = 0 ;  inOrder(root , ind)
        
        // return root ;
    }
};

// Time Complexity:  O(N * Log N)
// Space Complexity: O(N)
