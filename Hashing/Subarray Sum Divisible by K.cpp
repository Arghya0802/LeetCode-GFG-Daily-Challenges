// Link: https://leetcode.com/problems/subarray-sums-divisible-by-k/description/

// This is a classic (Hashing + prefixSum) question
// The more generalized version is the Subarray Sum equals K
// Instead of using (prefixSum - K) as the key we can use (prefixSum % K) as our key
// We need to use the forumla of ((a % b) + b) % b as we are dealing with negative numbers as well
// Lastly, we need to store (prefixSum % K) into our HashMap

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        int n = nums.size() ;

        int ans = 0 ; // Stores the Count of the Number of Subarrays whose Sum is divisible by K

        int prefixSum = 0 ; // Calculates the PrefixSum till now

        unordered_map<int , int> map ; // HashMap to store (prefixSum % K) as our Key and caluclate the Number of HashMaps accordingly
        
        map[0] = 1 ; // To handle the edge case, when the entire array's sum is equal to K

        for(int i = 0 ; i < n ; i++)
        {
            prefixSum += nums[i] ;

            int remainder = ( ( (prefixSum % k) + k) % k )  ; // We calculate the Key as we have discussed earlier

            if(map.find(remainder) != map.end()) // If we have encountered the key, we increment our ans variable by map[remainder]
                ans += map[remainder] ;

            map[remainder] += 1 ; // We always increment map[remainder] by 1
        }

        return ans ;

    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
