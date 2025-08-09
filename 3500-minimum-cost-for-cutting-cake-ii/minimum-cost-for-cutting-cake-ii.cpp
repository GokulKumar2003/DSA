class Solution {
public:
    static bool cmp(int a, int b){
        return b < a;
    }
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        
        int hCount = 1, vCount = 1;
        sort(horizontalCut.begin(), horizontalCut.end(), cmp);
        sort(verticalCut.begin(), verticalCut.end(), cmp);

        long long i=0,j=0,ans=0;
        while(i < horizontalCut.size() && j < verticalCut.size()){


            if(horizontalCut[i] >= verticalCut[j]){
                ans += (horizontalCut[i]*vCount);
                hCount++;
                i++;
            }
            else{
                ans += (verticalCut[j]*hCount);
                vCount++;
                j++;
            }
        }

        while(i<horizontalCut.size()){
            ans += (horizontalCut[i]*vCount);
            hCount++;
            i++;
        }

        while(j<verticalCut.size()){
            ans += (verticalCut[j]*hCount);
            vCount++;
            j++;
        }

        return ans;
    }
};