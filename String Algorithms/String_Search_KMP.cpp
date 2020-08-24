// S and T - input strings
// You need to check if string T is present in S or not
#include<bits/stdc++.h>

int *longest_prefix_suffix(char pattern[]){
    int len=strlen(pattern);
    int *lps=new int[len];
    lps[0]=0;
    int i=1;
    int j=0;
    while(i<len){
        if(pattern[i]==pattern[j]){
            lps[i]=j+1;
            j++;
            i++;
        } else {
            if(j!=0){
                j=lps[j-1];
            } else {
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}

int findString(char S[], char T[]) {
    int slen=strlen(S);
    int tlen=strlen(T);
    int *lps=longest_prefix_suffix(T);
    int i=0;
    int j=0;
    while(i<slen && j<tlen){
        if(S[i]==T[j]){
            j++;
            i++;
        } else {
            if(j!=0){
                j=lps[j-1];
            } else {
                i++;
            }
        }
    }
    if(j==tlen){
        return i-tlen;
    } else {
        return -1;
    }
}
