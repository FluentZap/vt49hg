##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=VT49
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/Toad/Documents/VT49
ProjectPath            :=C:/Users/Toad/Documents/VT49/VT49
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Toad
Date                   :=29/01/2018
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="VT49.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer -lopengl32 -lglu32
IncludePath            := $(IncludeSwitch)C:\Users\Toad\Documents\SDL2\SDL2Base\x86_64-w64-mingw32\include $(IncludeSwitch)C:\Users\Toad\Documents\SDL2\glew\include  $(IncludeSwitch)C:\Users\Toad\Documents\SDL2\SDL2Base\x86_64-w64-mingw32\include\SDL2 $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                :=$(LibraryPathSwitch)C:\Users\Toad\Documents\SDL2\SDL2Base\x86_64-w64-mingw32\lib $(LibraryPathSwitch)C:\Users\Toad\Documents\SDL2\glew\lib\Release\Win32  $(LibraryPathSwitch). $(LibraryPathSwitch)C:\Users\Toad\Documents\SDL2\SDL2Base\x86_64-w64-mingw32\lib $(LibraryPathSwitch)C:\Users\Toad\Documents\SDL2\SDL2Extra\x86_64-w64-mingw32\lib $(LibraryPathSwitch)C:\Users\Toad\Documents\SDL2\glew\lib\Release\Win32 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -std=c++14 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/VTStart.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/VTStart.cpp$(ObjectSuffix): VTStart.cpp $(IntermediateDirectory)/VTStart.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Toad/Documents/VT49/VT49/VTStart.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/VTStart.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/VTStart.cpp$(DependSuffix): VTStart.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/VTStart.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/VTStart.cpp$(DependSuffix) -MM VTStart.cpp

$(IntermediateDirectory)/VTStart.cpp$(PreprocessSuffix): VTStart.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/VTStart.cpp$(PreprocessSuffix) VTStart.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


