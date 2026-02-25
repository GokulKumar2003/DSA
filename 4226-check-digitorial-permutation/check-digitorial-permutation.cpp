class Solution {
public:
    int getFactorial(int num){
        long long fact = 1;
        while(num > 1){
            fact = fact*num;
            num--;
        }

        return fact;
    }
    bool isDigitorialPermutation(int n) {
        
        long long digitFactorialSum = 0;
        vector<int> freq1(10, 0), freq2(10, 0);
        int num = n;
        while(num){
            long long factorial = getFactorial(num%10);
            freq1[num%10]++;
            num /= 10;
            digitFactorialSum += factorial;
        }
        while(digitFactorialSum){
            freq2[digitFactorialSum%10]++;
            digitFactorialSum /= 10;
        }

        for(int i=0;i<freq1.size();i++){
            cout << freq1[i] << " " << freq2[i] << endl;
            if(freq1[i] != freq2[i]){
                return false;
            }
        }

        return true;


        
    }
};