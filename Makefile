#########################################################
## Program name: Makefile
## Author: Benjamin Fridkis
## Date: 5/17/17
## Description: Makefile for Final Project (Plane Crash 
##		Survival Game).
#########################################################

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
#CXXFLAGS += Werror
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS+= -03
#LDFLAGS = -lboost_date_time

OBJS = mainFinalProject.o Item.o Space.o Raft.o WaterJug.o BackPack.o FishingPole.o Rifle.o LockBox.o CrashSite.o Lake.o Mushroom.o NutGrove.o Fish.o Woods.o Snake.o BerryBush.o SmallBeast.o LargeBeast.o Meadow.o Player.o Menu.o InputValidation.o MenuInputValidation.o setSpacePointers.o executeGame.o randomOrderUniqueElementGenerator.o HackSaw.o highScore.o

SRCS = CrashSite.cpp Item.cpp Player.cpp Raft.cpp WaterJug.cpp BackPack.cpp FishingPole.cpp Rifle.cpp LockBox.cpp Lake.cpp Mushroom.cpp NutGrove.cpp Fish.cpp Woods.cpp Snake.cpp BerryBush.cpp SmallBeast.cpp LargeBeast.cpp Meadow.cpp Space.cpp InputValidation.cpp MenuInputValidation.cpp Menu.cpp mainFinalProject.cpp setSpacePointers.cpp executeGame.cpp randomOrderUniqueElementGenerator.cpp HackSaw.cpp highScore.cpp

HEADERS = CrashSite.hpp Item.hpp Raft.hpp WaterJug.hpp BackPack.hpp FishingPole.hpp Rifle.hpp LockBox.hpp Space.hpp Lake.hpp Mushroom.hpp NutGrove.hpp Fish.hpp Woods.hpp Snake.hpp BerryBush.hpp SmallBeast.hpp LargeBeast.hpp Meadow.hpp Player.hpp InputValidation.hpp MenuInputValidation.hpp Menu.hpp setSpacePointers.hpp executeGame.hpp randomOrderUniqueElementGenerator.hpp HackSaw.hpp highScore.hpp

PROGRAM_NAME = mainFinalProject

${PROGRAM_NAME}: ${OBJS}
	${CXX} ${LDFLAGS} ${OBJS} -o ${PROGRAM_NAME}

CrashSite.o : CrashSite.cpp
	${CXX} ${CXXFLAGS} -c CrashSite.cpp
Lake.o : Lake.cpp
	${CXX} ${CXXFLAGS} -c Lake.cpp
Mushroom.o : Mushroom.cpp
	${CXX} ${CXXFLAGS} -c Mushroom.cpp
NutGrove.o : NutGrove.cpp
	${CXX} ${CXXFLAGS} -c NutGrove.cpp
Fish.o : Fish.cpp
	${CXX} ${CXXFLAGS} -c Fish.cpp
Woods.o : Woods.cpp
	${CXX} ${CXXFLAGS} -c Woods.cpp
Snake.o : Snake.cpp
	${CXX} ${CXXFLAGS} -c Snake.cpp
BerryBush.o : BerryBush.cpp
	${CXX} ${CXXFLAGS} -c BerryBush.cpp
SmallBeast.o : SmallBeast.cpp
	${CXX} ${CXXFLAGS} -c SmallBeast.cpp
LargeBeast.o : LargeBeast.cpp
	${CXX} ${CXXFLAGS} -c LargeBeast.cpp
Meadow.o : Meadow.cpp
	${CXX} ${CXXFLAGS} -c Meadow.cpp
Item.o : Item.cpp
	${CXX} ${CXXFLAGS} -c Item.cpp 
Player.o : Player.cpp
	${CXX} ${CXXFLAGS} -c Player.cpp 
Raft.o : Raft.cpp
	${CXX} ${CXXFLAGS} -c Raft.cpp
WaterJug.o : WaterJug.cpp
	${CXX} ${CXXFLAGS} -c WaterJug.cpp
BackPack.o : BackPack.cpp
	${CXX} ${CXXFLAGS} -c BackPack.cpp
FishingPole.o : FishingPole.cpp
	${CXX} ${CXXFLAGS} -c FishingPole.cpp
Rifle.o : Rifle.cpp
	${CXX} ${CXXFLAGS} -c Rifle.cpp
LockBox.o : LockBox.cpp
	${CXX} ${CXXFLAGS} -c LockBox.cpp 
Space.o : Space.cpp
	${CXX} ${CXXFLAGS} -c Space.cpp 
InputValidation.o : InputValidation.cpp
	${CXX} ${CXXFLAGS} -c InputValidation.cpp 
MenuInputValidation.o : MenuInputValidation.cpp
	${CXX} ${CXXFLAGS} -c MenuInputValidation.cpp 
Menu.o : Menu.cpp
	${CXX} ${CXXFLAGS} -c Menu.cpp 
mainFinalProject.o : mainFinalProject.cpp
	${CXX} ${CXXFLAGS} -c mainFinalProject.cpp
setSpacePointers.o : setSpacePointers.cpp
	${CXX} ${CXXFLAGS} -c setSpacePointers.cpp
executeGame.o : executeGame.cpp
	${CXX} ${CXXFLAGS} -c executeGame.cpp
randomOrderUniqueElementGenerator.o : randomOrderUniqueElementGenerator.cpp
	${CXX} ${CXXFLAGS} -c randomOrderUniqueElementGenerator.cpp
HackSaw.o : HackSaw.cpp
	${CXX} ${CXXFLAGS} -c HackSaw.cpp
highScore.o : highScore.cpp
	${CXX} ${CXXFLAGS} -c highScore.cpp 
	
run:
	./${PROGRAM_NAME}
	
clean:
	rm *.o ${PROGRAM_NAME}
	
zip:
	zip -D FinalProject_Fridkis_Benjamin.zip ${SRCS} ${HEADERS} Makefile *.txt
