// Link: https://leetcode.com/problems/add-to-array-form-of-integer/description/

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums , int k) 
    {
        int n = nums.size() ;

        vector<int> ans ;

        int i = n - 1 ;
        int carry = 0 ;

        while(i >= 0 || k != 0 || carry > 0)
        {
            int sum = carry ;

            if(i >= 0)
            {
                sum += nums[i] ;
                i-- ;
            }

            if(k != 0)
            {
                sum += k % 10 ;

                k /= 10 ;
            }

            carry = sum / 10 ;

            ans.push_back(sum % 10) ;
        }

        reverse(ans.begin() , ans.end() ) ;
        
        return ans ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
