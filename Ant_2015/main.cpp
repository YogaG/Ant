
#include"Ant.h"

bool All_Tar(vector<Ant> ants)
{
	for (int i = 0; i < ants.size(); i++)
	{
		if (ants[i].IsTarget() == 0)
		{
			if (ants[i].Is_die() == 1)
			{
				//cout << "��" << i << "ֻ��������" << endl;
				continue;
			}
			return 0;
		}
		if (ants[i].IsTarget() == 1)
		{
			//cout << "��" << i << "ֻ�����ҵ�Ŀ��" << endl;
		}
	}
	return 1;
}

int main()
{
	//�������幦��

	/*��������*/
	
	
	int gener = 5; //��Ҫ�������ϵ����Ĵ���
	int num_ant = 5;//ÿ�����ϵ���Ŀ
	Map map(50, 3);//��ͼ��С
	map.SetGoal(24, 24);//ʳ������
	Buffer buf(num_ant);//��������С
	vector<Ant> ants;//����Ⱥ��ʼ��
	
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


	//����ʼ����
	while (temp_gener--)
	{
		/*buf.Show();

		cout << endl << endl;*/
	
	//��ʼ������

		buf.m_buffer.resize(num_ant*(gener - temp_gener));
		//������ants������������
		for (int i = (gener - temp_gener - 1)*num_ant; i < (gener - temp_gener - 1)*num_ant + num_ant; i++)
		{
			Ant m_ant(3, i);

			ants.push_back(m_ant);

			buf.Insert(i, ants[i].GetPos());
		}

		/*buf.Show();

		cout << endl << endl;*/
		

        //�ô����ϳ���
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