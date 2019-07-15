class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        int a = 0;
        int left, right, count = 0;
        if(points.size() <= 1)
            return points.size();
        
        //sort the vector list in ascending order
        sort(points.begin(), points.end());
        
        //a is 0 initially
        left = points[a][0];
        right = points[a][1];
        count ++;
        a++;
        
        while(a < points.size())
        {
            //resize the interval
            if(left < points[a][0])
            {
                left = points[a][0];
                if(right > points[a][1])
                    right = points[a][1];
            }
            
            //if the current element's left is greater than our default right, count will increase
            //reset left and right value
            if(points[a][0] > right)
            {
                count ++;
                left = points[a][0];
                right = points[a][1];
            }
            
            //increment position a arter each iteration
            a++;
        }
        //reutrn the number of count
        return count;
    }
};
