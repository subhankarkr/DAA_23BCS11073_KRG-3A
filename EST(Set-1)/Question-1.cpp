class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        int need[128] = {0};
        int have[128] = {0};

        // Count required characters
        int required = 0;
        for (int i = 0; i < t.size(); i++) {
            if (need[t[i]] == 0) required++;
            need[t[i]]++;
        }

        int formed = 0;
        int left = 0;
        int minLength = 1000000000;
        int startIndex = 0;

        for (int right = 0; right < s.size(); right++) {

            char ch = s[right];
            have[ch]++;

            if (have[ch] == need[ch]) {
                formed++;
            }

            while (formed == required) {

                int currentLength = right - left + 1;

                if (currentLength < minLength) {
                    minLength = currentLength;
                    startIndex = left;
                }

                have[s[left]]--;

                if (have[s[left]] < need[s[left]]) {
                    formed--;
                }

                left++;
            }
        }

        if (minLength == 1000000000) return "";
        return s.substr(startIndex, minLength);
    }
};
