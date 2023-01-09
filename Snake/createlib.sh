cd ./../lib/
source createlib.sh
cp libGames.a ./../Snake/
cd ./../Snake/

g++ -std=c++17 -c SnakeStatement/SnakeStatement.cpp SnakeScore/SnakeScore.cpp SnakeWorld/SnakeWorld.cpp
ar rc libSnake.a SnakeStatement.o SnakeScore.o SnakeWorld.o
rm SnakeStatement.o SnakeScore.o SnakeWorld.o
