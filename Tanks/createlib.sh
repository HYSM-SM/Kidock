cd ./../lib/
source createlib.sh
cp libGames.a ./../Tanks/
cd ./../Tanks

g++ -std=c++17 -c Ai/Ai.cpp PeacesNation/PeacesNation.cpp TanksScore/TanksScore.cpp TanksStatement/TanksStatement.cpp TanksWorld/TanksWorld.cpp
ar rc libTanks.a Ai.o PeacesNation.o TanksScore.o TanksStatement.o TanksWorld.o
rm Ai.o PeacesNation.o TanksScore.o TanksStatement.o TanksWorld.o
