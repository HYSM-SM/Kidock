source createlib.sh
g++ -DSINGLEPLAYER -std=c++17 -L. -I.  -o tanks main.cpp TanksMenu/TanksMenu.cpp TanksMap/TanksMap.cpp Projectile/Projectile.cpp Tank/Tank.cpp -lTanks -lGames -lpthread

rm libGames.a libTanks.a
