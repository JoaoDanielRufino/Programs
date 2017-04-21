#include <stdio.h>
#include <stdlib.h>

int main(){

    int n,m,i,j,**v;

    scanf("%d %d", &n,&m);

    v = (int**) malloc(n*sizeof(int*));
    for(i=0; i<n; i++){
        v[i] = (int*) malloc(m*sizeof(int));
        for(j=0; j<m; j++){
            scanf("%d", &v[i][j]);
        }
    }

    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            printf("%d ", v[i][j]);
        }
        free(v[i]);
        printf("\n");
    }

    free(v);

    return 0;
}
