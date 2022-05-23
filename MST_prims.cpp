// You have a business with several offices; you want to lease phone lines to connect them
// up with each other; and the phone company charges different amounts of money to
// connect different pairs of cities. You want a set of lines that connects all your offices
// with a minimum total cost. Solve the problem by suggesting appropriate data structures.

#include <iostream>
using namespace std;

int const N = 30;
int const MAX = 99999;
class MST
{
private:
    int matrix[N][N];
    int nVertices, nEdges, TotalWeight = 0;

public:
    MST()
    {
        nVertices = 0;
        nEdges = 0;

        for (int i = 0; i < nVertices; i++)
        {
            for (int j = 0; j < nVertices; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    MST(int nv)
    {
        nVertices = nv;
        nEdges = 0;
        for (int i = 0; i < nVertices; i++)
        {
            for (int j = 0; j < nVertices; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    MST(int nv, int ne)
    {
        nVertices = nv;
        nEdges = ne;
        for (int i = 0; i < nVertices; i++)
        {
            for (int j = 0; j < nVertices; j++)
            {
                matrix[i][j] = 0;
            }
        }
        for (int i = 0; i < nEdges; i++)
        {
            int u, v, w;
            cout << "Enter Start Vertex,End Vertex & Weight  : ";
            cin >> u >> v >> w;
            matrix[v][u] = w;
            matrix[u][v] = w;
        }
    }

    void getGraph(int nv, int ne)
    {
        nVertices = nv;
        nEdges = ne;
        for (int i = 0; i < nVertices; i++)
        {
            for (int j = 0; j < nVertices; j++)
            {
                matrix[i][j] = 0;
            }
        }
        for (int i = 0; i < nEdges; i++)
        {
            int u, v, w;
            cout << "Enter u,v,w : ";
            cin >> u >> v >> w;
            matrix[v][u] = w;
            matrix[u][v] = w;
        }
    }

    void primsAlgo()
    {
        int source[N] = {0}, count = 0, min;
        int x, y;
        source[0] = 1; // starting from 0 vertex
        int prims_Algo[nVertices][nVertices];
        
        for (int i = 0; i < nVertices; i++) 
        {
            for (int j = 0; j < nVertices; j++)
            {
                prims_Algo[i][j] = matrix[i][j];// Copying original matrix to temporary matrix
                if (prims_Algo[i][j] == 0)// Making all ZERO elements MAXIMUM
                {
                    prims_Algo[i][j] = MAX;
                }
            }
        }


        while (count < nVertices - 1)
        {
            min = MAX;
            for (int i = 0; i < nVertices; i++)
            {
                if (source[i] == 1)
                {
                    for (int j = 0; j < nVertices; j++)
                    {
                        if (source[j] == 0)
                        {

                            if (min > prims_Algo[i][j])
                            {
                                min = prims_Algo[i][j];
                                x = i;
                                y = j;
                            }
                        }
                    }
                }
            }
            source[y] = 1;
            cout << " [ " << x << " - " << y << " ] ->";
            TotalWeight = TotalWeight + prims_Algo[x][y];
            count = count + 1;
        }

        cout << "\nTotal Weight of Minimum Spanning Tree is : " << TotalWeight << endl;
    }
};

int main()
{
    int ch;
    MST m1;
    while (1)
    {
        cout << "Enter the choice :- " << endl;
        cout << "1.Create Graph 2.Prims Algo" << endl;
        cin >> ch;
        if (ch == 0)
        {
            return 0;
        }
        else if (ch == 1)
        {
            int nv, ne;
            cout << "Enter the number of Vertices : ";
            cin >> nv;
            cout << "Enter the number of Edges : ";
            cin >> ne;
            m1.getGraph(nv, ne);
        }
        else if (ch == 2)
        {
            m1.primsAlgo();
        }
        else
        {
            cout << "Wrong choice Try again !!" << endl;
        }
    }
    return 0;
}
