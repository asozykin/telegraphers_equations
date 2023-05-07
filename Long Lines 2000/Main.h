//---------------------------------------------------------------------------
#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <Graphics.hpp>
#include <Chart.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Series.hpp>
#include "LLMath.h"
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *File1;
        TMenuItem *Exit1;
        TMenuItem *New1;
        TMenuItem *Save1;
        TMenuItem *SaveAs1;
        TMenuItem *Load1;
        TRadioGroup *RadioGroup1;
        TGroupBox *GroupBox1;
        TPanel *Panel1;
        TCheckBox *CheckBox1;
        TCheckBox *CheckBox2;
        TCheckBox *CheckBox3;
        TImage *Image1;
        TImage *Image2;
        TImage *Image3;
        TEdit *eR;
        TEdit *eL;
        TEdit *eC;
        TComboBox *cbR;
        TComboBox *cbL;
        TComboBox *cbC;
        TRadioButton *rbNG;
        TRadioButton *rbHH;
        TRadioButton *rbKZ;
        TImage *Image4;
        TImage *Image5;
        TImage *Image6;
        TPanel *Panel2;
        TLabel *Label1;
        TEdit *eA1;
        TLabel *Label2;
        TEdit *eW;
        TComboBox *cbA1;
        TComboBox *cbW;
        TGroupBox *GroupBox2;
        TGroupBox *GroupBox3;
        TGroupBox *GroupBox4;
        TEdit *eR0;
        TEdit *eL0;
        TEdit *eG0;
        TEdit *eC0;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TComboBox *cbR0;
        TComboBox *cbL0;
        TComboBox *cbG0;
        TComboBox *cbC0;
        TLabel *Label7;
        TLabel *Label9;
        TLabel *Label10;
        TImage *Image7;
        TEdit *eAlf1;
        TEdit *eVf1;
        TEdit *eLw1;
        TEdit *eZre1;
        TEdit *eZim1;
        TLabel *Label15;
        TLabel *Label16;
        TEdit *eBet1;
        TLabel *Label8;
        TLabel *Label13;
        TEdit *Edit16;
        TEdit *Edit17;
        TEdit *Edit18;
        TEdit *Edit19;
        TChart *Chart1;
        TGroupBox *GroupBox5;
        TLabel *Label11;
        TLabel *Label12;
        TLabel *Label14;
        TLabel *Label17;
        TLabel *Label18;
        TLabel *Label19;
        TLabel *Label20;
        TImage *Image8;
        TEdit *eAlf3;
        TEdit *eBet3;
        TEdit *eZre3;
        TEdit *eZim3;
        TEdit *eVf3;
        TEdit *eLw3;
        TEdit *Edit26;
        TEdit *Edit27;
        TEdit *Edit28;
        TEdit *Edit29;
        TRadioButton *rbE;
        TRadioButton *rbI;
        TEdit *eA3;
        TComboBox *cbA3;
        TLabel *Label21;
        TLabel *Label22;
        TShape *Shape1;
        TShape *Shape2;
        TChart *Chart2;
   TEdit *eLL;
   TEdit *Edit2;
    TChart *Chart3;
    TMenuItem *N1;
    TMenuItem *N2;
    TMenuItem *N3;
    TMenuItem *N4;
    TMenuItem *N5;
    TMenuItem *N6;
    TFastLineSeries *Series2;
    TFastLineSeries *Series1;
    TFastLineSeries *Series7;
    TEdit *Edit1;
    TLabel *Label23;
    TFastLineSeries *Series5;
    TFastLineSeries *Series6;
    TPanel *PC;
    TFastLineSeries *Series8;
    TFastLineSeries *Series3;
    TFastLineSeries *Series4;
    TImage *Image9;
    TImage *Image10;
    TImage *Image11;
    TImage *Image12;
    TImage *Image13;
    TEdit *Edit3;
    TPanel *Panel3;
    TPanel *Panel4;
    TFastLineSeries *Series9;
    TFastLineSeries *Series10;
    TBitBtn *call3d;
    TFastLineSeries *Series11;
    TFastLineSeries *Series12;
    TFastLineSeries *Series13;
    TFastLineSeries *Series14;
    TFastLineSeries *Series15;
    TFastLineSeries *Series16;
    TOpenDialog *OpenDialog1;
    TSaveDialog *SaveDialog1;
    TComboBox *cbtemp;
    TCheckBox *cbxU;
    TCheckBox *cbxI;
    TLabel *Label24;
    TLabel *Label25;
        void __fastcall Exit1Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall rbHHClick(TObject *Sender);
        void __fastcall rbKZClick(TObject *Sender);
        void __fastcall rbNGClick(TObject *Sender);
        void __fastcall CheckBox1Click(TObject *Sender);
        void __fastcall CheckBox2Click(TObject *Sender);
        void __fastcall CheckBox3Click(TObject *Sender);
        void __fastcall Image4Click(TObject *Sender);
        void __fastcall Image5Click(TObject *Sender);
        void __fastcall Image6Click(TObject *Sender);
        void __fastcall Image1Click(TObject *Sender);
        void __fastcall Image2Click(TObject *Sender);
        void __fastcall Image3Click(TObject *Sender);
        void __fastcall rbEClick(TObject *Sender);
        void __fastcall rbIClick(TObject *Sender);
   void __fastcall eR0Enter(TObject *Sender);
   void __fastcall eR0Exit(TObject *Sender);
   void __fastcall eL0Exit(TObject *Sender);
   void __fastcall eL0Enter(TObject *Sender);
   void __fastcall eG0Enter(TObject *Sender);
   void __fastcall eG0Exit(TObject *Sender);
   void __fastcall eC0Exit(TObject *Sender);
   void __fastcall eC0Enter(TObject *Sender);
   void __fastcall eWEnter(TObject *Sender);
   void __fastcall eWExit(TObject *Sender);
   void __fastcall cbWChange(TObject *Sender);
   void __fastcall cbR0Change(TObject *Sender);
   void __fastcall cbL0Change(TObject *Sender);
   void __fastcall cbG0Change(TObject *Sender);
   void __fastcall cbC0Change(TObject *Sender);
   void __fastcall eR0KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
   void __fastcall eL0KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
   void __fastcall eG0KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
   void __fastcall eC0KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
   void __fastcall eWKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall cbRChange(TObject *Sender);
    void __fastcall cbLChange(TObject *Sender);
    void __fastcall cbCChange(TObject *Sender);
    void __fastcall eREnter(TObject *Sender);
    void __fastcall eRExit(TObject *Sender);
    void __fastcall eLEnter(TObject *Sender);
    void __fastcall eLExit(TObject *Sender);
    void __fastcall eCExit(TObject *Sender);
    void __fastcall eCEnter(TObject *Sender);
    void __fastcall eCKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall eLKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall eRKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall eLLExit(TObject *Sender);
    void __fastcall eLLEnter(TObject *Sender);
    void __fastcall eLLKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall rbNGEnter(TObject *Sender);
    void __fastcall eA1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall eA3KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall eA3Exit(TObject *Sender);
    void __fastcall eA3Enter(TObject *Sender);
    void __fastcall eA1Enter(TObject *Sender);
    void __fastcall eA1Exit(TObject *Sender);
    void __fastcall cbA1Change(TObject *Sender);
    void __fastcall cbA3Change(TObject *Sender);
    void __fastcall Chart3MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall Chart3MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall Chart3MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall Edit1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall New1Click(TObject *Sender);
    void __fastcall Edit1Exit(TObject *Sender);
    void __fastcall eAlf1Enter(TObject *Sender);
    void __fastcall call3dClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall Load1Click(TObject *Sender);
    void __fastcall SaveAs1Click(TObject *Sender);
    void __fastcall cbxUClick(TObject *Sender);
    void __fastcall cbxIClick(TObject *Sender);
    void __fastcall Save1Click(TObject *Sender);
    void __fastcall N4Click(TObject *Sender);
    void __fastcall N2Click(TObject *Sender);
