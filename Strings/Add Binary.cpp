// Link: https://leetcode.com/problems/add-binary/description/

class Solution {
public:
    string addBinary(string &a, string &b) 
    {
        int m = a.size() ; // Stores the Length of  String A
        int n = b.size() ; // Stores the Length of String B

        int carry = 0 ; // Used to keep track of the carry we have generated till now

        string ans = "" ; // Will contain our Final Ans

        // We use 2-pointers (i , j) and iterate both the strings from the end
        int i = m - 1 ; 
        int j = n - 1 ;

        // We keep on adding until we have finished iterating both the strings and carry has also become 0

        while(i >= 0 || j >= 0 || carry != 0)
        {
            int v1 = 0 , v2 = 0 ;

            if(i >= 0) // We can only iterate over string A if i >= 0
            {
                v1 = (int) (a[i] - '0') ;
                i -= 1 ;
            }   

            if(j >= 0) // We can only iterate over string B if j >= 0
            {
                v2 = (int) (b[j] - '0') ;
                j -= 1 ;
            }

            int sum = v1 + v2 + carry ; // We calculate the sum as (v1 + v2 + carry)

            carry = sum / 2 ; // We update carry as sum / 2

            sum = sum % 2 ; // We update sum as sum % 2

            string value = to_string(sum) ; // We convert our sum to string value

            ans += value ; // We insert the string value into our ans
        }

        // At the end, we reverse our ans string as we have traversed from the end while calculating 
        reverse(ans.begin() , ans.end() ) ; 
        
        return ans ;
    }
};

// Time Complexity:  O(M + N)
// Space Complexity: O(K) [For the ans string]
