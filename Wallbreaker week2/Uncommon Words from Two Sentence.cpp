class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        
        //use word_valA map to store each words with corresponding occurrence in each string
        map<string,int> word_valA;
        
        //word_valB to store words in B with each words' ocurrence
        map<string,int> word_valB;
        
        
        string word = "";
        //store words in A to map and assign each word an ocurrence value
        for(int i = 0; i < A.length(); i++)
        {
            
            if(A[i] == ' ')
            {
                if(word_valA.find(word) == word_valA.end())
                {
                    word_valA[word] = 1;
                }
                else
                    word_valA[word] ++;
                word = "";
            }
            else
                word += A[i];
            
        }
        
        //add the last word to map, if it is already in the map, increment its' occurence by 1
        if(word_valA.find(word) == word_valA.end())
        {
            word_valA[word] = 1;
        }
        else
            word_valA[word] ++;
        
        
        //reset word to empty string
        word = "";
        //do the same as previous step, instead of string A, we now add words in B to map of B
        for(string::iterator sB = B.begin(); sB != B.end(); ++sB)
        {
            cout << *sB << " ";
            if(*sB == ' ')
            {
                if(word_valB.find(word) == word_valB.end())
                {
                    word_valB[word] = 1;
                }
                else
                    word_valB[word] ++;
                
                word = "";
            }
            else
                word += *sB;
            
        }
        
        if(word_valB.find(word) == word_valB.end())
        {
            word_valB[word] = 1;
        }
        else
            word_valB[word] ++;
        
        
        //iterators
        map<string, int> ::iterator itA = word_valA.begin();
        map<string, int> ::iterator itB = word_valB.begin();
        //create a unique vector list to store the elements that are unique in each list
        vector<string> unique;
        for(; itA != word_valA.end(); itA++)
        {
            //if occurrence of a word is 1 and it is not found in B, then push it to vector list
            if(word_valB.find(itA->first) == word_valB.end() && itA->second == 1)
                unique.push_back(itA->first);
        }
        
        //do the same thing as previous loop
        for(;itB != word_valB.end(); itB++)
        {
            if(word_valA.find(itB->first) == word_valA.end() && itB->second == 1)
                unique.push_back(itB->first);
        }
        
        //now vector list was filled with unique uncommmon words of two string, simply return the unique vector
        return unique;
        
    }
};
