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
		cout << "복제할 원본 객체가 없습니다. " << endl;

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

	//출력
	for (list<Object*>::iterator iter = ObjectList.begin();
		iter != ObjectList.end(); ++iter)
	{
		if (ObjectList)
			(*iter)->Render();
	}


	//삭제
	for (list<Object*>::iterator iter = ObjectList.begin();
		iter != ObjectList.end(); ++iter)
	{
		if (ObjectList)
			ObjectList.clear();
	}




	return 0;
}