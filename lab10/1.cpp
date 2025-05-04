#include<stdio.h>
#include<unordered_map>
#include<vector>
#include<iostream>
#include<string>
using namespace std;
int main(){
    int t;
    printf("ENter number of testcases : ");
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
void solve(){
    int n ;
    printf("Enter number of words each player writes");
    scanf("%d",&n);
    vector<vector<string>>words(3,vector<string>(n));
    unordered_map<string,int>wordCount;
    for(int i = 0 ;i < 3 ; i++){
        printf("Enter %d words for %d\n",n,i+1);
        for(int j = 0;j <n ; j++){
            char temp[50];
            scanf("%s",temp);
            wordCount[words[i][j]]++;
        }
    }
               
    int score[3] = {0,0,0};
    for(int i = 0 ;i < 3 ; i++){
        for(int j = 0 ; j < n ; j++){
            if(wordCount[words[i][j]] == 1){
                score[i]+= 3;
            }
            else if(wordCount[words[i][j]]== 2){
                score[i]+= 1;
            }
        }
    }
    printf("Scores : %d %d %d\n",score[0],score[1],score[2]);
}