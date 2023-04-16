//source --> youtube(tushar roy) link=https://www.youtube.com/watch?v=GTJr8OvyEVQ

//applications 
//1 --> substring matching
//2--> min insertions to make palindrome (gfg source link)=https://www.geeksforgeeks.org/minimum-characters-added-front-make-string-palindrome/

#include<bits/stdc++.h>
using namespace std;

vector<int> calculateTempArray(string pattern)
{
       vector<int>lps=vector<int>((int)pattern.length(),0);

       
         int index =0;
        for(int i=1; i < pattern.length();){
            if(pattern[i] == pattern[index]){
                lps[i] = index + 1;
                index++;
                i++;
            }else{
                if(index != 0){
                    index = lps[index-1];
                }else{
                    lps[i] =0;
                    i++;
                }
            }
        }
        return lps;    

}


bool KMP_StringMatching(string text, string pattern){
        
        vector<int>lps= calculateTempArray(pattern);
        int i=0;
        int j=0;
        while(i < text.length() && j < pattern.length()){
            if(text[i] == pattern[j]){
                i++;
                j++;
            }else{
                if(j!=0){
                    j = lps[j-1];
                }else{
                    i++;
                }
            }
        }
        if(j == pattern.length()){
            return true;
        }
        return false;
    }
int main()
{

       
      string text="allshankarok";
      string pattern="shankar";
      cout<<KMP_StringMatching(text,pattern)<<endl;

}



//method 2 , Cp algorithm for calculating pi array

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}