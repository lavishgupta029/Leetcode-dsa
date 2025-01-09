class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int count=1;
        unordered_set<string> st;
        for(auto x: wordList) st.insert(x);
        st.insert(beginWord);
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                string word=q.front();
                q.pop();
                st.erase(word);
                if(word==endWord) return count;
                for(int j=0;j<word.size();j++){
                    char temp=word[j];
                    for(int x=0;x<26;x++){
                        word[j]=x+'a';
                        if(st.find(word)!=st.end()){
                            q.push(word);
                            st.erase(word);
                        }
                    }
                    word[j]=temp;
                }
            }
            count++;
        }
        return 0;
    }
};