
LIBS:=-lopengl32 -lglu32 -lglut32 -lglut32 -lwinmm -gdi32

TargetDir:=./Debug
OBJSDir:=$(TargetDir)/src
SRCDir:=./src

CXX:=g++

hello : hello.o
	$(CXX) -g -o $(TargetDir)/hello.exe $(OBJSDir)/hello.o $(LIBS)

hello.o : $(SRCDir)/hello.c
	$(CXX) -c $(SRCDir)/hello.c -o $(OBJSDir)/hello.o
		
clean : 
	rm $(TargetDir)/hello.exe $(OBJSDir)/hello.o
