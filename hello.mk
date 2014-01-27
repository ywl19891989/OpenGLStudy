
<<<<<<< HEAD
LIBS:=-lopengl32 -lglu32 -lglut32 -lglut32win -lwinmm -gdi32
=======
LIBS:=-lopengl32 -lglu32 -lglut32 -lglut32 -lwinmm -gdi32
>>>>>>> 006a7307419ab8cf57ff410435cc4f1e99c6fe01

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
