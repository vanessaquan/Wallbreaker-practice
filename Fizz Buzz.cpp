//
//  Fizz Buzz.cpp
//  wallbreakers
//
//  Created by XiaoJia Quan on 6/26/19.
//  Copyright © 2019 XiaoJia Quan. All rights reserved.
//


/*
 In this question, we want to interate through 1 to the target integer using a for loop, or while loop. In this case, I chose for loop.
 if we reached an integer that is dividable by 3 and not dividable by 5, we convert it to Fizz and push it to vector list.
 if we reached an integer that is dividable by 5 rather than 3 , we convert it to Buzz and push it to vector list.
 if can be divided by both 3 and 5, we push "FizzBuzz" to the vector list.
 otherwise, if the integer can neither be divided by 3 nor 5, we just convert that integer to a string and push it to the vector list.
 
 
 Finally, when we've tracked all the integers in range, return the vector list.
 https://leetcode.com/problems/fizz-buzz/description/
*/

#include <stdio.h>
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        
        vector<string> result;
        for(int i = 1; i<= n; i++)
        {
            if(i%3 == 0 && i%5!=0)
                result.push_back("Fizz");
            else if(i%3 != 0 && i%5 == 0)
                result.push_back("Buzz");
            else if(i%3 == 0 && i%5 == 0)
                result.push_back("FizzBuzz");
            else
            {
                result.push_back(to_string(i));
            }
        }
        
        
        return result;
    }
};
