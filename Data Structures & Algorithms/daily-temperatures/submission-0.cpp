class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size());
        stack<int> main,indices;
        for(int i=0;i<temperatures.size();i++){
            if(main.empty()){
                main.push(temperatures[i]);
                indices.push(i);
            }
            else{ 
                
                if(temperatures[i]>main.top())
                {
                    while(temperatures[i]>main.top()){
                        result[indices.top()]=i-indices.top();
                        main.pop();
                        indices.pop();
                        if(main.empty()){break;}
                    }}
                    main.push(temperatures[i]);
                    indices.push(i);

                
                
            
            
        }}
        while(!indices.empty()){
            result[indices.top()]=0;
            indices.pop();
        }
        return result;
    }
};
