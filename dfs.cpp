#include <bits/stdc++.h>
using namespace std;

class Graph 
{
public:
    map<int, bool> visited;
    map<int, list<int>> adj;
    void addEdge(int v, int w);
    void dfs(int v);
};
  
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
  
void Graph::dfs(int v)
{
    visited[v] = true;
    cout << v << " ";
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            dfs(*i);
}

int main()
{
    srand(time(0));

    int n = 10;
    double time, t;
    
    FILE *fp;

    fp = fopen("q1_plot_c.txt", "w");

    if(fp == NULL){
        printf("ERROR Opening File.\n");
    }

    while (n <= 100000)
    {
        time = t = 0.0;
        for (int k = 1; k <= 10; k++)
        {
            Graph g;
            for (int i = 0; i < n; i++)
            {
                g.addEdge(0, i);
            }

            ///MERGE SORT BEGINS
            time = clock();
            ///START
            g.dfs(rand() % k);
            ///END
            time = clock() - time;
            ///MERGE SORT ENDS
            t += ((double)time) / CLOCKS_PER_SEC;
        }
        time = t / 10;

        printf("\nTIME:%d, %f\n\n", n, time);

        fprintf(fp, "%d, %lf\n", n, time);

        n *= 10;
    }
    fclose(fp);
    
    return 0;
}
