class Solution {
public:
    bool isSubsequence(string s, string t) {
        int pt1 = 0;
        int pt2 = 0;

        if(s.size() == 0 ){
            return true;
        }

        if(s.size()== 1 && t.size() == 1 && s[0] != t[0]){
            return false;
        }


        while(pt2 < t.size()){
            if(s[pt1] == t[pt2]){
                pt1++;
                pt2++;
            }
            else{
                pt2++;
            }
        }

        if(pt1 < (s.size())){
            return false;
        }
        else{
            return true;
        }
    }
};