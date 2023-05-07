//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include "LLMath.h"
#include "Chart3D.h"
#include "About.h"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) // MYSORE?????
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Exit1Click(TObject *Sender) // QUIT
{
if(Application->MessageBox("Выйти без сохранения?","                       ВЫХОД",MB_YESNO | MB_ICONQUESTION) == 6)
 Close();
else
 return;
 }
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)  // OnFormCreate
{
   ErrOr = false;
   // face initialization (kak i w Menu.File.New)
   cbR->ItemIndex = 2;
   cbL->ItemIndex = 0;
   cbC->ItemIndex = 1;
   cbA1->ItemIndex = 1;
   cbW->ItemIndex = 2;
   cbR0->ItemIndex = 2;
   cbL0->ItemIndex = 1;
   cbG0->ItemIndex = 1;
   cbC0->ItemIndex = 0;
   cbA3->ItemIndex = 1;
   Series7->Clear();
   Series7->AddXY(19.53, 100, "", clTeeColor );
   Series7->AddXY(19.53, 0, "", clTeeColor );
   Series8->Clear();
   Series8->AddXY(19.53, 181, "", clTeeColor );
   Series8->AddXY(19.53, -181, "", clTeeColor );

   // secondary params set, drawing charts
   eLL->Text = FloatToStr(63);
   drawChart();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::rbHHClick(TObject *Sender)
{
Panel1->Enabled = false; // Panel disabling
eR->Enabled = false;
cbR->Enabled = false;
CheckBox1->Enabled = false;
eL->Enabled = false;
cbL->Enabled = false;
CheckBox2->Enabled = false;
eC->Enabled = false;
cbC->Enabled = false;
CheckBox3->Enabled = false;
eR->Text = FloatToStr(0);
eL->Text = FloatToStr(0);
eC->Text = FloatToStr(0);

try
{
   drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};

// Face : Change Line Icons (NG/HH/KZ)
Image13->Hide();
Image12->Show();
Image9->Hide();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::rbKZClick(TObject *Sender)
{
Panel1->Enabled = false; // Panel disabling
eR->Enabled = false;
cbR->Enabled = false;
CheckBox1->Enabled = false;
eL->Enabled = false;
cbL->Enabled = false;
CheckBox2->Enabled = false;
eC->Enabled = false;
cbC->Enabled = false;
CheckBox3->Enabled = false;
eR->Text = FloatToStr(0);
eL->Text = FloatToStr(0);
eC->Text = FloatToStr(0);
try
{
   drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


// Face : Change Line Icons (NG/HH/KZ)
Image13->Hide();
Image12->Hide();
Image9->Show();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::rbNGClick(TObject *Sender)
{
Panel1->Enabled = true; // Panel Enabling
eR->Enabled = true;
cbR->Enabled = true;
CheckBox1->Enabled = true;
CheckBox1->Checked = true;
eL->Enabled = true;
cbL->Enabled = true;
CheckBox2->Enabled = true;
CheckBox2->Checked = true;
eC->Enabled = true;
cbC->Enabled = true;
CheckBox3->Enabled = true;
CheckBox3->Checked = true;
eR->Text = FloatToStr(1);
eL->Text = FloatToStr(1);
eC->Text = FloatToStr(1);
try
{
   drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


// Face : Change Line Icons (NG/HH/KZ)
Image13->Show();
Image12->Hide();
Image9->Hide();

}
//---------------------------------------------------------------------------


void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
// Face : Edit&ComboBox Disabling
if (CheckBox1->Checked == True)
  {
  eR->Enabled = true;
  cbR->Enabled = true;
eR->Text = FloatToStr(1);

try
{
   drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


  }
else
  {
  eR->Enabled = false;
  cbR->Enabled = false;
  eR->Text = FloatToStr(0);
try
{
   drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox2Click(TObject *Sender)
{
// Face : Edit&ComboBox Disabling
if (CheckBox2->Checked == True)
  {
  eL->Enabled = true;
  cbL->Enabled = true;
  eL->Text = FloatToStr(1);

try
{
   drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};



  }
else
  {
  eL->Enabled = false;
  cbL->Enabled = false;
  eL->Text = FloatToStr(0);

try
{
   drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


  }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox3Click(TObject *Sender)
{
// Face : Edit&ComboBox Disabling
if (CheckBox3->Checked == True)
  {
  eC->Enabled = true;
  cbC->Enabled = true;
  eC->Text = FloatToStr(1);

try
{
   drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


  }
else
{
  eC->Enabled = false;
  cbC->Enabled = false;
  eC->Text = FloatToStr(0);
try
{
   drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image4Click(TObject *Sender)
{
// face
    rbNG->Checked = true;
    Panel1->Enabled = true; // Panel Enabling
    eR->Enabled = true;
    cbR->Enabled = true;
    CheckBox1->Enabled = true;
    CheckBox1->Checked = true;
    eL->Enabled = true;
    cbL->Enabled = true;
    CheckBox2->Enabled = true;
    CheckBox2->Checked = true;
    eC->Enabled = true;
    cbC->Enabled = true;
    CheckBox3->Enabled = true;
    CheckBox3->Checked = true;
    eR->Text = FloatToStr(1);
    eL->Text = FloatToStr(1);
    eC->Text = FloatToStr(1);

try
{
   drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image5Click(TObject *Sender)
{
// face
   rbHH->Checked = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image6Click(TObject *Sender)
{
// face
   rbKZ->Checked = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1Click(TObject *Sender)
{  //
// face
   CheckBox1->Checked = !(CheckBox1->Checked);
try
{
   drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image2Click(TObject *Sender)
{
// face
   CheckBox2->Checked = !(CheckBox2->Checked);
try
{
   drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image3Click(TObject *Sender)
{
// face
   CheckBox3->Checked = !(CheckBox3->Checked);
try
{
   drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


}
//---------------------------------------------------------------------------


void __fastcall TForm1::rbEClick(TObject *Sender)
{
// Face : Amplituda : Volt/Ampere
// A -> V
  cbA1->Clear();
  cbA1->Items->Add("кВ");
  cbA1->Items->Add("В");
  cbA1->ItemIndex = 1;
  cbA3->Clear();
  cbA3->Items->Add("кВ");
  cbA3->Items->Add("В");
  cbA3->ItemIndex = 1;
try
{
   drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


// Face : Change Line Icons (V/A)
// A -> V
  Image11->Hide();
  Image10->Show();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::rbIClick(TObject *Sender)
{
// Face : Amplituda : Volt/Ampere
// V -> A
  cbA1->Clear();
  cbA1->Items->Add("А");
  cbA1->Items->Add("мА");
  cbA1->Items->Add("мкА");
  cbA1->ItemIndex = 0;
  cbA3->Clear();
  cbA3->Items->Add("А");
  cbA3->Items->Add("мА");
  cbA3->Items->Add("мкА");
  cbA3->ItemIndex = 0;
try
{
   drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


// Face : Change Line Icons (V/A)
// V -> A
  Image10->Hide();
  Image11->Show();

}
//---------------------------------------------------------------------------


void TForm1::countSecondary(void) // recounts primary ,sets secondary vals : f(ComboBox->ItemIndex)
{  // вычисление вторичных параметров
   // variables setting
   switch (cbR0->ItemIndex)
   {
      case 0 : r0 = 1000000*StrToFloat(eR0->Text);
               break;
      case 1 : r0 = 1000*StrToFloat(eR0->Text);
               break;
      case 2 : r0 = StrToFloat(eR0->Text);
               break;
   }
   switch (cbL0->ItemIndex)
   {
      case 0 : l0 = StrToFloat(eL0->Text);
               break;
      case 1 : l0 = StrToFloat(eL0->Text)/1000;
               break;
   }
   switch (cbG0->ItemIndex)
   {
      case 0 : g0 = 1000*StrToFloat(eG0->Text);
               break;
      case 1 : g0 = StrToFloat(eG0->Text);
               break;
      case 2 : g0 = StrToFloat(eG0->Text)/1000;
               break;
   }
   switch (cbC0->ItemIndex)
   {
      case 0 : c0 = StrToFloat(eC0->Text)/1000000;
               break;
      case 1 : c0 = StrToFloat(eC0->Text)/1000000000;
               break;
   }

   switch (cbW->ItemIndex)
   {
      case 0 : w1 = 1000000*StrToFloat(eW->Text)*(M_PI*2);
               break;
      case 1 : w1 = 1000*StrToFloat(eW->Text)*(M_PI*2);
               break;
      case 2 : w1 = StrToFloat(eW->Text)*(M_PI*2);
               break;
   }
   w3 = 3*w1;
   z01 = COMPLEX(r0,w1*l0);
   y01 = COMPLEX(g0,w1*c0);
   z03 = COMPLEX(r0,w3*l0);
   y03 = COMPLEX(g0,w3*c0);

   // secondary parameters setting
   gam1 = countGamma(z01,y01);  // gamma(1/3)
   gam3 = countGamma(z03,y03);
   if((gam1 == COMPLEX(0,0))||(gam1 == COMPLEX(0,0)))
   {
       Application->MessageBox("Gamma = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
       writeToEdits();
       drawChart();
   };
   alf1 = real(gam1);
   bet1 = imag(gam1);
   alf3 = real(gam3);
   bet3 = imag(gam3);
   eAlf1->Text = FloatToStrF(alf1,ffFixed,7,2);
   eAlf3->Text = FloatToStrF(alf3,ffFixed,7,2);
   eBet1->Text = FloatToStrF(bet1,ffFixed,7,2);
   eBet3->Text = FloatToStrF(bet3,ffFixed,7,2);
   zw1 = countZ(z01,y01);       // zw(1/3)
   zw3 = countZ(z03,y03);
   eZre1->Text = FloatToStrF(real(zw1),ffFixed,7,3);
   eZim1->Text = FloatToStrF(imag(zw1),ffFixed,7,3);
   eZre3->Text = FloatToStrF(real(zw3),ffFixed,7,3);
   eZim3->Text = FloatToStrF(imag(zw3),ffFixed,7,3);
   vf1 = countVf(w1,bet1);      // vf(1/3)
   vf3 = countVf(w3,bet3);
   eVf1->Text = FloatToStrF(vf1,ffFixed,7,4);
   eVf3->Text = FloatToStrF(vf3,ffFixed,7,4);
   lw1 = countLw(bet1);           // lw(1/3)
   lw3 = countLw(bet3);
   eLw1->Text = FloatToStrF(lw1,ffFixed,7,5);
   eLw3->Text = FloatToStrF(lw3,ffFixed,7,5);
} /* Конец вычисления вторичных параметров */
void __fastcall TForm1::eR0Enter(TObject *Sender)
{
try
{
  drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


}
//---------------------------------------------------------------------------

void __fastcall TForm1::eR0Exit(TObject *Sender)
{
try
{
  drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


}
//---------------------------------------------------------------------------

void __fastcall TForm1::eL0Exit(TObject *Sender)
{
try
{
  drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


}
//---------------------------------------------------------------------------

void __fastcall TForm1::eL0Enter(TObject *Sender)
{
try
{
  drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


}
//---------------------------------------------------------------------------

void __fastcall TForm1::eG0Enter(TObject *Sender)
{
try
{
  drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


}
//---------------------------------------------------------------------------

void __fastcall TForm1::eG0Exit(TObject *Sender)
{
try
{
  drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


}
//---------------------------------------------------------------------------

void __fastcall TForm1::eC0Exit(TObject *Sender)
{
try
{
  drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


}
//---------------------------------------------------------------------------

void __fastcall TForm1::eC0Enter(TObject *Sender)
{
try
{
  drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


}
//---------------------------------------------------------------------------

void __fastcall TForm1::eWEnter(TObject *Sender)
{
try
{
  drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


}
//---------------------------------------------------------------------------

void __fastcall TForm1::eWExit(TObject *Sender)
{
try
{
  drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


}
//---------------------------------------------------------------------------

void __fastcall TForm1::cbWChange(TObject *Sender)
{
try
{
  drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};

}
//---------------------------------------------------------------------------

void __fastcall TForm1::cbR0Change(TObject *Sender)
{
try
{
  drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


}
//---------------------------------------------------------------------------

void __fastcall TForm1::cbL0Change(TObject *Sender)
{
try
{
  drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


}
//---------------------------------------------------------------------------

void __fastcall TForm1::cbG0Change(TObject *Sender)
{
try
{
  drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


}
//---------------------------------------------------------------------------

void __fastcall TForm1::cbC0Change(TObject *Sender)
{
try
{
  drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


}
//---------------------------------------------------------------------------


void __fastcall TForm1::eR0KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Key == VK_RETURN)
try
{
   drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


}
//---------------------------------------------------------------------------

void __fastcall TForm1::eL0KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if (Key == VK_RETURN)
   try
   {
     drawChart();
   }
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};



}
//---------------------------------------------------------------------------

void __fastcall TForm1::eG0KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Key == VK_RETURN)
try
{
   drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};



}
//---------------------------------------------------------------------------

void __fastcall TForm1::eC0KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Key == VK_RETURN)
try
{
   drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};



}
//---------------------------------------------------------------------------

void __fastcall TForm1::eWKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Key == VK_RETURN)
try
{
   drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};



}
//---------------------------------------------------------------------------

void TForm1::countA(void)  // counts A1(aa1)&A2(aa2) : f(RadioButtons) (1/3)
{
 tempk1 = 0;
 tempk3 = 0;
 // Line Length input
 if(StrToFloat(eLL->Text) > 0)
 {
    ll = StrToFloat(eLL->Text);
    x = (Chart3->Left + Chart3->Width/2 -Shape1->Left)*ll/Shape1->Width;
    Edit1->Text = FloatToStrF(x,ffFixed,10,2);
 }
 else
 {
    Application->MessageBox("Длина линии - положительное число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
    writeToEdits();
 };

 // Amplitude/sqrt(2) input (rbE/rbI)
 if (rbE->Checked == true)
 {
    switch (cbA1->ItemIndex)
    {
       case 0 : e1 = 1000*StrToFloat(eA1->Text);
                break;
       case 1 : e1 = StrToFloat(eA1->Text);
    }
    switch (cbA3->ItemIndex)
    {
       case 0 : e3 = 1000*StrToFloat(eA3->Text);
                break;
       case 1 : e3 = StrToFloat(eA3->Text);
    }
 }
 else
 {
    switch (cbA1->ItemIndex)
    {
       case 0 : i1 = StrToFloat(eA1->Text);
                break;
       case 1 : i1 = StrToFloat(eA1->Text)/1000;
                break;
       case 2 : i1 = StrToFloat(eA1->Text)/1000000;
    }
    switch (cbA3->ItemIndex)
    {
       case 0 : i3 = StrToFloat(eA3->Text);
                break;
       case 1 : i3 = StrToFloat(eA3->Text)/1000;
                break;
       case 2 : i3 = StrToFloat(eA3->Text)/1000000;
    }

 }; // End of Amplitude/sqrt(2) input
////////////////////////////////////////// 3 CONDITTIONS (NG/HH/KZ)
if (rbNG->Checked == true)
{
    // RLC input
//    if (eR->Enabled == true)
//    {
      switch (cbR->ItemIndex)
      {
         case 0 : r = 1000000*StrToFloat(eR->Text);
                  break;
         case 1 : r = 1000*StrToFloat(eR->Text);
                  break;
         case 2 : r = StrToFloat(eR->Text);
                  break;
      };
//    };
//    if (eL->Enabled == true)
//    {
      switch (cbL->ItemIndex)
      {
         case 0 : l = StrToFloat(eL->Text);
                  break;
         case 1 : l = StrToFloat(eL->Text)/1000;
                  break;
      };
//    };
//    if (eC->Enabled == true)
//    {
      switch (cbC->ItemIndex)
      {
         case 0 : c = StrToFloat(eC->Text)/1000000;
                  break;
         case 1 : c = StrToFloat(eC->Text)/1000000000;
                  break;
      };
//    }; // End of RLC input

    // counting z nagruzki (1/3)
    if(w1 == 0)
    {
        zng1 = COMPLEX(r,0);
        zng3 = COMPLEX(r,0);
    }
    else
    {
        if(c == 0)
        {
            zng1 = COMPLEX(r,(w1*l));
            zng3 = COMPLEX(r,(w3*l));
        }
        else
        {
            zng1 = COMPLEX(r,(w1*l-(1/(w1*c)))); // here was a bug (skobki)
            zng3 = COMPLEX(r,(w3*l-(1/(w3*c))));
        };
    };

    // count aa1,aa2 : f(gam,ll)  (1/3)
    if((zng1 != zw1)&&(zng3 != zw3))
    {
        /*2.23  10^-308 < |X| < 1.79  10^308*/
        tempgamll1 = real(gam1*ll);
        tempgamll3 = real(gam3*ll);
        if((tempgamll1 < 288)&&(tempgamll3 < 288))
        {
           tempk1 = exp(COMPLEX(2,0)*gam1*ll)*(zw1 + zng1)/(zw1 - zng1);
           tempk3 = exp(COMPLEX(2,0)*gam3*ll)*(zw3 + zng3)/(zw3 - zng3);
        }
        else
        {
           Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера ( произведение gamma*ll, где ll - длина линии, очень велико ). Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
           writeToEdits();
           drawChart();
        };
    }
    else  // soglasowannaya nagruzka
    {
        if(rbE->Checked)
        {
            aa11 = e1;
            aa13 = e3;
        }
        else
        {
            aa11 = i1*zw1;
            aa13 = i3*zw3;
        };
        aa21 = 0;
        aa23 = 0;
        return;
    };
    if (rbE->Checked == true)         // E
      {
      aa11 = tempk1*e1/(tempk1 - COMPLEX(1,0));
      aa13 = tempk3*e3/(tempk3 - COMPLEX(1,0));
      aa21 = e1/(COMPLEX(1,0) - tempk1);
      aa23 = e3/(COMPLEX(1,0) - tempk3);
      }
    else                              // I
      {
      aa11 = tempk1*i1*zw1/(tempk1 + COMPLEX(1,0));
      aa13 = tempk3*i3*zw3/(tempk3 + COMPLEX(1,0));
      aa21 = -(i1*zw1/(COMPLEX(1,0) + tempk1));
      aa23 = -(i3*zw3/(COMPLEX(1,0) + tempk3));
      };
}; // End of first if : (rbNG->Checked == true)

if (rbHH->Checked == true)
{
    tempk1 = -(exp(COMPLEX(2,0)*gam1*ll));
    tempk3 = -(exp(COMPLEX(2,0)*gam3*ll));
    if (rbE->Checked == true)         // E
      {
      aa11 = tempk1*e1/(tempk1 - COMPLEX(1,0));
      aa13 = tempk3*e3/(tempk3 - COMPLEX(1,0));
      aa21 = e1/(COMPLEX(1,0) - tempk1);
      aa23 = e3/(COMPLEX(1,0) - tempk3);
      }
    else                              // I
      {
      aa11 = tempk1*i1*zw1/(tempk1 + COMPLEX(1,0));
      aa13 = tempk3*i3*zw3/(tempk3 + COMPLEX(1,0));
      aa21 = -(i1*zw1/(COMPLEX(1,0) + tempk1));
      aa23 = -(i3*zw3/(COMPLEX(1,0) + tempk3));
      };
}; // End of second if : HH
if (rbKZ->Checked == true)
{
    tempk1 = exp(COMPLEX(2,0)*gam1*ll);
    tempk3 = exp(COMPLEX(2,0)*gam3*ll);
    if (rbE->Checked == true)         // E
      {
      aa11 = tempk1*e1/(tempk1 - COMPLEX(1,0)); // tut dohnet (tempk ~~ 1)
      aa13 = tempk3*e3/(tempk3 - COMPLEX(1,0));
      aa21 = e1/(COMPLEX(1,0) - tempk1);
      aa23 = e3/(COMPLEX(1,0) - tempk3);
      }
    else                              // I
      {
      aa11 = tempk1*i1*zw1/(tempk1 + COMPLEX(1,0));
      aa13 = tempk3*i3*zw3/(tempk3 + COMPLEX(1,0));
      aa21 = -(i1*zw1/(COMPLEX(1,0) + tempk1));
      aa23 = -(i3*zw3/(COMPLEX(1,0) + tempk3));
      };
}; // End of third if : KZ
} // End of countA
//---------------------------------------------------------------------------

void TForm1::drawChart(void) // рисует графики действующих значений и фаз от расстояния x
{
    // face : "" to "0"
    if(eA1->Text == "")eA1->Text = 0;
    if(eA3->Text == "")eA3->Text = 0;
    if(eW->Text == "")eW->Text = 0;
    if(eR->Text == "")eR->Text = 0;
    if(eL->Text == "")eL->Text = 0;
    if(eC->Text == "")eC->Text = 0;
    if(eR0->Text == "")eR0->Text = 0;
    if(eL0->Text == "")eL0->Text = 0;
    if(eG0->Text == "")eG0->Text = 0;
    if(eC0->Text == "")eC0->Text = 0;
    if(eLL->Text == "")eLL->Text = 0;
    if(Edit1->Text == "")Edit1->Text = 0;
    // drawChart
    countSecondary();
    countA();
    Series1->Clear();
    Series2->Clear();
    Series3->Clear();
    Series4->Clear();
    Series7->Clear();
    Series8->Clear();
    Series9->Clear();
    Series10->Clear();
    Series11->Clear();
    Series12->Clear();
    Series13->Clear();
    Series14->Clear();
    Series15->Clear();
    Series16->Clear();

    // making main arrays
    int i = 0;
    double iArr[500];
    double uArr[500];
    double faseiArr[500];
    double faseuArr[500];
    double imax;
    double umax;
    COMPLEX cu1, ci1, cu3, ci3;
    double mcu1 = 0, mci1 = 0, mcu3 = 0, mci3 = 0;
    dx = ll / 500;

    for(x = 0, i = 0, mcu1 = mcu3 = mci1 = mci3 = umax = imax = 0; i < 500; x += dx, i++)
    {
        cu1 = aa11*exp((-gam1)*x)+aa21*exp(gam1*x);
        ci1 = (aa11*exp((-gam1)*x)-aa21*exp(gam1*x))/zw1;
        cu3 = aa13*exp((-gam3)*x)+aa23*exp(gam3*x);
        ci3 = (aa13*exp((-gam3)*x)-aa23*exp(gam3*x))/zw3;

        uArr[i] = sqrt(abs(cu1)*abs(cu1) + abs(cu3)*abs(cu3));
        iArr[i] = sqrt(abs(ci1)*abs(ci1) + abs(ci3)*abs(ci3));
        faseuArr[i] = GetArg(cu1);
        faseiArr[i] = GetArg(ci1);

        // finding maximums
        if(uArr[i] > umax)umax = uArr[i];
        if(iArr[i] > imax)imax = iArr[i];
        if(abs(cu1) > mcu1)mcu1 = abs(cu1);
        if(abs(cu3) > mcu3)mcu3 = abs(cu3);
        if(abs(ci1) > mci1)mci1 = abs(ci1);
        if(abs(ci3) > mci3)mci3 = abs(ci3);
    };

 if((umax != 0)&&(imax != 0))
 {
    for(x = 0, i = 0; i < 500; x += dx, i++)
    {
        Series2->AddXY( x, 100*uArr[i]/umax, "", clTeeColor );
        Series1->AddXY( x, 100*iArr[i]/imax, "", clTeeColor );
        Series4->AddXY( x, faseuArr[i], "", clTeeColor );
        Series3->AddXY( x, faseiArr[i], "", clTeeColor );
    };
    //BOOTAFORIA wseh chartow
    if(cbxU->Checked)
    {
        Series9->AddXY( 0, (M_SQRT2)*(mcu1 + mcu3), "", clTeeColor );
        Series10->AddXY( 0, -(M_SQRT2)*(mcu1 + mcu3), "", clTeeColor );
        Series9->Active = true;
        Series10->Active = true;
    }
    else
    {
        Series9->Clear();
        Series10->Clear();
        Series9->Active = false;
        Series10->Active = false;
    };
    Series11->AddXY(ll, 102, "", clTeeColor );
    Series12->AddXY(ll, 182, "", clTeeColor );
    if(cbxI->Checked)
    {
        Series13->AddXY( 0, (M_SQRT2)*(mci1 + mci3), "", clTeeColor );
        Series14->AddXY( 0, -(M_SQRT2)*(mci1 + mci3), "", clTeeColor );
        Series13->Active = true;
        Series14->Active = true;
    }
    else
    {
        Series13->Clear();
        Series14->Clear();
        Series13->Active = false;
        Series14->Active = false;
    };
    Series15->AddXY(0, 102, "", clTeeColor );
    Series16->AddXY(0, 182, "", clTeeColor );

    drawOsc();
 };
//BOOTAFORIA Chartow 1 & 2  (const)
Series11->AddXY(ll, 102, "", clTeeColor );
Series12->AddXY(ll, 182, "", clTeeColor );
Series15->AddXY(0, 102, "", clTeeColor );
Series16->AddXY(0, 182, "", clTeeColor );
Series7->Clear();
Series7->AddXY(x, 102, "", clTeeColor );
Series7->AddXY(x, -2, "", clTeeColor );
Series8->Clear();
Series8->AddXY(x, 182, "", clTeeColor );
Series8->AddXY(x, -182, "", clTeeColor );
//  9180
readFromEdits();
}; /* End of TForm1::drawChart */
//---------------------------------------------------------------------------

void __fastcall TForm1::cbRChange(TObject *Sender)
{
try
{
  drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


}
//---------------------------------------------------------------------------

void __fastcall TForm1::cbLChange(TObject *Sender)
{
try
{
  drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};

  
}
//---------------------------------------------------------------------------

void __fastcall TForm1::cbCChange(TObject *Sender)
{
try
{
  drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


}
//---------------------------------------------------------------------------

void __fastcall TForm1::eREnter(TObject *Sender)
{
try
{
drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


}
//---------------------------------------------------------------------------

void __fastcall TForm1::eRExit(TObject *Sender)
{
try
{
drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


}
//---------------------------------------------------------------------------

void __fastcall TForm1::eLEnter(TObject *Sender)
{
try
{
drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


}
//---------------------------------------------------------------------------

void __fastcall TForm1::eLExit(TObject *Sender)
{
try
{
drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


}
//---------------------------------------------------------------------------

void __fastcall TForm1::eCExit(TObject *Sender)
{
try
{
drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


}
//---------------------------------------------------------------------------

void __fastcall TForm1::eCEnter(TObject *Sender)
{
try
{
drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


}
//---------------------------------------------------------------------------

void __fastcall TForm1::eCKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if (Key == VK_RETURN)
   try
   {
      drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


}
//---------------------------------------------------------------------------

void __fastcall TForm1::eLKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if (Key == VK_RETURN)
   try
   {
      drawChart();
   }
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};



}
//---------------------------------------------------------------------------

void __fastcall TForm1::eRKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if (Key == VK_RETURN)
   try
   {
      drawChart();
   }
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};



}
//---------------------------------------------------------------------------

void __fastcall TForm1::eLLExit(TObject *Sender)
{
try
{
drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


}
//---------------------------------------------------------------------------

void __fastcall TForm1::eLLEnter(TObject *Sender)
{
try
{
drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


}
//---------------------------------------------------------------------------

void __fastcall TForm1::eLLKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if (Key == VK_RETURN)
   try
   {
      drawChart();
   }
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};



}
//---------------------------------------------------------------------------

void __fastcall TForm1::rbNGEnter(TObject *Sender)
{
Panel1->Enabled = true; // Panel Enabling
eR->Enabled = true;
cbR->Enabled = true;
CheckBox1->Enabled = true;
CheckBox1->Checked = true;
eL->Enabled = true;
cbL->Enabled = true;
CheckBox2->Enabled = true;
CheckBox2->Checked = true;
eC->Enabled = true;
cbC->Enabled = true;
CheckBox3->Enabled = true;
CheckBox3->Checked = true;
try
{
drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};



}
//---------------------------------------------------------------------------

void __fastcall TForm1::eA1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if (Key == VK_RETURN)
   try
   {
      drawChart();
   }
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};



}
//---------------------------------------------------------------------------

void __fastcall TForm1::eA3KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if (Key == VK_RETURN)
   try
   {
      drawChart();
   }
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};



}
//---------------------------------------------------------------------------

void __fastcall TForm1::eA3Exit(TObject *Sender)
{
try
{
      drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};

      

}
//---------------------------------------------------------------------------

void __fastcall TForm1::eA3Enter(TObject *Sender)
{
try
{
      drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};

      
}
//---------------------------------------------------------------------------

void __fastcall TForm1::eA1Enter(TObject *Sender)
{
try
{
      drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


}
//---------------------------------------------------------------------------

void __fastcall TForm1::eA1Exit(TObject *Sender)
{
try
{
      drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};

      
}
//---------------------------------------------------------------------------

void __fastcall TForm1::cbA1Change(TObject *Sender)
{
try
{
      drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


}
//---------------------------------------------------------------------------

void __fastcall TForm1::cbA3Change(TObject *Sender)
{
try
{
      drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


}
//---------------------------------------------------------------------------

double TForm1::GetArg(COMPLEX c)
{
    double a;
    a = arg(c)*180/M_PI;
    if( fabs(a) > 179.99999 ) a = fabs(a);
    return(a);
}; /* End of GetArg */
//---------------------------------------------------------------------------

void __fastcall TForm1::Chart3MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{// Chart Sliding (1 of 3)
    oldmousex = X;
    oldmouseflag = true;

    Series7->Clear();
    Series7->AddXY(x, 102, "", clTeeColor );
    Series7->AddXY(x, -2, "", clTeeColor );
    Series8->Clear();
    Series8->AddXY(x, 182, "", clTeeColor );
    Series8->AddXY(x, -182, "", clTeeColor );

    drawOsc();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Chart3MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{// Chart Sliding (2 of 3)
    int xnew;
if(oldmouseflag)
{
    xnew = Chart3->Left + Chart3->Width/2 + X - oldmousex;
    if( xnew > Shape1->Left+Shape1->Width ) xnew = Shape1->Left+Shape1->Width;
    if( xnew < Shape1->Left ) xnew = Shape1->Left;

    x = (xnew - Shape1->Left)*ll/Shape1->Width;
    Chart3->Left = xnew - Chart3->Width/2;
    Chart3->Repaint();
    PC->Left = Chart3->Left + Chart3->Width/2-1;
    Shape1->Repaint();
    Shape2->Repaint();

    Series7->Clear();
    Series7->AddXY(x, 102, "", clTeeColor );
    Series7->AddXY(x, -2, "", clTeeColor );
    Series8->Clear();
    Series8->AddXY(x, 182, "", clTeeColor );
    Series8->AddXY(x, -182, "", clTeeColor );

    Edit1->Text = FloatToStrF(x,ffFixed,10,2);

    drawOsc();
};

}  // End Of OnMouseMove (Chart Sliding)
//---------------------------------------------------------------------------

void __fastcall TForm1::Chart3MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{// Chart Sliding (3 of 3)

oldmouseflag = false;
drawOsc();

        if(Chart3->Left + Chart3->Width/2 < Shape1->Left)               // Bounds Check
        {
            Chart3->Left = Shape1->Left - Chart3->Width/2;
            Chart3->Repaint();
            Edit1->Left = Chart3->Left + Chart3->Width/2 + 160;
            PC->Left = Chart3->Left + Chart3->Width/2-1;
        };
        if(Chart3->Left + Chart3->Width/2 > Shape1->Left+Shape1->Width)
        {
            Chart3->Left = Shape1->Left+Shape1->Width - Chart3->Width/2;
            Chart3->Repaint();
            PC->Left = Chart3->Left + Chart3->Width/2 - 1;

        };
}
//---------------------------------------------------------------------------


void TForm1::drawOsc(void)
{
    Series5->Clear();
    Series6->Clear();
    double faseu3;
    double fasei3;
    double faseu1;
    double fasei1;
    double t = 0;
    double T1 = 0;
    double dt = 0;
    COMPLEX cu1, ci1, cu3, ci3;
    T1 = 2*M_PI/w1;
    dt = T1 / 100;

    for(t = 0; t < T1; t += dt) // oscl-graph
    {
        x = (Chart3->Left + (Chart3->Width/2) - Shape1->Left)*ll/Shape1->Width;
        cu1 = aa11*exp((-gam1)*x)+aa21*exp(gam1*x);
        ci1 = (aa11*exp((-gam1)*x)-aa21*exp(gam1*x))/zw1;
        cu3 = aa13*exp((-gam3)*x)+aa23*exp(gam3*x);
        ci3 = (aa13*exp((-gam3)*x)-aa23*exp(gam3*x))/zw3;

        faseu1 = GetArg(cu1);
        fasei1 = GetArg(ci1);
        faseu3 = GetArg(cu3);
        fasei3 = GetArg(ci3);
        Series5->AddXY( t, ((M_SQRT2)*abs(cu1)*sin(w1*t + faseu1) + (M_SQRT2)*abs(cu3)*sin(w3*t + faseu3)), "", clTeeColor );
        Series6->AddXY( t, ((M_SQRT2)*abs(ci1)*sin(w1*t + fasei1) + (M_SQRT2)*abs(ci3)*sin(w3*t + fasei3)), "", clTeeColor );

    };
    readFromEdits();
} // End Of drawOsc
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
try
{
   if (Key == VK_RETURN)
      if((StrToFloat(Edit1->Text)>=0)&&(StrToFloat(Edit1->Text)<=ll))
      {
          Chart3->Left = (StrToFloat(Edit1->Text)*Shape1->Width/ll) - Chart3->Width/2 + Shape1->Left;
          PC->Left = Chart3->Left + Chart3->Width/2 - 1;
      };
          drawOsc();

          Series7->Clear();
          Series7->AddXY(x, 102, "", clTeeColor );
          Series7->AddXY(x, -2, "", clTeeColor );
          Series8->Clear();
          Series8->AddXY(x, 182, "", clTeeColor );
          Series8->AddXY(x, -182, "", clTeeColor );
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


};
//---------------------------------------------------------------------------

void __fastcall TForm1::New1Click(TObject *Sender) // NEW -> OnClick
{
Form1->Free();
Application->CreateForm(__classid(TForm1), &Form1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1Exit(TObject *Sender)
{
try
{
      if((StrToFloat(Edit1->Text)>=0)&&(StrToFloat(Edit1->Text)<=ll))
      {
          Chart3->Left = (StrToFloat(Edit1->Text)*Shape1->Width/ll) - Chart3->Width/2 + Shape1->Left;
          PC->Left = Chart3->Left + Chart3->Width/2 - 1;

      };
          drawOsc();

          Series7->Clear();
          Series7->AddXY(x, 102, "", clTeeColor );
          Series7->AddXY(x, -2, "", clTeeColor );
          Series8->Clear();
          Series8->AddXY(x, 182, "", clTeeColor );
          Series8->AddXY(x, -182, "", clTeeColor );
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


};

//---------------------------------------------------------------------------

void __fastcall TForm1::eAlf1Enter(TObject *Sender)
{
//////////// loose focus
}
//---------------------------------------------------------------------------

void __fastcall TForm1::call3dClick(TObject *Sender) // makes 3d chart
{
countSecondary();
countA();
// creating series (40x40) for 3d chart
int k;
TChartSeries *s;
TChartSeries *si;
for( k = 0; k < 40; k++ )
{
  s = new TAreaSeries(Chart1);
  Form2->Ss[k] = (TAreaSeries*)s;
  Form2->Ss[k]->ParentChart = Form2->Chart1;
  Form2->Chart1->AddSeries(Form2->Ss[k]);
  si = new TAreaSeries(Chart2);
  Form2->Ssi[k] = (TAreaSeries*)si;
  Form2->Ssi[k]->ParentChart = Form2->Chart2;
  Form2->Chart2->AddSeries(Form2->Ssi[k]);
};

// making main arrays & variables
    int i = 0;
    double faseu3 = 0;     // fases : U, 1 & 3
    double faseu1 = 0;
    double fasei1 = 0;
    double fasei3 = 0;
    double t = 0;          // time vars ( Current t, Period, dt )
    double T1 = 0;
    double dt = 0;
    T1 = 2*M_PI/w1;    // assign time vars
    dt = T1 / 40;
    COMPLEX cu1, ci1, cu3, ci3;   // temporary vars
    dx = ll / 40;
    int l;

for(l = 39, t = 0; t < T1, l >= 0; t += dt, l--) // t
{
    Form2->Ss[l]->Clear();
    for(x = 0, i = 0; i < 40, x < ll; x += dx, i++) // x
    {
        cu1 = aa11*exp((-gam1)*x)+aa21*exp(gam1*x);
        cu3 = aa13*exp((-gam3)*x)+aa23*exp(gam3*x);
        ci1 = (aa11*exp((-gam1)*x)-aa21*exp(gam1*x))/zw1;
        ci3 = (aa13*exp((-gam3)*x)-aa23*exp(gam3*x))/zw3;

        faseu1 = GetArg(cu1)*M_PI/180;  // assigning fases
        faseu3 = GetArg(cu3)*M_PI/180;
        fasei1 = GetArg(ci1)*M_PI/180;
        fasei3 = GetArg(ci3)*M_PI/180;

        Form2->Ss[l]->AddXY(x, /*y*/((M_SQRT2)*(abs(cu1)*sin(w1*t + faseu1) + abs(cu3)*sin(w3*t + faseu3))), "", clBlue );
        Form2->Ssi[l]->AddXY(x, /*y*/((M_SQRT2)*abs(ci1)*sin(w1*t + fasei1) + (M_SQRT2)*abs(ci3)*sin(w3*t + fasei3)), "", clRed );
    };
};

// face
Form1->Hide();
Form2->Show();
Form2->Chart2->Hide();
Form2->Chart1->Show();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
try
{
drawChart();
}
catch(EConvertError&)
{
   Application->MessageBox("Вы неверно ввели число.","Ошибка ввода",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EZeroDivide&)
{
   Application->MessageBox("Beta = 0. В этом случае фазовая скорость бесконечна ( как и длина волны ) , следовательно такая 'длинная линия' должна рассматриваться как элемент с сосредоточенными параметрами при любой конечной длине.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EInvalidOp&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
}
catch(EOverflow&)
{
   Application->MessageBox("Расчёт по данным параметрам невозможен из-за ограниченности возможностей компьютера. Попробуйте сначала изменить длину линии.","Параметры заданы некорректно ",MB_OK | MB_ICONWARNING);
   writeToEdits();
};


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Load1Click(TObject *Sender)
{
//OpenDialog1->Execute();

//loading params list
cbtemp->Items->Clear();
if(OpenDialog1->Execute())
cbtemp->Items->LoadFromFile(OpenDialog1->FileName);
writeToEdits();

// teleport oscillographa
x = StrToFloat(Edit1->Text);
Chart3->Left = x*Shape1->Width/ll - Chart3->Width/2 + Shape1->Left;
Chart3->Repaint();
PC->Left = Chart3->Left + Chart3->Width/2-1;
Shape1->Repaint();
Shape2->Repaint();

Series7->Clear();
Series7->AddXY(x, 102, "", clTeeColor );
Series7->AddXY(x, -2, "", clTeeColor );
Series8->Clear();
Series8->AddXY(x, 182, "", clTeeColor );
Series8->AddXY(x, -182, "", clTeeColor );

// смена заголовка формы
Form1->Caption = "Длинные линии - " + OpenDialog1->FileName;

drawChart();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SaveAs1Click(TObject *Sender)
{
readFromEdits();
//saving
SaveDialog1->Title = "Сохранить как...";
if (SaveDialog1->Execute())
{
  cbtemp->Items->SaveToFile(SaveDialog1->FileName);
  Save1->Enabled = true;
  // смена заголовка формы
  Form1->Caption = "Длинные линии - " + SaveDialog1->FileName;
};
//SaveToFile(SaveDialog)

}
//---------------------------------------------------------------------------


void TForm1::writeToEdits(void)
{
int i;
for(i = 0; i < cbtemp->Items->Count; i++)
{
   cbtemp->ItemIndex = i;
   switch (cbtemp->ItemIndex)
   {
   // Making edits
      case 0 : eR->Text = cbtemp->Text;
               break;
      case 1 : eL->Text = cbtemp->Text;
               break;
      case 2 : eC->Text = cbtemp->Text;
               break;
      case 3 : eA1->Text = cbtemp->Text;
               break;
      case 4 : eA3->Text = cbtemp->Text;
               break;
      case 5 : eW->Text = cbtemp->Text;
               break;
      case 6 : eR0->Text = cbtemp->Text;
               break;
      case 7 : eL0->Text = cbtemp->Text;
               break;
      case 8 : eG0->Text = cbtemp->Text;
               break;
      case 9 : eC0->Text = cbtemp->Text;
               break;
      case 10 : eLL->Text = cbtemp->Text;
               break;
      case 11 : Edit1->Text = cbtemp->Text;
               break;
   // Making ComboBoxes
      case 12 : cbR->ItemIndex = StrToInt(cbtemp->Text);
               break;
      case 13 : cbL->ItemIndex = StrToInt(cbtemp->Text);
               break;
      case 14 : cbC->ItemIndex = StrToInt(cbtemp->Text);
               break;
      case 15 : cbA1->ItemIndex = StrToInt(cbtemp->Text);
               break;
      case 16 : cbA3->ItemIndex = StrToInt(cbtemp->Text);
               break;
      case 17 : cbW->ItemIndex = StrToInt(cbtemp->Text);
               break;
      case 18 : cbR0->ItemIndex = StrToInt(cbtemp->Text);
               break;
      case 19 : cbL0->ItemIndex = StrToInt(cbtemp->Text);
               break;
      case 20 : cbG0->ItemIndex = StrToInt(cbtemp->Text);
               break;
      case 21 : cbC0->ItemIndex = StrToInt(cbtemp->Text);
               break;
   // Making RadioButtons & Images
      case 22 : if(cbtemp->Text == "rbE")
                {
                    rbE->Checked = true;
                    Image10->Show();
                    Image11->Hide();
                }
                else
                {
                    rbI->Checked = true;
                    Image11->Show();
                    Image10->Hide();
                };
               break;
      case 23 : if(cbtemp->Text != "rbNG")
                {
                    if(cbtemp->Text == "rbHH")
                    {
                        rbHH->Checked = true;
                        Image12->Show();
                        Image9->Hide();
                        Image13->Hide();
                    }
                    else
                    {
                        rbKZ->Checked = true;
                        Image9->Show();
                        Image12->Hide();
                        Image13->Hide();
                    };
                }
                else
                {
                    rbNG->Checked = true;
                    Image13->Show();
                    Image9->Hide();
                    Image12->Hide();
                };
               break;
   }// End Of Switch
}// End Of For
drawChart();
}// End Of writeToEdits
//---------------------------------------------------------------------------


void TForm1::readFromEdits(void)
{
//making params list :r,l,c,e1,e3,w1,r0,l0,g0,c0,ll,x & CB's &RB'S
cbtemp->Items->Clear();
cbtemp->Items->Add(eR->Text);
cbtemp->Items->Add(eL->Text);
cbtemp->Items->Add(eC->Text);
cbtemp->Items->Add(eA1->Text);
cbtemp->Items->Add(eA3->Text);
cbtemp->Items->Add(eW->Text);
cbtemp->Items->Add(eR0->Text);
cbtemp->Items->Add(eL0->Text);
cbtemp->Items->Add(eG0->Text);
cbtemp->Items->Add(eC0->Text);
cbtemp->Items->Add(eLL->Text);
cbtemp->Items->Add(Edit1->Text);
// CB's
cbtemp->Items->Add(FloatToStr(cbR->ItemIndex));
cbtemp->Items->Add(FloatToStr(cbL->ItemIndex));
cbtemp->Items->Add(FloatToStr(cbC->ItemIndex));
cbtemp->Items->Add(FloatToStr(cbA1->ItemIndex));
cbtemp->Items->Add(FloatToStr(cbA3->ItemIndex));
cbtemp->Items->Add(FloatToStr(cbW->ItemIndex));
cbtemp->Items->Add(FloatToStr(cbR0->ItemIndex));
cbtemp->Items->Add(FloatToStr(cbL0->ItemIndex));
cbtemp->Items->Add(FloatToStr(cbG0->ItemIndex));
cbtemp->Items->Add(FloatToStr(cbC0->ItemIndex));
// RB's
if(rbE->Checked == true) // V/A
    cbtemp->Items->Add("rbE");
else
    cbtemp->Items->Add("rbI");
if(!rbNG->Checked)                                //NG/HH/KZ
{
    if(rbHH->Checked)
        cbtemp->Items->Add("rbHH");
    else
        cbtemp->Items->Add("rbKZ");
}
else cbtemp->Items->Add("rbNG");

}

void __fastcall TForm1::cbxUClick(TObject *Sender)
{
if(cbxU->Checked)
{
    Series5->Active = true;
    drawChart();
}
else
{
    Series5->Active = false;
    //clear bootaforia
    Series9->Clear();
    Series10->Clear();
    cbxI->Checked = true;
};
}
//---------------------------------------------------------------------------

void __fastcall TForm1::cbxIClick(TObject *Sender)
{
if(cbxI->Checked)
{
    Series6->Active = true;
    drawChart();
}
else
{
    Series6->Active = false;
    //clear bootaforia
    Series13->Clear();
    Series14->Clear();
    cbxU->Checked = true;
};
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Save1Click(TObject *Sender)
{
  readFromEdits();
  cbtemp->Items->SaveToFile(SaveDialog1->FileName);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N4Click(TObject *Sender)
{
Form3->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N2Click(TObject *Sender)
{
  Application->HelpFile = "LLHLP.hlp";
  Application->HelpCommand(HELP_CONTENTS, 0);
}
//---------------------------------------------------------------------------

