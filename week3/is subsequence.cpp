class Solution {
public:
    bool isSubsequence(string s, string t)
    {
        
        //iterate each element in s
        int i = 0, j = 0;
        while(i < s.length() && j < t.length())
        {
            //if s is found in t
            if(s[i] == t[j])
            {
                //goto the next char of s
                i++;
            }
            
            //increment j in each loop process
            j++;
        }
        
        if(i == s.length())
            return true;
        else
            return false;
        
    }
};
