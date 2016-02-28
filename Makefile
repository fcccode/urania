# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.3

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Produce verbose output by default.
VERBOSE = 1

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake.exe

# The command to remove a file.
RM = /usr/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/strawberry/acy/develop2/urania

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/strawberry/acy/develop2/urania

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake.exe -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components

.PHONY : list_install_components/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake.exe -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake.exe -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake.exe -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: install/local

.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake.exe -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: install/strip

.PHONY : install/strip/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake.exe -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/strawberry/acy/develop2/urania/CMakeFiles /home/strawberry/acy/develop2/urania/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/strawberry/acy/develop2/urania/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named urania

# Build rule for target.
urania: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 urania
.PHONY : urania

# fast build rule for target.
urania/fast:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/build
.PHONY : urania/fast

bwin.o: bwin.cpp.o

.PHONY : bwin.o

# target to build an object file
bwin.cpp.o:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/bwin.cpp.o
.PHONY : bwin.cpp.o

bwin.i: bwin.cpp.i

.PHONY : bwin.i

# target to preprocess a source file
bwin.cpp.i:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/bwin.cpp.i
.PHONY : bwin.cpp.i

bwin.s: bwin.cpp.s

.PHONY : bwin.s

# target to generate assembly for a file
bwin.cpp.s:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/bwin.cpp.s
.PHONY : bwin.cpp.s

clkpanel.o: clkpanel.cpp.o

.PHONY : clkpanel.o

# target to build an object file
clkpanel.cpp.o:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/clkpanel.cpp.o
.PHONY : clkpanel.cpp.o

clkpanel.i: clkpanel.cpp.i

.PHONY : clkpanel.i

# target to preprocess a source file
clkpanel.cpp.i:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/clkpanel.cpp.i
.PHONY : clkpanel.cpp.i

clkpanel.s: clkpanel.cpp.s

.PHONY : clkpanel.s

# target to generate assembly for a file
clkpanel.cpp.s:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/clkpanel.cpp.s
.PHONY : clkpanel.cpp.s

cmndlg.o: cmndlg.cpp.o

.PHONY : cmndlg.o

# target to build an object file
cmndlg.cpp.o:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/cmndlg.cpp.o
.PHONY : cmndlg.cpp.o

cmndlg.i: cmndlg.cpp.i

.PHONY : cmndlg.i

# target to preprocess a source file
cmndlg.cpp.i:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/cmndlg.cpp.i
.PHONY : cmndlg.cpp.i

cmndlg.s: cmndlg.cpp.s

.PHONY : cmndlg.s

# target to generate assembly for a file
cmndlg.cpp.s:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/cmndlg.cpp.s
.PHONY : cmndlg.cpp.s

ctrl.o: ctrl.cpp.o

.PHONY : ctrl.o

# target to build an object file
ctrl.cpp.o:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/ctrl.cpp.o
.PHONY : ctrl.cpp.o

ctrl.i: ctrl.cpp.i

.PHONY : ctrl.i

# target to preprocess a source file
ctrl.cpp.i:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/ctrl.cpp.i
.PHONY : ctrl.cpp.i

ctrl.s: ctrl.cpp.s

.PHONY : ctrl.s

# target to generate assembly for a file
ctrl.cpp.s:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/ctrl.cpp.s
.PHONY : ctrl.cpp.s

ctrl_sb.o: ctrl_sb.cpp.o

.PHONY : ctrl_sb.o

# target to build an object file
ctrl_sb.cpp.o:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/ctrl_sb.cpp.o
.PHONY : ctrl_sb.cpp.o

ctrl_sb.i: ctrl_sb.cpp.i

.PHONY : ctrl_sb.i

# target to preprocess a source file
ctrl_sb.cpp.i:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/ctrl_sb.cpp.i
.PHONY : ctrl_sb.cpp.i

ctrl_sb.s: ctrl_sb.cpp.s

.PHONY : ctrl_sb.s

# target to generate assembly for a file
ctrl_sb.cpp.s:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/ctrl_sb.cpp.s
.PHONY : ctrl_sb.cpp.s

dialog.o: dialog.cpp.o

.PHONY : dialog.o

# target to build an object file
dialog.cpp.o:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/dialog.cpp.o
.PHONY : dialog.cpp.o

dialog.i: dialog.cpp.i

.PHONY : dialog.i

