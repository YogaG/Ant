#include"Ant.h"

Ant     ::Ant(int n,int index)//蚂蚁可以搜索多大的信息素范围
{	
	m_index = index;
	m_state = 0;
	m_repeat = 0;

	m_postion.x = 0;
	m_postion.y = 0;
	m_postion.z = 0;
	m_postion.m_judge = 0;

	m_n = n;

	m_dir = 8;

	m_feel.resize(n);

	for (int i = 0; i < n; i++)
	{
		m_feel[i].resize(n);
	}

}


/*这里需要优化如果蚂蚁在搜索范围内能找到食物 那么方向就确定了！*/

void Ant::Feel(Map&map,Buffer buf)
{
	for (int i = 0; i < m_n; i++)
	{
		for (int j = 0; j < m_n; j++)
		{
			//**********************
			m_feel[i][j] = map.Get_exp_phe(m_postion.x + map.GetN() / 2 + j, m_postion.y + map.GetN() / 2 + i);

			if (m_feel[i][j] == 99999999)
			{
				m_state = 1;
				m_dir = i*m_n + j;

				if (m_dir >= 4)
				{
					m_dir -= 1;
				}
			}

			/*//如果蚂蚁四周的点在buffer中并且不是食物 就给他-1？ 并不是这样的。。。蚂蚁不知道buffer中的点。
			Pos temp;
			temp.x = m_postion.x - 1 + j;
			temp.y = m_postion.y - 1 + i;
			temp.z = 0;
			temp.m_judge = 0;

			
			if (buf.IsInBuffer(m_index, temp) && map.Get_exp_phe(m_postion.x + map.GetN() / 2 + j, m_postion.y + map.GetN() / 2 + i) != 99999999)
			{
				m_feel[i][j] = -1;
			}
			else
			{
				m_feel[i][j] = map.Get_exp_phe(m_postion.x + map.GetN() / 2 + j, m_postion.y + map.GetN() / 2 + i);
			}*/
		}

		//********************
		m_feel[m_n / 2][m_n / 2] = -1;
	}



	//蚂蚁感知到的周围环境的输出
	/*for (int i = m_n - 1; i >= 0; i--)
	{
		for (int j = 0; j <m_n; j++)
		{
			cout << m_feel[i][j] << " ";
		}
		cout << endl;
	}*/
}

