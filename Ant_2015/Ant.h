#pragma once

#include"Map.h"

//1、只考虑蚂蚁走7个方向，只根据周围信息素决定自己选择哪个点，不考虑非8个方向的斜率，蚂蚁不会走回头路，意思是蚂蚁不会直接掉头而不是不能走重复点。
//2、蚂蚁所有的移动全部根据信息素

class Ant
{
	int m_index;//指明是第几只蚂蚁

	Pos m_postion;

	int m_n;//蚂蚁可探知的范围

	vector<vector<double>> m_feel;//设计成可以更改m_feel的大小。

	int m_state; //蚂蚁的状态，是否找到食物(1),是否死亡（2）；
	
	bool m_repeat;//蚂蚁是否重复走过某点，这是与Buffer的一个接口

	int m_dir;
public:

	Ant() {};

	Ant(int n,int index);
		
	void Feel(Map& map, Buffer buf);
	//1、n是蚂蚁可以搜索的宫格边长
	//2、此函数解决了障碍物的问题，把障碍物的部分信息素置-1便好
	//3、此函数同样解决了不能走回头路的问题，在feel中把走过的店置1就好


	int Direction();
	//返回蚂蚁下一步点的方位,方位是按照九宫格左下角到右上角，去掉中间那一点0~8。
	//1、此函数的作用是找到蚂蚁下一步去往哪~可以用来日后的优化
	//2、此函数只考虑了蚂蚁九宫格的情况
	
	
	void Update(Map& map,Buffer buf);//更新自己的坐标位置，插入到Buffer是Buffer类做的事情 

	Pos GetPos();//得到蚂蚁的坐标

	int GetIndex();//得到蚂蚁的编号

	bool IsTarget();//得到蚂蚁的状态

	bool Still_Road(vector<double> feel);//判断是否有路可走

	bool Is_die();//判断死亡

	void Test();//测试Feel
};