// Link:  https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1

class Solution {
    
    int findFirstPosition(int [] nums , int n , int key)
    {
        int low = 0 ;  int high = n - 1 ; int ans = -1 ;
        
        while(low <= high)
        {
            int mid = low + (high - low) / 2 ;
            
            if(nums[mid] == key)
            {
                ans = mid ;  high = mid - 1 ;
            }
            
            else if(nums[mid] < key)  low = mid + 1 ;
            
            else high = mid - 1 ;
            
        }
        
        return ans ;
    }
    
    int findLastPosition(int [] nums , int n , int key)
    {
        int low = 0 ;  int high = n - 1 ; int ans = -1 ;
        
        while(low <= high)
        {
            int mid = low + (high - low) / 2 ;
            
            if(nums[mid] == key)
            {
                ans = mid ;  low = mid + 1 ;
            }
            
            else if(nums[mid] < key)  low = mid + 1 ;
            
            else high = mid - 1 ;
        }
        
        return ans ;
    }
    
    int count(int[] arr, int n, int x) 
    {
        int first = findFirstPosition(arr , n , x) ;
        
        int last = findLastPosition(arr , n , x) ;
        
        // System.out.println(first + " " + last) ;
        
        return first == -1 ? 0 : last - first + 1 ;
    }
}

// Time Complexity:  O(Log N)
// Space Complexity: O(1)
