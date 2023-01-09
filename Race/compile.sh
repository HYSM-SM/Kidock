source createlib.sh
g++ -DSINGLEPLAYER -std=c++17 -L. -I. -o race main.cpp Car/Car.cpp Car/Player.cpp Car/Enemy.cpp RaceMenu/RaceMenu.cpp RaceMap/RaceMap.cpp -lpthread -lRace -lGames

rm libGames.a libRace.a