private:
    COMPLEX z01;
    COMPLEX y01;
    COMPLEX z03;
    COMPLEX y03;
    double w1;
    double w3;
    double bet1;
    double bet3;
    double alf1;
    double alf3;
    double lw1;
    double vf1;
    double lw3;
    double vf3;
    COMPLEX gam1;
    COMPLEX zw1;
    COMPLEX gam3;
    COMPLEX zw3;
    double r;
    double l;
    double c;
    double r0;
    double l0;
    double g0;
    double c0;
    double ll;
    COMPLEX zng1;
    COMPLEX zng3;
    double e1;
    double e3;
    double i1;
    double i3;
    COMPLEX aa11;
    COMPLEX aa13;
    COMPLEX aa21;
    COMPLEX aa23;
    COMPLEX tempk1;
    COMPLEX tempk3;
    double x;
    double dx;
    double oldmousex;
    bool oldmouseflag;
    int x_old;
    bool ErrOr;
    double tempgamll1;
    double tempgamll3;
    void countSecondary(void); // recounts primary vals : f(ComboBox->ItemIndex)
    void countA(void); // counts A1(aa1)&A2(aa2) : f(RadioButtons) (1/3)
    void drawChart(void);  // рисует графики действующих значений и фаз от расстояния x
    double GetArg(COMPLEX c);
    void drawOsc(void);
    void writeToEdits(void);
    void readFromEdits(void);
 // рисует графики действующих значений и фаз от расстояния x
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
