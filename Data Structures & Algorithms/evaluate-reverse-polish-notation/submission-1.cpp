class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        string temp;
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            temp=tokens[i];
            
            if(temp=="+"||temp=="-"||temp=="*"||temp=="/"){
                operation(st,temp);
            }
            else{
                st.push(stoi(temp));
                
            }
           
        }
        return st.top();
        
    }
    void operation(stack<int> &st,string operand){
        
        int operator1=(st.top());
        st.pop();
        int operator2=(st.top());
        st.pop();

        if(operand=="+"){
            st.push((operator2 + operator1));

        }
        else if(operand=="*"){
            st.push((operator2*operator1));

        }
        else if(operand=="/"){
            st.push((operator2/operator1));

        }
        else{
            st.push((operator2-operator1));
        }
        


    }
};
