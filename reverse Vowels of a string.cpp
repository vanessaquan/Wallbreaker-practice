//
//  reverse Vowels of a string.cpp
//  wallbreakers
//
//  Created by XiaoJia Quan on 6/26/19.
//  Copyright © 2019 XiaoJia Quan. All rights reserved.
//
//https://leetcode.com/problems/reverse-vowels-of-a-string/description/
#include <stdio.h>
class Solution {
public:
    string reverseVowels(string s) {
        //initialize a set of char named vowels which stores all the vowels in it.
        //the vowels in English contains: a e i o u
        set<char> vowels;
        vowels.insert('a');
        vowels.insert('A');
        vowels.insert('e');
        vowels.insert('E');
        vowels.insert('i');
        vowels.insert('I');
        vowels.insert('o');
        vowels.insert('O');
        vowels.insert('u');
        vowels.insert('U');
        
        //set two iterators i and j
        //i iterates from front of s
        //j iterates from back of s
        //i must less than j in order to swap s[i] and s[j]
        //if s[i] is found in the set vowels, then s[i] is a vowel,
        // ...we need also check if s[j] is a vowel, if not we need to go s[j-1], else we swap s[i] and s[j]
        //if s[i] is not a vowel, just go to s[i+1]
        //if s[j] is not a vowel, just go to s[j -1]
        //the loop ends when i == j, which means we've iterates through all elements in the list
        for(int i = 0, j = s.length() - 1; i < j;)
        {
            if(vowels.find(s[i]) != vowels.end() && vowels.find(s[j]) != vowels.end())
            {
                char c = s[i];
                s[i] = s[j];
                s[j] = c;
                i++;
                j--;
            }
            else if(vowels.find(s[i]) == vowels.end())
                i++;
            else if(vowels.find(s[j]) == vowels.end())
                j--;
            
        }
        
        //return the swapped string
        return s;
        
    }
};
