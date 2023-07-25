// Link:   https://leetcode.com/problems/peak-index-in-a-mountain-array/description/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        int n = arr.size() ;

        int low = 0 ;  int high = n - 1 ;

        while(low <= high)
        {
            int mid = low + (high - low) / 2 ;

            if(mid == 0)  return arr[0] > arr[1] ? 0 : 1 ;

            else if(mid == n - 1)  return arr[n - 1] > arr[n - 2] ? n - 2 : n - 1 ;

            else
            {
                if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1] )  return mid ;

                else if(arr[mid + 1] > arr[mid] )  low = mid + 1 ;

                else high = mid - 1 ;
            }
        }    

        return -1 ;
    }
};

// Time Complexity:  O(Log N)
// Space Complexity: O(1)
