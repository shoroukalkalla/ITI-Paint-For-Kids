#include "ActionRestoreGraph.h"

#include <fstream>

#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

#include "ActionAddSquare.h"
#include "ActionAddEllipse.h"
#include "ActionAddHexagon.h"

ActionRestoreGraph::ActionRestoreGraph(ApplicationManager* pApp) :Action(pApp)
{}

void ActionRestoreGraph::Execute()
{
	GUI* pGUI = pManager->GetGUI();

	pGUI->PrintMessage("Type the file name and hit [Enter]");
	string filename = pGUI->GetSrting();

	if (filename.empty()) {
		pGUI->PrintMessage("Failed to load the file, You didn't type a file name!");
	}
	else {
		filename += ".txt";

		ifstream inputFile(filename);

		if (!inputFile.is_open()) {
			pGUI->PrintMessage("Can't find a file with the entered name!");
		}
		else {
			pManager->ClearAllFigures();

			// Draw_Color Fill_Color Background_Color
			// Number_of_Figures

			int drawC[3];
			int fillC[3];
			int backC[3];
			
			inputFile >> drawC[0] >> drawC[1] >> drawC[2];
			inputFile >> fillC[0] >> fillC[1] >> fillC[2];
			inputFile >> backC[0] >> backC[1] >> backC[2];

			color drawColor((char)drawC[0], (char)drawC[1], (char)drawC[2]);
			color fillColor((char)fillC[0], (char)fillC[1], (char)fillC[2]);
			color backgroudColor((char)backC[0], (char)backC[1], (char)backC[2]);

			int figuresCount = 0;

			int figureType;

			pGUI->RestoreColors(drawColor, fillColor, backgroudColor);

			inputFile >> figuresCount;
			
			for (int i = 0; i < figuresCount; i++) {
				inputFile >> figureType;
				switch (figureType) {
					case TYPE_SQUARE: {
						ActionAddSquare addSquare(pManager);
						addSquare.Load(inputFile);
						break;
					}
					case TYPE_ELLIPSE: {
						ActionAddEllipse addEllipse(pManager);
						addEllipse.Load(inputFile);
						break;
					}
					case TYPE_HEXAGON: {
						ActionAddHexagon addHexagon(pManager);
						addHexagon.Load(inputFile);
						break;
					}
				}
			}
			inputFile.close();
			pGUI->PrintMessage("Loaded successfully!");
		}
	}

}