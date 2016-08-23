/*
	author : neonkid
	date : '16. 05. 27
*/

#pragma once

#include <tchar.h>

#include "Graph.h"

using namespace std;

//! 기본 글자색,,
const int DEFAULT_COLOR = 10;

//! 이미 방문한 정점,,
typedef vector<int> index;
typedef index::iterator FIter;
typedef index::const_iterator CFIter;

class BT;

//! 방문 정보 보관,,
typedef vector<BT *> Vsted;
typedef Vsted::iterator VIter;
typedef Vsted::const_iterator CVIter;

class BT
{
	Graph *graph;
	int dest;
	index idx;

public:
	BT(Graph *graph, int start, int dest);	//! 출발점과 도착점 선정,,
	Vsted EnumNext();	//! 현재 방문한 정점에서 이웃한 정점 방문,,
	bool IsDest()const;	//! 목적지 도착 판별,,
	void Print()const;	//! 현재 경로 출력,,
	void Setcolor(int color)const;	//! 색칠
private:
	BT(const BT *bvst, int vertex);	//! 이전 방문했던 정점에서 특정 정점 추가 방문 생성자,,
};