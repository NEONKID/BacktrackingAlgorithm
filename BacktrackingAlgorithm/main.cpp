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

	// �ʱ� ���� �ʱ�ȭ,,
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFAULT_COLOR);

	cout << " ������ ���� �Է�: ";
	cin >> i;
	cout << endl;

	Graph *graph = new Graph(i);	// �׷��� ����,,

	cout << endl << " ******** Index �Է� ��� ******** " << endl;
	cout << " Index�� �Է� ����� ������ �����ϴ�. " << endl;
	cout << " 0�� root�� ����, �ش� ������ �̿��� " << endl;
	cout << " ������ �Է��մϴ�. (�ؿ� ���� ����) " << endl;
	cout << " ex) 0 1 (0�� �̿��� ������ 1�� �߰�) " << endl;
	cout << " ex) 0 2 (0�� �̿��� �Ǵٸ� ���� 2 �߰�) " << endl << endl;

	/*
		Index�� �Է��� ������ ����.
		Root�� 0�̸�, 0�� �̿��ϴ� ��� �� ���� �Է����ش�. ex) 0 1
		�ٸ� ����, 1�� 2�� �̿��ϸ� ==> ex) 1 2
	*/

	for (int j = 1; j <= i; j++)
	{
		cout << " �ε��� �Է�(��: 1 2): ";
		cin >> x >> y;	// Input indexes

		graph->AddEdge(x,y);	// ���� ����,,
	}

	graph->PrintNeighbors();

	stack<BT *> vs;

	BT *vst = new BT(graph, 0, i - 1);	// �ʱ� �湮 ������ ����,,
	vs.push(vst);	// ���ÿ� ����
	while (vs.empty() == false)		// ������ ����ִ����� �˻�,,
	{
		vst = vs.top();	// ���ÿ��� ���� ���� ������,,
		vs.pop();
		vst->Print();
		Vsted nVsted = vst->EnumNext();	// ���ÿ��� ������ �湮 �������� ���� �湮 ��� ����
		VIter seek = nVsted.begin();
		VIter last = nVsted.end();

		for (; seek != last; ++seek)	// �ݺ� (���� �湮 ����� ���������� �ݺ�)
		{
			if ((*seek)->IsDest())	// �������� �����ϸ�
			{
				cout << " �ַ�� ";
				(*seek)->Print();	// ��� ���
				delete (*seek);
			}
			else	// �׷��� �ʴٸ�
			{
				vs.push(*seek);	// ���ÿ� ���� ��, return
			}
		}
		delete vst;
	}

	return 0;
}