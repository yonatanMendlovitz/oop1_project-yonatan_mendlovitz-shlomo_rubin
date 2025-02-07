# Copy texture files
configure_file("guard.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("player.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("stone.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("wall.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("blank.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("door.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("bomb.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("explosion.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("gameImage.jpeg" ${CMAKE_BINARY_DIR} COPYONLY)

# Copy sound files
configure_file("tick_tock.wav" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("timeIsOut.wav" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("timeUp.wav" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("explosion.wav" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("01_main_menu.wav" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("02_the_level_begins.wav" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("03_level_theme.wav" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("04_door_search.wav" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("levelComplete.wav" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("06_invincibility_theme.wav" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("death.wav" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("09_game_over.wav" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("10_ending_theme.wav" ${CMAKE_BINARY_DIR} COPYONLY)


configure_file("ARCADECLASSIC.TTF" ${CMAKE_BINARY_DIR} COPYONLY)

# Copy text file
configure_file("Toolbox.txt" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("level1.txt" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("level2.txt" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("level3.txt" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("fileList.txt" ${CMAKE_BINARY_DIR} COPYONLY)
