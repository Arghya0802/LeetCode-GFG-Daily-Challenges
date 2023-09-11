// Link:  https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& arr) {
        unordered_map<int,queue<int>>mp;
        vector<vector<int>>ans;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]].push(i);
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            int ele=it->first;
            queue<int>q=it->second;
            while(!q.empty())
            {
                vector<int>temp;
                for(int j=0;j<ele;j++)
                {
                    temp.push_back(q.front());
                    q.pop();
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
