g++ -std=c++17 -c Cursor.cpp GameInfo.cpp GameSettings.cpp GameRecords.cpp KeyBoard.cpp Menu.cpp MainMenu.cpp Painter.cpp
ar rc libGames.a Cursor.o GameInfo.o GameSettings.o GameRecords.o KeyBoard.o Menu.o MainMenu.o Painter.o
rm Cursor.o GameInfo.o GameSettings.o GameRecords.o KeyBoard.o Menu.o MainMenu.o Painter.o
