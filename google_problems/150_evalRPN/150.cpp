class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for (const string& item: tokens) {
            if (item == "+" || item == "-" || item == "*" || item == "/") {
                int right = stk.top();
                stk.pop();
                int left = stk.top();
                stk.pop();
                if (item == "+") {
                    stk.push(left + right);
                } else if (item == "-") {
                    stk.push(left - right);
                } else if (item == "*") {
                    stk.push(left * right);
                } else if (item == "/") {
                    stk.push(left / right);
                }
            } else {
                stk.push(stoi(item));
            }

        }
        return stk.top();
        
    }
};