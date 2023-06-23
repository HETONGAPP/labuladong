//「使括号有效的最少添加」：


int minAddToMakeValid(string s) {
 // res 记录插⼊次数
    int res = 0;
 // need 变量记录右括号的需求量
    int need = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
        // 对右括号的需求 + 1
        need++;
        }
 
        if (s[i] == ')') {
        // 对右括号的需求 - 1
            need--;
            if (need == -1) {
                need = 0;
                // 需插⼊⼀个左括号
                res++;
            }
        }
 }
 
 return res + need;
}
//加两个
int minInsertions(string s) {
 // need 记录需右括号的需求量
 int res = 0, need = 0;
 
 for (int i = 0; i < s.size(); i++) {
 // ⼀个左括号对应两个右括号
    if (s[i] == '(') {
        need += 2;
    }
 
    if (s[i] == ')') {
        need--;
    }
 }
 
 return res + need;
}




bool isValid(string str) {
    stack<char> left;
    for(char c : str)
    {
        if(c=='(' || c=='['|| c=='{')
            left.push(c);
        else
        {
            if(!left.empty() && leftof(c) == left.top())
                left.pop();
            else
                return false
        }
    }
    return left.empty();
}

char leftof(char c)
{
    if(c==')') return '(';
    if(c==']') return '[';
    return '{';
}




class Solution {
    public int longestValidParentheses(String s) {
        Stack<Integer> stk = new Stack<>();
        // dp[i] 的定义：记录以 s[i-1] 结尾的最长合法括号子串长度
        int[] dp = new int[s.length() + 1];
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                // 遇到左括号，记录索引
                stk.push(i);
                // 左括号不可能是合法括号子串的结尾
                dp[i + 1] = 0;
            } else {
                // 遇到右括号
                if (!stk.isEmpty()) {
                    // 配对的左括号对应索引
                    int leftIndex = stk.pop();
                    // 以这个右括号结尾的最长子串长度
                    int len = 1 + i - leftIndex + dp[leftIndex];
                    dp[i + 1] = len;
                } else {
                    // 没有配对的左括号
                    dp[i + 1] = 0;
                }
            }
        }
        // 计算最长子串的长度
        int res = 0;
        for (int i = 0; i < dp.length; i++) {
            res = Math.max(res, dp[i]);
        }
        return res;
    }
}



class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int result = 0;
        st.push(-1);
        for(int i = 0 ; i < s.size(); ++i)
        {
            if(s[i]=='(')
                st.push(i);
            else
            {
                st.pop();
                if(st.empty())
                {
                    st.push(i);
                }
                else
                {
                    result = max(result, i-st.top());
                }    
            }

        }
        return result;
    }
};
