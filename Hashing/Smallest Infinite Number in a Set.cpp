// Link: https://leetcode.com/problems/smallest-number-in-infinite-set/description/

class SmallestInfiniteSet {
private:
int freq[1001] = {0} ;

public:
    SmallestInfiniteSet() 
    {
        for(int i = 1 ; i <= 1000 ; i++)  freq[i] = 1 ;    
    }
    
    int popSmallest() 
    {
        for(int i = 1 ; i <= 1000 ; i++)
        {
            if(freq[i] > 0)
            {
                freq[i] = 0 ;
                return i ;
            }
        }

        return 0 ;    
    }
    
    void addBack(int num) 
    {
        if(freq[num] > 0)  return ;

        freq[num] = 1 ;    
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
