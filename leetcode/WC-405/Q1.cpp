// 3210. Find the Encrypted String

// https://leetcode.com/problems/find-the-encrypted-string/description/

class Solution {
public:
    string getEncryptedString(string s, int k) {
        string res="";
        int i=0;
        while(i<s.size()){
            int idx=(i+k)%s.size(); //To keep the index in the range of the length of string. Else we can get a outof bound error
            res+=s[idx];
            i++;
        }
        return res;
    }
};


// // Initial State
// i = 0
// res = ""
// s = "abcdef"
// k = 2

// // Iteration 1
// i = 0
// idx = (0 + 2) % 6 = 2
// res = res + s[idx] = "" + 'c' = "c"

// // Iteration 2
// i = 1
// idx = (1 + 2) % 6 = 3
// res = res + s[idx] = "c" + 'd' = "cd"

// // Iteration 3
// i = 2
// idx = (2 + 2) % 6 = 4
// res = res + s[idx] = "cd" + 'e' = "cde"

// // Iteration 4
// i = 3
// idx = (3 + 2) % 6 = 5
// res = res + s[idx] = "cde" + 'f' = "cdef"

// // Iteration 5
// i = 4
// idx = (4 + 2) % 6 = 0
// res = res + s[idx] = "cdef" + 'a' = "cdefa"

// // Iteration 6
// i = 5
// idx = (5 + 2) % 6 = 1
// res = res + s[idx] = "cdefa" + 'b' = "cdefab"

// // Final State
// res = "cdefab"


