/*
	author : neonkid
	date : '16. 05. 27
*/

#include "Graph.h"

Graph::Graph(int vn):vn(vn)
{
	matrix = new int *[vn];		// 인접 행렬 사용,,
	for (int i = 0; i < vn; i++)
	{
		matrix[i] = new int[vn];	// Matrix[i-row] allocated memory
		memset(matrix[i], 0, sizeof(int)*vn);	// 0 
	}
}

Graph::~Graph(void)
{
	for (int i = 0; i < vn; i++)
	{
		delete[] matrix[i];	// free(Matrix[i-row]);
	}
	delete[] matrix;	// free,,     
}

void Graph::AddEdge(int start, int goal)
{
	matrix[start][goal] = 1;	// 간선 설정
	matrix[goal][start] = 1;	// 간선 설정
}

void Graph::PrintNeighbors()const
{
	cout << endl << " === 이웃 정점 === " << endl;
	for (int i = 0; i < vn; i++)
	{
		cout << " " << i << "의 이웃: ";
		PrintNeighbor(i);	// i 정점의 이웃 보여주기
	}
	cout << endl;
}

void Graph::PrintNeighbor(int vertex)const
{
	for (int i = 0; i < vn; i++)
	{
		if (matrix[vertex][i])
		{
			cout << i << " ";
		}
	}
	cout << endl;
}

Neighbors Graph::SearchNeighbors(int vertex)
{
	Neighbors neighbors;
	for (int i = 0; i < vn; i++)
	{
		if (matrix[vertex][i])
		{
			neighbors.push_back(i);
		}
	}
	return neighbors;
}