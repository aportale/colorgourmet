HEADERS += \
    color.h \
    colormodel.h \
    colortransformation.h \
    colorsource.h \
    colorsourceui.h \
    analogous.h \
    analogousui.h \
    analogouscommands.h \
    complementary.h \
    mixture.h \
    mixtureui.h \
    mixturecommands.h \
    colortransformationnode.h \
    colortransformationnodeui.h \
    mainwindow.h \
    actionstoolbar.h \
    undocommand.h \
    undostack.h

SOURCES += \
    color.cpp \
    colormodel.cpp \
    colortransformation.cpp \
    colorsource.cpp \
    colorsourceui.cpp \
    analogous.cpp \
    analogousui.cpp \
    analogouscommands.cpp \
    complementary.cpp \
    mixture.cpp \
    mixtureui.cpp \
    mixturecommands.cpp \
    colortransformationnode.cpp \
    colortransformationnodeui.cpp \
    mainwindow.cpp \
    actionstoolbar.cpp \
    undocommand.cpp \
    undostack.cpp \
    main.cpp

FORMS += \
    colorsource.ui \
    analogous.ui \
    mixture.ui \
    colortransformationnode.ui

RESOURCES += \
    resources.qrc
    
macx:CONFIG += \
    x86 ppc

macx:QMAKE_MAC_SDK = /Developer/SDKs/MacOSX10.4u.sdk
