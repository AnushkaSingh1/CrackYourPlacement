class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if(wordSet.find(endWord) == wordSet.end()) return 0;
        unordered_set<string> s1, s2;
        s1.insert(beginWord);
        s2.insert(endWord);
        int ans = 1;
        while(!s1.empty() && !s2.empty()){
            ans++;
            if(s1.size() > s2.size()) swap(s1, s2);
            unordered_set<string> temp;
            for(auto it = s1.begin(); it != s1.end(); it++){
                string w = *it;
                for(int i = 0; i < w.size(); i++){
                    char c = w[i];
                    for(int j = 0; j < 26; j++){
                        w[i] = 'a' + j;
                        if(s2.find(w) != s2.end()) return ans;
                        if(wordSet.find(w) != wordSet.end()){
                            temp.insert(w);
                            wordSet.erase(w);
                        }
                    }
                    w[i] = c;
                }
            }
            swap(s1, temp);
        }
        return 0;
    }
};




















127. Word Ladder
Hard
9.6K
1.7K
Companies
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

Constraints:

1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.
