class MedianFinder {
public:
priority_queue<int> left;
priority_queue<int, vector<int> , greater<int>> right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty()&&right.empty()){left.push(num);return;}
        if(left.size()>=right.size())
        {

            if(num>=left.top())right.push(num);
            else{
                right.push(left.top());
                left.pop();
                left.push(num);
            }
        }
        else{
            if(num<=right.top()) left.push(num);
            else{left.push(right.top());right.pop();right.push(num);}
        }

    }
    
    double findMedian() {
      
       if(left.size()==right.size()){
        return ((left.top()+right.top())/2.0);
       }
       
        if(left.size()>right.size())return left.top();
        else return right.top();
       
        
    }
};
