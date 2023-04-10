#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/letter-tile-possibilities/ 

class Solution {
public:
    int count;
    void dfs(string tiles, int level) {
        count++;
        for(int i = level; i < tiles.length(); i++) {
            if(i != level && tiles[i] == tiles[level]) {
                continue;
            }
            swap(tiles[i], tiles[level]);
            dfs(tiles, level + 1);
        }
    }
    int numTilePossibilities(string tiles) {
        count = -1;
        sort(tiles.begin(), tiles.end()); 
        dfs(tiles, 0);
        return count;
    }
};