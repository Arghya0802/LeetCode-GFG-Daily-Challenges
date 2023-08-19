// Link:  https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1

class Solution
{
    //Function to find a continuous sub-array which adds up to a given number.
    static ArrayList<Integer> subarraySum(int[] arr, int n, int s) 
    {
        ArrayList<Integer> ans = new ArrayList<>() ; int end = 0 ; 
        
        if(s == 0)  
        {
            ans.add(-1) ; return ans ;
        }
        
        int currSum = 0 ;
        
        for(int start = 0 ; start < arr.length ; start++)
        {
            currSum += arr[start] ;
            
            while(end <= start && currSum > s)
            {
                currSum -= arr[end] ;  end++ ;
            }
            
            if(currSum == s)
            {
                ans.add(end + 1) ;  ans.add(start + 1) ;  break ;
            }
        }
        
        
        if(ans.size() == 0)  ans.add(-1) ;
        
        return ans ;
    }
}

// Time Complexity:  O(N)
// Space Complexity: O(N)
