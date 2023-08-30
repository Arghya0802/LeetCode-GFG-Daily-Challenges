// Link:  https://practice.geeksforgeeks.org/problems/delete-a-node-in-single-linked-list/1

/* Link list Node 
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

/*You are required to complete below method*/
Node* deleteNode(Node *head,int x)
{
    if(x == 1)  return head -> next ;
    
    Node *prev = NULL ; x-- ;
    
    Node *curr = head ;
    
    while(x--)
    {
        prev = curr ;  curr = curr -> next ;
    }
    
    prev -> next = curr -> next ;  delete curr ;
    
    return head ;
}

// Time Complexity:  O(N)
// Space Complexity: O(1)
