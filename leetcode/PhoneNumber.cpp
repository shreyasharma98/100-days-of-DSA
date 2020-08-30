/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/
class Solution {
public:
    void helper(int n, string s, string op, vector<string>& ans, map<int, string> mp){
        if(op.size()== n){
            ans.push_back(op);
            return;
        }
        int dg= s[0]- '0';
        s.erase(s.begin()+0);
        for(int i=0; i<mp[dg].size(); i++){
            string str= op;
            str+=mp[dg][i];
            helper(n, s, str, ans, mp);
        }
    }
    vector<string> letterCombinations(string digits) {

        map<int, string> mp ;
        mp[2]="abc"; mp[3]="def";  mp[4]="ghi";  mp[5]="jkl";
        mp[6]="mno";  mp[7]="pqrs";  mp[8]="tuv";  mp[9]="wxyz";
        vector<string> ans;
        int n= digits.size();
        if(n== 0)
            return ans;
        helper(n, digits, "", ans, mp);
        return ans;
    }
};
