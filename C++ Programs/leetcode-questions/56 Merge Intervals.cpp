class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        for(auto& i : intervals) {
           
            if(!res.empty() && i[0] <= res.back()[1]) {
                res.back()[1] = max(res.back()[1], i[1]);
            } else 
                res.push_back(i);
            
           
        }
        return res;
    }
};
