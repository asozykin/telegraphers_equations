//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("LongLine.res");
USEFORM("Main.cpp", Form1);
USEUNIT("LLMath.cpp");
USEFORM("Chart3D.cpp", Form2);
USEFILE("complex.h");
USEFORM("About.cpp", Form3);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->HelpFile = "D:\\Program Files\\Borland\\CBuilder5\\Projects\\CB4\\LongLine.6\\LLHLP.hlp";
         Application->Title = "Long Line";
         Application->CreateForm(__classid(TForm1), &Form1);
         Application->CreateForm(__classid(TForm2), &Form2);
         Application->CreateForm(__classid(TForm3), &Form3);
         Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
