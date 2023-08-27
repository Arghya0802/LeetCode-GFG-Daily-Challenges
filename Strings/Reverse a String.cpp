// Link:  https://practice.geeksforgeeks.org/problems/reverse-a-string/1

class Solution
{
    public:
    string reverseWord(string str)
    {
        int low = 0 ; int high = str.size() - 1 ;
        
        while(low <= high)
        {
            swap(str[low] , str[high] ) ;
            
            low++ ; high-- ;
        }
        
        return str ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
