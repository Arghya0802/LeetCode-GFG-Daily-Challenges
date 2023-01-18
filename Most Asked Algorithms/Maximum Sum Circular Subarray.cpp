// Link: https://leetcode.com/problems/maximum-sum-circular-subarray/description/

// This question is a slight variation of the Famous Kadane's Algorithm
// Instead of dealing with a linear array, we are asked to deal with Circular Array
// This is when our intuition comes in
// We first find the Max-Subarray-Sum using Kadane's Algorithm and keep track of the number of negative numbers present in the array
// If the array contains only negative numbers, we directly return Max-Subarray-Sum
// Otherwise, we need to check for the Circular SubArray Sum of the array
// For that, we calculate the TotalSum of the array as well as the Min-Subarray-Sum
// Min-Subarray-Sum can be found in the exact opposite way of Max-Subarray-Sum
// At the end, our Max-Circular-Subarray-Sum will be equal to the (TotalSum - Min-Subarray-Sum)
// We return Maximum of (MaxSubarraySum , MaxCircularSubArraySum)

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        int n = nums.size() ;

        int currSum = 0 ;
        int maxSubarraySum = nums[0] ; // To tackle the case of negative numbers we initalise MaxSubarraySum with any value present in array

        int cnt = 0 ; // To count the number of negative values in the array

        for(int i = 0 ; i < n ; i++)
        {
            currSum += nums[i] ;

            maxSubarraySum = max(maxSubarraySum , currSum) ; // We store the Maximum Sum 

            if(currSum < 0) // If any Subarray-Sum makes our Current-Sum negative, we discard that Subarray 
                currSum = 0 ; // Thus we re-initalise our Current-Sum with 0

            if(nums[i] < 0)
                cnt++ ;
        }
         
        // If our array contains only negative values, then MaxSubarraySum will be the Minimum of all the elements possible
        if(cnt == n)
            return maxSubarraySum ;

        currSum = 0 ; // We again re-initalise Current-Sum with 0

        int totalSum = 0 ; // Stores TotalSum into our Array
        int minSubarraySum = nums[0] ; // Stores the Minimum-Subarray-Sum possible

        for(int i = 0 ; i < n ; i++)
        {
            totalSum += nums[i] ;
            currSum += nums[i] ;

            if(minSubarraySum > currSum) // We store the Minimum-Subarray-Sum always
                minSubarraySum = currSum ;

            if(currSum >= 0) // Just the oposite condition to our Max-Subarray-Sum
                currSum = 0 ;
        }

        int maxCircularSubarraySum = totalSum - minSubarraySum ; // Maximum-Circular-Sum will be equal to the TotalSum - MinSubarraySum
        
        return maxSubarraySum >= circularSubarraySum ? maxSubarraySum : maxCircularSubarraySum ; // We return the Maximum of (MaxSubarraySum , MaxCircularSubarraySum)
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
