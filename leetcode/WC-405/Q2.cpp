// 3211. Generate Binary Strings Without Adjacent Zeros

// https://leetcode.com/problems/generate-binary-strings-without-adjacent-zeros/description/

class Solution {
public:
    vector<string> ans;
    void solve(int pr,string &str,int n){
        if(str.size()==n){
            ans.push_back(str);
            return;
        }
        str.push_back('1');
        solve(1,str,n);
        str.pop_back();
        if(pr==1){
            str.push_back('0');
            solve(0,str,n);
            str.pop_back();
        }
    }
    vector<string> validStrings(int n) {
        string st0="0",st1="1";
        ans.clear();
        solve(0,st0,n);
        solve(1,st1,n);
        return ans;
    }
};



// example
//                         start
//                       /          \
//              solve(0, "0", 3)   solve(1, "1", 3)
//                /                    \
// solve(1, "01", 3)                 solve(1, "11", 3)    solve(0, "10", 3)
//    /          \                     /        \                \
// solve(1, "011", 3) solve(0, "010", 3) solve(1, "111", 3) solve(0, "110", 3) solve(1, "101", 3)
//       |                  |                  |                 |               |
//     "011"             "010"               "111"            "110"            "101"
//   (add to ans)       (add to ans)       (add to ans)      (add to ans)     (add to ans)
