class Solution {
public:
    string minWindow(string s, string t) {
       unordered_map<char,int> mp;
        for(auto ch:t)
        {
            mp[ch]++;
        }
        int dist=mp.size() ;
        unordered_map<char,int> window;
        int count = 0 , ll = 0 , rr = 0 ;
        int l = 0 , r = 0 , ans = INT_MAX ;
        while(r<s.length())
        {
            window[s[r]]++ ;
            if(mp.count(s[r]) and mp[s[r]]==window[s[r]])
            {
                    count++;
            }
            r++;
            while(count == dist and l < r)
            {
                if(ans > r-l)
                {
                    ans= r - l ;
                    ll = l ;
                    rr = r ;
                }
                window[s[l]]-- ;
                if(mp.count(s[l]) and window[s[l]] < mp[s[l]])
                {
                        count--;
                }
                l++;
            }
        }
        return s.substr(ll,rr-ll);
    }
};
