QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../Libs/libqrencode/bitstream.c \
    ../Libs/libqrencode/mask.c \
    ../Libs/libqrencode/mmask.c \
    ../Libs/libqrencode/mqrspec.c \
    ../Libs/libqrencode/qrenc.c \
    ../Libs/libqrencode/qrencode.c \
    ../Libs/libqrencode/qrinput.c \
    ../Libs/libqrencode/qrspec.c \
    ../Libs/libqrencode/rsecc.c \
    ../Libs/libqrencode/split.c \
    ../Libs/libqrencode/tests/common.c \
    ../Libs/libqrencode/tests/create_frame_pattern.c \
    ../Libs/libqrencode/tests/create_mqr_frame_pattern.c \
    ../Libs/libqrencode/tests/datachunk.c \
    ../Libs/libqrencode/tests/decoder.c \
    ../Libs/libqrencode/tests/prof_qrencode.c \
    ../Libs/libqrencode/tests/pthread_qrencode.c \
    ../Libs/libqrencode/tests/rscode.c \
    ../Libs/libqrencode/tests/rsecc_decoder.c \
    ../Libs/libqrencode/tests/test_bitstream.c \
    ../Libs/libqrencode/tests/test_estimatebit.c \
    ../Libs/libqrencode/tests/test_mask.c \
    ../Libs/libqrencode/tests/test_mmask.c \
    ../Libs/libqrencode/tests/test_monkey.c \
    ../Libs/libqrencode/tests/test_mqrspec.c \
    ../Libs/libqrencode/tests/test_qrencode.c \
    ../Libs/libqrencode/tests/test_qrinput.c \
    ../Libs/libqrencode/tests/test_qrspec.c \
    ../Libs/libqrencode/tests/test_rs.c \
    ../Libs/libqrencode/tests/test_split.c \
    ../Libs/libqrencode/tests/test_split_urls.c \
    ../Libs/libqrencode/tests/view_qrcode.c \
    main.cpp \
    mainwindow.cpp \
    unit_test.cpp

HEADERS += \
    ../Libs/libqrencode/bitstream.h \
    ../Libs/libqrencode/mask.h \
    ../Libs/libqrencode/mmask.h \
    ../Libs/libqrencode/mqrspec.h \
    ../Libs/libqrencode/qrencode.h \
    ../Libs/libqrencode/qrencode_inner.h \
    ../Libs/libqrencode/qrinput.h \
    ../Libs/libqrencode/qrspec.h \
    ../Libs/libqrencode/rsecc.h \
    ../Libs/libqrencode/split.h \
    ../Libs/libqrencode/tests/common.h \
    ../Libs/libqrencode/tests/datachunk.h \
    ../Libs/libqrencode/tests/decoder.h \
    ../Libs/libqrencode/tests/rscode.h \
    ../Libs/libqrencode/tests/rsecc_decoder.h \
    cryptograph.h \
    mainwindow.h \
    unit_test.h
    LIBS += -libqrencode
TRANSLATIONS += \
       my.ts
FORMS += \
    mainwindow.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
win32: RC_ICONS = $$PWD/icon.ico
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qqw.qrc
    Picture1.png

DISTFILES += \
    ../Libs/libqrencode/.github/workflows/cmake-windows.yml \
    ../Libs/libqrencode/.github/workflows/cmake.yml \
    ../Libs/libqrencode/.github/workflows/configure.yml \
    ../Libs/libqrencode/.gitignore \
    ../Libs/libqrencode/.travis.yml \
    ../Libs/libqrencode/CMakeLists.txt \
    ../Libs/libqrencode/COPYING \
    ../Libs/libqrencode/ChangeLog \
    ../Libs/libqrencode/Doxyfile \
    ../Libs/libqrencode/NEWS \
    ../Libs/libqrencode/README.md \
    ../Libs/libqrencode/TODO \
    ../Libs/libqrencode/acinclude.m4 \
    ../Libs/libqrencode/autogen.sh \
    ../Libs/libqrencode/cmake/FindIconv.cmake \
    ../Libs/libqrencode/configure.ac \
    ../Libs/libqrencode/libqrencode.pc.in \
    ../Libs/libqrencode/makeREADME.sh \
    ../Libs/libqrencode/qrencode.1.in \
    ../Libs/libqrencode/tests/CMakeLists.txt \
    ../Libs/libqrencode/tests/URI_testset.inc \
    ../Libs/libqrencode/tests/frame \
    ../Libs/libqrencode/tests/test_all.sh \
    ../Libs/libqrencode/tests/test_basic.sh \
    ../Libs/libqrencode/tests/test_configure.sh \
    ../Libs/libqrencode/tests/test_qrenc.sh \
    ../Libs/libqrencode/use/config.rpath
