class Solution {
public:
    void f(vector<string>& ans, string& temp, int x, int y) {
        
        // No '(' or ')' left
        if (x == 0 && y == 0) {
            ans.push_back(temp);
            return;
        }

        // Take '('
        if (x > 0) {
            temp += '(';
            f(ans, temp, x - 1, y);
            temp.pop_back();
        }

        // Take ')' only if there are more ')' available
        if (y > x) {
            temp += ')';
            f(ans, temp, x, y - 1);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";

        f(ans, temp, n, n);

        return ans;
    }
};