# target to preprocess a source file
dialog.cpp.i:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/dialog.cpp.i
.PHONY : dialog.cpp.i

dialog.s: dialog.cpp.s

.PHONY : dialog.s

# target to generate assembly for a file
dialog.cpp.s:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/dialog.cpp.s
.PHONY : dialog.cpp.s

drop-h.o: drop-h.cpp.o

.PHONY : drop-h.o

# target to build an object file
drop-h.cpp.o:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/drop-h.cpp.o
.PHONY : drop-h.cpp.o

drop-h.i: drop-h.cpp.i

.PHONY : drop-h.i

# target to preprocess a source file
drop-h.cpp.i:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/drop-h.cpp.i
.PHONY : drop-h.cpp.i

drop-h.s: drop-h.cpp.s

.PHONY : drop-h.s

# target to generate assembly for a file
drop-h.cpp.s:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/drop-h.cpp.s
.PHONY : drop-h.cpp.s

getCLArgs.o: getCLArgs.cpp.o

.PHONY : getCLArgs.o

# target to build an object file
getCLArgs.cpp.o:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/getCLArgs.cpp.o
.PHONY : getCLArgs.cpp.o

getCLArgs.i: getCLArgs.cpp.i

.PHONY : getCLArgs.i

# target to preprocess a source file
getCLArgs.cpp.i:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/getCLArgs.cpp.i
.PHONY : getCLArgs.cpp.i

getCLArgs.s: getCLArgs.cpp.s

.PHONY : getCLArgs.s

# target to generate assembly for a file
getCLArgs.cpp.s:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/getCLArgs.cpp.s
.PHONY : getCLArgs.cpp.s

getCLArgsW.o: getCLArgsW.cpp.o

.PHONY : getCLArgsW.o

# target to build an object file
getCLArgsW.cpp.o:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/getCLArgsW.cpp.o
.PHONY : getCLArgsW.cpp.o

getCLArgsW.i: getCLArgsW.cpp.i

.PHONY : getCLArgsW.i

# target to preprocess a source file
getCLArgsW.cpp.i:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/getCLArgsW.cpp.i
.PHONY : getCLArgsW.cpp.i

getCLArgsW.s: getCLArgsW.cpp.s

.PHONY : getCLArgsW.s

# target to generate assembly for a file
getCLArgsW.cpp.s:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/getCLArgsW.cpp.s
.PHONY : getCLArgsW.cpp.s

getLongPath.o: getLongPath.cpp.o

.PHONY : getLongPath.o

# target to build an object file
getLongPath.cpp.o:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/getLongPath.cpp.o
.PHONY : getLongPath.cpp.o

getLongPath.i: getLongPath.cpp.i

.PHONY : getLongPath.i

# target to preprocess a source file
getLongPath.cpp.i:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/getLongPath.cpp.i
.PHONY : getLongPath.cpp.i

getLongPath.s: getLongPath.cpp.s

.PHONY : getLongPath.s

# target to generate assembly for a file
getLongPath.cpp.s:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/getLongPath.cpp.s
.PHONY : getLongPath.cpp.s

menu.o: menu.cpp.o

.PHONY : menu.o

# target to build an object file
menu.cpp.o:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/menu.cpp.o
.PHONY : menu.cpp.o

menu.i: menu.cpp.i

.PHONY : menu.i

# target to preprocess a source file
menu.cpp.i:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/menu.cpp.i
.PHONY : menu.cpp.i

menu.s: menu.cpp.s

.PHONY : menu.s

# target to generate assembly for a file
menu.cpp.s:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/menu.cpp.s
.PHONY : menu.cpp.s

menudesc.o: menudesc.cpp.o

.PHONY : menudesc.o

# target to build an object file
menudesc.cpp.o:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/menudesc.cpp.o
.PHONY : menudesc.cpp.o

menudesc.i: menudesc.cpp.i

.PHONY : menudesc.i

# target to preprocess a source file
menudesc.cpp.i:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/menudesc.cpp.i
.PHONY : menudesc.cpp.i

menudesc.s: menudesc.cpp.s

.PHONY : menudesc.s

# target to generate assembly for a file
menudesc.cpp.s:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/menudesc.cpp.s
.PHONY : menudesc.cpp.s

msgloop.o: msgloop.cpp.o

.PHONY : msgloop.o

# target to build an object file
msgloop.cpp.o:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/msgloop.cpp.o
.PHONY : msgloop.cpp.o

msgloop.i: msgloop.cpp.i

