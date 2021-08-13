#include "Prototype.h"
#include "Object.h"

list<Object*> ObjectList;

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

	for (int i = 0; i < 5; ++i)
	{
		Object* pTempObj = pObj->Clone();

		pTempObj->Initialize();
		pTempObj->SetIndex(i + 1);

		ObjectList.push_back(pTempObj);
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
		(*iter)->Render();
	}

	//삭제
	for (list<Object*>::iterator iter = ObjectList.begin();
		iter != ObjectList.end(); ++iter)
	{
		delete (*iter);
		(*iter) = nullptr;
	}
	ObjectList.clear();

	return 0;
}