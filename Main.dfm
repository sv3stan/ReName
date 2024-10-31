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
  OnClose = FormClose
  OnCreate = FormCreate
  TextHeight = 15
  object JvPanel1: TJvPanel
    Left = 0
    Top = 628
    Width = 1131
    Height = 41
    Align = alBottom
    TabOrder = 0
  end
  object JvxSplitter1: TJvxSplitter
    Left = 0
    Top = 625
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
    Height = 581
    Align = alLeft
    TabOrder = 4
  end
  object JvxSplitter3: TJvxSplitter
    Left = 185
    Top = 44
    Width = 3
    Height = 581
    ControlFirst = JvPanel3
    Align = alLeft
  end
  object JvPanel4: TJvPanel
    Left = 920
    Top = 44
    Width = 211
    Height = 581
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
        LinkedControls = <>
      end
      object JvCheckBox2: TJvCheckBox
        Left = 16
        Top = 43
        Width = 96
        Height = 17
        Caption = 'Date modified'
        TabOrder = 1
        LinkedControls = <>
      end
      object JvCheckBox3: TJvCheckBox
        Left = 16
        Top = 66
        Width = 82
        Height = 17
        Caption = 'Date access'
        TabOrder = 2
        LinkedControls = <>
      end
      object JvCheckBox4: TJvCheckBox
        Left = 16
        Top = 89
        Width = 79
        Height = 17
        Caption = 'Photo date'
        TabOrder = 3
        LinkedControls = <>
      end
    end
  end
  object JvxSplitter4: TJvxSplitter
    Left = 917
    Top = 44
    Width = 3
    Height = 581
    ControlFirst = JvPanel4
    Align = alRight
    ExplicitLeft = 950
  end
  object JvPanel5: TJvPanel
    Left = 188
    Top = 44
    Width = 729
    Height = 581
    Align = alClient
    TabOrder = 8
    ExplicitWidth = 762
    object JvPanel6: TJvPanel
      Left = 1
      Top = 524
      Width = 727
      Height = 56
      Align = alBottom
      TabOrder = 0
      ExplicitWidth = 760
    end
    object JvPanel7: TJvPanel
      Left = 1
      Top = 1
      Width = 727
      Height = 176
      Align = alTop
      TabOrder = 1
      ExplicitWidth = 760
      object Label1: TLabel
        Left = 29
        Top = 5
        Width = 76
        Height = 15
        Caption = #1055#1091#1090#1100' '#1082' '#1092#1072#1081#1083#1091':'
      end
      object Label3: TLabel
        Left = 29
        Top = 65
        Width = 43
        Height = 15
        Caption = #1056#1072#1079#1084#1077#1088':'
      end
      object Label7: TLabel
        Left = 29
        Top = 145
        Width = 60
        Height = 15
        Caption = #1040#1090#1088#1080#1073#1091#1090#1099' :'
      end
      object Label8: TLabel
        Left = 29
        Top = 45
        Width = 64
        Height = 15
        Caption = #1058#1080#1087' '#1092#1072#1081#1083#1072' :'
      end
      object Label4: TLabel
        Left = 29
        Top = 85
        Width = 84
        Height = 15
        Caption = #1044#1072#1090#1072' '#1089#1086#1079#1076#1072#1085#1080#1103' :'
      end
      object Label5: TLabel
        Left = 29
        Top = 105
        Width = 94
        Height = 15
        Caption = #1044#1072#1090#1072' '#1080#1079#1084#1077#1085#1077#1085#1080#1103' :'
      end
      object Label6: TLabel
        Left = 29
        Top = 125
        Width = 80
        Height = 15
        Caption = #1044#1072#1090#1072' '#1086#1090#1082#1088#1099#1090#1080#1103
      end
      object Label2: TLabel
        Left = 29
        Top = 25
        Width = 32
        Height = 15
        Caption = #1060#1072#1081#1083':'
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
        Width = 75
        Height = 15
        Caption = #1044#1072#1090#1072' '#1089#1085#1080#1084#1082#1072' :'
      end
      object Label18: TLabel
        Left = 254
        Top = 85
        Width = 46
        Height = 15
        Caption = #1042#1099#1089#1086#1090#1072' :'
      end
      object Label19: TLabel
        Left = 254
        Top = 105
        Width = 51
        Height = 15
        Caption = #1064#1080#1088#1080#1085#1072' :'
      end
      object Label20: TLabel
        Left = 254
        Top = 125
        Width = 42
        Height = 15
        Caption = #1052#1072#1088#1082#1072' :'
      end
      object Label21: TLabel
        Left = 254
        Top = 145
        Width = 49
        Height = 15
        Caption = #1052#1086#1076#1077#1083#1100' :'
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
      ExplicitWidth = 760
    end
    object JvxSplitter6: TJvxSplitter
      Left = 1
      Top = 521
      Width = 727
      Height = 3
      ControlFirst = JvPanel6
      Align = alBottom
      ExplicitWidth = 760
    end
    object JvPanel8: TJvPanel
      Left = 1
      Top = 180
      Width = 727
      Height = 341
      Align = alClient
      TabOrder = 4
      ExplicitWidth = 760
      object JvListView1: TJvListView
        Left = 1
        Top = 1
        Width = 725
        Height = 339
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
            AutoSize = True
            Caption = 'Attribute'
          end
          item
            Caption = 'New attribute'
            Width = 0
          end
          item
            Caption = 'New photo date'
            Width = 0
          end>
        DragMode = dmAutomatic
        GridLines = True
        HideSelection = False
        MultiSelect = True
        StyleName = 'Windows'
        RowSelect = True
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        ViewStyle = vsReport
        OnClick = JvListView1Click
        OnSelectItem = JvListView1SelectItem
        ColumnsOrder = 
          '0=145,1=142,2=0,3=142,4=50,5=0,6=50,7=0,8=50,9=0,10=142,11=0,12=' +
          '0'
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
