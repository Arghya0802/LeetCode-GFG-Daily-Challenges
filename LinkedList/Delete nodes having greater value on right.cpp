// Link:  https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    private:
    
    Node *reverseLL(Node *head)
    {
        Node *curr = head ;  Node *prev = NULL ;  Node *last = NULL ;
        
        while(curr != NULL)
        {
            last = prev ;  prev = curr ;
            
            curr = curr -> next ; 
            
            prev -> next = last ;
        }
        
        return prev ;
    }
    
    public:
    
    Node *compute(Node *head)
    {
        if(!head || !head -> next)  return head ;
        
        Node *rev = reverseLL(head) ;
        
        int maxVal = INT_MIN ;  Node *dummy = new Node(-1) ;  
        
        Node *tail = dummy ;  Node *p = rev ;
        
        while(p != NULL)
        {
            if(maxVal <= p -> data)
            {
                tail -> next = p ;  tail = p ;
                
                maxVal = p -> data ;
            }
            
            p = p -> next ;
        }
        
        tail -> next = NULL ;
        
        return reverseLL(dummy -> next) ;
    }
    
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
