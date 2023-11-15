//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include <math.h>
#include <stdio.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
typedef struct{
        float v[4][4];
}MATRIZ;
MATRIZ identidad={{{1,0,0,0},
                   {0,1,0,0},
                   {0,0,1,0},
                   {0,0,0,1}}};
MATRIZ mtrans=identidad;
struct VTX{
        float x,y,z;
        int dib;
};
VTX puntos[500000];
int npuntos = 0;
void aplica_matriz(VTX a, VTX &b){
        b.x=mtrans.v[0][0]*a.x+
            mtrans.v[0][1]*a.y+
            mtrans.v[0][2]*a.z+
            mtrans.v[0][3]*1;
        b.y=mtrans.v[1][0]*a.x+
            mtrans.v[1][1]*a.y+
            mtrans.v[1][2]*a.z+
            mtrans.v[1][3]*1;
        b.z=mtrans.v[2][0]*a.x+
            mtrans.v[2][1]*a.y+
            mtrans.v[2][2]*a.z+
            mtrans.v[2][3]*1;
        b.dib=a.dib;
}

void dibujar(){
 VTX aux;
 for(int i=0;i<npuntos;i++){
        aplica_matriz(puntos[i],aux);
   if(aux.dib==0){
        Form1->Canvas->MoveTo(aux.x , aux.y);
   }else{
        Form1->Canvas->LineTo(aux.x , aux.y);
   }
 }
}
void multiplicar(MATRIZ a, MATRIZ b, MATRIZ &c){
 for(int i=0;i<4;i++){
  for(int j=0;j<4;j++){
    c.v[i][j]=0;
    for(int k=0;k<4;k++){
      c.v[i][j] += a.v[i][k]*b.v[k][j];
    }
  }
 }
}
//---------------------------------------------------------------------------
void trasladar(float tx, float ty, float tz){
 MATRIZ aux=identidad;
 MATRIZ temp=mtrans;
 aux.v[0][3]=tx;
 aux.v[1][3]=ty;
 aux.v[2][3]=tz;
 multiplicar(aux,temp,mtrans);
}
void escalar(float sx, float sy, float sz){
 MATRIZ aux=identidad;
 MATRIZ temp=mtrans;
 aux.v[0][0]=sx;
 aux.v[1][1]=sy;
 aux.v[2][2]=sz;
 multiplicar(aux,temp,mtrans);
}
void rotarX(float ang){
 MATRIZ aux=identidad;
 MATRIZ temp=mtrans;
 ang=ang*M_PI/180;
 float vcos=cos(ang),vsin=sin(ang);
 aux.v[1][1]=vcos;
 aux.v[1][2]=-vsin;
 aux.v[2][1]=vsin;
 aux.v[2][2]=vcos;
 multiplicar(aux,temp,mtrans);
}
void rotarY(float ang){
 MATRIZ aux=identidad;
 MATRIZ temp=mtrans;
 ang=ang*M_PI/180;
 float vcos=cos(ang),vsin=sin(ang);
 aux.v[0][0]=vcos;
 aux.v[0][2]=vsin;
 aux.v[2][0]=-vsin;
 aux.v[2][2]=vcos;
 multiplicar(aux,temp,mtrans);
}
void rotarZ(float ang){
 MATRIZ aux=identidad;
 MATRIZ temp=mtrans;
 ang=ang*M_PI/180;
 float vcos=cos(ang),vsin=sin(ang);
 aux.v[0][0]=vcos;
 aux.v[0][1]=-vsin;
 aux.v[1][0]=vsin;
 aux.v[1][1]=vcos;
 multiplicar(aux,temp,mtrans);
}
void sun(int xc,int yc,int zc,int r);
void __fastcall TForm1::FormPaint(TObject *Sender)
{
    dibujar();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        rotarX(-10);
        Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
        rotarX(10);
        Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
        trasladar(-10,0,0);
        Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
        trasladar(10,0,0);
        Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button14Click(TObject *Sender)
{
        trasladar(0,0,-10);
        Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
        trasladar(0,-10,0);
        Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
        trasladar(0,10,0);
        Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
        escalar(0.8,0.8,0.8);
        Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
        escalar(1.2,1.2,1.2);
        Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
        rotarY(-10);
        Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
        rotarY(+10);
        Repaint();
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
 FILE *arch;
 if(OpenDialog1->Execute()){
  arch=fopen(OpenDialog1->FileName.c_str(),"rt");
  mtrans=identidad;
  npuntos=0;
  while(!feof(arch)){
   fscanf(arch,"%f%f%f%d",&puntos[npuntos].x,
   &puntos[npuntos].y,&puntos[npuntos].z,
   &puntos[npuntos].dib);
   if(!feof(arch)){npuntos++;}
  }
  fclose(arch);
  Repaint();
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
 FILE *arch;
 VTX aux;
 if(SaveDialog1->Execute()){
  arch=fopen(SaveDialog1->FileName.c_str(),"wt");
  for(int i=0;i<npuntos;i++){
   aplica_matriz(puntos[i],aux);
   fprintf(arch,"%8.3f%8.3f%8.3f%3d\n",aux.x,
   aux.y,aux.z,aux.dib);
  }
  fclose(arch);
 }
}
//---------------------------------------------------------------------------
int x0,y0,x1,y1,dibuja=0;




void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
if(Button==mbLeft){
 puntos[npuntos].dib=dibuja;
 puntos[npuntos].x=X;
 puntos[npuntos].y=Y;
 npuntos++;
 dibuja=1;
 x0=X;
 y0=Y;
 x1=X;
 y1=Y;
}else{
 dibuja=0;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
 //MouseMove
 if(dibuja){
  Canvas->Pen->Mode=pmNotXor;
  Canvas->MoveTo(x0,y0);
  Canvas->LineTo(x1,y1);

  Canvas->MoveTo(x0,y0);
  Canvas->LineTo(X,Y);
  x1=X;
  y1=Y;
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button13Click(TObject *Sender)
{
npuntos=0;
Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button15Click(TObject *Sender)
{

        trasladar(0,0,10);
        Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button16Click(TObject *Sender)
{
        rotarZ(-10);
        Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button17Click(TObject *Sender)
{
        rotarZ(+10);
        Repaint();
}
//---------------------------------------------------------------------------
//Para dibujar cualquier FUNCION
void __fastcall TForm1::Button18Click(TObject *Sender)
{
npuntos=0;
mtrans=identidad;
float x,y,z;
int i=0,d=0;
for(x=-15;x<=15;x+=0.1){
    d=0;
   for(y=-15;y<=15;y+=0.1){
       z=cos(x)+sin(y);//FUNCION
       puntos[i].x=x;
       puntos[i].y=y;
       puntos[i].z=z;
       puntos[i].dib=d;
       i++;
       d=1;
   }
}
npuntos=i;
escalar(20,20,20);
rotarX(-100);
rotarY(10);
trasladar(200,250,0);
Repaint();
}
//---------------------------------------------------------------------------
void esfera(float xc ,float yc ,float zc,int r){
    float x,y,z,xx;
    int d=0;
    for(float ang1=-90;ang1<=90;ang1+=10){
      xx=r*cos(ang1*M_PI/180);
      y=r*sin(ang1*M_PI/180)+yc;
      d = 0;
      for(float ang2=0;ang2<=360;ang2+=10){
       z=xx*cos(ang2*M_PI/180)+zc;
       x=xx*sin(ang2*M_PI/180)+xc;
       puntos[npuntos].x = x;
       puntos[npuntos].y = y;
       puntos[npuntos].z = z;
       puntos[npuntos].dib = d;
       npuntos++;
       d = 1;
       }
    }
}
void saturno(float xc ,float yc ,float zc,int r){
    float x,y,z,xx;
    int d=0;
    for(float ang1=-90;ang1<=90;ang1+=10){
      xx=r*cos(ang1*M_PI/180);
      y=r*sin(ang1*M_PI/180)+yc;
      d = 0;
      for(float ang2=0;ang2<=360;ang2+=10){
       z=xx*cos(ang2*M_PI/180)+zc;
       x=xx*sin(ang2*M_PI/180)+xc;
       puntos[npuntos].x = x;
       puntos[npuntos].y = y;
       puntos[npuntos].z = z;
       puntos[npuntos].dib = d;
       npuntos++;
       d = 1;
       }
    }
    //anillos
    float ax,ay,az;
    int d1 = 0;
    for(int radio = r + 30;radio <= r + 70 ; radio+=5){
        d1 = 0;
        for(float ang = 0; ang<=360 ; ang+=10){
            ax = xc + radio*cos(ang*M_PI/180);
            az = zc + radio*sin(ang*M_PI/180);
            ay = yc;
            puntos[npuntos].x = ax;
            puntos[npuntos].y = ay;
            puntos[npuntos].z = az;
            puntos[npuntos].dib = d1;
            npuntos++;
            d1 = 1;
        }
    }
}
void __fastcall TForm1::FormCreate(TObject *Sender)
{
        Form1->WindowState = wsMaximized;
        Timer1->Enabled = False;
}
//---------------------------------------------------------------------------

float xtierra = 0,ytierra = 0,xmercurio = 0,ymercurio = 0,
    xvenus = 0,yvenus = 0,xmarte = 0,ymarte = 0,xjupiter = 0,yjupiter = 0,
    xsaturno = 0,ysaturno = 0,xurano = 0,yurano = 0,xneptuno = 0,yneptuno = 0;
float angtierra = 0,angmercurio=0,angvenus = 0,angmarte = 0,angjupiter = 0,angsaturno = 0,
      angurano = 0,angneptuno =0;
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
        npuntos = 0;
        int xc = Form1->Width/2,yc = Form1->Height/2;
        npuntos = 0;
        Form1->Canvas->Pen->Color = clWhite;
        xmercurio = (xc+205)*cos(angmercurio*M_PI/180);
        ymercurio = (xc+205)*sin(angmercurio*M_PI/180);
        xvenus = (xc+285)*cos(angvenus*M_PI/180);
        yvenus = (xc+285)*sin(angvenus*M_PI/180);
        xtierra = (xc+395)*cos(angtierra*M_PI/180);
        ytierra = (xc+395)*sin(angtierra*M_PI/180);
        xmarte = (xc+545)*cos(angmarte*M_PI/180);
        ymarte = (xc+545)*sin(angmarte*M_PI/180);
        xjupiter = (xc+765)*cos(angjupiter*M_PI/180);
        yjupiter = (xc+765)*sin(angjupiter*M_PI/180);
        xsaturno = (xc+1085)*cos(angsaturno*M_PI/180);
        ysaturno = (xc+1085)*sin(angsaturno*M_PI/180);
        xurano = (xc+1485)*cos(angurano*M_PI/180);
        yurano = (xc+1485)*sin(angurano*M_PI/180);
        xneptuno = (xc+1985)*cos(angneptuno*M_PI/180);
        yneptuno = (xc+1985)*sin(angneptuno*M_PI/180);
        //SOL
        esfera(xc,0,yc,155);
        //MERCURIO
        esfera(xmercurio,0,ymercurio,10);
        //VENUS
        esfera(xvenus,0,yvenus,15);
        //TIERRA
        esfera(xtierra,0,ytierra,18);
        //MARTE
        esfera(xmarte,0,ymarte,12);
        //JUPITER
        esfera(xjupiter,0,yjupiter,45);
        //SATURNO
        saturno(xsaturno,0,ysaturno,40);
        //URANO
        esfera(xurano,0,yurano,30);
        //NEPTUNO
        esfera(xneptuno,0,yneptuno,28);
        angmercurio += 4.0909;
        angvenus += 1.6000;
        angtierra += 0.9863;
        angmarte += 0.5240;
        angjupiter += 0.0833;
        angsaturno += 0.0345;
        angurano += 0.0119;
        angneptuno += 0.0061;
        Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button20Click(TObject *Sender)
{
        Timer1->Enabled = False;        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button21Click(TObject *Sender)
{
        Timer1->Enabled = True;        
}
//---------------------------------------------------------------------------

