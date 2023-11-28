#QT_CFLAGS="$(/usr/bin/qmake -query QT_CFLAGS)"
#QT_LIBS="$(/usr/bin/qmake -query QT_LIBS)"

#echo QT_CFLAGS
#echo QT_LIBS

#g++ -o Simpledit main.cpp Engine/action.cpp MainWin.cpp -g $(pkg-config gtkmm-3.0 --cflags --libs) -I/usr/include/mpv -lmpv "$QT_CFLAGS" "$QT_LIBS"
#rm -f *.o
g++ -o Simpledit main.cpp Engine/action.cpp MainWin.cpp -g $(pkg-config gtkmm-3.0 --cflags --libs) 
./Simpledit
