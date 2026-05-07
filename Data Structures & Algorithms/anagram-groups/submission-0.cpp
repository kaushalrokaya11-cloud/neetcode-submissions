class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string,vector<string>> mainhash;
       vector<vector<string>> final;
       string key;
      for(string str:strs){
        key=signature(str);
       mainhash[key].push_back(str);}
       for( auto pair:mainhash)
       {
        final.push_back(pair.second);
       }
       return final;
    }
    string signature(string str){
unordered_map <char, int>freq;
for(char c='a';c<='z';c++)
{
    freq[c]++;
}
for(char ch: str){
    freq[ch]++;

}
stringstream key;
for(auto pair:freq){
 key<<pair.second<<'#';
 
}
string finalkey;
finalkey=key.str();
return finalkey;


 }

};
