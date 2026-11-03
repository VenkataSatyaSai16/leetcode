class FreqStack {
private:
    unordered_map<int, int> freq;
    priority_queue<tuple<int, int , int>> pq;
    int timer;

public:
    FreqStack() {
        timer = 0;    
    }
    
    void push(int val) {
        freq[val]++;
        timer++;
        pq.push({freq[val],timer,val});
    }
    
    int pop() {
        auto [fr , ti , val] = pq.top();
        pq.pop();
        freq[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */