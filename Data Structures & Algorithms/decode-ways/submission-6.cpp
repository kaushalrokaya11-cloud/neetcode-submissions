class Solution {
public:
    int numDecodings(string s)
    {
        if(s[0]=='0'){return 0;} 
        int a1=1, a2=0;
        int isLast2=0;
        for(int i=1;i<s.length();i++)
        {
            if(a1==0 && a2==0){
                return 0;
                
            }
            if(stoi(s.substr(i-1,2))>26&&s[i]=='0'){return 0;}
            if(stoi(s.substr(i-1,2))>26){ a1=a2+a1; a2=0; continue;}
            if(s[i]=='0'){a2=a1;a1=0; continue; }
          

            
            int temp1=a1+a2;
            int temp2= a1;
            a1=temp1;
            a2=temp2;
            
          
        }
        return (a1+a2);

    }
};
