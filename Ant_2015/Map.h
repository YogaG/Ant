#pragma once

#include"Buffer.h"


//蒸发先不考虑，现在预期的成果是蚂蚁能沿着固定的路径走下去并找到最佳路径

class Map
{
	int m_n;//地图的边长

	vector<vector<double>>m_pheromone;

	vector<vector<double>>m_expand_map;//扩展后的地图。默认蚂蚁搜索为3
public:
	
	Map(int N1,int scope);//N1是地图大小，scope是蚂蚁探知范围大小

	double Get_phe(int x, int y)const;//获取地图上信息素

	double Get_exp_phe(int x, int y)const;//获取扩展地图上的信息素

	void Change_phe(Buffer &buf, int index, int n);//n是蚂蚁的搜索范围

	void Evaporation();//每隔一段时间，信息素减2，直到其变为0.

	void expand(int n);

	void SetGoal(int x, int y);

	int GetN();

	void Test();//检测扩展地图
};