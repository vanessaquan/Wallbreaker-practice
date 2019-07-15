class Solution {
public:
    int firstUniqChar(string s)
    {
        for(int i = 0; i < s.length(); i++)
        {
            //use an rfind function find the last occurence of s[i]
            //if the last occurence of s[i] is i, return i
            //otherwise, continue to find one
            if(s.find(s[i]) == s.rfind(s[i]))
                return i;
        }
        return -1;
    }
};
