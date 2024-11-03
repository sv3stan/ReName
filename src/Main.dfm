object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 669
  ClientWidth = 1131
  Color = clBtnFace
  DragMode = dmAutomatic
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Icon.Data = {
    0000010001002020100000000000E80200001600000028000000200000004000
    0000010004000000000080020000000000000000000000000000000000002434
    34002C6C9400A44C3400947C9C00346C5C005C749400B47C3400A4BCCC00544C
    4C00D4E4EC009C7CDC006C9CAC00AC8464003494A4005C746400A4544C00FF22
    27662222C9A66F79F2F2229679C6F222299292729A292672229929223299888F
    08E88EC3C8833F8F8888800880888E88E880008888880808E88EEE884040E400
    000400000004E3833EE88808800840E6CE4CEEC4E0E88308E0088088CE330088
    048005000FE00800009007EEC04E80040000410C088B008004B0E97309990040
    440E40EF448E4E04E44037BB9999844E048000EED85553840E0083BB99998008
    EE888BE3888880844E5089BB9999804004ED91BB01D40084578059BB99998050
    800E009005B70888590B33BB99998848EE8E099000808E8F98443BBB99B900E0
    000E099EE4040389978439BB9999800000845790197B830BB7BD39BB9939E800
    40E9999199988053997799BB9979EC8E80E799EB799487CE993799BB997950EE
    084769F7799400E0999999BB99E98E03E309F9C779948999799997BB99E988E7
    E587F93339985977793399BB99898058B8E789F3799B9997793397B599890B79
    9F3C2999799999C2993C93B599398E99937019777993A97299CB95BB99799779
    999979C7799EA9789993855197997397913CF9237998E9999C0DD55E79799999
    7833F9837994B9994D3778E839975977783CC9473999D99009B97855B7793779
    7833E9077799979199962085B57F8777735C897997974E7797222200F222E777
    73CC0997995517775222222FF22F87777EC47979780177772222222222220000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    000000000000000000000000000000000000000000000000000000000000}
  OnClose = FormClose
  OnCreate = FormCreate
  TextHeight = 15
  object JvPanel1: TJvPanel
    Left = 0
    Top = 644
    Width = 1131
    Height = 25
    Align = alBottom
    TabOrder = 0
    object JvStatusBar1: TJvStatusBar
      Left = 1
      Top = 1
      Width = 1129
      Height = 23
      Align = alClient
      Panels = <
        item
          Text = #1042#1089#1077#1075#1086' '#1092#1072#1081#1083#1086#1074':'
          Width = 420
        end
        item
          Text = #1054#1090#1084#1077#1095#1077#1085#1086':'
          Width = 80
        end>
    end
  end
  object JvxSplitter1: TJvxSplitter
    Left = 0
    Top = 641
    Width = 1131
    Height = 3
    ControlFirst = JvPanel1
    Align = alBottom
  end
  object JvPanel2: TJvPanel
    Left = 0
    Top = 0
    Width = 1131
    Height = 41
    Align = alTop
    TabOrder = 2
  end
  object JvxSplitter2: TJvxSplitter
    Left = 0
    Top = 41
    Width = 1131
    Height = 3
    ControlFirst = JvPanel2
    Align = alTop
  end
  object JvPanel3: TJvPanel
    Left = 0
    Top = 44
    Width = 185
    Height = 597
    Align = alLeft
    TabOrder = 4
  end
  object JvxSplitter3: TJvxSplitter
    Left = 185
    Top = 44
    Width = 3
    Height = 597
    ControlFirst = JvPanel3
    Align = alLeft
  end
  object JvPanel4: TJvPanel
    Left = 920
    Top = 44
    Width = 211
    Height = 597
    Align = alRight
    TabOrder = 6
    object JvTransparentButton1: TJvTransparentButton
      Left = 159
      Top = 81
      Width = 40
      Height = 40
      Caption = 'OK'
    end
    object JvTransparentButton2: TJvTransparentButton
      Left = 159
      Top = 228
      Width = 40
      Height = 40
      Caption = 'OK'
    end
    object JvTransparentButton3: TJvTransparentButton
      Left = 159
      Top = 384
      Width = 40
      Height = 40
      Caption = 'OK'
      OnClick = JvTransparentButton3Click
    end
    object JvTransparentButton4: TJvTransparentButton
      Left = 6
      Top = 480
      Width = 147
      Height = 40
      Caption = 'Apply'
    end
    object JvRadioGroup1: TJvRadioGroup
      Left = 6
      Top = 146
      Width = 147
      Height = 122
      Caption = 'Date in file name'
      ItemIndex = 0
      Items.Strings = (
        'Date create'
        'Date modified'
        'Date access'
        'Photo date')
      TabOrder = 0
    end
    object JvGroupBox1: TJvGroupBox
      Left = 6
      Top = 287
      Width = 147
      Height = 137
      Caption = 'Attribute'
      TabOrder = 1
      object JvCheckBox5: TJvCheckBox
        Left = 16
        Top = 24
        Width = 64
        Height = 17
        Caption = 'Archival'
        TabOrder = 0
        OnClick = JvCheckBox5Click
        LinkedControls = <>
      end
      object JvCheckBox6: TJvCheckBox
        Left = 16
        Top = 47
        Width = 73
        Height = 17
        Caption = 'Read only'
        TabOrder = 1
        LinkedControls = <>
      end
      object JvCheckBox7: TJvCheckBox
        Left = 16
        Top = 70
        Width = 60
        Height = 17
        Caption = 'Hidden'
        TabOrder = 2
        LinkedControls = <>
      end
      object JvCheckBox8: TJvCheckBox
        Left = 16
        Top = 93
        Width = 59
        Height = 17
        Caption = 'System'
        TabOrder = 3
        LinkedControls = <>
      end
    end
    object JvGroupBox2: TJvGroupBox
      Left = 6
      Top = 6
      Width = 147
      Height = 115
      Caption = 'File name to date'
      TabOrder = 2
      object JvCheckBox1: TJvCheckBox
        Left = 16
        Top = 20
        Width = 80
        Height = 17
        Caption = 'Date create'
        TabOrder = 0
        OnClick = JvCheckBox1Click
        LinkedControls = <>
      end
      object JvCheckBox2: TJvCheckBox
        Left = 16
        Top = 43
        Width = 96
        Height = 17
        Caption = 'Date modified'
        TabOrder = 1
        OnClick = JvCheckBox2Click
        LinkedControls = <>
      end
      object JvCheckBox3: TJvCheckBox
        Left = 16
        Top = 66
        Width = 82
        Height = 17
        Caption = 'Date access'
        TabOrder = 2
        OnClick = JvCheckBox3Click
        LinkedControls = <>
      end
      object JvCheckBox4: TJvCheckBox
        Left = 16
        Top = 89
        Width = 79
        Height = 17
        Caption = 'Photo date'
        TabOrder = 3
        OnClick = JvCheckBox4Click
        LinkedControls = <>
      end
    end
  end
  object JvxSplitter4: TJvxSplitter
    Left = 917
    Top = 44
    Width = 3
    Height = 597
    ControlFirst = JvPanel4
    Align = alRight
  end
  object JvPanel5: TJvPanel
    Left = 188
    Top = 44
    Width = 729
    Height = 597
    Align = alClient
    TabOrder = 8
    object JvPanel6: TJvPanel
      Left = 1
      Top = 540
      Width = 727
      Height = 56
      Align = alBottom
      TabOrder = 0
      object JvCheckBox9: TJvCheckBox
        Left = 29
        Top = 6
        Width = 77
        Height = 17
        Caption = 'Show path'
        Checked = True
        State = cbChecked
        TabOrder = 0
        OnClick = JvCheckBox9Click
        LinkedControls = <>
      end
    end
    object JvPanel7: TJvPanel
      Left = 1
      Top = 1
      Width = 727
      Height = 176
      Align = alTop
      TabOrder = 1
      object Label1: TLabel
        Left = 29
        Top = 5
        Width = 27
        Height = 15
        Caption = 'Path:'
      end
      object Label3: TLabel
        Left = 29
        Top = 65
        Width = 23
        Height = 15
        Caption = 'Size:'
      end
      object Label7: TLabel
        Left = 29
        Top = 145
        Width = 53
        Height = 15
        Caption = 'Attribute :'
      end
      object Label8: TLabel
        Left = 29
        Top = 45
        Width = 30
        Height = 15
        Caption = 'Type :'
      end
      object Label4: TLabel
        Left = 29
        Top = 85
        Width = 65
        Height = 15
        Caption = 'Date create :'
      end
      object Label5: TLabel
        Left = 29
        Top = 105
        Width = 81
        Height = 15
        Caption = 'Date modified :'
      end
      object Label6: TLabel
        Left = 29
        Top = 125
        Width = 60
        Height = 15
        Caption = 'Date open :'
      end
      object Label2: TLabel
        Left = 29
        Top = 25
        Width = 54
        Height = 15
        Caption = 'File name:'
      end
      object Label9: TLabel
        Left = 128
        Top = 5
        Width = 34
        Height = 15
        Caption = 'Label9'
        Visible = False
      end
      object Label10: TLabel
        Left = 128
        Top = 25
        Width = 40
        Height = 15
        Caption = 'Label10'
        Visible = False
      end
      object Label11: TLabel
        Left = 128
        Top = 45
        Width = 40
        Height = 15
        Caption = 'Label11'
        Visible = False
      end
      object Label12: TLabel
        Left = 128
        Top = 65
        Width = 40
        Height = 15
        Caption = 'Label12'
        Visible = False
      end
      object Label13: TLabel
        Left = 128
        Top = 85
        Width = 40
        Height = 15
        Caption = 'Label13'
        Visible = False
      end
      object Label14: TLabel
        Left = 128
        Top = 105
        Width = 40
        Height = 15
        Caption = 'Label14'
        Visible = False
      end
      object Label15: TLabel
        Left = 128
        Top = 125
        Width = 40
        Height = 15
        Caption = 'Label15'
        Visible = False
      end
      object Label16: TLabel
        Left = 128
        Top = 145
        Width = 40
        Height = 15
        Caption = 'Label16'
        Visible = False
      end
      object JvImage1: TJvImage
        Left = 534
        Top = 1
        Width = 192
        Height = 174
        Align = alRight
        Stretch = True
        ExplicitLeft = 456
      end
      object Label17: TLabel
        Left = 254
        Top = 65
        Width = 73
        Height = 15
        Caption = 'Date original :'
      end
      object Label18: TLabel
        Left = 254
        Top = 85
        Width = 42
        Height = 15
        Caption = 'Height :'
      end
      object Label19: TLabel
        Left = 254
        Top = 105
        Width = 38
        Height = 15
        Caption = 'Width :'
      end
      object Label20: TLabel
        Left = 254
        Top = 125
        Width = 35
        Height = 15
        Caption = 'Make :'
      end
      object Label21: TLabel
        Left = 254
        Top = 145
        Width = 40
        Height = 15
        Caption = 'Model :'
      end
      object Label22: TLabel
        Left = 335
        Top = 65
        Width = 40
        Height = 15
        Caption = 'Label22'
        Visible = False
      end
      object Label23: TLabel
        Left = 335
        Top = 85
        Width = 40
        Height = 15
        Caption = 'Label23'
        Visible = False
      end
      object Label24: TLabel
        Left = 335
        Top = 105
        Width = 40
        Height = 15
        Caption = 'Label24'
        Visible = False
      end
      object Label25: TLabel
        Left = 335
        Top = 125
        Width = 40
        Height = 15
        Caption = 'Label25'
        Visible = False
      end
      object Label26: TLabel
        Left = 335
        Top = 145
        Width = 40
        Height = 15
        Caption = 'Label26'
        Visible = False
      end
    end
    object JvxSplitter5: TJvxSplitter
      Left = 1
      Top = 177
      Width = 727
      Height = 3
      ControlFirst = JvPanel7
      Align = alTop
    end
    object JvxSplitter6: TJvxSplitter
      Left = 1
      Top = 537
      Width = 727
      Height = 3
      ControlFirst = JvPanel6
      Align = alBottom
    end
    object JvPanel8: TJvPanel
      Left = 1
      Top = 180
      Width = 727
      Height = 357
      Align = alClient
      TabOrder = 4
      object JvListView1: TJvListView
        Left = 1
        Top = 1
        Width = 725
        Height = 355
        Align = alClient
        Columns = <
          item
            AutoSize = True
            Caption = 'Path'
          end
          item
            AutoSize = True
            Caption = 'Name'
          end
          item
            Caption = 'New name'
            Width = 0
          end
          item
            AutoSize = True
            Caption = 'Size'
          end
          item
            Caption = 'Date create'
          end
          item
            Caption = 'New date create'
            Width = 0
          end
          item
            Caption = 'Date modified'
          end
          item
            Caption = 'New date modified'
            Width = 0
          end
          item
            Caption = 'Date open'
          end
          item
            Caption = 'New date open'
            Width = 0
          end
          item
            Caption = 'Date original'
          end
          item
            Caption = 'New date original'
            Width = 0
          end
          item
            Alignment = taCenter
            Caption = 'Attribute'
            Width = 60
          end
          item
            Caption = 'New attribute'
            Width = 0
          end>
        DoubleBuffered = True
        DragMode = dmAutomatic
        GridLines = True
        HideSelection = False
        MultiSelect = True
        StyleName = 'Windows'
        RowSelect = True
        ParentDoubleBuffered = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        ViewStyle = vsReport
        OnSelectItem = JvListView1SelectItem
        ColumnsOrder = 
          '0=0,1=153,2=0,3=153,4=50,5=0,6=50,7=0,8=50,9=0,10=50,11=0,12=60,' +
          '13=0'
        OnBeginColumnResize = JvListView1BeginColumnResize
        ExtendedColumns = <
          item
          end
          item
          end
          item
          end
          item
          end
          item
          end
          item
          end
          item
          end
          item
          end
          item
          end
          item
          end
          item
          end
          item
          end
          item
          end
          item
          end>
      end
    end
  end
  object JvDragDrop1: TJvDragDrop
    DropTarget = JvListView1
    OnDrop = JvDragDrop1Drop
    Left = 80
    Top = 508
  end
  object JvBrowseForFolderDialog1: TJvBrowseForFolderDialog
    Left = 80
    Top = 244
  end
  object JvOpenDialog1: TJvOpenDialog
    Height = 0
    Width = 0
    Left = 88
    Top = 356
  end
end
