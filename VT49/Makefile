#OBJS specifies which files to compile as part of the project
OBJS = src/VTStart.cpp src/VTNetwork.cpp

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer -lserial

#OBJ_NAME specifies the name of our executable
OBJ_NAME = VT49

INC = -IC:\Users\Toad\Documents\SDL2\SDL2Base\x86_64-w64-mingw32\include\SDL2 ./include

LIB = -L/usr/local/lib -Wl,-rpath,/usr/local/lib -Wl,--enable-new-dtags -lSDL2

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(INC) $(LIB) $(LINKER_FLAGS) -o $(OBJ_NAME)
