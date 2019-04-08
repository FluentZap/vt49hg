##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=serial
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/Toad/Documents/VT49
ProjectPath            :=C:/Users/Toad/Documents/VT49/serial
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Toad
Date                   :=07/04/2019
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
ObjectsFileList        :="serial.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch)C:\Users\Toad\Documents\VT49\VT49 $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

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
Objects0=$(IntermediateDirectory)/up_up_up_Desktop_wjwwood-serial-1.2.1-29-g5a354ea_wjwwood-serial-5a354ea_src_impl_win.cc$(ObjectSuffix) $(IntermediateDirectory)/up_VT49_serial.cc$(ObjectSuffix) $(IntermediateDirectory)/up_up_up_Desktop_wjwwood-serial-1.2.1-29-g5a354ea_wjwwood-serial-5a354ea_src_impl_list_ports_list_ports_win.cc$(ObjectSuffix) 



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
	@echo rebuilt > "C:\Users\Toad\Documents\VT49/.build-debug/serial"

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


./Debug:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/up_up_up_Desktop_wjwwood-serial-1.2.1-29-g5a354ea_wjwwood-serial-5a354ea_src_impl_win.cc$(ObjectSuffix): ../../../Desktop/wjwwood-serial-1.2.1-29-g5a354ea/wjwwood-serial-5a354ea/src/impl/win.cc $(IntermediateDirectory)/up_up_up_Desktop_wjwwood-serial-1.2.1-29-g5a354ea_wjwwood-serial-5a354ea_src_impl_win.cc$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Toad/Desktop/wjwwood-serial-1.2.1-29-g5a354ea/wjwwood-serial-5a354ea/src/impl/win.cc" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_up_Desktop_wjwwood-serial-1.2.1-29-g5a354ea_wjwwood-serial-5a354ea_src_impl_win.cc$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_up_Desktop_wjwwood-serial-1.2.1-29-g5a354ea_wjwwood-serial-5a354ea_src_impl_win.cc$(DependSuffix): ../../../Desktop/wjwwood-serial-1.2.1-29-g5a354ea/wjwwood-serial-5a354ea/src/impl/win.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_up_Desktop_wjwwood-serial-1.2.1-29-g5a354ea_wjwwood-serial-5a354ea_src_impl_win.cc$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_up_Desktop_wjwwood-serial-1.2.1-29-g5a354ea_wjwwood-serial-5a354ea_src_impl_win.cc$(DependSuffix) -MM ../../../Desktop/wjwwood-serial-1.2.1-29-g5a354ea/wjwwood-serial-5a354ea/src/impl/win.cc

$(IntermediateDirectory)/up_up_up_Desktop_wjwwood-serial-1.2.1-29-g5a354ea_wjwwood-serial-5a354ea_src_impl_win.cc$(PreprocessSuffix): ../../../Desktop/wjwwood-serial-1.2.1-29-g5a354ea/wjwwood-serial-5a354ea/src/impl/win.cc
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_up_Desktop_wjwwood-serial-1.2.1-29-g5a354ea_wjwwood-serial-5a354ea_src_impl_win.cc$(PreprocessSuffix) ../../../Desktop/wjwwood-serial-1.2.1-29-g5a354ea/wjwwood-serial-5a354ea/src/impl/win.cc

$(IntermediateDirectory)/up_VT49_serial.cc$(ObjectSuffix): ../VT49/serial.cc $(IntermediateDirectory)/up_VT49_serial.cc$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Toad/Documents/VT49/VT49/serial.cc" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_VT49_serial.cc$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_VT49_serial.cc$(DependSuffix): ../VT49/serial.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_VT49_serial.cc$(ObjectSuffix) -MF$(IntermediateDirectory)/up_VT49_serial.cc$(DependSuffix) -MM ../VT49/serial.cc

$(IntermediateDirectory)/up_VT49_serial.cc$(PreprocessSuffix): ../VT49/serial.cc
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_VT49_serial.cc$(PreprocessSuffix) ../VT49/serial.cc

$(IntermediateDirectory)/up_up_up_Desktop_wjwwood-serial-1.2.1-29-g5a354ea_wjwwood-serial-5a354ea_src_impl_list_ports_list_ports_win.cc$(ObjectSuffix): ../../../Desktop/wjwwood-serial-1.2.1-29-g5a354ea/wjwwood-serial-5a354ea/src/impl/list_ports/list_ports_win.cc $(IntermediateDirectory)/up_up_up_Desktop_wjwwood-serial-1.2.1-29-g5a354ea_wjwwood-serial-5a354ea_src_impl_list_ports_list_ports_win.cc$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Toad/Desktop/wjwwood-serial-1.2.1-29-g5a354ea/wjwwood-serial-5a354ea/src/impl/list_ports/list_ports_win.cc" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_up_Desktop_wjwwood-serial-1.2.1-29-g5a354ea_wjwwood-serial-5a354ea_src_impl_list_ports_list_ports_win.cc$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_up_Desktop_wjwwood-serial-1.2.1-29-g5a354ea_wjwwood-serial-5a354ea_src_impl_list_ports_list_ports_win.cc$(DependSuffix): ../../../Desktop/wjwwood-serial-1.2.1-29-g5a354ea/wjwwood-serial-5a354ea/src/impl/list_ports/list_ports_win.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_up_Desktop_wjwwood-serial-1.2.1-29-g5a354ea_wjwwood-serial-5a354ea_src_impl_list_ports_list_ports_win.cc$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_up_Desktop_wjwwood-serial-1.2.1-29-g5a354ea_wjwwood-serial-5a354ea_src_impl_list_ports_list_ports_win.cc$(DependSuffix) -MM ../../../Desktop/wjwwood-serial-1.2.1-29-g5a354ea/wjwwood-serial-5a354ea/src/impl/list_ports/list_ports_win.cc

$(IntermediateDirectory)/up_up_up_Desktop_wjwwood-serial-1.2.1-29-g5a354ea_wjwwood-serial-5a354ea_src_impl_list_ports_list_ports_win.cc$(PreprocessSuffix): ../../../Desktop/wjwwood-serial-1.2.1-29-g5a354ea/wjwwood-serial-5a354ea/src/impl/list_ports/list_ports_win.cc
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_up_Desktop_wjwwood-serial-1.2.1-29-g5a354ea_wjwwood-serial-5a354ea_src_impl_list_ports_list_ports_win.cc$(PreprocessSuffix) ../../../Desktop/wjwwood-serial-1.2.1-29-g5a354ea/wjwwood-serial-5a354ea/src/impl/list_ports/list_ports_win.cc


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


