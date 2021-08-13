#include "Prototype.h"
#include "Object.h"

list<Object*>ObjectList;

void InitObject(string _Key)
{
	Object* pObj = Prototype::GetInstance()->FineObject(_Key);

	if (pObj == nullptr)
	{
		COORD Pos = { (SHORT)50, (SHORT)15 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
		cout << "������ ���� ��ü�� �����ϴ�. " << endl;

		return;
	}


	for (list<Object*>::iterator iter = ObjectList.begin();
		iter != ObjectList.end();++iter)
	{
		ObjectList.push_back((*iter)->Clone());

		(*iter)->Initialize();
		(*iter)->SetIndex(ObjectList.begin() + 1);
	}

}

int main(void)
{
	Prototype::GetInstance()->Initialize();

	InitObject("Object");

	//���
	for (list<Object*>::iterator iter = ObjectList.begin();
		iter != ObjectList.end(); ++iter)
	{
			(*iter)->Render(1);
	}


	//����
	for (list<Object*>::iterator iter = ObjectList.begin();
		iter != ObjectList.end(); ++iter)
	{
			ObjectList.clear();
	}




	return 0;
}