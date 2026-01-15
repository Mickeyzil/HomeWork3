CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

TARGET = battleship

SRCS = main.cpp \
       Game.cpp \
       Player.cpp \
       HumanPlayer.cpp \
       AiPlayer.cpp \
       Grid.cpp \
       Ship.cpp \
       Carrier.cpp \
       Battleship.cpp \
       Cruiser.cpp \
       Submarine.cpp \
       Destroyer.cpp

OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

rebuild: clean $(TARGET)
