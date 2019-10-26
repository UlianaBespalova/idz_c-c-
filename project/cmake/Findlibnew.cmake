set (FIND_LIBNEW_PATHS /home/uliana/xm)

find_path(LIBNEW_INCLUDE_DIR libnew.h
        PATH_SUFFIXES library
        PATHS ${FIND_LIBNEW_PATHS})

find_library(LIBNEW_LIBRARY
        NAMES libnew.a
        PATH_SUFFIXES library
        PATHS ${FIND_LIBNEW_PATHS})