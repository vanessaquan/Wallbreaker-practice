//
//  reverse words in a string III.cpp
//  wallbreakers
//
//  Created by XiaoJia Quan on 6/26/19.
//  Copyright © 2019 XiaoJia Quan. All rights reserved.
//

//https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
#include <stdio.h>
class Solution {
public:
    
    string reverseWords(string s)
    {
        //single stores a single word
        string single = "";
        
        // newS will store the reversed string
        string newS = "";
        //wordLen is the length of input string
        int wordLen = s.length();
        
        // use a for loop to go through each char in string
        for(int i = 0; i < wordLen; i++)
        {
            
            //if reached a white space char, it means single now stored a whole word
            if(s[i] == ' ')
            {
                //add single to back of newS and reset single to empty string
                newS += single;
                single = "";
                //if we reached the end of string, we don't need to add a white space, otherwise, we add a whitespace to back of newS
                if(i+1 != wordLen)
                    newS += ' ';
            }
            //if i reached the end of string, we also add the char to single and add single to newS
            else if(i == (wordLen - 1))
            {
                single = s[i]+single;
                newS += single;
            }
            //otherwise, we add char to single's front, so that it is in reverse order
            else
                single = s[i] + single;
        }
        
        //return the whole new string.
        
        return newS;
    }
};
