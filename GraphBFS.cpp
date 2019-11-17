#include "GraphBFS.h"

GraphBFS::GraphBFS()
{
	nodeNumber = 0;
	begin = end = 0;
	Graph.clear();
	visited.clear();
	distance.clear();
	while (!q1.empty())
		q1.pop();
}

void GraphBFS::Init()
{
	cout << "请输入点的个数" << endl;
	cin >> nodeNumber;
	Graph.resize(nodeNumber + 1);//链表申请
	visited.resize(nodeNumber + 1, false);
	distance.resize(nodeNumber + 1, MAX);
	parent.resize(nodeNumber + 1, -1);
	cout << "请输入有几个关系" << endl;
	int a,b,c;
	cin >> a;
	cout << "请输入各边的关系以及距离" << endl;
	while (a--)
	{
		nPoint* p = new nPoint;
		cin >> b >> c >> p->d;
		p->arrive = c;
		LinkNode(b, p);//利用头插法插入链表中，b是定位到那个链表
	}
	cout << "请输入开始点和结束点" << endl;
	cin >> begin >> end;
}

void GraphBFS::BFS(int s)
{
	visited[s] = true;
	distance[s] = 0;
	q1.push(s);
	while (!q1.empty())
	{
		int u = q1.front();
		nPoint* op1 = Graph[u].next;
		while (op1)
		{
			if (!visited[op1->arrive])
			{
				q1.push(op1->arrive);
				parent[op1->arrive] = u;
				distance[op1->arrive] = distance[u] + op1->d;
				visited[op1->arrive] = true;
			}
			op1 = op1->next;
		}
		q1.pop();
	}
}


void GraphBFS::LinkNode(int locate, nPoint *p)
{
	nPoint* op1 = nullptr;
	op1 = Graph[locate].next;
	Graph[locate].next = p;
	p->next = op1;
	op1 = nullptr;
}

void GraphBFS::Display()
{
	BFS(begin);
	cout << "路径是: ";
	PrintPath(begin, end);
	cout << endl << "距离是: " << distance[end] << endl;
}

void GraphBFS::PrintPath(int b, int e)
{
	if (b == e)
		cout << b << " ";
	else if (parent[e] == -1)
		return;
	else {
		PrintPath(b, parent[e]);
		cout << e << " ";
	}
}

GraphBFS::~GraphBFS()
{
	Graph.clear();
	visited.clear();
	while (!q1.empty())
		q1.pop();
	begin = end = 0;
	nodeNumber = 0;
}
