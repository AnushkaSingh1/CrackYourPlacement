class cmp{
    public:
    bool operator()(pair<int,char> &a,pair<int,char> &b)
    {
        return a.first<b.first;
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        for(auto it:s)mp[it]++;
        string ans = "";
        priority_queue< pair<int,char>,vector<pair<int,char>>,cmp > pq;
        char l = '!';
        
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
        
        while(pq.size())
        {
            auto curr = pq.top();
            pq.pop();
            if(curr.second==l)
            {
                if(pq.size()==0)return "";
                auto new_curr = pq.top();
                pq.pop();
                ans.push_back(new_curr.second);
                new_curr.first -= 1;
                l = new_curr.second;
                if(new_curr.first)
                    pq.push(new_curr);
                pq.push(curr);
            }
            else
            {
                ans.push_back(curr.second);
                curr.first -= 1;
                if(curr.first)
                    pq.push(curr);
                l = curr.second;
            }
        }
        return ans;
    }
};















Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

 

Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.
Accepted
227,432
Submissions
433,312








