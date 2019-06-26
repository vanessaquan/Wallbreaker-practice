//
//  longest common prefix.cpp
//  wallbreakers
//
//  Created by XiaoJia Quan on 6/26/19.
//  Copyright © 2019 XiaoJia Quan. All rights reserved.
//
//https://leetcode.com/problems/longest-common-prefix/description/
#include <stdio.h>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //return strs if strs is empty
        if (strs.empty())
            return "";
        
        //otherwise, if input string not empty
        //check each substring of the first word in strs
        //initialize the index for string.substr() function to be 1;
        
        int sub = 1;
        
        //substr will hold the substring from 0 to sub-1 position
        string substr = strs[0].substr(0, sub);
        
        //s will store the return string
        string s = "";
        
        //using a for loop to iterate each word in strs
        for(int i = 0, j = strs.size() - 1; j >= 0;)
        {
            //if j is reached to 0, it means we've checked all substring in each word where substr is s[0].substr(0, sub)
            if(j == 0)
            {
                //assign this substr to s
                s = substr;
                
                //update the substr by next larger substr, if substr already reached the end of s[0], just return s
                //otherwise, update substr and j to become the last position of list
                if(sub + 1 <= strs[0].length())
                {
                    sub ++;
                    substr = strs[0].substr(0, sub);
                    j = strs.size() - 1;
                }
                else
                    return s;
                
            }
            
            //if sub is less than current word's length, which means we can get the substring of current word
            if(sub <= strs[j].length())
            {
                //check if current word's substring is equal to s[0]
                //if equal, then we continue to check the next last of word in list
                //otherwise if not euqal, there is no need to go further, we just return s
                if(substr == strs[j].substr(0, sub))
                    j --;
                else
                    return s;
            }
            //if sub is out of range, which means we cannot get a substr with the providing sub
            //we just need to return s
            else
                return s;
            
        }
        return s;
    }
};
