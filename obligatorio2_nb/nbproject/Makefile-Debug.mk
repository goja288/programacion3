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
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/328021252/Estrategias.o \
	${OBJECTDIR}/_ext/328021252/main.o \
	${OBJECTDIR}/_ext/328021252/Territorio.o \
	${OBJECTDIR}/_ext/328021252/Testeo.o \
	${OBJECTDIR}/_ext/328021252/Mundo.o


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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/obligatorio2_nb

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/obligatorio2_nb: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/obligatorio2_nb ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/328021252/Estrategias.o: /home/gjmF15/Documents/Facultad/Programacion3/Laboratorios/obligatorio2_nb/Estrategias.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/328021252
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/328021252/Estrategias.o /home/gjmF15/Documents/Facultad/Programacion3/Laboratorios/obligatorio2_nb/Estrategias.cpp

${OBJECTDIR}/_ext/328021252/main.o: /home/gjmF15/Documents/Facultad/Programacion3/Laboratorios/obligatorio2_nb/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/328021252
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/328021252/main.o /home/gjmF15/Documents/Facultad/Programacion3/Laboratorios/obligatorio2_nb/main.cpp

${OBJECTDIR}/_ext/328021252/Territorio.o: /home/gjmF15/Documents/Facultad/Programacion3/Laboratorios/obligatorio2_nb/Territorio.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/328021252
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/328021252/Territorio.o /home/gjmF15/Documents/Facultad/Programacion3/Laboratorios/obligatorio2_nb/Territorio.cpp

${OBJECTDIR}/_ext/328021252/Testeo.o: /home/gjmF15/Documents/Facultad/Programacion3/Laboratorios/obligatorio2_nb/Testeo.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/328021252
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/328021252/Testeo.o /home/gjmF15/Documents/Facultad/Programacion3/Laboratorios/obligatorio2_nb/Testeo.cpp

${OBJECTDIR}/_ext/328021252/Mundo.o: /home/gjmF15/Documents/Facultad/Programacion3/Laboratorios/obligatorio2_nb/Mundo.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/328021252
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/328021252/Mundo.o /home/gjmF15/Documents/Facultad/Programacion3/Laboratorios/obligatorio2_nb/Mundo.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/obligatorio2_nb

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
