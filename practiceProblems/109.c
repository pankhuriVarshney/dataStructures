#include <stdio.h>
int main(){
    int r, c;
    printf("ENTER ROW AND COLUMN OF MATRIX: ");
    scanf("%d %d", &r, &c);
    int m1[r][c];
    printf("ENTER ELEMENTS OF MATRIX:\n");
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            scanf("%d", &m1[i][j]);
    
    int trans[c][r];
    for(int i=0; i<c; i++){
        for(int j=0; j<r; j++){
            trans[i][j]=m1[j][i];
        }
    }
    printf("TRANSPOSE: \n");
    for(int i=0; i<c; i++){
        for(int j=0; j<r; j++)
            printf("%d\t", trans[i][j]);
        printf("\n");
    }
}