/*
	author : neonkid
	date : '16. 05. 27
*/

#include "Graph.h"

Graph::Graph(int vn):vn(vn)
{
	matrix = new int *[vn];		// ���� ��� ���,,
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
	matrix[start][goal] = 1;	// ���� ����
	matrix[goal][start] = 1;	// ���� ����
}

void Graph::PrintNeighbors()const
{
	cout << endl << " === �̿� ���� === " << endl;
	for (int i = 0; i < vn; i++)
	{
		cout << " " << i << "�� �̿�: ";
		PrintNeighbor(i);	// i ������ �̿� �����ֱ�
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