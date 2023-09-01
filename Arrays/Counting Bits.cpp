// Link:  https://leetcode.com/problems/counting-bits/

class Solution {
private:

int count(int num)
{
    int cnt = 0 ;

    while(num)
    {
        if(num % 2 == 1)  cnt++ ;

        num /= 2 ;
    }

    return cnt ;
}

public:
    vector<int> countBits(int n) 
    {
        vector<int> ans(n + 1) ;

        for(int i = 0 ; i <= n ; i++)
        {
            int cnt = count(i) ;  ans[i] = cnt ;
        }

        return ans ;
    }
};

// Time Complexity:  O(N * Log N)
// Space Complexity: O(N)
