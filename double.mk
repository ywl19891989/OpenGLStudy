
LIBS:=-lopengl32 -lglu32 -lglut32 -lglut32win -lwinmm -gdi32

Target:=double
TargetDir:=./Debug
OBJSDir:=$(TargetDir)/src
SRCDir:=./src

CXX:=g++

$(Target) : $(Target).o
	$(CXX) -g -o $(TargetDir)/$(Target).exe $(OBJSDir)/$(Target).o $(LIBS)

$(Target).o : $(SRCDir)/$(Target).c
	$(CXX) -c $(SRCDir)/$(Target).c -o $(OBJSDir)/$(Target).o
		
clean : 
	rm $(TargetDir)/$(Target).exe $(OBJSDir)/$(Target).o
