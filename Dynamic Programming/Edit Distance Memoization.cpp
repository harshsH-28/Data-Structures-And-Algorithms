class Solution {
public:
int editDistance(string s, string t, vector<vector<int>> &v)
{
    int m = s.length(), n = t.length();

    if (s.length() == 0 || t.length() == 0)
        return max(s.size(), t.size());

    if (v[m][n] != -1)
        return v[m][n];

    int ans;
    if (s[0] == t[0])
        ans = editDistance(s.substr(1), t.substr(1), v);
    else
    {
        int p1 = editDistance(s.substr(1), t.substr(1), v) + 1;
        int p2 = editDistance(s.substr(1), t, v) + 1;
        int p3 = editDistance(s, t.substr(1), v) + 1;

        ans = min(p1, min(p2, p3));
    }

    v[m][n] = ans;
    return v[m][n];
}
int minDistance(string s,string t)
{
    vector<vector<int>> v(s.length() + 1, vector<int>(t.length() + 1, -1));
    int ans = editDistance(s, t, v);
    return ans;
}
};
