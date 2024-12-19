#include<stdio.h>
#include<stdbool.h>

int main(){
    int n;
    scanf("%d", &n);
    char arr[n];
    scanf("%s",arr);
    if(n < 2){
        printf("Invalid String\n");
    }else{
        bool req = true;
        if(arr[n-1]!='b' && arr[n-2] != 'b'){
            printf("Invalid string");
            req = false;
        }

        if(req){
            for(int i=n-3; i>=0; i--){
                if(arr[i] != 'a'){
                    req = false;
                    printf("Invalid String");
                    break;
                }
            }
        }

        if(req){
            printf("Valid String");
        }
        
    }
}