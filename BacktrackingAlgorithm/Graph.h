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
	const int vn;	// 정점의 갯수,,
	int **matrix;	// 인접 행렬,,

public:
	Graph(int vn);
	~Graph(void);	// 메모리 해제,,
	void AddEdge(int start, int goal);	// 간선 추가,,
	void PrintNeighbors()const;
	void PrintNeighbor(int vertex)const;
	Neighbors SearchNeighbors(int vertex);
};