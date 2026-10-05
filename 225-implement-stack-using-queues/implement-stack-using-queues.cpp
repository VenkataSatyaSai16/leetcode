class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        // Move all elements except the last one
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        // Last element is the stack top
        int result = q1.front();
        q1.pop();

        // Move everything back
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }

        return result;
    }
    
    int top() {
        // Move all elements except the last one
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        // Last element is the stack top
        int result = q1.front();

        // Move it too
        q2.push(q1.front());
        q1.pop();

        // Move everything back
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }

        return result;
    }
    
    bool empty() {
        return q1.empty();
    }
};