##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=ImportOBJ
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/Toad/Documents/VT49
ProjectPath            :=C:/Users/Toad/Documents/VT49/ImportOBJ
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Toad
Date                   :=09/03/2019
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
ObjectsFileList        :="ImportOBJ.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch)C:\Users\Toad\Documents\SDL2\SDL2Base\x86_64-w64-mingw32\include\SDL2 $(IncludeSwitch)C:\Users\Toad\Documents\VT49\VT49\q3 $(IncludeSwitch)C:\Users\Toad\Documents\VT49\ $(IncludeSwitch)C:\Users\Toad\Documents\VT49\VT49 $(IncludeSwitch)C:\Users\Toad\Documents\VT49\bullet3-2.88\src $(IncludeSwitch)C:\Users\Toad\Documents\VT49\bullet3-2.88\Extras\Serialize\BulletWorldImporter $(IncludeSwitch). 
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
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/up_bullet3-2.88_examples_Importers_ImportObjDemo_Wavefront2GLInstanceGraphicsShape.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_bullet3-2.88_examples_Importers_ImportObjDemo_LoadMeshFromObj.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_bullet3-2.88_examples_Importers_ImportObjDemo_ImportObjExample.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/up_bullet3-2.88_examples_Importers_ImportObjDemo_Wavefront2GLInstanceGraphicsShape.cpp$(ObjectSuffix): ../bullet3-2.88/examples/Importers/ImportObjDemo/Wavefront2GLInstanceGraphicsShape.cpp $(IntermediateDirectory)/up_bullet3-2.88_examples_Importers_ImportObjDemo_Wavefront2GLInstanceGraphicsShape.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Toad/Documents/VT49/bullet3-2.88/examples/Importers/ImportObjDemo/Wavefront2GLInstanceGraphicsShape.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_bullet3-2.88_examples_Importers_ImportObjDemo_Wavefront2GLInstanceGraphicsShape.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_bullet3-2.88_examples_Importers_ImportObjDemo_Wavefront2GLInstanceGraphicsShape.cpp$(DependSuffix): ../bullet3-2.88/examples/Importers/ImportObjDemo/Wavefront2GLInstanceGraphicsShape.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_bullet3-2.88_examples_Importers_ImportObjDemo_Wavefront2GLInstanceGraphicsShape.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_bullet3-2.88_examples_Importers_ImportObjDemo_Wavefront2GLInstanceGraphicsShape.cpp$(DependSuffix) -MM ../bullet3-2.88/examples/Importers/ImportObjDemo/Wavefront2GLInstanceGraphicsShape.cpp

$(IntermediateDirectory)/up_bullet3-2.88_examples_Importers_ImportObjDemo_Wavefront2GLInstanceGraphicsShape.cpp$(PreprocessSuffix): ../bullet3-2.88/examples/Importers/ImportObjDemo/Wavefront2GLInstanceGraphicsShape.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_bullet3-2.88_examples_Importers_ImportObjDemo_Wavefront2GLInstanceGraphicsShape.cpp$(PreprocessSuffix) ../bullet3-2.88/examples/Importers/ImportObjDemo/Wavefront2GLInstanceGraphicsShape.cpp

$(IntermediateDirectory)/up_bullet3-2.88_examples_Importers_ImportObjDemo_LoadMeshFromObj.cpp$(ObjectSuffix): ../bullet3-2.88/examples/Importers/ImportObjDemo/LoadMeshFromObj.cpp $(IntermediateDirectory)/up_bullet3-2.88_examples_Importers_ImportObjDemo_LoadMeshFromObj.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Toad/Documents/VT49/bullet3-2.88/examples/Importers/ImportObjDemo/LoadMeshFromObj.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_bullet3-2.88_examples_Importers_ImportObjDemo_LoadMeshFromObj.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_bullet3-2.88_examples_Importers_ImportObjDemo_LoadMeshFromObj.cpp$(DependSuffix): ../bullet3-2.88/examples/Importers/ImportObjDemo/LoadMeshFromObj.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_bullet3-2.88_examples_Importers_ImportObjDemo_LoadMeshFromObj.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_bullet3-2.88_examples_Importers_ImportObjDemo_LoadMeshFromObj.cpp$(DependSuffix) -MM ../bullet3-2.88/examples/Importers/ImportObjDemo/LoadMeshFromObj.cpp

$(IntermediateDirectory)/up_bullet3-2.88_examples_Importers_ImportObjDemo_LoadMeshFromObj.cpp$(PreprocessSuffix): ../bullet3-2.88/examples/Importers/ImportObjDemo/LoadMeshFromObj.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_bullet3-2.88_examples_Importers_ImportObjDemo_LoadMeshFromObj.cpp$(PreprocessSuffix) ../bullet3-2.88/examples/Importers/ImportObjDemo/LoadMeshFromObj.cpp

$(IntermediateDirectory)/up_bullet3-2.88_examples_Importers_ImportObjDemo_ImportObjExample.cpp$(ObjectSuffix): ../bullet3-2.88/examples/Importers/ImportObjDemo/ImportObjExample.cpp $(IntermediateDirectory)/up_bullet3-2.88_examples_Importers_ImportObjDemo_ImportObjExample.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Toad/Documents/VT49/bullet3-2.88/examples/Importers/ImportObjDemo/ImportObjExample.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_bullet3-2.88_examples_Importers_ImportObjDemo_ImportObjExample.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_bullet3-2.88_examples_Importers_ImportObjDemo_ImportObjExample.cpp$(DependSuffix): ../bullet3-2.88/examples/Importers/ImportObjDemo/ImportObjExample.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_bullet3-2.88_examples_Importers_ImportObjDemo_ImportObjExample.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_bullet3-2.88_examples_Importers_ImportObjDemo_ImportObjExample.cpp$(DependSuffix) -MM ../bullet3-2.88/examples/Importers/ImportObjDemo/ImportObjExample.cpp

$(IntermediateDirectory)/up_bullet3-2.88_examples_Importers_ImportObjDemo_ImportObjExample.cpp$(PreprocessSuffix): ../bullet3-2.88/examples/Importers/ImportObjDemo/ImportObjExample.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_bullet3-2.88_examples_Importers_ImportObjDemo_ImportObjExample.cpp$(PreprocessSuffix) ../bullet3-2.88/examples/Importers/ImportObjDemo/ImportObjExample.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


