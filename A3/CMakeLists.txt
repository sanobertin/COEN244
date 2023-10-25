
message("Othello Game Executables")
add_executable(Othello main.cpp Othello.cpp Othello.h Board.cpp Board.h Position.cpp Position.h Player.cpp Player.h)

message("Adding Test file ")
add_executable(A3.TEST testfile.cpp)