// Link:  https://practice.geeksforgeeks.org/problems/leftmost-and-rightmost-nodes-of-binary-tree/1

/* Function to print corner node at each level */

/*
Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};
*/
void printCorner(Node *root)
{
    if(!root)  return ;
    
    queue<Node *> q ;  q.push(root) ;
    
    while(!q.empty() )
    {
        int size = q.size() ;
        
        for(int i = 0 ; i < size ; i++)
        {
            auto node = q.front() ;  q.pop() ;
            
            if(i == 0)  cout << node -> data << " " ;
            
            else if(i == size - 1)  cout << node -> data << " " ;
            
            if(node -> left)  q.push(node -> left) ;
            
            if(node -> right)  q.push(node -> right) ;
        }
    }
    
    return ;
}

// Time Complexity:  O(N)
// Space Complexity: O(N) 
