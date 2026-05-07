class Solution {
public:
    bool validPalindrome(string s) 
    {
      int i=0,j=s.length()-1,x1,x2;
      bool p=true;;
      while(j>i){
        if(s[i]!=s[j]){
            x1=i;
            x2=j;
            p=false;
            break;
        }
        i++;
        j--;
      }
      if(p==true){
        return true;
      }
      else{
       p=true;
        i=0,j=s.length()-1;
        while(j>i){
            if(i==x1){
                i=i+1;
            }
            if(s[i]!=s[j]){
                
                p=false;
                break;
            }
            i++;
            j--;
        }
        if(p==true){
            return true;
        }

        p=true;
        i=0,j=s.length()-1;
        while(j>i){
            if(j==x2){
                j=j-1;
            }
            if(s[i]!=s[j]){
              
                p=false;
                  break;
            }
            i++;
            j--;
        }
        if(p==true){
            return true;
        }


      }
      return false;
      
    }
};