class Solution {
public:
    int factorial(int n){
        if(n <= 1)return 1;
        return n * factorial(n-1);
    }
    int numTilePossibilities(string tiles) {
        map<string, int> m;
        vector<char> v;
        int ans = 0;
        for (int j = 0; j < tiles.size() ; j++) {
            v.push_back(tiles[j]);
        }
        sort(v.begin(),v.end());
        for (int i = 1; i < (1 << tiles.size()); i++) {
            int x = i;
            int index = 0;
            string temp = "";
            int l[26] = {};
            while (x) {
                if(x & 1){
                    temp += v[index];
                    l[v[index] - 'A']++;
                }
                x = x >> 1;
                index ++;
            }
            if(m[temp])continue;
            m[temp] = 1;
            int k = factorial(temp.size());
            for(int j = 0 ; j < 26 ;j ++){
                if(l[j] != 0)
                    k /= factorial(l[j]);
            }
            // cout << temp << " " << k << endl;
            ans += k;
        }
        return ans;
    }
};