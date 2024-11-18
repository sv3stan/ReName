object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'ReName'
  ClientHeight = 744
  ClientWidth = 1131
  Color = clBtnFace
  TransparentColorValue = clBtnFace
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
    Top = 719
    Width = 1131
    Height = 25
    Align = alBottom
    TabOrder = 0
    ExplicitTop = 644
    object JvStatusBar1: TJvStatusBar
      Left = 1
      Top = 1
      Width = 1129
      Height = 23
      Align = alClient
      Panels = <
        item
          Text = 'Total files :'
          Width = 420
        end
        item
          Text = 'Selected :'
          Width = 80
        end>
    end
  end
  object JvxSplitter1: TJvxSplitter
    Left = 0
    Top = 716
    Width = 1131
    Height = 3
    ControlFirst = JvPanel1
    Align = alBottom
    ExplicitTop = 641
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
    Width = 105
    Height = 672
    Align = alLeft
    TabOrder = 4
    ExplicitHeight = 597
  end
  object JvxSplitter3: TJvxSplitter
    Left = 105
    Top = 44
    Width = 3
    Height = 672
    ControlFirst = JvPanel3
    Align = alLeft
    ExplicitHeight = 597
  end
  object JvPanel4: TJvPanel
    Left = 920
    Top = 44
    Width = 211
    Height = 672
    Align = alRight
    TabOrder = 6
    ExplicitHeight = 597
    object Filename_To_Date_Button_: TJvTransparentButton
      Left = 159
      Top = 81
      Width = 40
      Height = 40
      Caption = 'OK'
      OnClick = Filename_To_Date_Button_Click
    end
    object JvTransparentButton2: TJvTransparentButton
      Left = 159
      Top = 228
      Width = 40
      Height = 40
      Caption = 'OK'
      OnClick = JvTransparentButton2Click
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
        'Original date')
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
        Width = 87
        Height = 17
        Caption = 'Date created'
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
        Width = 88
        Height = 17
        Caption = 'Date opened'
        TabOrder = 2
        OnClick = JvCheckBox3Click
        LinkedControls = <>
      end
      object JvCheckBox4: TJvCheckBox
        Left = 16
        Top = 89
        Width = 89
        Height = 17
        Caption = 'Original date'
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
    Height = 672
    ControlFirst = JvPanel4
    Align = alRight
    ExplicitHeight = 597
  end
  object JvPanel5: TJvPanel
    Left = 108
    Top = 44
    Width = 809
    Height = 672
    Align = alClient
    TabOrder = 8
    ExplicitHeight = 597
    object JvPanel6: TJvPanel
      Left = 1
      Top = 544
      Width = 807
      Height = 127
      Align = alBottom
      TabOrder = 0
      object JvCheckBox9: TJvCheckBox
        Left = 29
        Top = 6
        Width = 77
        Height = 17
        Caption = 'Show path'
        TabOrder = 0
        OnClick = JvCheckBox9Click
        LinkedControls = <>
      end
      object DateTemplateEdit: TJvEdit
        Left = 152
        Top = 6
        Width = 121
        Height = 23
        TabOrder = 1
        Text = 'DateTemplateEdit'
        OnChange = DateTemplateEditChange
      end
      object JvEdit2: TJvEdit
        Left = 320
        Top = 6
        Width = 121
        Height = 23
        TabOrder = 2
        Text = 'JvEdit2'
      end
      object FormattedDateEdit: TJvEdit
        Left = 152
        Top = 35
        Width = 121
        Height = 23
        TabOrder = 3
        Text = 'FormattedDateEdit'
      end
      object JvEdit4: TJvEdit
        Left = 320
        Top = 35
        Width = 121
        Height = 23
        TabOrder = 4
        Text = 'JvEdit4'
      end
    end
    object JvPanel7: TJvPanel
      Left = 1
      Top = 1
      Width = 807
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
        Width = 72
        Height = 15
        Caption = 'Date created :'
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
        Width = 73
        Height = 15
        Caption = 'Date opened :'
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
        Left = 614
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
      Width = 807
      Height = 3
      ControlFirst = JvPanel7
      Align = alTop
    end
    object JvxSplitter6: TJvxSplitter
      Left = 1
      Top = 541
      Width = 807
      Height = 3
      ControlFirst = JvPanel6
      Align = alBottom
      ExplicitTop = 537
    end
    object JvPanel8: TJvPanel
      Left = 1
      Top = 180
      Width = 807
      Height = 361
      Align = alClient
      TabOrder = 4
      ExplicitHeight = 357
      object JvListView1: TJvListView
        Left = 1
        Top = 1
        Width = 805
        Height = 359
        Align = alClient
        Checkboxes = True
        Columns = <
          item
            Caption = 'Name'
            Width = 200
          end
          item
            Caption = 'New name'
            Width = 200
          end
          item
            Caption = 'Path'
            Width = 0
          end
          item
            Alignment = taCenter
            Caption = 'Size'
            Width = 60
          end
          item
            Alignment = taCenter
            Caption = 'Date create'
            Width = 120
          end
          item
            Alignment = taCenter
            Caption = 'New date create'
            Width = 0
          end
          item
            Alignment = taCenter
            Caption = 'Date modified'
            Width = 120
          end
          item
            Alignment = taCenter
            Caption = 'New date modified'
            Width = 0
          end
          item
            Alignment = taCenter
            Caption = 'Date open'
            Width = 120
          end
          item
            Alignment = taCenter
            Caption = 'New date open'
            Width = 0
          end
          item
            Alignment = taCenter
            Caption = 'Date original'
            Width = 120
          end
          item
            Alignment = taCenter
            Caption = 'New date original'
            Width = 0
          end
          item
            Alignment = taCenter
            Caption = 'Attribute'
            Width = 60
          end
          item
            Alignment = taCenter
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
        PopupMenu = JvPopupMenu1
        ShowHint = True
        TabOrder = 0
        ViewStyle = vsReport
        OnCustomDrawItem = JvListView1CustomDrawItem
        OnCustomDrawSubItem = JvListView1CustomDrawSubItem
        OnSelectItem = JvListView1SelectItem
        ColumnsOrder = 
          '0=200,1=200,2=0,3=60,4=120,5=0,6=120,7=0,8=120,9=0,10=120,11=0,1' +
          '2=60,13=0'
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
        ExplicitHeight = 355
      end
    end
  end
  object JvDragDrop1: TJvDragDrop
    DropTarget = JvListView1
    OnDrop = JvDragDrop1Drop
    Left = 40
    Top = 324
  end
  object JvBrowseForFolderDialog1: TJvBrowseForFolderDialog
    Left = 40
    Top = 188
  end
  object JvOpenDialog1: TJvOpenDialog
    Height = 0
    Width = 0
    Left = 40
    Top = 260
  end
  object JvTimer1: TJvTimer
    OnTimer = JvTimer1Timer
    Left = 40
    Top = 124
  end
  object JvPopupMenu1: TJvPopupMenu
    ImageMargin.Left = 0
    ImageMargin.Top = 0
    ImageMargin.Right = 0
    ImageMargin.Bottom = 0
    ImageSize.Height = 0
    ImageSize.Width = 0
    Left = 45
    Top = 400
    object N15: TMenuItem
      Caption = 'Mark'
      object Mark_Selected_: TMenuItem
        Caption = 'Mark selected'
        OnClick = Mark_Selected_Click
      end
      object Unmark_Selected_: TMenuItem
        Caption = 'Unmark selected'
        OnClick = Unmark_Selected_Click
      end
      object Mark_All_: TMenuItem
        Caption = 'Mark all'
        OnClick = Mark_All_Click
      end
      object Unmark_All_: TMenuItem
        Caption = 'Unmark all'
        OnClick = Unmark_All_Click
      end
      object Invert_Marked_: TMenuItem
        Caption = 'Invert marked'
        OnClick = Invert_Marked_Click
      end
    end
    object N5: TMenuItem
      Caption = '-'
      GroupIndex = 1
    end
    object N14: TMenuItem
      Caption = 'Select'
      GroupIndex = 1
      object Select_All_: TMenuItem
        Caption = 'Select all'
        OnClick = Select_All_Click
      end
      object Deselect_All_: TMenuItem
        Caption = 'Deselect all'
        OnClick = Deselect_All_Click
      end
      object Invert_Selection_: TMenuItem
        Caption = ' Invert selection'
        OnClick = Invert_Selection_Click
      end
    end
    object N4: TMenuItem
      Caption = '-'
      GroupIndex = 1
    end
    object N22: TMenuItem
      Caption = 'Actions'
      GroupIndex = 1
      object Filename_To_Date_: TMenuItem
        Caption = 'Filename to date'
        OnClick = Filename_To_Date_Click
      end
      object N24: TMenuItem
        Caption = 'Date to filename'
      end
      object N25: TMenuItem
        Caption = 'Attributes'
      end
      object N26: TMenuItem
        Caption = 'Custom date'
      end
    end
    object N3: TMenuItem
      Caption = '-'
      GroupIndex = 1
    end
    object Insert_: TMenuItem
      Caption = 'Insert'
      GroupIndex = 1
      ShortCut = 45
      OnClick = Insert_Click
    end
    object Delete_: TMenuItem
      Caption = 'Delete'
      GroupIndex = 1
      ShortCut = 46
      OnClick = Delete_Click
    end
    object Delete_All_: TMenuItem
      Caption = 'Delete all'
      GroupIndex = 1
      ShortCut = 8238
      OnClick = Delete_All_Click
    end
    object N21: TMenuItem
      Caption = '-'
      GroupIndex = 1
    end
    object Open_With_: TMenuItem
      Caption = 'Open with...'
      GroupIndex = 1
      OnClick = Open_With_Click
    end
    object Properties_: TMenuItem
      Caption = 'Properties'
      GroupIndex = 1
      OnClick = Properties_Click
    end
    object Open_File_Location_: TMenuItem
      Caption = 'Open file location'
      GroupIndex = 1
      OnClick = Open_File_Location_Click
    end
    object N30: TMenuItem
      Caption = '-'
      GroupIndex = 1
    end
    object N33: TMenuItem
      Caption = 'Show columns'
      GroupIndex = 1
      object N37: TMenuItem
        Caption = 'Name'
      end
      object N36: TMenuItem
        Caption = 'Path'
      end
      object N38: TMenuItem
        Caption = 'Size'
      end
      object N39: TMenuItem
        Caption = 'Date creation'
      end
      object Datemodified1: TMenuItem
        Caption = 'Date modified'
      end
      object Dateopened1: TMenuItem
        Caption = 'Date opened'
      end
      object Dateoriginal1: TMenuItem
        Caption = 'Date original'
      end
      object Attribute1: TMenuItem
        Caption = 'Attribute'
      end
    end
    object N34: TMenuItem
      Caption = '-'
      GroupIndex = 1
    end
    object Refresh_: TMenuItem
      Caption = 'Refresh'
      GroupIndex = 1
      ShortCut = 116
      OnClick = Refresh_Click
    end
  end
end
