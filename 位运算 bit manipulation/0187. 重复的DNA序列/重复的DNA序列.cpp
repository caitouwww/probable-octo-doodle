class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        // vector<string> res;
        // unordered_map<string,int> m;
        // for(int i=0;i<=int(s.size()-10);i++)
        // {
        //     string str=s.substr(i,10);
        //     if(++m[str]==2) res.push_back(str);
        // }
        // return res;
        //位运算
        unordered_map<char,int> m{{'A',0},{'C',1},{'G',2},{'T',3}};
        vector<string> res;
        bitset< 1<<20 > s1,s2;
        int val=0,mask=(1<<20)-1;
        for(int i=0;i<10;i++)   val=(val<<2)|m[s[i]];
        s1.set(val);//将s1中第val个数置1
        for(int i=10;i<s.size();i++)
        {
            val=(val<<2)&mask|m[s[i]];
            if(s2.test(val))    continue;
            if(s1.test(val))
            {
                res.push_back(s.substr(i-9,10));
                s2.set(val);
            }
            else    s1.set(val);
        }
        return res;
    }
};