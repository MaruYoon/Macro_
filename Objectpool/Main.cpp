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
	 C (절차지향) 에서 C++(객체지향)으로 바뀌었고, C#(++++)로 진화한다.
	 
	 수동적 언어 : C, C++ 
	 자동적 언어 : C#

	 C와 C++은(수동형 언어) 포인터로 주소만 들고와 참조할 수 있기 때문에 다른 언어들에 비해 적은 비용이 든다.
	 메모리 관리가 효율적이다.

	 객체 지향 (OOP)의 특징
	 1) 정보은닉
     2) 추상화
     3) 캡슐화
     4) 상속
     5) 다형성

	 추상화 밑에 다형성이 있고 서로의 관계는 상속이 된다. 
	 다형성을 가지는 각개의 Object는 데이터와 기능을 하나로 묶인 캡슐화 하며,
	 정보를 은닉한다. 

	 객체지향적 언어는 JAVA가 대표적이다.

	 c#은 static 을 기본으로 한다. (프로그램이 무겁고 비용이 비싸지만 그만큼의 효율을 보여준다.)

	 ObjectPool은 메모리의 부하를 가져오는 쓰레기를 만들지 않는 방식의 디자인 패턴이다.

	 C#은 쓰레기들이 모이는 가비지 라는 저장공간이 가득차면 일괄적으로 삭제를 하는데
	 생성과 삭제는 메모리에 가장 큰 부하를 가져다주기 때문에 게임이 멈출수있다. 



	 */

	return 0;
}

void InputKey(Objectpool* _pool)
{
	if (!check)
		return;

	

}




