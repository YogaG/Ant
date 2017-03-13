#include"Map.h"

Map::Map(int N1,int n)//
{
	m_n = N1;

	m_pheromone.resize(N1);

	for (int i = 0; i < N1; i++)
	{
		m_pheromone[i].resize(N1);
	}

	for (int i = 0; i < m_pheromone.size(); i++)
	{
		for (int j = 0; j < m_pheromone.size(); j++)
		{
			if (i == j)
			{
				m_pheromone[i][j] = 10;
			}
		}
	}

	//À©Õ¹µØÍ¼
	m_expand_map.resize(m_pheromone.size() + (n / 2) * 2);

	for (int i = 0; i < m_pheromone.size() + (n / 2) * 2; i++)
	{
		m_expand_map[i].resize(m_pheromone.size() + (n / 2) * 2);
	}

	for (int i = 0; i < m_expand_map.size(); i++)
	{
		for (int j = 0; j < n / 2; j++)
		{
			m_expand_map[j][i] = -1;

			m_expand_map[i][j] = -1;

			m_expand_map[m_expand_map.size() - 1 - j][i] = -1;

			m_expand_map[i][m_expand_map.size() - 1 - j] = -1;
		}
	}

	for (int i = n / 2; i < m_expand_map.size() - n / 2; i++)
	{
		for (int j = n / 2; j < m_expand_map.size() - n / 2; j++)
		{
			m_expand_map[i][j] = m_pheromone[i - n / 2][j - n / 2];
		}
	}

	//test
	/*for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			m_pheromone[i][j] = 2;
		}
	}*/
}

double Map::Get_phe(int x, int y)const
{
	return m_pheromone[y][x];
}

double Map::Get_exp_phe(int x, int y)const
{
	return m_expand_map[y][x];
}

void   Map::Change_phe(Buffer &buf,int index,int n)
{
	for (int i = 0; i < buf.m_buffer[index].size(); i++)
	{
		m_pheromone[buf.m_buffer[index][i].y+m_n/2][buf.m_buffer[index][i].x+m_n/2] += 10;
	}

	for (int i = n / 2; i < m_expand_map.size() - n / 2; i++)
	{
		for (int j = n / 2; j < m_expand_map.size() - n / 2; j++)
		{
			m_expand_map[i][j] = m_pheromone[i - n / 2][j - n / 2];
		}
	}

}

void   Map::Evaporation()
{
	for (int i = 0; i < m_pheromone.size(); i++)
	{
		for (int j = 0; j < m_pheromone.size(); i++)
		{
			if (m_pheromone[i][j] < 2)
			{
				m_pheromone[i][j] = 0;
			}
			m_pheromone[i][j] -= 2;

		}
	}
}

int    Map::GetN()
{
	return m_n;
}

void   Map::expand(int n)
{
	
}

void   Map::Test()
{
	for (int i = 0; i < m_expand_map.size(); i++)
	{
		for (int j = 0; j < m_expand_map.size(); j++)
		{
			cout << m_expand_map[i][j] << " ";
		}

		cout << endl;
	}
}

void   Map::SetGoal(int x, int y)
{
	m_pheromone[y + m_n / 2][x + m_n / 2] = 99999999;
	
	int temp = (m_expand_map.size() - m_pheromone.size()) / 2;

	m_expand_map[y + m_n / 2 + temp][x + m_n / 2 + temp] = 99999999;
}