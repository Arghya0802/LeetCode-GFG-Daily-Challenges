// Link:  https://leetcode.com/problems/asteroid-collision/description/

using pp = pair<int , int> ;

class Solution {
private:

bool isCollide(stack<pp> &st , int sign)
{
    if(st.empty() )  return false ;

    if(st.top().first == 1 && sign == -1)  return true ;

    else return false ;
}

public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        int n = asteroids.size() ;  stack<pp> st ;  

        for(int nums : asteroids)
        {
            int val = abs(nums) ;  int sign = nums >= 0 ? 1 : -1 ;

            while(isCollide(st , sign) && val > st.top().second) st.pop() ;

            if(isCollide(st , sign) && st.top().second == val)  st.pop() ;

            else if(!isCollide(st , sign) )  st.push(make_pair(sign , val) ) ;
        }

        vector<int> ans ;

        while(!st.empty() )
        {
            ans.push_back( st.top().first * st.top().second ) ;  st.pop() ;
        }

        reverse(ans.begin() , ans.end() ) ;  

        return ans ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N) 
