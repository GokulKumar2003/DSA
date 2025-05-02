class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        
        long long ans = 0;
        stack<int> st1, st2;

        int n = nums.size();
        vector<int> next_smaller(n), prev_smaller(n);
        vector<int> next_larger(n), prev_larger(n);
        for(int i=0;i<n;i++){
            next_smaller[i] = n-i-1;
            next_larger[i] = n-i-1;
            prev_smaller[i] = i;
            prev_larger[i] = i;
        }

        for(int i=0;i<n;i++){
            while(st1.size() && nums[i] < nums[st1.top()]){
                next_smaller[st1.top()] = i - st1.top() - 1;
                st1.pop();
            }

            while(st2.size() && nums[i] > nums[st2.top()]){
                next_larger[st2.top()]  = i - st2.top() - 1;
                st2.pop();
            }

            st1.push(i);
            st2.push(i);
        }
        while(st1.size()){
            st1.pop();
        }
        while(st2.size()){
            st2.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(st1.size() && nums[i] <= nums[st1.top()]){
                prev_smaller[st1.top()] = st1.top() - i - 1;
                st1.pop();
            }
            while(st2.size() && nums[i] >= nums[st2.top()]){
                prev_larger[st2.top()] = st2.top() - i - 1;
                st2.pop();
            }
            st1.push(i);
            st2.push(i);
        }

        for(int i=0;i<n;i++){
            ans += nums[i]*((long long)(next_larger[i] + 1)*(prev_larger[i] + 1) - (long long)(next_smaller[i] + 1)*(prev_smaller[i] + 1));
        }
        
        for(int it:next_smaller){
            cout << it << " ";
        }
        cout << endl;
        for(int it:next_larger){
            cout << it << " ";
        }
        cout << endl;
        for(int it:prev_smaller){
            cout << it << " ";
        }
        cout << endl;
        for(int it:prev_larger){
            cout << it << " ";
        }
        cout << endl;
        return ans;
    }
};