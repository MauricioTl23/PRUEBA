object Form1: TForm1
  Left = 245
  Top = 128
  Width = 696
  Height = 479
  Caption = 'Form1'
  Color = clBlack
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnMouseDown = FormMouseDown
  OnMouseMove = FormMouseMove
  OnPaint = FormPaint
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 1245
    Top = 16
    Width = 43
    Height = 13
    Caption = 'Rotacion'
  end
  object Label2: TLabel
    Left = 1244
    Top = 160
    Width = 44
    Height = 13
    Caption = 'Trasladar'
    OnClick = Button1Click
  end
  object Label3: TLabel
    Left = 1245
    Top = 280
    Width = 35
    Height = 13
    Caption = 'Escalar'
    OnClick = Button1Click
  end
  object Button1: TButton
    Left = 1184
    Top = 40
    Width = 75
    Height = 25
    Caption = 'Rotar X-'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 1272
    Top = 40
    Width = 75
    Height = 25
    Caption = 'Rotar X+'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 1184
    Top = 184
    Width = 75
    Height = 25
    Caption = 'Eje X -'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 1272
    Top = 184
    Width = 75
    Height = 25
    Caption = 'Eje X+'
    TabOrder = 3
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 1184
    Top = 216
    Width = 75
    Height = 25
    Caption = 'Eje Y-'
    TabOrder = 4
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 1272
    Top = 216
    Width = 75
    Height = 25
    Caption = 'Eje Y+'
    TabOrder = 5
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 1184
    Top = 304
    Width = 75
    Height = 25
    Caption = 'Decrecer'
    TabOrder = 6
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 1272
    Top = 304
    Width = 75
    Height = 25
    Caption = 'Crecer'
    TabOrder = 7
    OnClick = Button8Click
  end
  object Button11: TButton
    Left = 1184
    Top = 368
    Width = 75
    Height = 25
    Caption = 'Recuperar'
    TabOrder = 8
    OnClick = Button11Click
  end
  object Button12: TButton
    Left = 1272
    Top = 368
    Width = 75
    Height = 25
    Caption = 'Grabar'
    TabOrder = 9
    OnClick = Button12Click
  end
  object Button13: TButton
    Left = 1232
    Top = 408
    Width = 75
    Height = 25
    Caption = 'Limpiar'
    TabOrder = 10
    OnClick = Button13Click
  end
  object Button14: TButton
    Left = 1184
    Top = 248
    Width = 75
    Height = 25
    Caption = 'Eje Z-'
    TabOrder = 11
    OnClick = Button14Click
  end
  object Button15: TButton
    Left = 1272
    Top = 248
    Width = 75
    Height = 25
    Caption = 'Eje Z+'
    TabOrder = 12
    OnClick = Button15Click
  end
  object Button9: TButton
    Left = 1184
    Top = 72
    Width = 75
    Height = 25
    Caption = 'Rotar Y-'
    TabOrder = 13
    OnClick = Button9Click
  end
  object Button10: TButton
    Left = 1272
    Top = 72
    Width = 75
    Height = 25
    Caption = 'Rotar Y+'
    TabOrder = 14
    OnClick = Button10Click
  end
  object Button16: TButton
    Left = 1184
    Top = 104
    Width = 75
    Height = 25
    Caption = 'Rotar Z-'
    TabOrder = 15
    OnClick = Button16Click
  end
  object Button17: TButton
    Left = 1272
    Top = 104
    Width = 75
    Height = 25
    Caption = 'Rotar Z+'
    TabOrder = 16
    OnClick = Button17Click
  end
  object Button18: TButton
    Left = 1232
    Top = 448
    Width = 75
    Height = 25
    Caption = 'FUNCION'
    TabOrder = 17
    OnClick = Button18Click
  end
  object Button20: TButton
    Left = 1232
    Top = 528
    Width = 75
    Height = 25
    Caption = 'STOP'
    TabOrder = 18
    OnClick = Button20Click
  end
  object Button21: TButton
    Left = 1232
    Top = 568
    Width = 75
    Height = 25
    Caption = 'RUN'
    TabOrder = 19
    OnClick = Button21Click
  end
  object OpenDialog1: TOpenDialog
    DefaultExt = 'txt'
    Filter = 'grafico|*.txt'
    Left = 8
    Top = 8
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = 'txt'
    Filter = 'grafico|*.txt'
    Left = 40
    Top = 8
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 80
    Top = 8
  end
end
