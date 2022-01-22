#include "ActionStoreGraph.h"

#include <fstream>

#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"


ActionStoreGraph::ActionStoreGraph(ApplicationManager* pApp) :Action(pApp)
{}

void ActionStoreGraph::Execute()
{
	GUI* pGUI = pManager->GetGUI();

	pGUI->PrintMessage("Type the file name and hit [Enter]");
	string filename = pGUI->GetSrting();

	if (filename.empty()) {
		pGUI->PrintMessage("Failed to save the file, You didn't type a file name!");
	}
	else {
		filename += ".txt";

		ofstream outputFile(filename);
		pManager->StoreGraphData(outputFile);
		outputFile.close();
		pGUI->PrintMessage("Saved successfully!");
	}
}