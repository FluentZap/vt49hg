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
Date                   :=02/07/2019
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
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch)C:\Users\Toad\Documents\SDL2\SDL2Base\x86_64-w64-mingw32\include\SDL2 $(IncludeSwitch)C:\Users\Toad\Documents\VT49\VT49\q3 $(IncludeSwitch)C:\Users\Toad\Documents\VT49\VT49 $(IncludeSwitch)C:\Users\Toad\Documents\VT49\bullet3-2.88\src $(IncludeSwitch)C:\Users\Toad\Documents\VT49\bullet3-2.88\Extras\Serialize\BulletWorldImporter $(IncludeSwitch)C:\Users\Toad\Documents\VT49\bullet3-2.88\src\Bullet3Serialize\Bullet2FileLoader $(IncludeSwitch)C:\Users\Toad\Documents\VT49\bullet3-2.88\src\BulletCollision\CollisionDispatch $(IncludeSwitch)C:\Users\Toad\Documents\VT49\VT49\include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)mingw32 $(LibrarySwitch)SDL2main $(LibrarySwitch)SDL2 $(LibrarySwitch)SDL2_net $(LibrarySwitch)SDL2_ttf $(LibrarySwitch)SDL2_image $(LibrarySwitch)SDL2_mixer $(LibrarySwitch)serial $(LibrarySwitch)Bullet3 
ArLibs                 :=  "mingw32" "SDL2main" "SDL2" "SDL2_net" "SDL2_ttf" "SDL2_image" "SDL2_mixer" "serial" "Bullet3" 
LibPath                := $(LibraryPathSwitch)C:\Users\Toad\Documents\SDL2\SDL2Base\x86_64-w64-mingw32\lib $(LibraryPathSwitch)C:\Users\Toad\Documents\SDL2\SDL2Extra\x86_64-w64-mingw32\lib $(LibraryPathSwitch)C:\Users\Toad\Documents\VT49\VT49\lib $(LibraryPathSwitch)C:\Users\Toad\Documents\VT49\Bullet3\Release 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -std=c++17 -std=c++14 -std=c++11 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/src_DiceRoller.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_PanelData.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_VTRender.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_SDL_FontCache.c$(ObjectSuffix) $(IntermediateDirectory)/src_VTNetwork.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_SWSimulation.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_VTSerialParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_VTMap.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_VTStart.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_tinyxml2.cpp$(ObjectSuffix) \
	



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
$(IntermediateDirectory)/src_DiceRoller.cpp$(ObjectSuffix): src/DiceRoller.cpp $(IntermediateDirectory)/src_DiceRoller.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Toad/Documents/VT49/VT49/src/DiceRoller.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_DiceRoller.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_DiceRoller.cpp$(DependSuffix): src/DiceRoller.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_DiceRoller.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_DiceRoller.cpp$(DependSuffix) -MM src/DiceRoller.cpp

$(IntermediateDirectory)/src_DiceRoller.cpp$(PreprocessSuffix): src/DiceRoller.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_DiceRoller.cpp$(PreprocessSuffix) src/DiceRoller.cpp

$(IntermediateDirectory)/src_PanelData.cpp$(ObjectSuffix): src/PanelData.cpp $(IntermediateDirectory)/src_PanelData.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Toad/Documents/VT49/VT49/src/PanelData.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_PanelData.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_PanelData.cpp$(DependSuffix): src/PanelData.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_PanelData.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_PanelData.cpp$(DependSuffix) -MM src/PanelData.cpp

$(IntermediateDirectory)/src_PanelData.cpp$(PreprocessSuffix): src/PanelData.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_PanelData.cpp$(PreprocessSuffix) src/PanelData.cpp

$(IntermediateDirectory)/src_VTRender.cpp$(ObjectSuffix): src/VTRender.cpp $(IntermediateDirectory)/src_VTRender.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Toad/Documents/VT49/VT49/src/VTRender.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_VTRender.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_VTRender.cpp$(DependSuffix): src/VTRender.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_VTRender.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_VTRender.cpp$(DependSuffix) -MM src/VTRender.cpp

$(IntermediateDirectory)/src_VTRender.cpp$(PreprocessSuffix): src/VTRender.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_VTRender.cpp$(PreprocessSuffix) src/VTRender.cpp

