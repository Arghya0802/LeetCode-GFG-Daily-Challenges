// Link: https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
    if(!head || !head -> next)  return head ;
    
    Node *dummy = new Node(INT_MAX) ; Node *tail = dummy ;
    
    Node *p = head ; int prev = - INT_MAX ;
    
    while(p != NULL)
    {
        if(p -> data != prev)
        {
            tail -> next = p ; tail = p ;  
            prev = p -> data ;
        }
        
        p = p -> next ;
    }
    
    tail -> next = NULL ;
    
    return dummy -> next ;
}

// Time Complexity:  O(N)
// Space Complexity: O(1) 
