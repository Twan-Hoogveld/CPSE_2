#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source files in this project (main.cpp is automatically assumed)
SOURCES := BoardState.cpp Game.cpp Interface.cpp Picture.cpp Tile.cpp

# header files in this project
HEADERS := BoardState.hpp Game.hpp Interface.hpp Picture.hpp Tile.hpp definitions.hpp

# other places to look for files for this project
SEARCH  := Pictures

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.native
