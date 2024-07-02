QT += widgets

HEADERS       = shapedclock.h
SOURCES       = shapedclock.cpp \
                main.cpp \
    size.cpp \
    dial.cpp \
    hand.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/widgets/shapedclock
INSTALLS += target
