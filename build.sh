g++ -o Simpledit main.cpp Engine/action.cpp MainWin.h   MainWin.cpp -g $(pkg-config gtkmm-3.0 --cflags --libs)
./Simpledit
