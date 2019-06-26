//
//  Transpose Matrix.cpp
//  wallbreakers
//
//  Created by XiaoJia Quan on 6/26/19.
//  Copyright © 2019 XiaoJia Quan. All rights reserved.
//


//notes:
/*The type of problem is a double vector list.
 
 To get the transpose of a matrix(a double vector list)
 we know that : [[a,b],                 [[a,c],
 [c,d]] .   ==> .    [b,d]]
 
 we can see that we need to append the same index column of each row to a list and then push that list to a vector list. In this way we can get a list of new lists that contains same index columns of each rows.
 
 
 In this solution I provides, I used an embedded for loop. the outer loop helps to track by columns, from 0 to the end of colums of a row.  the inner loop helps to iterates the number of rows. In this case, I have a double vector list A. A[row][col] will need to get the col of each row. Thus, I'll need to set col to a val and then interate rows. therefore, this is why I need row to be the inner loop instead of rows.
 for each of the element of the same col, I need to store to a temp vector int list. once I get all the element on (col n) from each rows, I insert the whole list to the double vector list.   Finally, return the double list.
 */
//https://leetcode.com/problems/transpose-matrix/description/

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>> newA;
        
        for(int col = 0; col < A[0].size(); col++)
        {
            vector<int> newrow;
            for(int row = 0; row < A.size(); row++)
            {
                newrow.push_back(A[row][col]);
            }
            newA.push_back(newrow);
        }
        
        return newA;
        
    }
};
