#include <fstream>
using namespace std;
int main()
{
  ifstream f("BFS.in");
  int n, m, X;
  f >> n >> m >> X;
  X--; // retin indicii de la 0
  // initializez matricea de adiacenta
  int** a = new int*[n];
  for (int i = 0; i < n; i++)
  {
    a[i] = new int[n];
    for (int j = 0; j < n; j++)
      a[i][j] = 0;
  }
  // citesc muchiile si construiesc matricea de adiacenta
  while (m > 0)
  {
    int x, y;
    f >> x >> y;
    a[x-1][y-1] = a[y-1][x-1] = 1;
    m--;
  }
  f.close();
  // initializez vector caracteristic
  int* viz = new int[n];
  for (int i = 0; i < n; i++) 
    viz[i] = 0;
  // initializez coada
  int* cd = new int[n];
  int prim = 0, ultim = -1;
  cd[++ultim] = X;
  viz[X] = 1;
  ofstream g("BFS.out");
  g << X+1 << ' ';
  // BFS
  while (prim <= ultim)
  {
    X = cd[prim++];
    for (int i = 0; i < n; i++)
      if (!viz[i] && a[X][i])
      {
        viz[i] = 1;
        g << i+1 << ' ';
        cd[++ultim] = i;
      }
  }
  g.close();
  return 0;
}

