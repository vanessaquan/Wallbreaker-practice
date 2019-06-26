//
//  valid-palindrome.cpp
//  wallbreakers
//
//  Created by XiaoJia Quan on 6/26/19.
//  Copyright © 2019 XiaoJia Quan. All rights reserved.
//
//https://leetcode.com/problems/valid-palindrome/description/
#include <stdio.h>


class Solution {
public:
    bool isPalindrome(string s)
    {
        //if s contains only a single element or s is empty, return true
        if(s == "" || s.length() == 1)
            return true;
        
        //initialize size to be the length of input s
        int size = s.length();
        
        //set two iters i and j, let i to start from front and j from back of s
        //the for loop ends when i == j
        for(int i = 0, j = size - 1; i < j && j >= 0; )
        {
            //if s[i] is not an alphanumeric char, we need to go to the next char of s[i]
            if((s[i] > 90 && s[i] < 97) || s[i] > 122 || s[i] < 48 || (s[i] > 57 && s[i] < 65))
            {
                i++;
            }
            //if s[j] is not an alphanumeric char, we need to go to the previous char of s[j]
            else if( (s[j] > 90 && s[j] < 97) || s[j] > 122 || s[j] < 48 || (s[j] > 57 && s[j] < 65))
            {
                j--;
            }
            //if both s[j] and s[i] are  alphanumeric char, we compare them
            else
            {
                //if both chars equal or they are only differs in capitals, we continue to check next pair of chars
                if((s[i] == s[j]) ||((s[i] >= 65)&&(s[i]+32 == s[j] ))  || ((s[j] >= 65)&&(s[j] +32 == s[i] )))
                {
                    i++;
                    j--;
                }
                //if they are not equal, return false directly
                else
                    return false;
            }
        }
        
        //returns true if passed all conditions
        return true;
        
    }
};
