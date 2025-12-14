#include "bwt.h"
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

namespace bwt {
    void shiftString(std::string& str) {
        int shift = 1;
        if (str.empty()) {
            return;
        }
        int n = str.length();
        shift %= n;
        if (shift < 0) {
            shift += n;
        }

        std::string temp = str.substr(n - shift);
        str.erase(n - shift);
        str.insert(0, temp);
    }

    void encode(const string& s, string& buf, int& index)
    {
        vector<string> shifts(s.length());
        string cur = s;

        for(int i = 0; i != (int)s.length(); i++)
        {
            shifts[i] = cur;
            shiftString(cur);
        }

        sort(shifts.begin(), shifts.end());

        for(int i = 0; i != (int)s.length(); i++)
        {
            if (shifts[i] == s) {
                index = i;
            }
            buf = buf + shifts[i].back();
        }
    }

    void decode(const string& s, string& buf, int& index) {
        vector<string> shifts(s.length());

        for(int i = 0; i != (int)s.length(); i++)
        {
            for(int j = 0; j != (int)s.length(); j++)
            {
                shifts[j].insert(0, std::string(1, s[j]));
            }
            sort(shifts.begin(), shifts.end());
        }

        buf = shifts[index];
    }
}
