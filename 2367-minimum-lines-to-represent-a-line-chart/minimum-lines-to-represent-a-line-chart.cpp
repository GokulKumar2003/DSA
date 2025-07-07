class Solution {
public:
    int minimumLines(vector<vector<int>>& price) {
        
        if(price.size() <= 2){
            return price.size() - 1;
        }

        sort(price.begin(), price.end());
        
        int lines = 1;
        for(int i=2;i<price.size();i++){
           long x1 = price[i][0], x2 = price[i-1][0], x3 = price[i-2][0];
           long y1 = price[i][1], y2 = price[i-1][1], y3 = price[i-2][1];

           long diff1 = (y3 - y2)*(x2 - x1);
           long diff2 = (y2 - y1)*(x3 - x2);

           if(diff1 != diff2){
                lines++;
           }
        }
        return lines;
    }
};