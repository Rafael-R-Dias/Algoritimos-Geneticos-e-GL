CXX = g++

TARGET = genvis.out

CXXFLAGS = -std=c++23 -g -DGL_SILENCE_DEPRECATION -Wno-write-strings -Wno-narrowing -Wno-stringop-overflow \
			#-O1 -funroll-loops

LIBS = -lGL -lGLU -lglut -lm

SRC = Main.cpp Temporizador.cpp Vertice.cpp FormaGeometrica2D.cpp Circulo.cpp Utilities.cpp Estado.cpp

OBJ = $(SRC:.cpp=.o)

all = $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ) $(LIBS)

%.o: %.cpp Main.hpp Temporizador.hpp Vertice.hpp FormaGeometrica2D.hpp Circulo.hpp Utilities.hpp Estado.hpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET)