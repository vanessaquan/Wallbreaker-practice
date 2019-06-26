//
//  two sum.cpp
//  wallbreakers
//
//  Created by XiaoJia Quan on 6/26/19.
//  Copyright © 2019 XiaoJia Quan. All rights reserved.
//

#include <stdio.h>

//https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        //initialize a hash map that maps val in nums to its corresponding position set in nums.
        //for example:
        //if nums = [1,2,3,4,3];
        //position_map[1] = 0;
        //position_map[2] = 1;
        //position_map[3] = {2,4};
        //position_map[4] = {3};
        map<int, set<int>> position_map;
        //initialize a vector list named result. this will store the return value
        vector<int> result;
        
        //fill position_map with values in nums
        for(int i = 0; i < nums.size(); i++)
        {
            position_map[nums[i]].insert(i);
        }
        
        
        //for each element in nums, we iterate from the first to last and see if there is a corresponding val in hashmap
        //that add up to target
        for(int i = 0; i < nums.size(); i++)
        {
            //assume nums[i] is the first part of target, target-nums[i] will be the rest of target
            //if we found "target-nums[i]" exist
            //check if "target-nums[i]" is the same position as i,
            //since each position_map[j] stores a set of positions where the value j occurs in nums
            // we need a for loop to iterate the set in position_map[j] to find a position where it is not the same position as i.
            //if we found it, we just return the value i and the value in position_map[j] set which differ from i;
            //otherwise, we will continue to start the next pair
            if(position_map.find(target - nums[i]) != position_map.end())
            {
                set<int>::iterator it;
                for(it = position_map[target - nums[i]].begin(); it != position_map[target - nums[i]].end(); it++)
                    if(*it != i)
                    {
                        result.push_back(i);
                        result.push_back(*it);
                        return result;
                    }
            }
        }
        
        return result;
    }
};
