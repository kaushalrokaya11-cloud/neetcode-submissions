class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        string temp;
        stack<string> st;
        for(int i=0;i<tokens.size();i++){
            temp=tokens[i];
            st.push(temp);
            
            if(temp=="+"||temp=="-"||temp=="*"||temp=="/"){
                operation(st);
            }
           
        }
        return stoi(st.top());
        
    }
    void operation(stack<string> &st){
        //int operand=stoi(oper);
        string operand=st.top();
        st.pop();
        int operator1=stoi(st.top());
        st.pop();
        int operator2=stoi(st.top());
        st.pop();

        if(operand=="+"){
            st.push(to_string(operator2 + operator1));

        }
        else if(operand=="*"){
            st.push(to_string(operator2*operator1));

        }
        else if(operand=="/"){
            st.push(to_string(operator2/operator1));

        }
        else{
            st.push(to_string(operator2-operator1));
        }
        


    }
};
