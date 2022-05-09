#include<iostream>
#include <list>

using namespace std;

class DGRAPH
{
	int v; 
	list<int> *adjacent;
public:
	DGRAPH(int v);
	 
	void Edge(int a, int z);
	void BFS(int x);
};

DGRAPH::DGRAPH(int v)
{
	this->v = v;
	adjacent = new list<int>[v];
}

void DGRAPH::Edge(int a, int z)
{
	adjacent[a].push_back(z); 
}

void DGRAPH::BFS(int x)
{
	bool *Visit = new bool[v];
	for(int i = 0; i < v; i++)
		Visit[i] = false;
	list<int> queue;
	Visit[x] = true;
	queue.push_back(x);
	list<int>::iterator n;

	while(!queue.empty())
	{
		x = queue.front();
		cout << x << " ";
		queue.pop_front();
		for (n = adjacent[x].begin(); n != adjacent[x].end(); ++n)
		{
			if (!Visit[*n])
			{
				Visit[*n] = true;
				queue.push_back(*n);
			}
		}
	}
}
int main()
{
	DGRAPH G(6);
	G.Edge(0, 1);
	G.Edge(0, 2);
	G.Edge(1, 2);
	G.Edge(1, 3);
	G.Edge(2, 3);
    G.Edge(3, 4);
    G.Edge(4, 4); 
	cout << "Breadth_First_Search(starting from vertex 0) \n";
	G.BFS(0);

	return 0;
}

