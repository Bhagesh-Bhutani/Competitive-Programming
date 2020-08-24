#include<bits/stdc++.h>

int countPalindromeSubstrings(char s[]) {
    int c=0;
    int n=strlen(s);
    for(int i=0;i<n;i++){
        //odd
        int o=i;
        int left,right;
        left=i-1;
        right=i+1;
        c++;
        while(left>=0 && right<n){
            if(s[left]==s[right]){
                c++;
                left--;
                right++;
            } else {
                break;
            }
        }
        
        //even
        if(i+1<n){
            int e1,e2;
            e1=i;
            e2=i+1;
            if(s[e1]!=s[e2]){
                continue;
            }
            c++;
            left=i-1;
            right=i+2;
            while(left>=0 && right<n){
                if(s[left]==s[right]){
                    c++;
                    left--;
                    right++;
                } else {
                    break;
                }
            }
        } 
    }
    return c;
}
