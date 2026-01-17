
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic \
           -IGame -IGrid -IPlayers -IShips

TARGET = battleship

SRCS = main.cpp \
       Game/Game.cpp \
       Grid/Grid.cpp \
       Players/Player.cpp Players/HumanPlayer.cpp Players/AiPlayer.cpp \
       Ships/Ship.cpp Ships/Carrier.cpp Ships/Battleship.cpp \
       Ships/Cruiser.cpp Ships/Submarine.cpp Ships/Destroyer.cpp

OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

rebuild: clean $(TARGET)
