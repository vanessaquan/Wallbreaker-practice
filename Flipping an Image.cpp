//
//  Flipping an Image.cpp
//  wallbreakers
//
//  Created by XiaoJia Quan on 6/26/19.
//  Copyright © 2019 XiaoJia Quan. All rights reserved.
//


/*
 
 This question asked us to first convert 1 to 0 and convert 0 to 1. then it want use to rotate the matrix horizontally.
 
 I implemented two functions, 'flipAndInvertImage' is the main function which first convert the digits to 1 and 0 and then it pass the new A to the helper function 'flip'
 the flip function will rotate the matrix and return the rotated matrix.
 
 the main function will return what flip function returns
 https://leetcode.com/problems/flipping-an-image/description/
 
 */

#include <vector>

class Solution {
public:
    vector<vector<int>> flip(vector<vector<int>>& A)
    {
        
        for(int row = 0; row < A.size(); row++)
        {
            for(int col = 0, back = A[row].size() - 1; col < back && back >= 0; col++)
            {
                int tmp = A[row][col];
                A[row][col] = A[row][back];
                A[row][back] = tmp;
                back --;
            }
        }
        
        return A;
    }
    
    
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A)
    {
        for(int row = 0; row < A.size(); row++)
        {
            for(int col = 0; col < A[row].size(); col++)
            {
                if(A[row][col] == 0)
                    A[row][col] = 1;
                else
                    A[row][col] = 0;
            }
        }
        
        return flip(A);
    }
};
