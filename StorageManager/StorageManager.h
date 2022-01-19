#ifndef STORAGE_MANAGER_H
#define STORAGE_MANAGER_H

#include "..\Figures\CFigure.h"

class ApplicationManager;

class StorageManager
{
private:
	ApplicationManager* pManager;	//Actions needs AppMngr to do their job

public:
	StorageManager(ApplicationManager* pApp);

	void StoreGraph(CFigure* figures);
	CFigure* RestoreGraph(string fileName);
};

#endif

