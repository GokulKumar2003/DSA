class Solution {
public:
    int minimizeXor(int num1, int num2) {
        
        vector<int> num1Bin;
        int cnt=0, bits = 0;

        while(num1){
            num1Bin.push_back(num1%2);
            num1 /= 2;
        }

        while(num2){
            if(num2%2 == 1){
                cnt += 1;
            }
            num2 /= 2;
            bits+=1;
        }

        int rem = cnt - num1Bin.size();
        while(rem > 0 && rem--){
            num1Bin.push_back(0);
        }
        reverse(num1Bin.begin(), num1Bin.end());
        cout << cnt << endl;
        for(int i=0;i<num1Bin.size() && cnt;i++){
            if(num1Bin[i] == 1){
                cnt -= 1;
                num1Bin[i] = -1;
            }
        }

        for(int i=num1Bin.size()-1;i>=0 && cnt;i--){
            if(num1Bin[i] == 0){
                cnt -= 1;
                num1Bin[i] = -1;
            }
        }

        for(int i=0;i<num1Bin.size();i++){
            cout << num1Bin[i] << " ";
        }

        int mini = 0;
        for(int i=num1Bin.size()-1, p = 0;i>=0;i--,p++){
            if(num1Bin[i] == -1){
                mini += pow(2, p);
            }
        }
        return mini;
    }
};