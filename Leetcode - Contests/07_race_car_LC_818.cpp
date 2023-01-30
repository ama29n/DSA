#include <bits/stdc++.h>
using namespace std;

// The reason why we add <= 10000 condition for "A" instruction is, so if we accelerate the car when 
// we are near at 10000, it will go far beyond what we want to reach. Since the 0 <= target <= 10000, 
// The possibility that we can reach to target when we are behind the 10000 will be shorter than the 
// possibility of getting the target after we go beyond the 10000.

class Solution {
public:
    int racecar(int target) {
        queue<vector<int>> q;
        // {position, speed, moves}
        q.push({0, 1, 0});
        
        while(q.size()) {
            int pos = q.front()[0], speed = q.front()[1], moves = q.front()[2];
            q.pop();
            
            if(pos == target)
                return moves;
            
            // Try A
            if(pos + speed <= 10000 && pos + speed > 0)
                q.push({pos + speed, 2 * speed, moves + 1});
            
            // Try R
            if(pos + speed > target && speed > 0)
                q.push({pos, -1, moves + 1});
            if(pos + speed < target && speed < 0)
                q.push({pos, 1, moves + 1});
        }
        return -1;
    }
};
