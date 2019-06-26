//
//  friend-circles(union find).cpp
//  wallbreakers
//
//  Created by XiaoJia Quan on 6/26/19.
//  Copyright © 2019 XiaoJia Quan. All rights reserved.
//

#include <stdio.h>
//https://leetcode.com/problems/friend-circles/

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        //create a queue named friend_queue to store one friend circle's nodes
        queue<int> friend_queue;
        //create a set named visited which stores all the elements that have been visited
        set<int> visited;
        //initilize the number of friend circles to 0
        int circles = 0;
        
        //since the matrix is N*N
        //we will go through elements in range 0 to N-1, notice that the maximum circles we can find is N
        for(int i = 0; i < M.size(); i++)
        {
            //if index i has not been visited, which means it has no relations
            //with any other nodes, we increment circles by 1 and push i to queue
            if(visited.find(i) == visited.end())
            {
                circles++;
                friend_queue.push(i);
                while(!friend_queue.empty())
                {
                    int check = friend_queue.front();
                    //if front of queue not been visited
                    if(visited.find(check) == visited.end())
                    {
                        //insert it to visited and pop it out
                        visited.insert(check);
                        friend_queue.pop();
                        //insert all the index i that has no been visited and maps the position to 1
                        for(int i = 0; i < M.size(); i++)
                        {
                            if(M[check][i] == 1 && i!= check && visited.find(i) == visited.end())
                            {
                                friend_queue.push(i);
                            }
                        }
                        
                    }
                    else
                    {
                        //if front of queue has been visited, pop it out
                        friend_queue.pop();
                    }
                    
                }
            }
        }
        
        //return the number of circles
        return circles;
    }
};
