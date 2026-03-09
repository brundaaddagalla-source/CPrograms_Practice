#include <stdio.h>
#include <limits.h>

#define V 5

int main()
{
    int graph[V][V] = {
        {0,10,6,0,0},
        {10,0,5,15,0},
        {6,5,0,4,12},
        {0,15,4,0,8},
        {0,0,12,8,0}
    };
	int i,j;
    int selected[V] = {0};
    int edges = 0;
    int total = 0;
    selected[0] = 1;

    char vertex[] = {'P','Q','R','S','T'};

    while (edges < V - 1)
    {
        int min = INT_MAX;
        int x = 0, y = 0;

        for (i = 0; i < V; i++)
        {
            if (selected[i])
            {
                for (j = 0; j < V; j++)
                {
                    if (!selected[j] && graph[i][j])
                    {
                        if (graph[i][j] < min)
                        {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        printf("%c - %c : %d\n", vertex[x], vertex[y], graph[x][y]);
        total += graph[x][y];
        selected[y] = 1;
        edges++;
    }

    printf("Total Cost = %d\n", total);

    return 0;
}
