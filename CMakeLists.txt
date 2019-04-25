cmake_minimum_required(VERSION 3.7)
project(cesar)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
find_package(wxWidgets COMPONENTS all REQUIRED)
include(${wxWidgets_USE_FILE})
add_executable(cesar Main.cpp MainFrame.cpp MainFrame.h Table.cpp Table.h Common.h DataTable.cpp DataTable.h SidePanel.cpp SidePanel.h ProgramTable.cpp ProgramTable.h CPU.cpp CPU.h Register.h Register.cpp ExecutionPanel.h ExecutionPanel.cpp)
target_link_libraries(cesar ${wxWidgets_LIBRARIES})
