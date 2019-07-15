class Solution {
public:
    int numJewelsInStones(string J, string S) {
        //create a set named mapJ to store elements in J
        unordered_set <char> mapJ;
        
        //first, store all the element in J to set
        for(int i = 0; i < J.length(); i++)
        {
            mapJ.insert(J[i]);
        }
        
        
        //use variable 'count' to count the total number of Js in S
        int count = 0;
        //if element in S is found in J, increment count by 1
        for(int i = 0; i < S.length(); i++)
        {
            if(mapJ.find(S[i]) != mapJ.end())
                count ++;
        }
        
        //return the value of count
        return count;
        
    }
};
