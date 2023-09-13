#include <bits/stdc++.h> 
using namespace std;

// https://www.codingninjas.com/studio/problems/subsequences-of-string_985087 

vector<string> subsequences(string &str) {
	int n = str.size();
	vector<string> ans;
	int range = 1 << n;
	for(int mask = 0; mask < range; mask++) {
		string x = "";
		for(int i = 0; i < n; i++) {
			if((mask & (1 << i))) 
				x += str[i];
		}
		if(x != "") ans.push_back(x);
	}
	return ans;
}

// https://efds.fa.em5.oraclecloud.com/hcmUI/CandidateExperience/en/sites/CX_1/job/14271/?utm_medium=jobshare 

