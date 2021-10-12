class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, int> cnt;
        for (int x : arr) cnt[x]++;
        
        for (int x : arr) {
            if (cnt[x] == 0) continue;
            if (x < 0 && x % 2 != 0) return false; 
            int y = x > 0 ? x*2 : x/2;
            if (cnt[y] == 0) return false; 
            cnt[x]--;
            cnt[y]--;
        }
        return true;
    }
};
