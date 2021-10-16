#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fastIO {ios_base::sync_with_stdio(false); cin.tie(NULL);}

int main(){
    fastIO
	int t;
    cin >> t;
    while(t--){
        int f = 1;
        string s;
        cin >> s;
        stack <char> st;
        for(auto it: s)
            if(st.empty()){
                if((it == ')') || (it == '}') || (it == ']')){
                    cout << "NO" << endl;
                    f = 0;
                    break;
                }
                else
                    st.push(it);
            }
            else
                if((it == ')') || (it == '}') || (it == ']')){
                    if((it == ')') && (st.top() == '('))
                        st.pop();
                    else if((it == '}') && (st.top() == '{'))
                        st.pop();
                    else if((it == ']') && (st.top() == '['))
                        st.pop();
                    else{
                        cout << "NO" << endl;
                        f = 0;
                        break;
                    }
                }
                else{
                    st.push(it);
                }

            if(st.empty() && (f==1))
                cout << "YES" << endl;
            else if(f==1)
                cout << "NO" << endl;
    }
}
