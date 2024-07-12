// 3206. Alternating Groups I
// https://leetcode.com/problems/alternating-groups-i/

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        colors.push_back(colors[0]);
        colors.push_back(colors[1]); //pushed last 2 elements to maintain the rotational sequence
        int ans=0;
        for(int i=0;i<colors.size()-2;i++){
            if(colors[i]!=colors[i+1] && colors[i+1]!=colors[i+2] && colors[i]==colors[i+2])
            ans++;
        }
        return ans;
    }
};