#include <iostream>
#include <Windows.h>
#include <list>

using namespace std;


struct ObjectPool
{
	int Key;
	int Value;
	bool Active;

	ObjectPool() : Key(0), Value(0), Active(false) {}
	ObjectPool (int _Key, int _Value, bool _Active)
		: Key(_Key), Value(_Value), Active(_Active){}
};



bool check;


template <typename T>
inline void Safe_Delete(T& _Obj)
{
	if (_Obj)
	{
		delete _Obj;
		_Obj = NULL;
	}
}

#define SAFE_RELEASE(_Obj){Safe_Delete(_Obj);}




int main(void)
{
	list<ObjectPool*>ObjectPoolList;



	/*
	for (list< ObjectPool*>::iterator iter = ObjectPoolList.begin();
		iter != ObjectPoolList.end(); ++iter)
	{
		ObjectPoolList = (new ObjectPool(i,0,false));
	}
	*/

	



	ObjectPool*  Array[128] = { NULL };

	for (int i = 0; i < 128; ++i)
	{
		Array[i] = new ObjectPool;

		Array[i]->Active = false;
		Array[i]->Key = i;
		Array[i]->Value = 0;
	}


	while (true)
	{
		system("cls");

		check = false;

		if (GetAsyncKeyState(VK_RETURN))
			check = true;
		

		if (check)
		{
			list< ObjectPool*>::iterator iter = ObjectPoolList.begin();

			if (ObjectPoolList.empty())
			{

			}


				/*
				if (!(*iter)->Active)
				{
					Array[i]->Active = true;
					Array[i]->Value = 0;
					break;
				}
			 */
			}

		}
	

		for (int i = 0; i < 128; ++i)
		{
			if (Array[i])
			{
				cout << Array[i]->Key << "  :  " << Array[i]->Value << endl<< endl;

				if (Array[i]->Value >= 50)
				{
					Array[i]->Active = false;
				}
			}
		}
		Sleep(50);
	}


	for (int i = 0; i < 128; ++i)
	{
		delete Array[i];
		Array[i] = NULL;
	}




	 /*
	 C (��������) ���� C++(��ü����)���� �ٲ����, C#(++++)�� ��ȭ�Ѵ�.
	 
	 ������ ��� : C, C++ 
	 �ڵ��� ��� : C#

	 C�� C++��(������ ���) �����ͷ� �ּҸ� ���� ������ �� �ֱ� ������ �ٸ� ���鿡 ���� ���� ����� ���.
	 �޸� ������ ȿ�����̴�.

	 ��ü ���� (OOP)�� Ư¡
	 1) ��������
     2) �߻�ȭ
     3) ĸ��ȭ
     4) ���
     5) ������

	 �߻�ȭ �ؿ� �������� �ְ� ������ ����� ����� �ȴ�. 
	 �������� ������ ������ Object�� �����Ϳ� ����� �ϳ��� ���� ĸ��ȭ �ϸ�,
	 ������ �����Ѵ�. 

	 ��ü������ ���� JAVA�� ��ǥ���̴�.

	 c#�� static �� �⺻���� �Ѵ�. (���α׷��� ���̰� ����� ������� �׸�ŭ�� ȿ���� �����ش�.)

	 ObjectPool�� �޸��� ���ϸ� �������� �����⸦ ������ �ʴ� ����� ������ �����̴�.

	 C#�� ��������� ���̴� ������ ��� ��������� �������� �ϰ������� ������ �ϴµ�
	 ������ ������ �޸𸮿� ���� ū ���ϸ� �������ֱ� ������ ������ ������ִ�. 



	 */

	return 0;
}

void InputKey(Objectpool* _pool)
{
	if (!check)
		return;

	

}




