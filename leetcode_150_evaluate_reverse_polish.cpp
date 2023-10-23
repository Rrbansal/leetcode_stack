class Solution {
public:
int solve(int val1,int val2,string ch)
{
    if(ch=="+") return val1+val2;
    if(ch=="-") return val1-val2;
    if(ch=="*") return val1*val2;
    if(ch=="/") return val1/val2;
    return 0;
}
stack<int>st;
    int evalRPN(vector<string>& tokens) {
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/")
            {
                // remember first value is val2 then val1
                int val2=st.top();
                st.pop();
                int val1=st.top();
                st.pop();
                int ans=solve(val1,val2,tokens[i]);
                st.push(ans);
            }
            else
            {
                int num=stoi(tokens[i]);
                st.push(num);
            }
        }
        return st.top();
        
    }
};
