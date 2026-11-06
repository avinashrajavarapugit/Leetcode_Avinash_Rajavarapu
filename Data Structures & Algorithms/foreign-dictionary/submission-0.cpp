class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        string res = "";
        unordered_map<char, vector<char>> adjList; // build adj list
        unordered_map<char, int> indegree;
        // initialize all letters in all words as 0 indegree
        for(string word : words)
        {
            for(char c : word)
                indegree[c] = 0;
        }
        for(int i = 0; i < words.size()-1; i++)
        {
            string word1 = words[i];
            string word2 = words[i+1];
            if(word1.length() > word2.length() && word1.substr(0, word2.length()) == word2)
                return "";
            // strip common letters in two words to determine how to build the adj list
            int l1 = 0, l2 = 0;
            while(l1 < word1.length() && l2 < word2.length() && word1[l1] == word2[l2])
            {
                l1++;
                l2++;
            }
            // now that l1 and l2 point to letters in word1 and word2 that are not the same
            // we know that word1[l1] will come before word2[l2] so build graph
            if(l1 < word1.length() && l2 < word2.length())
            {
                adjList[word1[l1]].push_back(word2[l2]);
                indegree[word2[l2]]++;
            }
        }
        // standard topological sort algorithm, but with characters instead of int array
        queue<char> q;
        for(auto it : indegree)
        {
            if(it.second == 0)
                q.push(it.first);
        }
        while(!q.empty())
        {
            char front = q.front();
            q.pop();
            res += front;
            for(char next : adjList[front])
            {
                indegree[next]--;
                if(indegree[next] == 0)
                    q.push(next);
            }
        }
        return res.length() == indegree.size() ? res : "";
    }
};
