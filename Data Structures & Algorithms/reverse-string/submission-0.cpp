class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        int i=0,j=s.size()-1;
        char temp;
        while(j>i){
            temp =s[i];
            s[i]=s[j];
            s[j]=temp;
            j--;
            i++;


        }   
         
    }

};