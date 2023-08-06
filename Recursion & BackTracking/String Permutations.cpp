// Link:  https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string-1587115620/1

class Solution{
    
    private:
    vector<string> ans ;
    
    void allPermutations(int ind , string &s)
    {
        if(ind >= s.size() )
        {
            ans.push_back(s) ;  return ;
        }
        
        for(int i = ind ; i < s.size() ; i++)
        {
            swap(s[ind] , s[i] ) ;
            
            allPermutations(ind + 1 , s) ;
            
            swap(s[ind] , s[i] ) ;
        }
        
        return ;
    }
    
    public:
    vector<string> permutation(string &S)
    {
        allPermutations(0 , S) ;
        
        sort(ans.begin() , ans.end() ) ;  return ans ;
    }
};
