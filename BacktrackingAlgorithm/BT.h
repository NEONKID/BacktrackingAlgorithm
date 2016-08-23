/*
	author : neonkid
	date : '16. 05. 27
*/

#pragma once

#include <tchar.h>

#include "Graph.h"

using namespace std;

//! �⺻ ���ڻ�,,
const int DEFAULT_COLOR = 10;

//! �̹� �湮�� ����,,
typedef vector<int> index;
typedef index::iterator FIter;
typedef index::const_iterator CFIter;

class BT;

//! �湮 ���� ����,,
typedef vector<BT *> Vsted;
typedef Vsted::iterator VIter;
typedef Vsted::const_iterator CVIter;

class BT
{
	Graph *graph;
	int dest;
	index idx;

public:
	BT(Graph *graph, int start, int dest);	//! ������� ������ ����,,
	Vsted EnumNext();	//! ���� �湮�� �������� �̿��� ���� �湮,,
	bool IsDest()const;	//! ������ ���� �Ǻ�,,
	void Print()const;	//! ���� ��� ���,,
	void Setcolor(int color)const;	//! ��ĥ
private:
	BT(const BT *bvst, int vertex);	//! ���� �湮�ߴ� �������� Ư�� ���� �߰� �湮 ������,,
};