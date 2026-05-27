class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26);
        priority_queue<int> maxHeap;
        queue<pair<int,int>> q;

        for(auto task: tasks){
            count[task-'A']++;
        }
        
        for(int i=0;i<count.size();i++){
            if(count[i]==0)continue;
            maxHeap.push(count[i]);
        }
        int time=0;
        while(!q.empty()|| !maxHeap.empty()){
            if(!q.empty() && time == q.front().second){maxHeap.push(q.front().first);q.pop();}
            if(!maxHeap.empty()){
                int element= maxHeap.top()-1;maxHeap.pop();
            
                 if(element>0){q.push({element,time+n+1});}
            }
                 time++;

            
        }
        return time;
    }
};
