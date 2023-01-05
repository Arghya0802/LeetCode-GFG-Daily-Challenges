// Link: https://leetcode.com/problems/sort-characters-by-frequency/description/

// This section will contain question where we have to sort a given vector or Priority Queue and we need to involve Comparator Class or Function in that problem
class Solution {
public:
     
    // As we are sorting a vector<pair<int , int>>, we can use static bool cmp() as a PUBLIC FUNCTION
    // For Custom Priority Queue, we need to use another seperate Struct or Class in C++
  
    static bool cmp(pair<char, int> &A , pair<char,int> &B)
    {
        if(A.second > B.second) // As we are sorting on the basis of Frequency, we need to follow the Order in which they have need to appear in our final array
            return true ;

        else if(A.second == B.second) // If the Frequencies are same, we need to sort them in Ascending Order of their ASCII Values
        {
            if(A.first < B.first) // Again, just follow the order in which we need the final elements to be in our sorted array
                return true ;
        }

        return false ;
    }

    string frequencySort(string &s) 
    {
        unordered_map<char , int> map ; // We use a Map to store the count of frequencies of elements

        for(char ch : s)
            map[ch] += 1 ;

        vector<pair<char , int>> nums ; // We transport the values as a pair inside a vector from our Map, in order to sort it

        for(auto &x : map)
        {
            char ch  = x.first ;
            int freq = x.second ;

            nums.push_back( {ch , freq} ) ;
        }

        sort(nums.begin() ,  nums.end() , cmp) ;

        string ans = "" ;

        int n = nums.size() ;
        
        // At the end, we just need to add the characters, as per their frequencies, inside our String ans
      
        for(int i = 0 ; i < n ; i++)
        {
            char ch  = nums[i].first  ;
            int freq = nums[i].second ;

            while(freq--)
                ans += ch ;
        }

        return ans ;
    }
};

// Time Complexity:  O(N * Log N) [Due to Sorting]
// Space Complexity: O(N) [The Length of our ans string]
