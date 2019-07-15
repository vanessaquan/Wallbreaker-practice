class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words)
    {
        map <char, string> key;
        string morse[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        char k = 'a';
        //map each morse code with an alphabet, starting from 'a'
        for(int i = 0; i < 26; i++)
        {
            key[k] = morse[i];
            k++;
        }
        
        set<string> encode;
        for(int i = 0; i < words.size(); i++)
        {
            string s = "";
            for(int j = 0; j < words[i].length(); j++)
            {
                s += morse[words[i][j] - 'a'];
            }
            encode.insert(s);
        }
        
        
        return encode.size();
        
    }
};
