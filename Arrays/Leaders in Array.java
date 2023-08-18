// Link:  https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

class Solution{
    //Function to find the leaders in the array.
    static ArrayList<Integer> leaders(int arr[], int n)
    {
        Stack<Integer> st = new Stack<>() ;
        
        int maxi = arr[n - 1] ;  st.push(maxi) ;
         
        for(int i = n - 2 ; i >= 0 ; i--)
        {
            if(arr[i] >= maxi) 
            {
                maxi = arr[i] ; st.push(maxi) ;
            }
        }
        
        ArrayList<Integer> ans = new ArrayList<>() ;
        
        while(!st.isEmpty() )  ans.add(st.pop() ) ;
        
        return ans ;
    }
}

// Time Complexity:  O(N)
// Space Complexity: O(N)
