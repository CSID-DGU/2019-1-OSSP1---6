#include<iostream>
#include<vector>
#include<random>
#include<time.h>
using namespace std;

class Cowboy
{
public:
	float accuracy;
	bool isAlive = true;
	int point = 0; // ��Ƴ��� Ƚ��.
public:
	Cowboy()
	{}
	Cowboy(float accuracy) :accuracy(accuracy) {}
};

int getRandom()
//1���� 100���� ���� ����
{
	int number;
	number = rand() % 100 + 1;
	return number;
}

int getStrongest(vector<Cowboy> cowboyz , int index)
{
	int size = cowboyz.size();
	float temp = -1;
	int strongest;
	for (int i = 0; i < size; i++)
	{
		if (i!=index && cowboyz[i].accuracy > temp && cowboyz[i].isAlive)
		{
				temp = cowboyz[i].accuracy;
				strongest = i;
		}
	}
	return strongest;
}

int main()
{
	srand(time(NULL));
	vector<Cowboy> cowboyz;
	int index;
	cout << "ī�캸�̴� ���? ";
	cin >> index;
	int killCount = index;
	for (int i = 0; i < index; i++)
	{
		float percent;
		cin >> percent;
		cowboyz.push_back(Cowboy(percent*100));
	}
	for (int k = 0; k < 10000; k++)
	{
		while (killCount != 1)
		{
			for (int i = 0; i < index; i++)
			{
				if (cowboyz[i].accuracy > getRandom() && cowboyz[i].isAlive)
				{
					if (killCount == 1)
						break;
					cowboyz[getStrongest(cowboyz, i)].isAlive = false;
					killCount--;
				}
			}
		}
		for (int i = 0; i < index; i++)
		{
			if (cowboyz[i].isAlive)
				cowboyz[i].point +=1;
		}
		for (int i = 0; i < index; i++)
			cowboyz[i].isAlive = true;
		
		killCount = index;
	}
	for (int i = 0; i < index; i++)
		cout << i + 1 << "��° ī�캸�̰� ��Ƴ��� Ȯ�� : " << (float)cowboyz[i].point/100 << "%"<< endl;
	return 0;
}
