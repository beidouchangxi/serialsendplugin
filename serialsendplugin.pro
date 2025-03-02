# include global settings for all DLT Viewer Plugins
include( ../plugin.pri )

# Put intermediate files in the build directory
MOC_DIR     = build/moc
OBJECTS_DIR = build/obj
RCC_DIR     = build/rcc
UI_DIR      = build/ui

# target name
TARGET = $$qtLibraryTarget(serialsendplugin)

# plugin header files
HEADERS += \
    myqcombobox.h \
    serialsendplugin.h \
    form.h

# plugin source files
SOURCES += \
    myqcombobox.cpp \
    serialsendplugin.cpp \
    form.cpp

# plugin forms
FORMS += \
    form.ui
