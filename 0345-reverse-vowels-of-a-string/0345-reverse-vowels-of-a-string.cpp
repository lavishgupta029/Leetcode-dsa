class Solution {
public:
    string reverseVowels(string s) {
        set<char> nums={'a' , 'e' ,'i' , 'o', 'u' , 'A' , 'I', 'O' , 'E' , 'U'};

        int n=s.size();
        int i=0, j=n-1;
        while(i<j){
            while(i<j && nums.find(s[i])==nums.end()) i++;
            while(i<j && nums.find(s[j])==nums.end()) j--;
            char temp=s[i];
            s[i]=s[j];
            s[j]=temp;
            i++;
            j--;
        }
        return s;
    }
};