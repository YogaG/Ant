#include"Buffer.h"

Buffer::Buffer(int num_ant)
{
	m_buffer.resize(num_ant);
}

void Buffer::Insert(int index, Pos p)
{
	if (!IsInBuffer(index, p))
	{
		m_buffer[index].push_back(p);
	}
}

bool Buffer::IsInBuffer(int index,Pos p)
{
	for (int i = 0; i < m_buffer[index].size(); i++)
	{
		if (p.x == m_buffer[index][i].x && p.y == m_buffer[index][i].y)
		{
			return 1;
		}
	}
	return 0;
}

void Buffer::Show()
{
	for (int i = 0; i < m_buffer.size(); i++)
	{
		for (int j = 0; j < m_buffer[i].size(); j++)
		{
			cout << "(" << m_buffer[i][j].x << "," << m_buffer[i][j].y << ")" << " ";
		}
		cout << endl << endl;
	}
}

void Buffer::Write()
{
	ofstream file;

	file.open("Buffer");

	for (int i = 0; i < m_buffer.size(); i++)
	{
		for (int j = 0; j < m_buffer[i].size(); j++)
		{
			 file << "(" << m_buffer[i][j].x << "," << m_buffer[i][j].y << ")" << " ";
		}
		file << "\n" << "\n";

		if ((i + 1) % 5 == 0)
		{
			file << "\n";
		}
	}

	file.close();
}