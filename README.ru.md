[![en](https://img.shields.io/badge/Language-English-red.svg)](https://github.com/demianblogan/Game-The_Simplest_Tetris/blob/main/README.md)
[![ru](https://img.shields.io/badge/Language-Russian-blue.svg)](https://github.com/demianblogan/Game-The_Simplest_Tetris/blob/main/README.ru.md)
[![ua](https://img.shields.io/badge/Language-Ukrainian-green.svg)](https://github.com/demianblogan/Game-The_Simplest_Tetris/blob/main/README.ua.md)

# **Обзор**<br />
Это моя 3-я игра в моем портфолио. Этот проект написан на C++ с использованием SFML. Это классический тетрис с некоторой статистикой (зачеркнутые строки, текущий уровень и счет).

![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/ff65de37-7666-4587-b6b3-a6aa15581637)

## **Управление:**<br />
Стрелка вниз -> Переместить блок вниз<br />
Стрелка влево -> Переместить блок влево<br />
Стрелка вправо -> Переместить блок вправо<br />
A -> Повернуть блок влево<br />
D -> Повернуть блок вправо<br />
Escape -> Закрыть игру<br />

## **Как играть?**<br />
Игра начинается сразу после её запуска. Вы получаете случайный блок и должны поместить его в нижнюю часть сетки. После того, как вы опустите его, появится следующий случайный блок. Вы должны построить из них ряд, чтобы разрушить его и получить за это очки. Если вы построите башню из блоков, которая касается вершины сетки, вы проиграете. Вы переходите на следующий уровень через каждые 10 зачеркнутых рядов. Чем больше у вас уровень - тем больше очков вы получите за выполненные ряды.

## **Как создать и скомпилировать этот проект в Visual Studio?**<br />
1. Скачайте этот репозиторий как .zip файл и розархивируйте его:<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/290a257d-6183-4f0b-ae44-661153228b7a)

2. Создайте пустой C++ проект в Visual Studio:<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/8993b7c0-12b8-4d7a-868b-0b87e6bc738e)

3. Откройте папку проекта в проводнике и переместите все файлы из архива туда:<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/726509fb-4f07-47b1-a87b-ecb91efcbe6c)

4. Чтобы сделать все эти файлы видимыми в вашем проекте, нажтиме на кнопку "Show all files" в Solution Explorer:<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/f7515e79-1877-42e0-8953-a940900aa30d)

5. Подключите все .dll файлы из папки "Binaries" к проекту:
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/556c31da-136b-49d5-89b5-b9c700ae946b)

6. Выберите "All Configurations" и "All Platforms":<br />
![image](https://github.com/demianblogan/Game-Until_Last_Asteroid/assets/105989117/32a7b835-c44a-4807-88ef-f1aff00f1456)

7. Библиотека SFML состоит из 3 частей: .h/.cpp файлы (папка include), .lib файлы (папка lib) и .dll файлы. Давайте подключим сначала папку "include". Перейдите ко вкладке "C/C++", найдите пункт "Additional Include Directories", нажмите на стрелочку справа и нажмите "<Edit...>":<br />
![8](https://github.com/demianblogan/Game-Until_Last_Asteroid/assets/105989117/79cb8d11-aabb-40e5-897f-ddbf3fe087c1)

8. В появившемся окне дважды нажмите на пустую строку и напишите "$(ProjectDir)SFML\include", после чего нажмите кнопку "ОК" снизу окна:<br />
![9](https://github.com/demianblogan/Game-Until_Last_Asteroid/assets/105989117/4257e884-5b7f-41da-b223-804560326285)

9. Вам нужно сделать то же самое с .lib файлами: перейдите ко вкладке "Linker", найдите пункт "Additional Library Directories", нажмите на стрелочку справа и нажмите "<Edit...>:<br />
![10](https://github.com/demianblogan/Game-Until_Last_Asteroid/assets/105989117/3ada0b06-2495-444c-ba47-03de46a538f5)

10. Сделайте то же, что и в пункте №10, но теперь напишите "$(ProjectDir)SFML\lib":<br />
![image](https://github.com/demianblogan/Game-Until_Last_Asteroid/assets/105989117/a0488d5d-414c-4050-9a61-9f9ae3860f52)

11. Почти готово. Нам только нужно добавить .dll файлы в проект. Сохраните ваши изменения, нажав кнопку "Apply" снизу окна настроек проекта, измените конфигурацию на "Debug", перейдите ко вкладке "Linker" -> "Input", найдите пункт "Additional Dependencies", нажмите на стрелочку справа и нажмите "<Edit...>":<br />
![11](https://github.com/demianblogan/Game-Until_Last_Asteroid/assets/105989117/d6be1795-e5a9-49c4-b285-0bf18b07ed25)

12. В окне, которое появилось, напишите следующие строки:<br />
sfml-system-d.lib<br />
sfml-window-d.lib<br />
sfml-audio-d.lib<br />
sfml-graphics-d.lib<br />
sfml-network-d.lib<br />
и нажмите кнопку "Ok".<br />
![image](https://github.com/demianblogan/Game-Until_Last_Asteroid/assets/105989117/58e2669e-8805-4624-b2a5-aaf502f12297)

13. Нажмите "Apply", поменяйте конфигурацию на "Release" и сделайте то же самое, только напишите следующие строки:<br />
sfml-system.lib<br />
sfml-window.lib<br />
sfml-audio.lib<br />
sfml-graphics.lib<br />
sfml-network.lib<br />
и нажмите кнопку "Ok".<br />
![12](https://github.com/demianblogan/Game-Until_Last_Asteroid/assets/105989117/3f3f6dd1-6dae-46f0-8f26-6a9c873685c7)

14. Вот и всё! Нажмите "Apply", и теперь библиотека SFML подключена к вашему проекту.

15. Чтобы скомпилировать и запустить игру, нажмите "Ctrl + F5".
