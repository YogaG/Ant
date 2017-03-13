
#include"Ant.h"

bool All_Tar(vector<Ant> ants)
{
	for (int i = 0; i < ants.size(); i++)
	{
		if (ants[i].IsTarget() == 0)
		{
			if (ants[i].Is_die() == 1)
			{
				//cout << "第" << i << "只蚂蚁阵亡" << endl;
				continue;
			}
			return 0;
		}
		if (ants[i].IsTarget() == 1)
		{
			//cout << "第" << i << "只蚂蚁找到目标" << endl;
		}
	}
	return 1;
}

int main()
{
	//测试整体功能

	/*控制数据*/
	
	
	int gener = 5; //需要进行蚂蚁迭代的次数
	int num_ant = 5;//每代蚂蚁的数目
	Map map(50, 3);//地图大小
	map.SetGoal(24, 24);//食物坐标
	Buffer buf(num_ant);//缓冲区大小
	vector<Ant> ants;//蚂蚁群初始化
	
	double small_step = 999999;
	int    small_index = 0;
	int temp_gener = gener;

	/*for (int i = 0; i < num_ant; i++)
	{
		Ant m_ant(3, i);

		ants.push_back(m_ant);

		buf.Insert(i, ants[i].GetPos());
	}*/

	

	map.Test();


	//程序开始运行
	while (temp_gener--)
	{
		/*buf.Show();

		cout << endl << endl;*/
	
	//初始化容器

		buf.m_buffer.resize(num_ant*(gener - temp_gener));
		//继续给ants数组后面加蚂蚁
		for (int i = (gener - temp_gener - 1)*num_ant; i < (gener - temp_gener - 1)*num_ant + num_ant; i++)
		{
			Ant m_ant(3, i);

			ants.push_back(m_ant);

			buf.Insert(i, ants[i].GetPos());
		}

		/*buf.Show();

		cout << endl << endl;*/
		

        //该代蚂蚁出发
		while (!All_Tar(ants))
		{
			/*buf.Show();

			cout << endl << endl;*/

			for (int i = (gener - temp_gener - 1)*num_ant; i < (gener - temp_gener - 1)*num_ant + num_ant; i++)
			{
				if (ants[i].IsTarget())
				{
					continue;
				}
				else if (ants[i].Is_die())
				{
					continue;
				}

				else
				{
					ants[i].Update(map, buf);

					buf.Insert(i, ants[i].GetPos());

					//buf.Show();

					//cout << endl << endl << endl;

					if (ants[i].IsTarget())
					{
						if (buf.m_buffer[i].size() < small_step)
						{
							small_step = buf.m_buffer[i].size();

							small_index = i;

							map.Change_phe(buf, ants[i].GetIndex(), 3);
						}
					}
				}


			}

		}

		buf.Show();
		cout << endl;
		cout << small_index << endl;
		cout << small_step << endl;
		
		//system("pause");
	}

	buf.Write();
}