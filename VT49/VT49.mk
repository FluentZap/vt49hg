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
Date                   :=31/03/2019
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
IncludePath            :=  $(IncludeSwitch)C:\Users\Toad\Documents\SDL2\SDL2Base\x86_64-w64-mingw32\include\SDL2 $(IncludeSwitch)C:\Users\Toad\Documents\VT49\VT49\q3 $(IncludeSwitch)C:\Users\Toad\Documents\VT49\VT49 $(IncludeSwitch)C:\Users\Toad\Documents\VT49\bullet3-2.88\src $(IncludeSwitch)C:\Users\Toad\Documents\VT49\bullet3-2.88\Extras\Serialize\BulletWorldImporter $(IncludeSwitch)C:\Users\Toad\Documents\VT49\bullet3-2.88\src\Bullet3Serialize\Bullet2FileLoader $(IncludeSwitch)C:\Users\Toad\Documents\VT49\bullet3-2.88\src\BulletCollision\CollisionDispatch 
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
Objects0=$(IntermediateDirectory)/DiceRoller.cpp$(ObjectSuffix) $(IntermediateDirectory)/VTNetwork.cpp$(ObjectSuffix) $(IntermediateDirectory)/VTStart.cpp$(ObjectSuffix) $(IntermediateDirectory)/tinyxml2.cpp$(ObjectSuffix) $(IntermediateDirectory)/VTSerialPhraser.cpp$(ObjectSuffix) $(IntermediateDirectory)/SDL_FontCache.c$(ObjectSuffix) $(IntermediateDirectory)/SWSimulation.cpp$(ObjectSuffix) $(IntermediateDirectory)/PanelData.cpp$(ObjectSuffix) $(IntermediateDirectory)/VTMap.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/DiceRoller.cpp$(ObjectSuffix): DiceRoller.cpp $(IntermediateDirectory)/DiceRoller.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Toad/Documents/VT49/VT49/DiceRoller.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/DiceRoller.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DiceRoller.cpp$(DependSuffix): DiceRoller.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DiceRoller.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/DiceRoller.cpp$(DependSuffix) -MM DiceRoller.cpp

$(IntermediateDirectory)/DiceRoller.cpp$(PreprocessSuffix): DiceRoller.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DiceRoller.cpp$(PreprocessSuffix) DiceRoller.cpp

$(IntermediateDirectory)/VTNetwork.cpp$(ObjectSuffix): VTNetwork.cpp $(IntermediateDirectory)/VTNetwork.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Toad/Documents/VT49/VT49/VTNetwork.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/VTNetwork.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/VTNetwork.cpp$(DependSuffix): VTNetwork.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/VTNetwork.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/VTNetwork.cpp$(DependSuffix) -MM VTNetwork.cpp

$(IntermediateDirectory)/VTNetwork.cpp$(PreprocessSuffix): VTNetwork.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/VTNetwork.cpp$(PreprocessSuffix) VTNetwork.cpp

$(IntermediateDirectory)/VTStart.cpp$(ObjectSuffix): VTStart.cpp $(IntermediateDirectory)/VTStart.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Toad/Documents/VT49/VT49/VTStart.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/VTStart.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/VTStart.cpp$(DependSuffix): VTStart.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/VTStart.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/VTStart.cpp$(DependSuffix) -MM VTStart.cpp

$(IntermediateDirectory)/VTStart.cpp$(PreprocessSuffix): VTStart.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/VTStart.cpp$(PreprocessSuffix) VTStart.cpp

$(IntermediateDirectory)/tinyxml2.cpp$(ObjectSuffix): tinyxml2.cpp $(IntermediateDirectory)/tinyxml2.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Toad/Documents/VT49/VT49/tinyxml2.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tinyxml2.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tinyxml2.cpp$(DependSuffix): tinyxml2.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tinyxml2.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/tinyxml2.cpp$(DependSuffix) -MM tinyxml2.cpp

$(IntermediateDirectory)/tinyxml2.cpp$(PreprocessSuffix): tinyxml2.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tinyxml2.cpp$(PreprocessSuffix) tinyxml2.cpp

$(IntermediateDirectory)/VTSerialPhraser.cpp$(ObjectSuffix): VTSerialPhraser.cpp $(IntermediateDirectory)/VTSerialPhraser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Toad/Documents/VT49/VT49/VTSerialPhraser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/VTSerialPhraser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/VTSerialPhraser.cpp$(DependSuffix): VTSerialPhraser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/VTSerialPhraser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/VTSerialPhraser.cpp$(DependSuffix) -MM VTSerialPhraser.cpp

$(IntermediateDirectory)/VTSerialPhraser.cpp$(PreprocessSuffix): VTSerialPhraser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/VTSerialPhraser.cpp$(PreprocessSuffix) VTSerialPhraser.cpp

$(IntermediateDirectory)/SDL_FontCache.c$(ObjectSuffix): SDL_FontCache.c $(IntermediateDirectory)/SDL_FontCache.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Toad/Documents/VT49/VT49/SDL_FontCache.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SDL_FontCache.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SDL_FontCache.c$(DependSuffix): SDL_FontCache.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SDL_FontCache.c$(ObjectSuffix) -MF$(IntermediateDirectory)/SDL_FontCache.c$(DependSuffix) -MM SDL_FontCache.c

$(IntermediateDirectory)/SDL_FontCache.c$(PreprocessSuffix): SDL_FontCache.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SDL_FontCache.c$(PreprocessSuffix) SDL_FontCache.c

$(IntermediateDirectory)/SWSimulation.cpp$(ObjectSuffix): SWSimulation.cpp $(IntermediateDirectory)/SWSimulation.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Toad/Documents/VT49/VT49/SWSimulation.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SWSimulation.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SWSimulation.cpp$(DependSuffix): SWSimulation.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SWSimulation.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SWSimulation.cpp$(DependSuffix) -MM SWSimulation.cpp

$(IntermediateDirectory)/SWSimulation.cpp$(PreprocessSuffix): SWSimulation.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SWSimulation.cpp$(PreprocessSuffix) SWSimulation.cpp

$(IntermediateDirectory)/PanelData.cpp$(ObjectSuffix): PanelData.cpp $(IntermediateDirectory)/PanelData.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Toad/Documents/VT49/VT49/PanelData.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PanelData.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PanelData.cpp$(DependSuffix): PanelData.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/PanelData.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/PanelData.cpp$(DependSuffix) -MM PanelData.cpp

$(IntermediateDirectory)/PanelData.cpp$(PreprocessSuffix): PanelData.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PanelData.cpp$(PreprocessSuffix) PanelData.cpp

$(IntermediateDirectory)/VTMap.cpp$(ObjectSuffix): VTMap.cpp $(IntermediateDirectory)/VTMap.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Toad/Documents/VT49/VT49/VTMap.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/VTMap.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/VTMap.cpp$(DependSuffix): VTMap.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/VTMap.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/VTMap.cpp$(DependSuffix) -MM VTMap.cpp

$(IntermediateDirectory)/VTMap.cpp$(PreprocessSuffix): VTMap.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/VTMap.cpp$(PreprocessSuffix) VTMap.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


