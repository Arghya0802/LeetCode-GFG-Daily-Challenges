// Link: https://leetcode.com/problems/can-place-flowers/description/

class Solution {
private:

bool isOkay(int ind , int n , vector<int> &flower)
{
    if(n == 1)
        return true ;

    if(ind == 0 || ind == n - 1)
    {
        if(ind == 0 && flower[ind + 1] == 1)
            return false ;

        if(ind == n - 1 && flower[ind - 1] == 1)
            return false ;
    }

    else if(flower[ind - 1] == 1 || flower[ind + 1] == 1)
        return false ;

    return true ;
}

public:
    bool canPlaceFlowers(vector<int>& flowerbed, int k) 
    {
        int n = flowerbed.size() ;

        int empty = -2 ;

        for(int i = 0 ; i < n ; i++)
        {
            if(k == 0)
                break ;

            int flower = flowerbed[i] ;

            if(flower == 1)
                continue ;

            if(i - empty > 1 && isOkay(i , n , flowerbed) )
            {
                k-- ;
                empty = i ;
            }
        }

        return k == 0 ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
