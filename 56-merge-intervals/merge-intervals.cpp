

class Solution {
public:
    struct Interval {
        int start, end;
    };

    static bool compareInterval(const Interval& i1, const Interval& i2) {
        return (i1.start < i2.start);
    }

    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& r) {
        std::vector<Interval> intervals;
        for (const auto& interval : r) {
            intervals.push_back({interval[0], interval[1]});
        }

        std::sort(intervals.begin(), intervals.end(), compareInterval);

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i - 1].end >= intervals[i].start) {
                intervals[i - 1].end = std::max(intervals[i - 1].end, intervals[i].end);
                intervals.erase(intervals.begin() + i);
                i--; 
            }
        }

        std::vector<std::vector<int>> result;
        for (const auto& interval : intervals) {
            result.push_back({interval.start, interval.end});
        }

        return result;
    }
};
