# ----------------------------
# Makefile Options
# ----------------------------

NAME = TILE
ICON = icon.png
DESCRIPTION = "CE Toolchain Demo"
COMPRESSED = YES
ARCHIVED = NO

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)
