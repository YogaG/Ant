#pragma once

#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

struct Pos
{
	double x;

	double y;

	double z;

	int m_judge;//judge the postion if is drawed
};

class Buffer
{
public:

	vector<vector<Pos>> m_buffer;

	Buffer(int num_ant);

	void Insert(int index,Pos p);//用于蚂蚁更新自己坐标后，buffe接收蚂蚁新的坐标信息。 

	bool IsInBuffer(int index,Pos p);

	//double com_path(int index);//计算到达终点的蚂蚁的真实路径长度

	void Show();

	void Write();
};