.PHONY : msgloop.i

# target to preprocess a source file
msgloop.cpp.i:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/msgloop.cpp.i
.PHONY : msgloop.cpp.i

msgloop.s: msgloop.cpp.s

.PHONY : msgloop.s

# target to generate assembly for a file
msgloop.cpp.s:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/msgloop.cpp.s
.PHONY : msgloop.cpp.s

pdev.o: pdev.cpp.o

.PHONY : pdev.o

# target to build an object file
pdev.cpp.o:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/pdev.cpp.o
.PHONY : pdev.cpp.o

pdev.i: pdev.cpp.i

.PHONY : pdev.i

# target to preprocess a source file
pdev.cpp.i:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/pdev.cpp.i
.PHONY : pdev.cpp.i

pdev.s: pdev.cpp.s

.PHONY : pdev.s

# target to generate assembly for a file
pdev.cpp.s:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/pdev.cpp.s
.PHONY : pdev.cpp.s

pdev2.o: pdev2.cpp.o

.PHONY : pdev2.o

# target to build an object file
pdev2.cpp.o:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/pdev2.cpp.o
.PHONY : pdev2.cpp.o

pdev2.i: pdev2.cpp.i

.PHONY : pdev2.i

# target to preprocess a source file
pdev2.cpp.i:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/pdev2.cpp.i
.PHONY : pdev2.cpp.i

pdev2.s: pdev2.cpp.s

.PHONY : pdev2.s

# target to generate assembly for a file
pdev2.cpp.s:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/pdev2.cpp.s
.PHONY : pdev2.cpp.s

pmdev.o: pmdev.cpp.o

.PHONY : pmdev.o

# target to build an object file
pmdev.cpp.o:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/pmdev.cpp.o
.PHONY : pmdev.cpp.o

pmdev.i: pmdev.cpp.i

.PHONY : pmdev.i

# target to preprocess a source file
pmdev.cpp.i:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/pmdev.cpp.i
.PHONY : pmdev.cpp.i

pmdev.s: pmdev.cpp.s

.PHONY : pmdev.s

# target to generate assembly for a file
pmdev.cpp.s:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/pmdev.cpp.s
.PHONY : pmdev.cpp.s

pmdidx.o: pmdidx.cpp.o

.PHONY : pmdidx.o

# target to build an object file
pmdidx.cpp.o:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/pmdidx.cpp.o
.PHONY : pmdidx.cpp.o

pmdidx.i: pmdidx.cpp.i

.PHONY : pmdidx.i

# target to preprocess a source file
pmdidx.cpp.i:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/pmdidx.cpp.i
.PHONY : pmdidx.cpp.i

pmdidx.s: pmdidx.cpp.s

.PHONY : pmdidx.s

# target to generate assembly for a file
pmdidx.cpp.s:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/pmdidx.cpp.s
.PHONY : pmdidx.cpp.s

scroll-h.o: scroll-h.cpp.o

.PHONY : scroll-h.o

# target to build an object file
scroll-h.cpp.o:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/scroll-h.cpp.o
.PHONY : scroll-h.cpp.o

scroll-h.i: scroll-h.cpp.i

.PHONY : scroll-h.i

# target to preprocess a source file
scroll-h.cpp.i:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/scroll-h.cpp.i
.PHONY : scroll-h.cpp.i

scroll-h.s: scroll-h.cpp.s

.PHONY : scroll-h.s

# target to generate assembly for a file
scroll-h.cpp.s:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/scroll-h.cpp.s
.PHONY : scroll-h.cpp.s

sys-mbs2ws.o: sys-mbs2ws.cpp.o

.PHONY : sys-mbs2ws.o

# target to build an object file
sys-mbs2ws.cpp.o:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/sys-mbs2ws.cpp.o
.PHONY : sys-mbs2ws.cpp.o

sys-mbs2ws.i: sys-mbs2ws.cpp.i

.PHONY : sys-mbs2ws.i

# target to preprocess a source file
sys-mbs2ws.cpp.i:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/sys-mbs2ws.cpp.i
.PHONY : sys-mbs2ws.cpp.i

sys-mbs2ws.s: sys-mbs2ws.cpp.s

.PHONY : sys-mbs2ws.s

# target to generate assembly for a file
sys-mbs2ws.cpp.s:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/sys-mbs2ws.cpp.s
.PHONY : sys-mbs2ws.cpp.s

