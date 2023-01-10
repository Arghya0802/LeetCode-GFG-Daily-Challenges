// Link: https://leetcode.com/problems/same-tree/description/

// Recursive Code to check for Same Trees

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(p == NULL && q == NULL)  
            return true ;

        if(p == NULL || q == NULL)    
            return false ;

        if(p -> val != q -> val)
            return false ;

        bool leftAns  = isSameTree(p -> left , q -> left)  ;
        bool rightAns = isSameTree(p -> right , q -> right) ;

        return leftAns && rightAns ;
    }
};

// Iterative Code to check for Same Tree

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(p == NULL && q == NULL)
            return true ;

        stack<pair<TreeNode *, TreeNode *>> st ;

        st.push({p , q}) ;

        while(st.empty() == false)
        {
            TreeNode *first  = st.top().first ;
            TreeNode *second = st.top().second ;
            st.pop() ;

            if(first == NULL && second != NULL)
                return false ;

            if(second == NULL && first != NULL)
                return false ;
            
            if(first == NULL && second == NULL)
                continue ;
                
            if(first -> val != second -> val)
                return false ;

            st.push( {first -> left , second -> left} ) ;

            st.push( {first -> right , second -> right} ) ;

        }

        return true ;    
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
