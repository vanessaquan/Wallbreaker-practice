//
//  number of islands.cpp
//  wallbreakers
//
//  Created by XiaoJia Quan on 6/26/19.
//  Copyright © 2019 XiaoJia Quan. All rights reserved.
//

#include <stdio.h>
//https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        //use a map named pairs to store the set of '1''s col in each role
        map<int, set<int>> pairs;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    pairs[i].insert(j);
                    cout << " " << i << ", "<< j<< endl;
                }
            }
        }
        
        //count_island will count the number of islands
        int count_island = 0;
        
        //create a pair named singlePair to store a single pair
        pair <int, int> singlePair;
        stack<pair <int, int>> island;
        set<pair <int, int>> visited;
        
        //iterates all pairs in map
        for(map<int, set<int>> ::iterator it = pairs.begin(); it != pairs.end(); it++)
        {
            for(set<int> ::iterator itset = pairs[it->first].begin(); itset != pairs[it->first].end(); itset ++)
            {
                singlePair = make_pair(it->first, *itset);
                //if singlepair has been visited, we just skip it and go to the next pair
                //otherwise, push it to stack, since it's not been visited while to go to each neightbors point
                //it is isolate to any node we've gone through before
                //thus, the island number should increment by 1
                if(visited.find(singlePair) == visited.end())
                {
                    
                    island.push(singlePair);
                    count_island ++;
                    
                    //continuing adding new point (a, b) where the point (a, b) is in pairs map and has not been visited, remember: the pairs map stores all points that it's value = 1
                    //the while loop continues to find each up, left, right, bottom points for the top point pair in stack until the stack is emtpy
                    //whatever left in pairs that has not been visited, it belongs to some other islands.
                    while(!island.empty())
                    {
                        int row = island.top().first;
                        int col = island.top().second;
                        cout << "current"<< row << ", "<< col << endl;
                        if(visited.find(island.top()) != visited.end())
                        {
                            
                            island.pop();
                        }
                        else
                        {
                            visited.insert(island.top());
                            island.pop();
                            //check left
                            if(col -1 >= 0
                               && pairs[row].find(col - 1) != pairs[row].end())
                            {
                                
                                pair <int,int> newPair = make_pair(row, col- 1);
                                if(visited.find(newPair)==visited.end())
                                {
                                    island.push(newPair);
                                }
                            }
                            
                            //check right
                            if(col + 1 < grid[row].size()
                               && pairs[row].find(col + 1) != pairs[row].end())
                            {
                                
                                pair<int, int> newPair = make_pair(row, col + 1);
                                if(visited.find(newPair)==visited.end())
                                {
                                    island.push(newPair);
                                }
                            }
                            
                            //check bottom
                            if(row + 1 < grid.size()
                               && pairs.find(row+1)!=pairs.end()
                               && pairs[row+1].find(col) != pairs[row+1].end())
                            {
                                
                                pair<int, int> newPair = make_pair(row+1, col);
                                if(visited.find(newPair)==visited.end())
                                {
                                    island.push(newPair);
                                }
                            }
                            
                            
                            //check up
                            if(row - 1 >= 0
                               && pairs.find(row - 1) != pairs.end()
                               && pairs[row-1].find(col) != pairs[row-1].end())
                            {
                                
                                pair<int, int> newPair = make_pair(row-1, col);
                                if(visited.find(newPair)==visited.end())
                                {
                                    island.push(newPair);
                                }
                            }
                        }
                    }
                }
            }
            
        }
        
        
        return count_island;
        
    }
};
