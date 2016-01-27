; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPointMutationPrimerDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DNA Analysis.h"
LastPage=0

ClassCount=7
Class1=CDNAAnalysisApp
Class2=CDNAAnalysisDoc
Class3=CDNAAnalysisView
Class4=CMainFrame

ResourceCount=5
Resource1=IDR_MAINFRAME
Resource2=IDD_PointMutationPrimers
Class5=CChildFrame
Class6=CAboutDlg
Resource3=IDR_DNAANATYPE
Class7=CPointMutationPrimerDlg
Resource4=IDD_ABOUTBOX
Resource5=IDD_DIALOG1

[CLS:CDNAAnalysisApp]
Type=0
HeaderFile=DNA Analysis.h
ImplementationFile=DNA Analysis.cpp
Filter=N

[CLS:CDNAAnalysisDoc]
Type=0
HeaderFile=DNA AnalysisDoc.h
ImplementationFile=DNA AnalysisDoc.cpp
Filter=N

[CLS:CDNAAnalysisView]
Type=0
HeaderFile=DNA AnalysisView.h
ImplementationFile=DNA AnalysisView.cpp
Filter=C
LastObject=ID_ANALYSIS_DNA_CODONUAGE
BaseClass=CEditView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T


[CLS:CChildFrame]
Type=0
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp
Filter=M


[CLS:CAboutDlg]
Type=0
HeaderFile=DNA Analysis.cpp
ImplementationFile=DNA Analysis.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_PRINT_SETUP
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
Command8=ID_APP_ABOUT
CommandCount=8

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_DNAANATYPE]
Type=1
Class=CDNAAnalysisView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_IMPORT_DNASEQUENCE
Command7=ID_FILE_EXPORT_DNASEQUENCE
Command8=ID_FILE_EXPORT_PROTEINSEQUENCE
Command9=ID_FILE_PRINT
Command10=ID_FILE_PRINT_PREVIEW
Command11=ID_FILE_PRINT_SETUP
Command12=ID_FILE_MRU_FILE1
Command13=ID_APP_EXIT
Command14=ID_ANALYSIS_DNA_RESTRICTIONSITES
Command15=ID_ANALYSIS_DNA_TRANSLATE
Command16=ID_ANALYSIS_DNA_PRIMERS_POINTMUTATION
Command17=ID_ANALYSIS_DNA_CODONUAGE
Command18=ID_EDIT_UNDO
Command19=ID_EDIT_CUT
Command20=ID_EDIT_COPY
Command21=ID_EDIT_PASTE
Command22=ID_VIEW_TOOLBAR
Command23=ID_VIEW_STATUS_BAR
Command24=ID_WINDOW_NEW
Command25=ID_WINDOW_CASCADE
Command26=ID_WINDOW_TILE_HORZ
Command27=ID_WINDOW_ARRANGE
Command28=ID_APP_ABOUT
CommandCount=28

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_PointMutationPrimers]
Type=1
Class=CPointMutationPrimerDlg
ControlCount=16
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT2,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT3,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT4,edit,1350631552
Control10=IDC_EDIT5,edit,1350631552
Control11=IDC_EDIT6,edit,1350631552
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_MinBaseChange,button,1342177289
Control16=IDC_CodonUsage,button,1342177289

[CLS:CPointMutationPrimerDlg]
Type=0
HeaderFile=PointMutationPrimerDlg.h
ImplementationFile=PointMutationPrimerDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_CodonUsage

[DLG:IDD_DIALOG1]
Type=1
Class=?
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