$(IntermediateDirectory)/src_SDL_FontCache.c$(ObjectSuffix): src/SDL_FontCache.c $(IntermediateDirectory)/src_SDL_FontCache.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Toad/Documents/VT49/VT49/src/SDL_FontCache.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_SDL_FontCache.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_SDL_FontCache.c$(DependSuffix): src/SDL_FontCache.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_SDL_FontCache.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_SDL_FontCache.c$(DependSuffix) -MM src/SDL_FontCache.c

$(IntermediateDirectory)/src_SDL_FontCache.c$(PreprocessSuffix): src/SDL_FontCache.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_SDL_FontCache.c$(PreprocessSuffix) src/SDL_FontCache.c

$(IntermediateDirectory)/src_VTNetwork.cpp$(ObjectSuffix): src/VTNetwork.cpp $(IntermediateDirectory)/src_VTNetwork.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Toad/Documents/VT49/VT49/src/VTNetwork.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_VTNetwork.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_VTNetwork.cpp$(DependSuffix): src/VTNetwork.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_VTNetwork.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_VTNetwork.cpp$(DependSuffix) -MM src/VTNetwork.cpp

$(IntermediateDirectory)/src_VTNetwork.cpp$(PreprocessSuffix): src/VTNetwork.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_VTNetwork.cpp$(PreprocessSuffix) src/VTNetwork.cpp

$(IntermediateDirectory)/src_SWSimulation.cpp$(ObjectSuffix): src/SWSimulation.cpp $(IntermediateDirectory)/src_SWSimulation.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Toad/Documents/VT49/VT49/src/SWSimulation.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_SWSimulation.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_SWSimulation.cpp$(DependSuffix): src/SWSimulation.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_SWSimulation.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_SWSimulation.cpp$(DependSuffix) -MM src/SWSimulation.cpp

$(IntermediateDirectory)/src_SWSimulation.cpp$(PreprocessSuffix): src/SWSimulation.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_SWSimulation.cpp$(PreprocessSuffix) src/SWSimulation.cpp

$(IntermediateDirectory)/src_VTSerialParser.cpp$(ObjectSuffix): src/VTSerialParser.cpp $(IntermediateDirectory)/src_VTSerialParser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Toad/Documents/VT49/VT49/src/VTSerialParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_VTSerialParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_VTSerialParser.cpp$(DependSuffix): src/VTSerialParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_VTSerialParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_VTSerialParser.cpp$(DependSuffix) -MM src/VTSerialParser.cpp

$(IntermediateDirectory)/src_VTSerialParser.cpp$(PreprocessSuffix): src/VTSerialParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_VTSerialParser.cpp$(PreprocessSuffix) src/VTSerialParser.cpp

$(IntermediateDirectory)/src_VTMap.cpp$(ObjectSuffix): src/VTMap.cpp $(IntermediateDirectory)/src_VTMap.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Toad/Documents/VT49/VT49/src/VTMap.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_VTMap.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_VTMap.cpp$(DependSuffix): src/VTMap.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_VTMap.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_VTMap.cpp$(DependSuffix) -MM src/VTMap.cpp

$(IntermediateDirectory)/src_VTMap.cpp$(PreprocessSuffix): src/VTMap.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_VTMap.cpp$(PreprocessSuffix) src/VTMap.cpp

$(IntermediateDirectory)/src_VTStart.cpp$(ObjectSuffix): src/VTStart.cpp $(IntermediateDirectory)/src_VTStart.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Toad/Documents/VT49/VT49/src/VTStart.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_VTStart.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_VTStart.cpp$(DependSuffix): src/VTStart.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_VTStart.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_VTStart.cpp$(DependSuffix) -MM src/VTStart.cpp

$(IntermediateDirectory)/src_VTStart.cpp$(PreprocessSuffix): src/VTStart.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_VTStart.cpp$(PreprocessSuffix) src/VTStart.cpp

$(IntermediateDirectory)/src_tinyxml2.cpp$(ObjectSuffix): src/tinyxml2.cpp $(IntermediateDirectory)/src_tinyxml2.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Toad/Documents/VT49/VT49/src/tinyxml2.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_tinyxml2.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_tinyxml2.cpp$(DependSuffix): src/tinyxml2.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_tinyxml2.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_tinyxml2.cpp$(DependSuffix) -MM src/tinyxml2.cpp

$(IntermediateDirectory)/src_tinyxml2.cpp$(PreprocessSuffix): src/tinyxml2.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_tinyxml2.cpp$(PreprocessSuffix) src/tinyxml2.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


