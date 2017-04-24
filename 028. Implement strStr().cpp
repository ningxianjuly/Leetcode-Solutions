//I used a improved brute-force way to handle the problem
//This algorithm do not need n*m, we just loop haystack and memory each start point we encountered.
//there are 3 situation in the loop: not realted, matching correct and matching false.
class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.size() > haystack.size()) {
			return -1;
		}
		if (needle.empty()) {
			return 0;
		}
		int i = 0, j = 0, lastpos = 0;;
		while (j < haystack.size()) {
			if (needle[i] == haystack[j]) {
				if (i == needle.size() - 1) {
					return j - needle.size() + 1;
				}
				if (i != 0 && haystack[j] == needle[0] && lastpos == 0) {
					lastpos = j;
				}
				i++;
				j++;
			}
			else if (i != 0) {
				i = 0;
				if (lastpos != 0) {
					j = lastpos;
					lastpos = 0;
				}
			}
			else {
				j++;
			}


		}
		return -1;


	}
};