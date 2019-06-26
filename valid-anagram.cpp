//
//  valid-anagram.cpp
//  wallbreakers
//
//  Created by XiaoJia Quan on 6/26/19.
//  Copyright © 2019 XiaoJia Quan. All rights reserved.
//

#include <stdio.h>
//https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    bool isAnagram(string s, string t) {
        //initialize a hash map to store the number of occurence of each characters in s
        map<char, int> char_count;
        
        //if two string's length not the same, return false directly
        if(s.length() != t.length())
            return false;
        
        //assign values to char_count map
        for(int i = 0; i < s.length(); i++)
        {
            if(char_count.find(s[i]) == char_count.end())
                char_count[s[i]] = 1;
            else
                char_count[s[i]] ++;
        }
        
        //iterates string t
        //if any element in t is not found in map, which means the charater is in t but not s, return false
        //if element A in t is also found in s, see if the val of A in map is reached to 0
        //if it reached to 0, it means the number of A in 's' is less than the number of A in 't'. return false
        //otherwise, reduce the val of A in map.
        //return true if all conditions not appllied
        for(int j = 0; j < t.length(); j++)
        {
            if(char_count.find(t[j]) == char_count.end())
                return false;
            else if(char_count[t[j]] == 0)
                return false;
            else
                char_count[t[j]] --;
        }
        
        return true;
        
    }
};
