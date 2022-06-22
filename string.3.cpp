class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "")return 0;
        else if(haystack.length()<needle.length())return -1;
        else{
            int n1 = haystack.length();
            int n2 = needle.length();
            char a = needle[0];
            for(int i=0;i<=n1-n2;i++){
                if (haystack[i] == a){
                    int j=1;
                    while(j<n2 && needle[j]==haystack[i+j])j++;
                    if(j==n2)return i;
                    else continue;
                }
            }
        }
        return -1;
    }
};








class Solution {
public:
    vector<int> generateLpsArray(string &str) {
        vector<int> lps(str.size());
        int l = 0, r = 1;
        while(r < str.size()) {
            if(str[l] == str[r]) {
                lps[r] = l + 1;
                ++l;
                ++r;
            }
            else if(l > 0) l = lps[l - 1];
            else ++r;
        }
        return lps;
    }
    int strStr(string haystack, string needle) {
        if(needle.size() > haystack.size())
            return -1;
        vector<int> lps = generateLpsArray(needle);
        int hix = 0, nix = 0;
        while(hix < haystack.size()) {
            if(haystack[hix] == needle[nix]) {
                ++hix;
                ++nix;
            }
            else if(nix > 0) nix = lps[nix - 1];
            else ++hix;
            if(nix == needle.size()) return hix - nix;
        }
        return -1;
    }
};
