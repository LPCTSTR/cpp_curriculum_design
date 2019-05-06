cmake_minimum_required(VERSION 3.13)
project(Curriculum_Work)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXE_LINKER_FLAGS -static)
add_executable(Curriculum_Work main.cpp Model/Card.cpp Model/Card.h Model/CardFactory.cpp Model/CardFactory.h Model/CardDispatcher.cpp Model/CardDispatcher.h Model/Pool/Pool.hpp Model/Pool_Proxy.cpp Model/Pool_Proxy.h Model/pch.h Controller/MainController.cpp Controller/MainController.h View/Vpch.h Controller/Command/ICommand.cpp Controller/Command/ICommand.h Controller/Player/PlayerManager.cpp Controller/Player/PlayerManager.h Controller/Player/Player.cpp Controller/Player/Player.h Controller/Command/BasicCmd.cpp Controller/Command/BasicCmd.h Controller/Command/Cmd_Pch.h Controller/Command/PlayerCmd.cpp Controller/Command/PlayerCmd.h Controller/Command/Pool_Cmd.cpp Controller/Command/Pool_Cmd.h)