cd lib
source createlib.sh
cp libGames.a ./../
cd ./../

g++ -std=c++17 -c Race/SpeedManager/SpeedManager.cpp Race/RaceStatement/RaceStatement.cpp Race/TrackOwner/TrackOwner.cpp Race/Action/Action.cpp Race/Timer/Timer.cpp Race/RaceWorld/RaceWorld.cpp
ar rc libRace.a SpeedManager.o RaceStatement.o TrackOwner.o Action.o Timer.o RaceWorld.o
rm SpeedManager.o RaceStatement.o TrackOwner.o Action.o Timer.o RaceWorld.o

g++ -std=c++17 -c Snake/SnakeStatement/SnakeStatement.cpp Snake/SnakeScore/SnakeScore.cpp Snake/SnakeWorld/SnakeWorld.cpp
ar rc libSnake.a SnakeStatement.o SnakeScore.o SnakeWorld.o
rm SnakeStatement.o SnakeScore.o SnakeWorld.o

g++ -std=c++17 -c Tanks/Ai/Ai.cpp Tanks/PeacesNation/PeacesNation.cpp Tanks/TanksScore/TanksScore.cpp Tanks/TanksStatement/TanksStatement.cpp Tanks/TanksWorld/TanksWorld.cpp
ar rc libTanks.a Ai.o PeacesNation.o TanksScore.o TanksStatement.o TanksWorld.o
rm Ai.o PeacesNation.o TanksScore.o TanksStatement.o TanksWorld.o
