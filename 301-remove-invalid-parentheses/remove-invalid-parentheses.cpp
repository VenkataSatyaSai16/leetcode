class Solution {
public:
    set<string> result;

    bool isSafe(const string& s) {
        int balance = 0;
        for (char c : s) {
            if (c == '(') {
                balance++;
            } 
            else if (c == ')') {
                balance--;
                if (balance < 0) return false;
            }
        }
        return balance == 0;
    }

    void computeResult(string& end, const string& s, int index, int k,int del) {
        int n = s.size();
        if (del > k) return;

        if (index == n) {
            if (del == k && isSafe(end)) {
                result.insert(end);
            }
            return;
        }
        if (del == k) {
            for (int i = index; i < n; i++)
                end.push_back(s[i]);
            if (isSafe(end))
                result.insert(end);
            for (int i = index; i < n; i++)
                end.pop_back();
            return;
        }

        if (s[index] != '(' && s[index] != ')') {
            end.push_back(s[index]);
            computeResult(end, s, index + 1, k, del);
            end.pop_back();
            return;
        }
        computeResult(end, s, index + 1, k, del + 1);
        end.push_back(s[index]);
        computeResult(end, s, index + 1, k, del);
        end.pop_back();
    }

    vector<string> removeInvalidParentheses(string s) {
        int k = 0;
        int balance = 0;

        for (char c : s) {
            if (c == '(') {
                balance++;
            }
            else if (c == ')') {
                if (balance > 0)
                    balance--;
                else
                    k++;
            }
        }
        k += balance;

        string end;
        computeResult(end, s, 0, k, 0);

        return vector<string>(result.begin(), result.end());
    }
};