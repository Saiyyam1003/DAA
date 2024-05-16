#include <stdio.h>
#define INF 9999999
#define V 5

int G[V][V] = { { 0, 9, 75, 0, 0 },
                { 9, 0, 95, 19, 42 },
                { 75, 95, 0, 51, 66 },
                { 0, 19, 51, 0, 31 },
                { 0, 42, 66, 31, 0 } };

int main() {
    int no_edge;  // number of edge
    int selected[V];
    for(int i = 0; i < V ; i++)
        selected[i] = 0;
    no_edge = 1;
    selected[0] = 1;
    int x;  //  row number
    int y;  //  col number
    printf("Edge : Weight\n");
    while (no_edge < V) {
        int min = INF;
        x = 0;
        y = 0;
        for (int i = 0; i < V; i++) {
            if (selected[i] == 1) {
                for (int j = 0; j < V; j++) {
                    if (selected[j] == 0 && G[i][j]) { 
                        if (min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf("%d -> %d : %d\n", x, y, G[x][y]);
        selected[y] = 1;
        no_edge++;
    }
    return 0;
}