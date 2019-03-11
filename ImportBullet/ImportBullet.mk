##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=ImportBullet
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/Toad/Documents/VT49
ProjectPath            :=C:/Users/Toad/Documents/VT49/ImportBullet
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
ObjectsFileList        :="ImportBullet.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch)C:\Users\Toad\Documents\SDL2\SDL2Base\x86_64-w64-mingw32\include\SDL2 $(IncludeSwitch)C:\Users\Toad\Documents\VT49\VT49\q3 $(IncludeSwitch)C:\Users\Toad\Documents\VT49\ $(IncludeSwitch)C:\Users\Toad\Documents\VT49\VT49 $(IncludeSwitch)C:\Users\Toad\Documents\VT49\bullet3-2.88\src $(IncludeSwitch)C:\Users\Toad\Documents\VT49\bullet3-2.88\Extras\Serialize\BulletWorldImporter $(IncludeSwitch)C:\Users\Toad\Documents\VT49\bullet3-2.88\examples $(IncludeSwitch)C:\Users\Toad\Documents\VT49\bullet3-2.88\examples\CommonInterfaces $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)mingw32 $(LibrarySwitch)Bullet3 
ArLibs                 :=  "mingw32" "Bullet3" 
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
Objects0=$(IntermediateDirectory)/up_bullet3-2.88_examples_Importers_ImportBullet_SerializeSetup.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/up_bullet3-2.88_examples_Importers_ImportBullet_SerializeSetup.cpp$(ObjectSuffix): ../bullet3-2.88/examples/Importers/ImportBullet/SerializeSetup.cpp $(IntermediateDirectory)/up_bullet3-2.88_examples_Importers_ImportBullet_SerializeSetup.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Toad/Documents/VT49/bullet3-2.88/examples/Importers/ImportBullet/SerializeSetup.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_bullet3-2.88_examples_Importers_ImportBullet_SerializeSetup.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_bullet3-2.88_examples_Importers_ImportBullet_SerializeSetup.cpp$(DependSuffix): ../bullet3-2.88/examples/Importers/ImportBullet/SerializeSetup.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_bullet3-2.88_examples_Importers_ImportBullet_SerializeSetup.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_bullet3-2.88_examples_Importers_ImportBullet_SerializeSetup.cpp$(DependSuffix) -MM ../bullet3-2.88/examples/Importers/ImportBullet/SerializeSetup.cpp

$(IntermediateDirectory)/up_bullet3-2.88_examples_Importers_ImportBullet_SerializeSetup.cpp$(PreprocessSuffix): ../bullet3-2.88/examples/Importers/ImportBullet/SerializeSetup.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_bullet3-2.88_examples_Importers_ImportBullet_SerializeSetup.cpp$(PreprocessSuffix) ../bullet3-2.88/examples/Importers/ImportBullet/SerializeSetup.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


