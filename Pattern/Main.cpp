#include "ObjectPoolManager.h"


int main(void)
{
	while (true)
	{
		ObjectpoolManager::GetInstance()->Initialize();
		ObjectpoolManager::GetInstance()->Update();
		ObjectpoolManager::GetInstance()->Render();
	}







	
	return 0;
}