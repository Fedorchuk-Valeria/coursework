//---------------------------------------------------------------------------

#ifndef FieldH
#define FieldH
//---------------------------------------------------------------------------
#endif

#include "Display.h"
#include "Bombs.h"
#include <vcl.h>

class Field
{
  Bombs* bombs = NULL;

  public:
	int safeÑells;

	void FillingWithBombs(TStringGrid *Field);

	void FillingWithNumbers(TStringGrid *Field);

	void AmountOfSafeCells(TStringGrid *Field);

	~Field()
	{
        delete bombs;
    	}
};
