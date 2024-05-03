
#message("Othello Game Executables")
#add_executable(Othello main.cpp Board.cpp Board.h Position.cpp Position.h Player.cpp Player.h Othello.h Othello.cpp
 #       test.cpp)

#message("Adding Test file ")
#add_executable("Test" test.cpp)
add_library(Board Board.cpp)
add_library(Player Player.cpp)
add_executable(Othello Othello.cpp Othello.h)
target_link_libraries(Othello Board Player)
