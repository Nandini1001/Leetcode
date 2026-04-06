class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0, y = 0, ans = 0;
        char xdir = '0', ydir = '+';

        unordered_map<int, set<int>> xmap, ymap;

        for (auto &o : obstacles) {
            xmap[o[0]].insert(o[1]);
            ymap[o[1]].insert(o[0]);
        }

        for (int i : commands) {
            if (i == -1) { // turn right
                if (ydir == '+') { xdir = '+'; ydir = '0'; }
                else if (ydir == '-') { xdir = '-'; ydir = '0'; }
                else if (xdir == '+') { xdir = '0'; ydir = '-'; }
                else { xdir = '0'; ydir = '+'; }
            }
            else if (i == -2) { // turn left
                if (ydir == '+') { xdir = '-'; ydir = '0'; }
                else if (ydir == '-') { xdir = '+'; ydir = '0'; }
                else if (xdir == '+') { xdir = '0'; ydir = '+'; }
                else { xdir = '0'; ydir = '-'; }
            }
            else {
                // moving in X direction
                if (xdir != '0') {
                    if (ymap.count(y)) {
                        auto &st = ymap[y];

                        if (xdir == '+') {
                            auto it = st.lower_bound(x + 1);
                            if (it != st.end() && *it <= x + i)
                                x = *it - 1;
                            else
                                x += i;
                        }
                        else { // xdir == '-'
                            auto it = st.lower_bound(x);
                            if (it != st.begin()) {
                                --it;
                                if (*it >= x - i)
                                    x = *it + 1;
                                else
                                    x -= i;
                            } else {
                                x -= i;
                            }
                        }
                    } else {
                        if (xdir == '+') x += i;
                        else x -= i;
                    }
                }
                // moving in Y direction
                else {
                    if (xmap.count(x)) {
                        auto &st = xmap[x];

                        if (ydir == '+') {
                            auto it = st.lower_bound(y + 1);
                            if (it != st.end() && *it <= y + i)
                                y = *it - 1;
                            else
                                y += i;
                        }
                        else { // ydir == '-'
                            auto it = st.lower_bound(y);
                            if (it != st.begin()) {
                                --it;
                                if (*it >= y - i)
                                    y = *it + 1;
                                else
                                    y -= i;
                            } else {
                                y -= i;
                            }
                        }
                    } else {
                        if (ydir == '+') y += i;
                        else y -= i;
                    }
                }

                ans = max(ans, x * x + y * y);
            }
        }
        return ans;
    }
};