#include <stdio.h>
int main(){
    int r1, c1;
    printf("ENTER ROW AND COLUMN OF MATRIX ONE: ");
    scanf("%d %d", &r1, &c1);
    int m1[r1][c1];
    printf("ENTER ELEMENTS OF MATRIX 1:\n");
    for(int i=0; i<r1; i++)
        for(int j=0; j<c1; j++)
            scanf("%d", &m1[i][j]);
    int r2, c2;
    printf("ENTER ROW AND COLUMN OF MATRIX ONE: ");
    scanf("%d %d", &r2, &c2);
    int m2[r2][c2];
    printf("ENTER ELEMENTS OF MATRIX 2:\n");
    for(int i=0; i<r2; i++)
        for(int j=0; j<c2; j++)
            scanf("%d", &m2[i][j]);
    if(c1==r2){
        int mul[r1][c2];
        for(int i=0; i<r1; i++){
            for(int j=0; j<c2; j++){
                mul[i][j]=0;
                for(int k=0; k<c1; k++){
                    mul[i][j]+=(m1[i][k]*m2[k][j]);
                }
            }
        }

        printf("MATRIX MULTIPLICATION: \n");
        for(int i=0; i<r1; i++){
            for(int j=0; j<c2; j++)
                printf("%d\t", mul[i][j]);
            printf("\n");
        }
    }
    else
    printf("MATRIX MULTIPLICATION NOT POSSIBLE");

}
