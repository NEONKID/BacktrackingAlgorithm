/*
	author : neonkid
	date : '16. 05. 27
*/

#include "BT.h"

BT::BT(Graph *graph, int start, int dest)
{
	this->graph = graph;	// 그래프 설정,,
	idx.push_back(start);	// 시작 정점 방문,,
	this->dest = dest;	// 목적지 설정,,
}

Vsted BT::EnumNext()
{
	Vsted nVsted;
	int last_foot = (*idx.rbegin());	// 가장 최근에 방문한 정점
	Neighbors neighbors = graph->SearchNeighbors(last_foot);	// 마지막 방문 정점의 이웃하는 정점을 구함
	FIter seek = neighbors.begin();
	FIter last = neighbors.end();
	for (; seek != last; ++seek)
	{
		if (find(idx.begin(), idx.end(), *seek) == idx.end())	// 방문한 적이 없는 경우,,
		{
			nVsted.push_back(new BT(this, *seek));	// *seek를 추가 방문하는 새로운 경험을 생성
		}
	}
	return nVsted;
}

// 마지막 방문지가 내가 정한 목적지와 같은지 확인,,
bool BT::IsDest()const
{
	return (*idx.rbegin()) == dest;
}

// 색칠,, (used WinAPI)
void BT::Setcolor(int color)const
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void BT::Print()const
{
	cout << " Visits: ";
	CFIter seek = idx.begin();
	CFIter last = idx.end();
	int COLOR_NUMBER = 4;

	for (; seek != last; ++seek)
	{
		Setcolor(COLOR_NUMBER);			// 지정된 색으로 칠,,

		if (seek == last - 1)
		{
			cout << (*seek) << " ";
			Setcolor(DEFAULT_COLOR);	// 색깔 초기화,,
		}

		else
		{
			cout << (*seek); 
			Setcolor(DEFAULT_COLOR);	// 색깔 초기화,,
			cout << " -> ";
		}

		++COLOR_NUMBER;
	}
	cout << endl;
}

BT::BT(const BT *bvst, int vertex)
{
	this->graph = bvst->graph;
	idx = bvst->idx;
	this->dest = bvst->dest;

	idx.push_back(vertex);	// 해당 정점을 방문한 행적에 추가
}