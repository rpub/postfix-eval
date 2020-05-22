cmake_minimum_required(VERSION 3.16)
project(postfix_eval_Ramiisaac)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(postfix_eval_Ramiisaac
        .idea/deployment.xml
        .idea/misc.xml
        .idea/modules.xml
        .idea/postfix-eval-Ramiisaac.iml
        .idea/vcs.xml
        .idea/workspace.xml
        .gitignore
        evaluator.cpp
        evaluator.h
        main.cpp
        makefile
        README.md)
