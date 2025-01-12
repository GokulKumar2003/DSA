class Solution {
public:
    bool canBeValid(string s, string locked) {
        
        if(s.length()%2 != 0){
            return false;
        }

        stack<int> open, unlocked;

        for(int i=0;i<s.length();i++){
            if(locked[i] == '0'){
                unlocked.push(i);
            }
            else if(s[i] == '('){
                open.push(i);
            }
            else if(s[i] == ')'){
                if(open.size()){
                    open.pop();
                }
                else if(unlocked.size()){
                    unlocked.pop();
                }
                else{
                    return false;
                }
            }
        }

        while(open.size() && unlocked.size() && open.top() < unlocked.top()){
            open.pop();
            unlocked.pop();
        }

        return open.size() == 0;
    }
};