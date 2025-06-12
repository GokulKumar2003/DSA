class FreqStack {
public:
    stack<int> st;
    int maxi;
    map<int, int> m;
    FreqStack() {
        
    }
    
    void push(int val) {
        m[val] += 1;
        maxi = max(maxi, m[val]);
        st.push(val);
    }
    
    int pop() {
        stack<int> t;
        int num;
        while(st.size()){
            num = st.top();
            st.pop();
            if(m[num] == maxi){
                m[num] -= 1;
                if(m[num] == 0){
                    m.erase(num);
                }
                break;
            }
            else{
                t.push(num);
            }
        }

        while(t.size()){
            st.push(t.top());
            t.pop();
        }

        /* update maxi */
        maxi = 0;
        for(auto it:m){
            maxi = max(maxi, it.second);
        }

        return num;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */