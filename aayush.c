#include <stdio.h>
#define w "w"
#define a "a"
int main(){
    int n,m,num;
    char type,A,B=' ';
    printf("Enter character:");
    scanf("%c",&A);
    printf("Enter type (Type A/B):");
    scanf("\n%c",&type);
    printf("Enter number of rows:");
    scanf("%d",&n);
    printf("Enter number of patterns:");
    scanf("%d",&num);
    if (type=='B'){
        char C=A;
        A=B;
        B=C;
    }
    m=n;
    for (int i=1; i<=num;i++){
        n=m;
        FILE *hi=fopen("file.txt",(i==1)? w:a);
        n=(m%2==0)? n/2: n/2+1;
        for (int i=1; i<=n;i++){
            for (int j=1; j<=2*n-1;j++){
                if (j>=n-(i-1) && j<=n+(i-1)) fprintf(hi,"%c ",A);
                else fprintf(hi,"%c ",B);
            }
            fprintf(hi,"\n");
        }
        n=(m%2==0)? n: n-1;
        for (int i=1,k=2*n-1; i<=n;i++,k--){
            if (m%2!=0) fprintf(hi,"  ");
            for (int j=1; j<=2*n-1;j++){
                if (j<=k && j>=i) fprintf(hi,"%c ",A);
                else fprintf(hi,"%c ",B);
            }
            fprintf(hi,"\n");
        }
        fclose(hi);
    }
}