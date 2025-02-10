class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for(int i = 0; i < s.size() ; i++){
            if(s[i] >= '0' && s[i] <= '9'){
                if(!st.empty())st.pop();
            }
            else st.push(s[i]);
        }
        string a= "",b ="";
        while(!st.empty()){
            b += st.top();
            st.pop();
        }
        for(int i = b.size() - 1 ; i >= 0 ; i--){
            a += b[i];
        }
        return a;
    }
};