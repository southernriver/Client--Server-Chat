TEMPLATE=app
SOURCES=chatServer.cpp \
		ServerWindow.cpp \
		ChatException.cpp \
		ServerSocket.cpp   \
		ThAccept.cpp        \
		ThClient.cpp
		
HEADERS=ServerWindow.h \
	ChatException.h  \
	ServerSocket.h     \
	ThAccept.h           \
	ThClient.h
CONFIG=release qt
QT=widgets
TARGET=server