int  Ant::Direction()
{
	double sum = 0;
	
	int selection = 0; //选择往哪个方位移动,selection只有0-9 10个选项，8代表停止,9代表无路可走，暂时定义让他停下来

	//**********找到目标
	if (m_state == 1)
	{
		return m_dir;
	}

	/*if (m_feel[1][1] == 99999999)
	{
		m_state = 1;
		selection = 8;
		return selection;
	}*/



	//没有找到目标

	//初始化两个辅助数组
	vector<double> feel;//将二维信息素数组转化为一维，确定了信息素的标号
	vector<int> phero;//存放的是信息素非-1的标号,和没有走过的点的标号

	//初始化feel数组
	for (int i = 0; i < m_n; i++)
	{
		for (int j = 0; j < m_n; j++)
		{
			if (i == 1)
			{
				if (j == 1)
				{
					continue;
				}
				
			}
			feel.push_back(m_feel[i][j]);
		}
	}

	//对自己本身的方向做一个修改，知道自己的方向后，更倾向于走自己原来的方向 m_dir是初始化的方向
	
	switch (m_dir)
	{
	case 0: 
	{
		if (feel[0] == 0)
		{
			feel[0] += 4;
		}
		else if (feel[0] != -1)
		{
			feel[0] *= 4;
		}

		if (feel[1] == 0)
		{
			feel[1] += 2;
		}

		else if (feel[1] != -1)
		{
			feel[1] *= 2;
		}

		if (feel[3] == 0)
		{
			feel[3] += 2;
		}

		else if (feel[3] != -1)
		{
			feel[3] *= 2;
		}
	}
	break;
	case 1:
	{
		if (feel[1] == 0)
		{
			feel[1] += 4;
		}
		else if (feel[1] != -1)
		{
			feel[1] *= 4;
		}

		if (feel[0] == 0)
		{
			feel[0] += 2;
		}

		else if (feel[0] != -1)
		{
			feel[0] *= 2;
		}

		if (feel[2] == 0)
		{
			feel[2] += 2;
		}

		else if (feel[2] != -1)
		{
			feel[2] *= 2;
		}
	}
	break;
	case 2:
	{
		if (feel[2] == 0)
		{
			feel[2] += 4;
		}
		else if (feel[2] != -1)
		{
			feel[2] *= 4;
		}

		if (feel[1] == 0)
		{
			feel[1] += 2;
		}

		else if (feel[1] != -1)
		{
			feel[1] *= 2;
		}

		if (feel[4] == 0)
		{
			feel[4] += 2;
		}

		else if (feel[4] != -1)
		{
			feel[4] *= 2;
		}
	}
	break;
	case 3:
	{
		if (feel[3] == 0)
		{
			feel[3] += 4;
		}
		else if (feel[3] != -1)
		{
			feel[3] *= 4;
		}

		if (feel[0] == 0)
		{
			feel[0] += 2;
		}

		else if (feel[0] != -1)
		{
			feel[0] *= 2;
		}

		if (feel[5] == 0)
		{
			feel[5] += 2;
		}

		else if (feel[5] != -1)
		{
			feel[5] *= 2;
		}
	}
	break;
	case 4:
	{
		if (feel[4] == 0)
		{
			feel[4] += 4;
		}
		else if (feel[4] != -1)
		{
			feel[4] *= 4;
		}

		if (feel[2] == 0)
		{
			feel[2] += 2;
		}

		else if (feel[2] != -1)
		{
			feel[2] *= 2;
		}

		if (feel[7] == 0)
		{
			feel[7] += 2;
		}

		else if (feel[7] != -1)
		{
			feel[7] *= 2;
		}
	}break;
	case 5:
	{
		if (feel[5] == 0)
		{
			feel[5] += 4;
		}
		else if (feel[5] != -1)
		{
			feel[5] *= 4;
		}

		if (feel[3] == 0)
		{
			feel[3] += 2;
		}

		else if (feel[3] != -1)
		{
			feel[3] *= 2;
		}

		if (feel[6] == 0)
		{
			feel[6] += 2;
		}

		else if (feel[6] != -1)
		{
			feel[6] *= 2;
		}
	}break;
	case 6:
	{
		if (feel[6] == 0)
		{
			feel[6] += 4;
		}
		else if (feel[6] != -1)
		{
			feel[6] *= 4;
		}

		if (feel[5] == 0)
		{
			feel[5] += 2;
		}

		else if (feel[5] != -1)
		{
			feel[5] *= 2;
		}

		if (feel[7] == 0)
		{
			feel[7] += 2;
		}

		else if (feel[7] != -1)
		{
			feel[7] *= 2;
		}
	}break;
	case 7:
	{
		if (feel[7] == 0)
		{
			feel[7] += 4;
		}
		else if (feel[7] != -1)
		{
			feel[7] *= 4;
		}

		if (feel[6] == 0)
		{
			feel[6] += 2;
		}

		else if (feel[6] != -1)
		{
			feel[6] *= 2;
		}

		if (feel[4] == 0)
		{
			feel[4] += 2;
		}

		else if (feel[4] != -1)
		{
			feel[4] *= 2;
		}
	}
	break;
	}

	//******************这里去掉了
	/*//安全性处理，如果周围的点都已经是-1了怎么办
	if (!Still_Road(feel))
	{
		m_state = 2.;
		selection = 9;
		return selection;
	}*/

	//***else
	//***{
		//初始化phero数组
		for (int i = 0; i < feel.size(); i++)
		{
			if (feel[i] != -1)
			{
				phero.push_back(i);

				sum += feel[i];
			}
		}

		/*//test
		for (int i = 0; i < phero.size(); i++)
		{
			cout << phero[i] << " ";
		}
		cout << endl << endl;*/


		vector<double> pro; //用来存储0~1各点，分界点为前一概率和其概率之和

		if (sum == 0)
		{
			int a = rand() % phero.size();
			selection = phero[a];
		}

		else
		{
			pro.push_back(feel[phero[0]] / sum);

			for (int i = 1; i < phero.size() - 1; i++)
			{
				pro.push_back(pro[i - 1] + feel[phero[i]] / sum);
			}

			pro.push_back(1);

			double p = rand() % 100 * 0.01;

			for (int i = 0; i < pro.size(); i++)
			{
				if (p < pro[i])
				{
					selection = phero[i];
					break;
				}
			}
		}

		/*//test
		for (int i = 0; i < pro.size(); i++)
		{
			cout << pro[i] << " ";
		}
		cout << endl<<endl;
		cout << selection << endl;*/

		return selection;
	}
//***}

void Ant::Update(Map& map,Buffer buf)
{
	Feel(map,buf);

	m_dir = Direction();
	
	if (m_dir == 0)
	{
		m_postion.x -= 1;

		m_postion.y -= 1;

	}

	else if (m_dir == 1)
	{
		m_postion.y -= 1;

	}

	else if (m_dir == 2)
	{
		m_postion.x += 1;
		m_postion.y -= 1;

	}

	else if (m_dir == 3)
	{
		m_postion.x -= 1;

	}

	else if (m_dir == 4)
	{
		m_postion.x += 1;

	
	}

	else if (m_dir == 5)
	{
		m_postion.x -= 1;
		m_postion.y += 1;

	}

	else if (m_dir == 6)
	{
		m_postion.y += 1;

	}

	else if (m_dir == 7)
	{
		m_postion.x += 1;
		m_postion.y += 1;
	}

}

bool Ant::IsTarget()
{
	if (m_state == 1)
	{
		return true;
	}
	else
		return false;
}

int Ant::GetIndex()
{
	return m_index;
}

Pos Ant::GetPos()
{
	return m_postion;
}

bool Ant::Still_Road(vector<double> feel)
{
	for (int i = 0; i < feel.size(); i++)
	{
		if (feel[i] != -1)
		{
			return 1;
		}
	}
	return 0;
}

bool Ant::Is_die()
{
	if (m_state == 2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Ant::Test()
{
	for (int i = m_n - 1; i >= 0; i--)
	{
		for (int j = 0; j <m_n ; j++)
		{
			cout << m_feel[i][j] << " ";
		}
		cout << endl;
	}
}
