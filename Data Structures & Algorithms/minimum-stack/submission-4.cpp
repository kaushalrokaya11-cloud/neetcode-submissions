class MinStack {
public:
    stack <int> st;
    stack <int> minst;
    int mini;

    
    MinStack() 
    {
        
    }
    
    void push(int val) 
    {   if(st.empty()){
        mini=val;}
        else{
            mini=min(val,minst.top());
        }
        minst.push(mini);
        st.push(val);
    }

    
    
    void pop() {
       
        
        minst.pop();
        
         st.pop(); 
        
        
    }
    
    int top() {
        return st.top();
        
    }
    
    int getMin() {
        return minst.top();
        
    }
};
