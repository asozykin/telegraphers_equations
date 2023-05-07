//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Chart3D.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
Form1->Show();
    int i;
    for( i = 0; i < 100; i++ )
    {
        Ss[i]->Free();
        Ssi[i]->Free();
    };

Form2->Hide();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
Form1->Show();
    int i;
    for( i = 0; i < 100; i++ )
    {
        Ss[i]->Free();
        Ssi[i]->Free();
    };
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{
Chart2->Hide();
Chart1->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button3Click(TObject *Sender)
{
Chart1->Hide();
Chart2->Show();
}
//---------------------------------------------------------------------------

