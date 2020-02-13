#include <stdio.h>

int main() {
    int a,b,c;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);

    if(a==b || a==c || b==c){
        printf("S\n");
    }else if((a==(b+c)) || (b==(a+c)) || (c==(b+a))){
        printf("S\n");
    }else if(a==0 || b==0|| c==0){
        printf("S\n");
    }else{
        printf("N\n");
    }

    return 0;
}
