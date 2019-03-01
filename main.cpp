#include <bits/stdc++.h>
using namespace std;
#define maxx 100002

int Reverse(int x)
{
    if(x==1)
        return -1;
    else
        return 1;
}

bool BFS(vector < vector <int > > &V ,  vector <int > &Visited,int curr)
{
    queue <int> q;
    q.push(curr);
    Visited[curr] = 1;
    while(!q.empty())
    {
        curr = q.front();
        q.pop();
        for(int i=0;i<V[curr].size();i++)
        {
            if(Visited[ V[curr][i] ] == 0  )
            {
                Visited [ V[curr][i] ] = Reverse(Visited[curr]);
                q.push(V[curr][i] );
            }
            else
            {
                if(Visited[ V[curr][i] ] == Visited[curr])
                    return 0;

            }

        }

    }

return 1;


}
main()
{
    int n,m,x,y;
    cin >> n >> m;
    vector < vector <int> > V(100001);
    vector <int > Visited (100001);
    for(int i=0;i<m;i++)
    {
        cin >> x >> y ;
        V[x].push_back(y);
        V[y].push_back(x);
    }

    fill(Visited.begin(), Visited.end() , 0);
    for(int i=1 ;i< V.size()+1;i++)
    {
        if(Visited[i] == 0 )
        {
            if(!BFS(V,Visited,i))
            {
                //print_vector(Visited);
                printf("0");
                return 0;
            }
        }
    }


printf("1");
}
