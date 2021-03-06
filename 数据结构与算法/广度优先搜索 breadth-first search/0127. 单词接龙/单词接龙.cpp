class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordDict(wordList.begin(), wordList.end());
        if(wordDict.find(endWord) == wordDict.end())    return 0;
        unordered_set<string> beginSet{beginWord};
        unordered_set<string> endSet{endWord};
        int step = 1;
        for(; !beginSet.empty();){
            unordered_set<string> tmpSet;
            step++;
            for(auto s : beginSet){
                wordDict.erase(s);
            }
            for(auto s : beginSet){
                for(int i = 0; i < s.size(); i++){
                    string str = s;
                    for(char c = 'a'; c <= 'z'; c++){
                        str[i] = c;
                        if(wordDict.find(str) == wordDict.end())    continue;
                        if(endSet.find(str) != endSet.end())    return step;
                        tmpSet.insert(str);
                    }
                }
            }
            if(tmpSet.size() < endSet.size())   beginSet = tmpSet;
            else{
                beginSet = endSet;
                endSet = tmpSet;
            }
        }
        return 0;
    }
};
// 【笔记】两端搜索。本题是需要从beginWord转换为endWord。上一份笔记严格按照这个要求，进行转换，结果为88ms。

// 本条笔记采用两端搜索对上一份笔记进行了优化。两端搜索也就是说：“一头从beginWord转换为endWord，另外一头从endWord转换为beginWord。”为什么要这么做呢？有什么意义呢？

// 举个例子：

// 假设从beginWord转换为endWord，存在于字典中的，（第一个）中间结果有30个。

// 而，从endWord转换为beginWord，存在于字典中的，（第一个）中间结果只有2个。

// 那么，很显然。从endWord开始会更快。所以，每次都从个数少的那块开始替换一位。

// 因此，我们每次都从中间结果少的那一端出发，这样就能剪枝掉很多不必要的搜索过程。

// 以下优化结果16ms。


/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_multimap<string, string> dict;
        unordered_set<string> memo;
        bool isValid = false;
        for(auto& word : wordList){
            if(word == endWord) isValid = true;
            string str = word;
            for(int i = 0; i < word.size(); i++){
                str[i] = '*';
                dict.emplace(str, word);
                str[i] = word[i];
            }
        }
        if(!isValid)    return 0;
        queue<string> q;
        q.push(beginWord);
        int step = 1;
        while(!q.empty()){
            step++;
            int len = q.size();
            while(len--){
                string cur = q.front();
                q.pop();
                for(int i = 0; i < cur.size(); i++){
                    char tmp = cur[i];
                    cur[i] = '*';
                    auto range = dict.equal_range(cur);
                    for(auto iter = range.first; iter != range.second; iter++){
                        if(memo.count(iter->second) == 0){
                            if(iter->second == endWord) return step;
                            q.push(iter->second);
                            memo.emplace(iter->second);
                        }
                    }
                    cur[i] = tmp;
                }
            }
        }
        return 0;
    }
};
// @lc code=end

