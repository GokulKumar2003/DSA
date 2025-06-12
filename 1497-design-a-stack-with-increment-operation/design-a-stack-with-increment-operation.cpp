class CustomStack {
public:
    stack<int> st;
    int maxi;
    CustomStack(int maxSize) {
        maxi = maxSize;
    }
    
    void push(int x) {
        if(st.size() < maxi){
            st.push(x);
        }
    }
    
    int pop() {
        int ans = -1;
        if(st.size()){
            ans = st.top();
            st.pop();
        }
        return ans;
    }
    
    void increment(int k, int val) {
        stack<int> t;
        while(st.size()){
            t.push(st.top());
            st.pop();
        }

        int ind = 0;
        while(t.size()){
            if(ind < k){
                st.push(t.top() + val);
            }
            else{
                st.push(t.top());
            }
            t.pop();
            ind++;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */