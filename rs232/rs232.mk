##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=rs232
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/Toad/Documents/VT49
ProjectPath            :=C:/Users/Toad/Documents/VT49/rs232
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Toad
Date                   :=19/02/2018
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
OutputFile             :=$(IntermediateDirectory)/lib$(ProjectName).a
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="rs232.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            := $(IncludeSwitch)C:\Users\Toad\Documents\SDL2\SDL2Base\x86_64-w64-mingw32\include $(IncludeSwitch)C:\Users\Toad\Documents\SDL2\glew\include  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                :=$(LibraryPathSwitch)C:\Users\Toad\Documents\SDL2\SDL2Base\x86_64-w64-mingw32\lib $(LibraryPathSwitch)C:\Users\Toad\Documents\SDL2\glew\lib\Release\Win32  $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/up_up_up_Desktop_rs232-master_rs232_win.cc$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(IntermediateDirectory) $(OutputFile)

$(OutputFile): $(Objects)
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(AR) $(ArchiveOutputSwitch)$(OutputFile) @$(ObjectsFileList) $(ArLibs)
	@$(MakeDirCommand) "C:\Users\Toad\Documents\VT49/.build-debug"
	@echo rebuilt > "C:\Users\Toad\Documents\VT49/.build-debug/rs232"

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


./Debug:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/up_up_up_Desktop_rs232-master_rs232_win.cc$(ObjectSuffix): ../../../Desktop/rs232-master/rs232_win.cc $(IntermediateDirectory)/up_up_up_Desktop_rs232-master_rs232_win.cc$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Toad/Desktop/rs232-master/rs232_win.cc" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_up_Desktop_rs232-master_rs232_win.cc$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_up_Desktop_rs232-master_rs232_win.cc$(DependSuffix): ../../../Desktop/rs232-master/rs232_win.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_up_Desktop_rs232-master_rs232_win.cc$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_up_Desktop_rs232-master_rs232_win.cc$(DependSuffix) -MM ../../../Desktop/rs232-master/rs232_win.cc

$(IntermediateDirectory)/up_up_up_Desktop_rs232-master_rs232_win.cc$(PreprocessSuffix): ../../../Desktop/rs232-master/rs232_win.cc
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_up_Desktop_rs232-master_rs232_win.cc$(PreprocessSuffix) ../../../Desktop/rs232-master/rs232_win.cc


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


