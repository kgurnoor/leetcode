class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ans; 
        for (string& s : strs){ //all elements of strs 
            array<int, 26> count = {0}; //initialise a fixed length array for all 26 lower case letters, corresponding to value 0
            for(char c : s) {    //all letters in each s including duplicates
                count[c - 'a'] ++ ; //whichever letter in s, increment count value, by subtracting 'a' ASCII to get index of letter
            }
            string key;
            for(int num: count){
                key += to_string(num) + '#' ;
            }
            ans[key].push_back(s); //key(as string) : value(as the array containing s)
        }
        //move only the values of ans hashmap into result 
        vector<vector<string>> result; //result array containing array of groups with same key
        for(auto& entry: ans){
            result.push_back(move(entry.second));
        }
        return result;

    }
};