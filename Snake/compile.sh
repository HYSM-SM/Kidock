source createlib.sh
g++ -DSINGLEPLAYER -std=c++17 -L. -I. -o snake main.cpp Fruits/Fruits.cpp Fruits/Apple.cpp Fruits/Banan.cpp Fruits/Orange.cpp SnakeMenu/SnakeMenu.cpp SnakeMap/SnakeMap.cpp Snake/Snake.cpp -lpthread -lSnake -lGames

rm libGames.a libSnake.a
