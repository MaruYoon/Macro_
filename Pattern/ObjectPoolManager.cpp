#include "ObjectPoolManager.h"
#include "Object.h"

ObjectpoolManager* ObjectpoolManager::Instance = nullptr;

ObjectpoolManager::ObjectpoolManager()
{
}

ObjectpoolManager::~ObjectpoolManager()
{
}

void ObjectpoolManager::Initialize()
{

	//** DesableList �� ������ ������Ʈ�� �ִ��� Ȯ�� �ϰ� ���ٸ�...
	if (GetAsyncKeyState(VK_RETURN))
	{
		if (DesableList.empty())
		{
			DesableList.push_back(new Object);
		}
	}



	//** �߰� ������ ������Ʈ �ϳ��� ����.
	list<Object*>::iterator iter = DesableList.begin();


	//** �ʱ�ȭ �� �ʿ��� ���� �ۼ�.
	(*iter)->Initialize();

	//** ����� ����Ʈ�� �߰�.
	EnableList.push_back((*iter));

	//** ���� ����Ʈ���� ����.
	DesableList.pop_front();
}

void ObjectpoolManager::Update()
{

	for (list<Object*>::iterator iter = EnableList.begin();
		iter != EnableList.end();)
	{
		int iResult = (*iter)->Update();
		(*iter)->Render();

		if (iResult == 1)
		{
			//** ���� ����Ʈ���� ����.
			DesableList.push_back((*iter));

			//** ����� ����Ʈ�� �߰�.
			iter = EnableList.erase(iter);
		}
		else
			++iter;
	}

}

void ObjectpoolManager::Render()
{
	
	//** ���� ����Ʈ�� �����ִ� ������Ʈ�� ���� Ȯ��. (DesableList)
	string Buffer = "DesableList : " + to_string(DesableList.size());
	OutPut(10, 1, Buffer);
	Buffer.clear();

	//** ���� ����Ʈ�� �����ִ� ������Ʈ�� ���� Ȯ��. (EnableList)
	Buffer = "EnableList : " + to_string(EnableList.size());
	OutPut(10, 2, Buffer);
	

}

void ObjectpoolManager::Release()
{
	//** DesableList ���� ����
	for (list<Object*>::iterator iter = DesableList.begin();
		iter != DesableList.end(); ++iter)
	{
		delete (*iter);
		(*iter) = nullptr;
	}
	DesableList.clear();


	//** EnableList ���� ����
	for (list<Object*>::iterator iter = EnableList.begin();
		iter != EnableList.end(); ++iter)
	{
		delete (*iter);
		(*iter) = nullptr;
	}
	EnableList.clear();

}

void ObjectpoolManager::OutPut(float _x, float _y, string _str)
{
	COORD Pos = { (SHORT)_x, (SHORT)_y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	cout << _str << endl;
}





