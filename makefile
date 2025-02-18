CXX = g++

CXXFLAGS = -Wall -g

TARGET = shiftSplitter

TARGET_DEL = shiftSplitter.exe

#source files
SRCS = shiftSplitter.cpp shifter.cpp

OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	$(TARGET)

clean:
	del $(TARGET_DEL) $(OBJS)
