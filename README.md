[![en](https://img.shields.io/badge/Language-English-red.svg)](https://github.com/demianblogan/Game-The_Simplest_Tetris/blob/main/README.md)
[![ru](https://img.shields.io/badge/Language-Russian-blue.svg)](https://github.com/demianblogan/Game-The_Simplest_Tetris/blob/main/README.ru.md)
[![ua](https://img.shields.io/badge/Language-Ukrainian-green.svg)](https://github.com/demianblogan/Game-The_Simplest_Tetris/blob/main/README.ua.md)

# **Overview**<br />
This is my 3rd game for my portfolio. This project is written on C++ with SFML. It's a classic Tetris game with some statistics (rows completed, current level, and score).

![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/ff65de37-7666-4587-b6b3-a6aa15581637)

## **Game controls:**<br />
Arrow down  -> Move tetramino down<br />
Arrow left  -> Move tetramino left<br />
Arrow right -> Move tetramino right<br />
A           -> Rotate tetramino left<br />
D           -> Rotate tetramino right<br />
Escape      -> Close the game<br />

## **How to play?**<br />
The game starts right after you launch it. You get a random tetramino, and must place it at the bottom of the grid. After you place it, the next random tetramino appears.
You must build a row of them to destroy it and the you will get points for this. If you build a tower of tetraminos that touches the top of the grid - you lose. You go to the next level
every 10 completed rows. The more level you have - the more points you get from completed rows.

## **How to create and build this project in Visual Studio?**<br />
1. Download this repository as a .zip file and extract it:<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/97809306-8ac0-4e7f-9203-5f7758804065)

2. Create an empty C++ project in Visual Studio:<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/40bca872-b0f3-4969-acc4-f85216b9af0a)

3. Open the project's folder in File Explorer and move all files from the archive into it:<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/2eaf6be5-f6a9-4732-a78f-3f3cece9cb12)

4. Now you have to include these files to your project. At first, to make all those files visible in your project, click the button "Show all files" in Solution Explorer. After this select them, RMB on them and click "Include in Project":<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/8c15fa56-58c1-4219-a693-6a1ea2101b7b)

5. Now let's go to Project's Properties:<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/208d3fc0-f57a-42ea-82d0-3b4a320853b7)

6. Let's link "Binaries" Folder to the project. Select "All Configurations" and "All Platforms". Then go to "Debugging" tab, find field "Working Directory" and type "$(ProjectDir)Binaries":<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/55605fb0-c65c-46e0-a198-3bb135f04d49)

7. Now let's connect SFML library to the project. Let's start from "include" folder. Go to the "C/C++" tab, find "Additional Include Directories", press the arrow on its right, and click "<Edit...>":<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/be6838e9-11bd-413d-a910-13c50deae4c7)

8. In the new window double-click on the empty line, type "$(ProjectDir)Libraries\SFML\include", and press "OK" at the bottom of the window:<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/5d0b9c04-0243-4a33-a541-2e50c82077a3)

9. Now do the same with "lib" folder: go to the tab "Linker", find "Additional Library Directories", press the arrow on its right, and click "<Edit...>":<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/18723745-d2cf-4731-9cf4-8ec7b7df1ada)

10. In the new window double-click on the empty line, type "$(ProjectDir)Libraries\SFML\lib", and press "OK" at the bottom of the window:<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/d26851be-f844-43fa-97f5-7fd8a13b6921)

11. Almost done. We only need to add .dll files to our project. Save your changes by clicking the "Apply" button at the bottom of the project's properties, change the configuration to "Debug", go to "Linker" -> "Input" tab, find "Additional Dependencies", click the arrow on its right, and click "<Edit...>".<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/1ed08c65-6332-4b44-859d-9bb108f5a59e)

12. In the new window write the next lines:<br />
sfml-system-d.lib<br />
sfml-window-d.lib<br />
sfml-audio-d.lib<br />
sfml-graphics-d.lib<br />
sfml-network-d.lib<br />
and press "Ok" button.<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/f816b73d-ce64-4a45-bcbb-47f8ae042159)

13. Press "Apply", switch configuration to "Release" and do the same things, but write the next lines:<br />
sfml-system.lib<br />
sfml-window.lib<br />
sfml-audio.lib<br />
sfml-graphics.lib<br />
sfml-network.lib<br />
and press "Ok" button.<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/de2d7b06-3c7d-4551-9b9a-7242be3e492b)

14. That's it! Press "Apply", and now SFML is linked to your project.

15. To compile & launch the game, press "Ctrl + F5".
