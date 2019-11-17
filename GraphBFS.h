#pragma once
#ifndef _GRAPHBFS_H_
#define _GRAPHBFS_H_
#include<iostream>
#include<cstdlib>
#include<queue>
#include<vector>
using namespace std;
const int MAX = 0xffffff;

struct nPoint
{

	int arrive;
	int d;
	nPoint* next = nullptr;
	
};
class GraphBFS//使用邻接表访问
{
private:
	int nodeNumber;
	int begin, end;
	vector<nPoint>Graph;//连续性，相当于头指针
	vector<bool>visited;//判断是否经历过
	vector<int>distance;//距离
	vector<int>parent;//父母
	queue<int>q1;//队列

	void BFS(int s);//进行广搜
	void PrintPath(int b, int e);//打印路线
	void LinkNode(int locate,nPoint *p);//链接nPoint结点

public:
	GraphBFS();//构造函数
	void Init();//初始化
	void Display();
	~GraphBFS();

 };
#endif // !_GRAPHBFS_H_
