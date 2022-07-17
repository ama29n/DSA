#include <bits/stdc++.h>
using namespace std;

bool wordPattern(string pattern, string s) {
	unordered_map<char, string> mp;
	vector<string> words;

	// Creating array of words 
	int i = 0;
	while(i < s.size()) {
		string word = "";
		if(s[i] == ' ')
			i++;
		while(i < s.size() && s[i] != ' ')
			word += s[i++];
		words.push_back(word);
	}
	
	// If the pattern size and words are not equal return false
	if(words.size() != pattern.size())
		return false;
	
	for(int i = 0; i < words.size(); i++) {
		// If word corresponding to a pattern letter doesn't exists
        // The following check is for testcases like: pattern : abba, words : dog dog dog dog
		if(mp.find(pattern[i]) == mp.end()) {
			for(auto m : mp)
				if(m.second == words[i])
					return false;
			mp[pattern[i]] = words[i];
		}
		// If exists then check for the similarity of words 
		else if(mp[pattern[i]] != words[i])
			return false;
	}
	return true;
}