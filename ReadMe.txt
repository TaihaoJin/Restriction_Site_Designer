========================================================================
       MICROSOFT FOUNDATION CLASS LIBRARY : DNA Analysis
========================================================================


AppWizard has created this DNA Analysis application for you.  This application
not only demonstrates the basics of using the Microsoft Foundation classes
but is also a starting point for writing your application.

This file contains a summary of what you will find in each of the files that
make up your DNA Analysis application.

DNA Analysis.dsp
    This file (the project file) contains information at the project level and
    is used to build a single project or subproject. Other users can share the
    project (.dsp) file, but they should export the makefiles locally.

DNA Analysis.h
    This is the main header file for the application.  It includes other
    project specific headers (including Resource.h) and declares the
    CDNAAnalysisApp application class.

DNA Analysis.cpp
    This is the main application source file that contains the application
    class CDNAAnalysisApp.

DNA Analysis.rc
    This is a listing of all of the Microsoft Windows resources that the
    program uses.  It includes the icons, bitmaps, and cursors that are stored
    in the RES subdirectory.  This file can be directly edited in Microsoft
	Visual C++.

DNA Analysis.clw
    This file contains information used by ClassWizard to edit existing
    classes or add new classes.  ClassWizard also uses this file to store
    information needed to create and edit message maps and dialog data
    maps and to create prototype member functions.

res\DNA Analysis.ico
    This is an icon file, which is used as the application's icon.  This
    icon is included by the main resource file DNA Analysis.rc.

res\DNA Analysis.rc2
    This file contains resources that are not edited by Microsoft 
	Visual C++.  You should place all resources not editable by
	the resource editor in this file.



/////////////////////////////////////////////////////////////////////////////

For the main frame window:

MainFrm.h, MainFrm.cpp
    These files contain the frame class CMainFrame, which is derived from
    CMDIFrameWnd and controls all MDI frame features.

res\Toolbar.bmp
    This bitmap file is used to create tiled images for the toolbar.
    The initial toolbar and status bar are constructed in the CMainFrame
    class. Edit this toolbar bitmap using the resource editor, and
    update the IDR_MAINFRAME TOOLBAR array in DNA Analysis.rc to add
    toolbar buttons.
/////////////////////////////////////////////////////////////////////////////

For the child frame window:

ChildFrm.h, ChildFrm.cpp
    These files define and implement the CChildFrame class, which
    supports the child windows in an MDI application.

/////////////////////////////////////////////////////////////////////////////

AppWizard creates one document type and one view:

DNA AnalysisDoc.h, DNA AnalysisDoc.cpp - the document
    These files contain your CDNAAnalysisDoc class.  Edit these files to
    add your special document data and to implement file saving and loading
    (via CDNAAnalysisDoc::Serialize).

DNA AnalysisView.h, DNA AnalysisView.cpp - the view of the document
    These files contain your CDNAAnalysisView class.
    CDNAAnalysisView objects are used to view CDNAAnalysisDoc objects.

res\DNA AnalysisDoc.ico
    This is an icon file, which is used as the icon for MDI child windows
    for the CDNAAnalysisDoc class.  This icon is included by the main
    resource file DNA Analysis.rc.


/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named DNA Analysis.pch and a precompiled types file named StdAfx.obj.

Resource.h
    This is the standard header file, which defines new resource IDs.
    Microsoft Visual C++ reads and updates this file.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" to indicate parts of the source code you
should add to or customize.

If your application uses MFC in a shared DLL, and your application is 
in a language other than the operating system's current language, you
will need to copy the corresponding localized resources MFC42XXX.DLL
from the Microsoft Visual C++ CD-ROM onto the system or system32 directory,
and rename it to be MFCLOC.DLL.  ("XXX" stands for the language abbreviation.
For example, MFC42DEU.DLL contains resources translated to German.)  If you
don't do this, some of the UI elements of your application will remain in the
language of the operating system.

/////////////////////////////////////////////////////////////////////////////
