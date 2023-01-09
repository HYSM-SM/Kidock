source createlib.sh

snake="Snake/SnakeMap/SnakeMap.cpp Snake/Snake/Snake.cpp Snake/Fruits/Fruits.cpp Snake/Fruits/Apple.cpp Snake/Fruits/Banan.cpp Snake/Fruits/Orange.cpp Snake/SnakeMenu/SnakeMenu.cpp"
race="Race/RaceMap/RaceMap.cpp Race/RaceMenu/RaceMenu.cpp Race/Car/Car.cpp Race/Car/Player.cpp Race/Car/Enemy.cpp"
tanks="Tanks/TanksMap/TanksMap.cpp Tanks/Tank/Tank.cpp Tanks/TanksMenu/TanksMenu.cpp Tanks/Projectile/Projectile.cpp"

g++ -std=c++17 -L. -I. -o kidock main.cpp $snake $race $tanks  -lSnake -lRace -lTanks -lGames -lpthread

rm libGames.a libRace.a libSnake.a libTanks.a
