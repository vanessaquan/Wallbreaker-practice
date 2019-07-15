class Solution {
public:
    
    vector<int> findAnagrams(string s, string p) {
        //if two strings are equal, just return the 0
        if(s == p)
            return {0};
        //otherwise if s's length is even less than p's  , return nothing
        else if(s.length() < p.length())
            return {};
        
        
        //create a pos vector list to store the positions that the anagrams start
        vector <int> pos;
        
        //create a multiset str to store the required length's char in sorted order
        multiset<char> str;
        str.insert(p.begin(), p.begin()+p.length());
        
        
        for(int it = 0; it < s.length(); it++)
        {
            
            int j = p.length() - 1;
            //sub is another multiset that stores the chars in s with the same length as p requires
            multiset<char> sub;
            
            while(j >= 0)
            {
                if(it+j >= s.length())
                    break;
                else
                    sub.insert(s[it+j]);
                j --;
            }
            
            //if two sets are equal, then this means the position start with it and ends in p length is an anagram of p
            if(sub == str)
                pos.push_back(it);
            
        }
        
        //return the collection of positions
        
        return pos;
        
    }
};
