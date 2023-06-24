[![en](https://img.shields.io/badge/Language-English-red.svg)](https://github.com/demianblogan/Game-The_Simplest_Tetris/blob/main/README.md)
[![ru](https://img.shields.io/badge/Language-Russian-blue.svg)](https://github.com/demianblogan/Game-The_Simplest_Tetris/blob/main/README.ru.md)
[![ua](https://img.shields.io/badge/Language-Ukrainian-green.svg)](https://github.com/demianblogan/Game-The_Simplest_Tetris/blob/main/README.ua.md)

# **Overview**<br />
This is my 3rd game for my portfolio. This project is written on C++ with SFML. It's a classic Tetris game with some statistics (lines completed, current level, and score).

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
You must build a row of them to destroy it and get points for this. If you build a tower of tetraminos that touches the top of the grid - you lose. You go to the next level
every 10 completed rows. The more level you have - the more points you get from completed rows.

## **How to create and build this project in Visual Studio?**<br />
1. Download this repository as a .zip file and extract it:<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/290a257d-6183-4f0b-ae44-661153228b7a)

2. Create an empty C++ project in Visual Studio:<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/8993b7c0-12b8-4d7a-868b-0b87e6bc738e)

3. Open the project's folder in File Explorer and move all files from the archive into it:<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/726509fb-4f07-47b1-a87b-ecb91efcbe6c)

4. To make all those files visible in your project, click the button "Show all files" in Solution Explorer. After this select them, RMB on them and click "Include in Project":<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/f7515e79-1877-42e0-8953-a940900aa30d)

6. Select "All Configurations" and "All Platforms" in Project.<br />
![image](https://github.com/demianblogan/Game-Until_Last_Asteroid/assets/105989117/32a7b835-c44a-4807-88ef-f1aff00f1456)

5. Connect .dll files in "Binaries" folder with the project:
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/556c31da-136b-49d5-89b5-b9c700ae946b)

7. SFML library consists of three parts: .h/.cpp files (folder "include"), .lib files (folder "lib"), and .dll files. Let's link the "include" folder first. Go to the "C/C++" tab, find "Additional Include Directories", press the arrow on its right, and click "<Edit...>".<br />
![8](https://github.com/demianblogan/Game-Until_Last_Asteroid/assets/105989117/79cb8d11-aabb-40e5-897f-ddbf3fe087c1)

8. In the new window double-click on the empty line, type "$(ProjectDir)SFML\include", and press "OK" at the bottom of the window.<br />
![9](https://github.com/demianblogan/Game-Until_Last_Asteroid/assets/105989117/4257e884-5b7f-41da-b223-804560326285)

9. You need to do the same with .lib files: go to the tab "Linker", find "Additional Library Directories", press the arrow on its right, and click "<Edit...>".<br />
![10](https://github.com/demianblogan/Game-Until_Last_Asteroid/assets/105989117/3ada0b06-2495-444c-ba47-03de46a538f5)

10. Do the same as you did in item #10, but now write "$(ProjectDir)SFML\lib".<br />
![image](https://github.com/demianblogan/Game-Until_Last_Asteroid/assets/105989117/a0488d5d-414c-4050-9a61-9f9ae3860f52)

11. Almost done. We only need to add .dll files to our project. Save your changes by clicking the "Apply" button at the bottom of the project's properties, change the configuration to "Debug", go to "Linker" -> "Input" tab, find "Additional Dependencies", click the arrow on its right, and click "<Edit...>".<br />
![11](https://github.com/demianblogan/Game-Until_Last_Asteroid/assets/105989117/d6be1795-e5a9-49c4-b285-0bf18b07ed25)

12. In the popup window write the next lines:<br />
sfml-system-d.lib<br />
sfml-window-d.lib<br />
sfml-audio-d.lib<br />
sfml-graphics-d.lib<br />
sfml-network-d.lib<br />
and press "Ok" button.<br />
![image](https://github.com/demianblogan/Game-Until_Last_Asteroid/assets/105989117/58e2669e-8805-4624-b2a5-aaf502f12297)

13. Press "Apply", switch configuration to "Release" and do the same things, but write the next lines:<br />
sfml-system.lib<br />
sfml-window.lib<br />
sfml-audio.lib<br />
sfml-graphics.lib<br />
sfml-network.lib<br />
and press "Ok" button.<br />
![12](https://github.com/demianblogan/Game-Until_Last_Asteroid/assets/105989117/3f3f6dd1-6dae-46f0-8f26-6a9c873685c7)

14. That's it! Press "Apply", and now SFML is linked to your project.

15. To compile & launch the game, press "Ctrl + F5".
