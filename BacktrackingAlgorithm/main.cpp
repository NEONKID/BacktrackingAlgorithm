/*
	author : neonkid
	date : '16. 05. 27
*/

#include <stack>

#include "BT.h"

using namespace std;

int _tmain()
{
	int i, x, y;

	// 초기 색깔 초기화,,
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFAULT_COLOR);

	cout << " 정점의 갯수 입력: ";
	cin >> i;
	cout << endl;

	Graph *graph = new Graph(i);	// 그래프 생성,,

	cout << endl << " ******** Index 입력 방법 ******** " << endl;
	cout << " Index의 입력 방식은 다음과 같습니다. " << endl;
	cout << " 0을 root로 놓고, 해당 정점과 이웃한 " << endl;
	cout << " 정점을 입력합니다. (밑에 예시 참조) " << endl;
	cout << " ex) 0 1 (0과 이웃한 정점이 1을 추가) " << endl;
	cout << " ex) 0 2 (0과 이웃한 또다른 정점 2 추가) " << endl << endl;

	/*
		Index의 입력은 다음과 같다.
		Root가 0이면, 0과 이웃하는 노드 한 개를 입력해준다. ex) 0 1
		다른 예로, 1과 2도 이웃하면 ==> ex) 1 2
	*/

	for (int j = 1; j <= i; j++)
	{
		cout << " 인덱스 입력(예: 1 2): ";
		cin >> x >> y;	// Input indexes

		graph->AddEdge(x,y);	// 엣지 생성,,
	}

	graph->PrintNeighbors();

	stack<BT *> vs;

	BT *vst = new BT(graph, 0, i - 1);	// 초기 방문 정보를 생성,,
	vs.push(vst);	// 스택에 보관
	while (vs.empty() == false)		// 스택이 비어있는지를 검사,,
	{
		vst = vs.top();	// 스택에서 경험 정보 가져옴,,
		vs.pop();
		vst->Print();
		Vsted nVsted = vst->EnumNext();	// 스택에서 꺼내온 방문 정보에서 다음 방문 목록 조사
		VIter seek = nVsted.begin();
		VIter last = nVsted.end();

		for (; seek != last; ++seek)	// 반복 (다음 방문 목록을 순차적으로 반복)
		{
			if ((*seek)->IsDest())	// 목적지에 도달하면
			{
				cout << " 솔루션 ";
				(*seek)->Print();	// 결과 출력
				delete (*seek);
			}
			else	// 그렇지 않다면
			{
				vs.push(*seek);	// 스택에 보관 후, return
			}
		}
		delete vst;
	}

	return 0;
}