sys-ws2mbs.o: sys-ws2mbs.cpp.o

.PHONY : sys-ws2mbs.o

# target to build an object file
sys-ws2mbs.cpp.o:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/sys-ws2mbs.cpp.o
.PHONY : sys-ws2mbs.cpp.o

sys-ws2mbs.i: sys-ws2mbs.cpp.i

.PHONY : sys-ws2mbs.i

# target to preprocess a source file
sys-ws2mbs.cpp.i:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/sys-ws2mbs.cpp.i
.PHONY : sys-ws2mbs.cpp.i

sys-ws2mbs.s: sys-ws2mbs.cpp.s

.PHONY : sys-ws2mbs.s

# target to generate assembly for a file
sys-ws2mbs.cpp.s:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/sys-ws2mbs.cpp.s
.PHONY : sys-ws2mbs.cpp.s

system.o: system.cpp.o

.PHONY : system.o

# target to build an object file
system.cpp.o:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/system.cpp.o
.PHONY : system.cpp.o

system.i: system.cpp.i

.PHONY : system.i

# target to preprocess a source file
system.cpp.i:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/system.cpp.i
.PHONY : system.cpp.i

system.s: system.cpp.s

.PHONY : system.s

# target to generate assembly for a file
system.cpp.s:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/system.cpp.s
.PHONY : system.cpp.s

win.o: win.cpp.o

.PHONY : win.o

# target to build an object file
win.cpp.o:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/win.cpp.o
.PHONY : win.cpp.o

win.i: win.cpp.i

.PHONY : win.i

# target to preprocess a source file
win.cpp.i:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/win.cpp.i
.PHONY : win.cpp.i

win.s: win.cpp.s

.PHONY : win.s

# target to generate assembly for a file
win.cpp.s:
	$(MAKE) -f CMakeFiles/urania.dir/build.make CMakeFiles/urania.dir/win.cpp.s
.PHONY : win.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... list_install_components"
	@echo "... install"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... rebuild_cache"
	@echo "... urania"
	@echo "... bwin.o"
	@echo "... bwin.i"
	@echo "... bwin.s"
	@echo "... clkpanel.o"
	@echo "... clkpanel.i"
	@echo "... clkpanel.s"
	@echo "... cmndlg.o"
	@echo "... cmndlg.i"
	@echo "... cmndlg.s"
	@echo "... ctrl.o"
	@echo "... ctrl.i"
	@echo "... ctrl.s"
	@echo "... ctrl_sb.o"
	@echo "... ctrl_sb.i"
	@echo "... ctrl_sb.s"
	@echo "... dialog.o"
	@echo "... dialog.i"
	@echo "... dialog.s"
	@echo "... drop-h.o"
	@echo "... drop-h.i"
	@echo "... drop-h.s"
	@echo "... getCLArgs.o"
	@echo "... getCLArgs.i"
	@echo "... getCLArgs.s"
	@echo "... getCLArgsW.o"
	@echo "... getCLArgsW.i"
	@echo "... getCLArgsW.s"
	@echo "... getLongPath.o"
	@echo "... getLongPath.i"
	@echo "... getLongPath.s"
	@echo "... menu.o"
	@echo "... menu.i"
	@echo "... menu.s"
	@echo "... menudesc.o"
	@echo "... menudesc.i"
	@echo "... menudesc.s"
	@echo "... msgloop.o"
	@echo "... msgloop.i"
	@echo "... msgloop.s"
	@echo "... pdev.o"
	@echo "... pdev.i"
	@echo "... pdev.s"
	@echo "... pdev2.o"
	@echo "... pdev2.i"
	@echo "... pdev2.s"
	@echo "... pmdev.o"
	@echo "... pmdev.i"
	@echo "... pmdev.s"
	@echo "... pmdidx.o"
	@echo "... pmdidx.i"
	@echo "... pmdidx.s"
	@echo "... scroll-h.o"
	@echo "... scroll-h.i"
	@echo "... scroll-h.s"
	@echo "... sys-mbs2ws.o"
	@echo "... sys-mbs2ws.i"
	@echo "... sys-mbs2ws.s"
	@echo "... sys-ws2mbs.o"
	@echo "... sys-ws2mbs.i"
	@echo "... sys-ws2mbs.s"
	@echo "... system.o"
	@echo "... system.i"
	@echo "... system.s"
	@echo "... win.o"
	@echo "... win.i"
	@echo "... win.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

