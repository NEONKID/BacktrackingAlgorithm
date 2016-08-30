/*
	author : neonkid
	date : '16. 05. 27
*/

#pragma once

#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

typedef vector<int> Neighbors;

class Graph
{
	const int vn;	// ������ ����,,
	int **matrix;	// ���� ���,,

public:
	Graph(int vn);
	~Graph(void);	// �޸� ����,,
	void AddEdge(int start, int goal);	// ���� �߰�,,
	void PrintNeighbors()const;
	void PrintNeighbor(int vertex)const;
	Neighbors SearchNeighbors(int vertex);
};