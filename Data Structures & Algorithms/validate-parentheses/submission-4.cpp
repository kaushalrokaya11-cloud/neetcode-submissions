class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        char c;
        
        for (char c:s)
        {
            if (c=='('|| c=='{'||c=='['){
                stk.push(c);
                continue;
            }
            if (stk.empty()){return false;}
            if((c==')' && stk.top()=='(')||(c=='}' && stk.top()=='{')||(c==']' && stk.top()=='['))
            {
                stk.pop();
            }
            else{
                return false;
            }
        }
        if (stk.empty()){
            return true;
        }
        else{return false;}

        
    }
};
