class Solution {
public:
    bool findAllPossibleBinaryStrings(string& binaryString, int len, int ind, set<string>& strings, string str){
        if(ind == len){
            if(strings.find(str) == strings.end()){
                binaryString += str;
                return true;
            }
            return false;
        }

        string s1 = str + "1";
        string s2 = str + "0";
        if(findAllPossibleBinaryStrings(binaryString, len, ind + 1, strings, s1)){
            return true;
        }
        if(findAllPossibleBinaryStrings(binaryString, len, ind + 1, strings, s2)){
            return true;
        }
        return false;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        
        string binaryString = "";
        set<string> strings;
        for(int i=0;i<nums.size();i++){
            strings.insert(nums[i]);
        }

        findAllPossibleBinaryStrings(binaryString, nums.size(), 0, strings, "");

        return binaryString;
    }
};