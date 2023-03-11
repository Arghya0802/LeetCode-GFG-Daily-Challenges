// Link: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) 
    {
        if(head == NULL)
            return NULL ;

        if(head -> next == NULL)
        {
            TreeNode *leaf = new TreeNode(head -> val) ;

            return leaf ;
        }

        ListNode *fast = head ;
        ListNode *slow = head ;
        ListNode *prev = NULL ;

        while(fast && fast -> next)
        {
            prev = slow ;
            slow = slow -> next ;

            fast = fast -> next -> next ;
        }

        ListNode *nextPart = slow -> next ; // Right Part of the BST
        prev -> next = NULL ; // Left Part of the BST

        TreeNode *newNode = new TreeNode(slow -> val) ; // Middle of the LinkedList is our root
        newNode -> left = sortedListToBST(head) ;

        newNode -> right = sortedListToBST(nextPart) ;

        return newNode ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N) [To create the height balanced BST]
