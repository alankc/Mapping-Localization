#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Lms200.o \
	${OBJECTDIR}/NormalDistribution.o \
	${OBJECTDIR}/OccupancyGridMapping.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=`pkg-config --cflags playerc++ ` -L/usr/local/lib64 -L/usr/local/lib -L/usr/local/lib64 -lplayerc++ -lboost_thread -lboost_system -lboost_signals -lboost_system -lm -lplayerc -lm -lz -lplayerinterface -lplayerwkb -lplayercommon `pkg-config --libs opencv`  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mapeamento-localizacao

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mapeamento-localizacao: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mapeamento-localizacao ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Lms200.o: Lms200.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/local/include/player-3.0 -I. `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Lms200.o Lms200.cpp

${OBJECTDIR}/NormalDistribution.o: NormalDistribution.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/local/include/player-3.0 -I. `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/NormalDistribution.o NormalDistribution.cpp

${OBJECTDIR}/OccupancyGridMapping.o: OccupancyGridMapping.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/local/include/player-3.0 -I. `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/OccupancyGridMapping.o OccupancyGridMapping.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/local/include/player-3.0 -I. `pkg-config --cflags opencv` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
