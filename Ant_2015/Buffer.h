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

	void Insert(int index,Pos p);//�������ϸ����Լ������buffe���������µ�������Ϣ�� 

	bool IsInBuffer(int index,Pos p);

	//double com_path(int index);//���㵽���յ�����ϵ���ʵ·������

	void Show();

	void Write();
};