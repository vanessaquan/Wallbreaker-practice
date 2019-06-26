//
//  reverse string.cpp
//  wallbreakers
//
//  Created by XiaoJia Quan on 6/26/19.
//  Copyright © 2019 XiaoJia Quan. All rights reserved.
//

#include <stdio.h>

/*
 The problem is to reverse a string stored in vector list.
 To do that, we will need to make the first element to become the last element and so on...
 one thing we can do is to swap those element. in this case, i used two iterators, one "front" and one "back". "front" will start from the first element and iterates to the last.
 "back" will start from the last element and iterates to the start.
 if "front" and "back" meet each other, which means we've went through and swapped all element, we can stop the loop.
*/

class Solution {
public:
    void reverseString(vector<char>& s)
    {
        for(int front = 0, back = s.size() -1; front < back; front ++, back --)
        {
            char c = s[front];
            s[front] = s[back];
            s[back] = c;
        }
    }
};
