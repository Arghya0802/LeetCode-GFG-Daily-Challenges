// Link:  https://leetcode.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }3
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        if(!head)  return NULL ;

        Node *dummy = new Node(-1) ; Node *tail = dummy ;

        unordered_map<Node * , Node *> nodeMap ;

        Node *p = head ;

        while(p)
        {
            Node *copy = new Node(p -> val) ;

            nodeMap[p] = copy ;  p = p -> next ;
        }

        p = head ;

        while(p)
        {
            Node *copy = nodeMap[p] ;

            Node *copyRand = nodeMap[p -> random] ;

            tail -> next = copy ; tail = copy ;

            copy -> random = copyRand ;  p = p -> next ;
        }

        return dummy -> next ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
