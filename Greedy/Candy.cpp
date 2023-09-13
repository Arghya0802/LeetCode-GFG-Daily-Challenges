// Link: https://leetcode.com/problems/candy/

class Solution {
public:
    int candy(vector<int>& ratings) {
        
    int n = ratings.size() ;
        
    vector<int> countCandies(n) ;    
    
    int prevRating = ratings[0] ;
    int count = 1 ;
        
    countCandies[0] = 1 ;
        
    for(int i = 1 ; i < n ; i++)
    {
        if(ratings[i] > prevRating)
            count += 1 ;
        
        else
            count = 1 ;
        
        countCandies[i] = count ;
        
        prevRating = ratings[i] ;
    }
        
    prevRating = ratings[n - 1] ;
    count = 1 ;
        
    for(int i = n - 2 ; i >= 0 ; i--)
    {
        if(ratings[i] > prevRating)
        {
            count += 1 ;
            countCandies[i] = max(countCandies[i] , count) ;
        }
        
        else
            count = 1 ;
        
        prevRating = ratings[i] ;
    }
        
    int totalCandies = 0 ;
        
    for(int i = 0 ; i < n ; i++)
    {
        totalCandies += countCandies[i] ;
    }
    
    return totalCandies ;
}
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
