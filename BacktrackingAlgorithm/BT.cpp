/*
	author : neonkid
	date : '16. 05. 27
*/

#include "BT.h"

BT::BT(Graph *graph, int start, int dest)
{
	this->graph = graph;	// �׷��� ����,,
	idx.push_back(start);	// ���� ���� �湮,,
	this->dest = dest;	// ������ ����,,
}

Vsted BT::EnumNext()
{
	Vsted nVsted;
	int last_foot = (*idx.rbegin());	// ���� �ֱٿ� �湮�� ����
	Neighbors neighbors = graph->SearchNeighbors(last_foot);	// ������ �湮 ������ �̿��ϴ� ������ ����
	FIter seek = neighbors.begin();
	FIter last = neighbors.end();
	for (; seek != last; ++seek)
	{
		if (find(idx.begin(), idx.end(), *seek) == idx.end())	// �湮�� ���� ���� ���,,
		{
			nVsted.push_back(new BT(this, *seek));	// *seek�� �߰� �湮�ϴ� ���ο� ������ ����
		}
	}
	return nVsted;
}

// ������ �湮���� ���� ���� �������� ������ Ȯ��,,
bool BT::IsDest()const
{
	return (*idx.rbegin()) == dest;
}

// ��ĥ,, (used WinAPI)
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
		Setcolor(COLOR_NUMBER);			// ������ ������ ĥ,,

		if (seek == last - 1)
		{
			cout << (*seek) << " ";
			Setcolor(DEFAULT_COLOR);	// ���� �ʱ�ȭ,,
		}

		else
		{
			cout << (*seek); 
			Setcolor(DEFAULT_COLOR);	// ���� �ʱ�ȭ,,
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

	idx.push_back(vertex);	// �ش� ������ �湮�� ������ �߰�
}