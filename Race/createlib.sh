cd ./../lib/
source createlib.sh
cp libGames.a ./../Race/
cd ./../Race/

g++ -std=c++17 -c SpeedManager/SpeedManager.cpp RaceStatement/RaceStatement.cpp TrackOwner/TrackOwner.cpp Action/Action.cpp Timer/Timer.cpp RaceWorld/RaceWorld.cpp
ar rc libRace.a SpeedManager.o RaceStatement.o TrackOwner.o Action.o Timer.o RaceWorld.o
rm SpeedManager.o RaceStatement.o TrackOwner.o Action.o Timer.o RaceWorld.o
