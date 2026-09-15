class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
            [](auto& a, auto& b) {
                return a[1] < b[1];
            });


        int res = 0;
        int lastEnd = INT_MIN;

        for (auto& interval : intervals) {
            if (interval[0] < lastEnd) {
                res++;
            }
            else {
                lastEnd = interval[1];
            }
        }

        return res;
    }
};
