class Solution {
public:
    struct HashCharSet {
        std::size_t operator()(const multiset<char>& char_set) const {
            std::size_t hash = 17;
            for (const char c : char_set) { hash += 31 * (c - '0');}
            return hash;
        }    
    };
    
    struct EqualCharSet {
        bool operator()(const std::multiset<char>& a, const std::multiset<char>& b) const {
            if (a.size() != b.size()) { return false; }
            
            auto it1 = a.begin();
            auto it2 = b.begin();
            
            while (it1 != a.end()) {
                if (*it1 != *it2) { return false; }
                ++it1;
                ++it2;
            }
            
            return true;
        }
    };
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<multiset<char>, vector<string>, HashCharSet, EqualCharSet> anagrams;
        
        for (const string& str : strs) {
            multiset<char> basic_str;
            for (const char c : str) { basic_str.insert(c); }
            anagrams[basic_str].push_back(str);
        } 
        
        vector<vector<string>> grouped_anagrams;
        for (const auto& char_set_to_anagrams : anagrams) { grouped_anagrams.push_back(char_set_to_anagrams.second); }
        
        return grouped_anagrams;
    }
};





















49. Group Anagrams
Medium

11359

360

Add to List

Share
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
