class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for(int stone: stones){
            maxHeap.push(stone);
            
        }

        while(maxHeap.size()> 1){
          int f= maxHeap.top();
          maxHeap.pop();
          int s= maxHeap.top();
          maxHeap.pop();

          if(f!=s){maxHeap.push(f-s);}

        }
       return (maxHeap.size()==1?maxHeap.top():0);
        
    }
};
