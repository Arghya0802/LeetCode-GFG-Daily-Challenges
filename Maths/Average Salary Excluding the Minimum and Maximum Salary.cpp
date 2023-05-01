// Link:  https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/description/

class Solution {
public:
    double average(vector<int>& salary) 
    {
        double ans = 0 ;

        int minSalary = INT_MAX , maxSalary = INT_MIN ;

        for(int nums : salary)
        {
            minSalary = min(minSalary , nums) ;

            maxSalary = max(maxSalary , nums) ;

            ans += (double) nums ;
        }    

        ans -= minSalary ;  ans -= maxSalary ;

        double n = salary.size() - 2 ;
        
        return (ans / n) ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
