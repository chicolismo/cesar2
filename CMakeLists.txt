cmake_minimum_required(VERSION 3.13)
project(cesar)

set(CMAKE_CXX_STANDARD 17)
find_package(wxWidgets COMPONENTS all REQUIRED)
include(${wxWidgets_USE_FILE})
add_executable(cesar Main.cpp MainFrame.cpp MainFrame.h Table.cpp Table.h Common.h DataTable.cpp DataTable.h SidePanel.cpp SidePanel.h ProgramTable.cpp ProgramTable.h CPU.cpp CPU.h Register.h Register.cpp ExecutionPanel.h ExecutionPanel.cpp)
target_link_libraries(cesar ${wxWidgets_LIBRARIES})