class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> out;
        generateBacktracking(out, "", 0, 0, n);
        return out;
    }

    void generateBacktracking(vector<string>& out, string currString, int opening, int closing, int n) {
        if(currString.length() == n*2) {
            out.push_back(currString);
            return;
        }

        if(opening<n) {
            generateBacktracking(out, currString+"(", opening+1, closing, n);
        }

        if(closing<opening) {
            generateBacktracking(out, currString+")", opening, closing+1, n);
        }


    }
};
