class KthLargest {
public:
int k;
vector<int> nums;
priority_queue<int,vector<int>, greater<int>> heap;

    KthLargest(int k, vector<int>& nums) {
        this->k =k;

        for(int num:nums){
            heap.push(num);
            
        }
        while(heap.size()>k){
            heap.pop();
        }
        
    }
    
    int add(int val) {

        heap.push(val);
        if(heap.size()>k){heap.pop();}
        if(heap.size()<k) return -1;
        return heap.top();
        
    }
};
