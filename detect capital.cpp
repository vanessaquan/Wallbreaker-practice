//
//  detect capital.cpp
//  wallbreakers
//
//  Created by XiaoJia Quan on 6/26/19.
//  Copyright © 2019 XiaoJia Quan. All rights reserved.
//

#include <stdio.h>
//https://leetcode.com/problems/detect-capital/description/
 
class Solution {
public:
    bool detectCapitalUse(string word) {
        // a key is a value to count the number of digits in word that is capitalized
        int key = 0;
        
        //a start is a start position of iterator
        int start = 0;
        
        //check if the first element is between 'A' and 'Z',
        //if yes, then we only need to check from the position 1 element to the last element of word.
        //if not, we will need to check the whole word
        if(word[0] >= 65 && word[0] <= 90)
            start = 1;
        else
            start = 0;
        
        //assign the length of the word to a integer named size;
        int size = word.length();
        
        //start to check the rest of word from begin to end
        for(int i = start; i < size; i++)
        {
            //if any element in word is capitalized, value of key will increment by 1
            if((word[i] >= 65) && (word[i] <= 90))
            {
                key ++;
            }
        }
        
        //now we've got the value of key, it shoule be either 0 or be the value of "size - start" in order to be valid
        //since the word starting at "start position" may contain only non-capitalized or all capitalized digits.
        //this gives true if all the rest digits of word is valid, and false if not.
        if(key == 0 || key == (size - start))
            return true;
        else
            return false;
    }
};
