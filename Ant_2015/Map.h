#pragma once

#include"Buffer.h"


//�����Ȳ����ǣ�����Ԥ�ڵĳɹ������������Ź̶���·������ȥ���ҵ����·��

class Map
{
	int m_n;//��ͼ�ı߳�

	vector<vector<double>>m_pheromone;

	vector<vector<double>>m_expand_map;//��չ��ĵ�ͼ��Ĭ����������Ϊ3
public:
	
	Map(int N1,int scope);//N1�ǵ�ͼ��С��scope������֪̽��Χ��С

	double Get_phe(int x, int y)const;//��ȡ��ͼ����Ϣ��

	double Get_exp_phe(int x, int y)const;//��ȡ��չ��ͼ�ϵ���Ϣ��

	void Change_phe(Buffer &buf, int index, int n);//n�����ϵ�������Χ

	void Evaporation();//ÿ��һ��ʱ�䣬��Ϣ�ؼ�2��ֱ�����Ϊ0.

	void expand(int n);

	void SetGoal(int x, int y);

	int GetN();

	void Test();//�����չ��ͼ
};