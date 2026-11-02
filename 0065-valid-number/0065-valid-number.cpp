class Solution {
public:
    bool isNumber(string s) {
        bool num=false,dot=false,exp=false,numAfterExp=true;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            //digit
            if(c>='0' && c<='9'){
                num=true;
                numAfterExp=true;
            }
            //sign
            else if(c=='-' || c=='+'){
                if(i!=0 && s[i-1]!='e' && s[i-1]!='E')return false;
            }
            //dot
            else if(c=='.'){
                if(dot||exp)return false;
                dot=true;
            }
            else if(c=='e'||c=='E'){
                if(exp||!num)return false;
                exp=true;
                numAfterExp=false;
            }
            else return false;
        }
        return num&&numAfterExp;
        
    }
};