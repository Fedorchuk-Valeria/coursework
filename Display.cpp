//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Display.h"
#include "Field.h"
#include "Flag.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPlayDisplay *PlayDisplay;
Field field;
Flag flag;

//---------------------------------------------------------------------------
__fastcall TPlayDisplay::TPlayDisplay(TComponent* Owner)
	: TForm(Owner)
{
	field.FillingWithBombs(Field);
	field.FillingWithNumbers(Field);
	field.AmountOfSafeCells(Field);
}
//---------------------------------------------------------------------------

void __fastcall TPlayDisplay::SelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect)
{
	if(Field->Cells[ACol][ARow] == "b" && flag.flag == 0)
	{
		Field->Canvas->Brush->Color = clRed;
		for(int i = 0; i < 21; i++)
		{
			for(int j = 0; j < 21; j++)
			{
				TRect Rect = Field->CellRect(i, j);
				Field->Canvas->FillRect(Rect);
			}
		}
		End->Left = 270;
		End->Caption = "GAME OVER";
	} else if(Field->Cells[ACol][ARow] != "b" && flag.flag == 0)
	{
		TRect Rect = Field->CellRect(ACol, ARow);
		Field->Canvas->Brush->Color = clGray;
		Field->Canvas->FillRect(Rect);
        Field->Canvas->Font->Color = clBlack;
		Field->Canvas->TextOut(Rect.Left, Rect.Top, Field->Cells[ACol][ARow]);
		field.safeÑells--;
	} else if(flag.flag == 1)
	{
	   TRect Rect = Field->CellRect(ACol, ARow);
	   Field->Canvas->Brush->Color = clRed;
	   Field->Canvas->FillRect(Rect);
	}
	if(field.safeÑells == 0)
	{
        End->Left = 270;
		End->Caption = "YOU WIN";
    }
}
//---------------------------------------------------------------------------

void __fastcall TPlayDisplay::MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	if(Button == mbRight && flag.count == 0)
	{
		flag.Press();
	} else if(Button == mbRight)
	{
		flag.Release();
    }
}
//---------------------------------------------------------------------------

void __fastcall TPlayDisplay::ReplayButtonClick(TObject *Sender)
{
	End->Caption = "";
	End->Left = -50;
	Field->Canvas->Brush->Color = clBlack;
	for(int i = 0; i < 21; i++)
	{
		for(int j = 0; j < 21; j++)
		{
			TRect Rect = Field->CellRect(i, j);
			Field->Canvas->FillRect(Rect);
		}
	}
    for(int j = 0; j < 21; j++)
	{
        Field->Rows[j]->Clear();
	}
	field.FillingWithBombs(Field);
	field.FillingWithNumbers(Field);
    field.AmountOfSafeCells(Field);
}
//---------------------------------------------------------------------------

