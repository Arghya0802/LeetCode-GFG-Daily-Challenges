// GFG Link:  https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1

//User function Template for Java

/*Complete the function below
Node is as follows:
class Node{
	int data;
	Node left,right;
	Node(int d){
		data=d;
		left=right=null;
	}
}
*/
class Solution
{
    // returns the inorder successor of the Node x in BST (rooted at 'root')
	public Node inorderSuccessor(Node root,Node x)
    {
        Node ans = new Node(-1) ;
        
        while(root != null)
        {
            if(root.data <= x.data)  root = root.right ;
            
            else
            {
                ans = root ;  root = root.left ;
            }
        }
        
        return ans ;
    }
}

// Time Complexity:  O(Log N)
// Space Complexity: O(1)
