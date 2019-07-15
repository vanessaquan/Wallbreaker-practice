class Solution {
public:
    vector<int> partitionLabels(string S) {
        
        //get the last element's position in S and assign to last
        int last = S.length()-1;
        //get the first element's position in S and assign it to front
        int front = 0;
        //initialize a vector list container to store the results
        vector<int> sizes;
        
        //base case
        //if S's length is 1, just return 1
        if(S.length() == 1)
            return {1};
        //if nothing in S, return 0
        else if (S == "")
            return {0};
        
        //if more than 1 element in S
        while(!S.empty())
        {
            //update last to be the last position in S
            last = S.length() - 1;
            //update front to be the first occurrence position of the last element of S
            front = S.find(S[last]);
            //get the substring by cutting from the front position to the last element
            string sub = S.substr(front, S.length() - front);
            
            //iterate each element in the substring to see if any of the characters in the substring appears somewhere even earlier than front
            //that is, if I have a substring "labacdjal" initially
            //I'll need to check, if j occurs before the first l in the original string
            //if that is the case, I'll need to reset the substring from the earliest occurence of j to the last element
            //so on ...
            int a = 0;
            while(a < sub.length())
            {
                if(S.find(sub[a]) < front)
                {
                    front = S.find(sub[a]);
                    sub = S.substr(front, S.length() - front);
                    //initalize a to 0 and start over to check the substring
                    a = 0;
                }
                a++;
            }
            
            //insert the final substring's size to the front of vector list
            sizes.insert(sizes.begin(),sub.length());
            //reset S to the rest string such that it is a complement of substring in S
            S = S.substr(0, front);
        }
        
        //return the int vector list
        return sizes;
    }
};
