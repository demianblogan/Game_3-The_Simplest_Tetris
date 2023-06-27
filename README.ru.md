[![en](https://img.shields.io/badge/Language-English-red.svg)](https://github.com/demianblogan/Game-The_Simplest_Tetris/blob/main/README.md)
[![ru](https://img.shields.io/badge/Language-Russian-blue.svg)](https://github.com/demianblogan/Game-The_Simplest_Tetris/blob/main/README.ru.md)
[![ua](https://img.shields.io/badge/Language-Ukrainian-green.svg)](https://github.com/demianblogan/Game-The_Simplest_Tetris/blob/main/README.ua.md)

# **Обзор**<br />
Это моя третья игра в моем портфолио. Этот проект написан на C++ с использованием SFML. Это классический тетрис с некоторой статистикой (зачеркнутые ряды, текущий уровень и счет).

![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/ff65de37-7666-4587-b6b3-a6aa15581637)

## **Управление:**<br />
Стрелка вниз -> Переместить блок вниз<br />
Стрелка влево -> Переместить блок влево<br />
Стрелка вправо -> Переместить блок вправо<br />
A -> Повернуть блок влево<br />
D -> Повернуть блок вправо<br />
Escape -> Закрыть игру<br />

## **Как играть?**<br />
Игра запускается сразу после запуска. Вы получаете случайное тетрамино и должны разместить его в нижней части сетки. После того, как вы разместите его, появится следующее случайное тетрамино.
Вы должны построить ряд из тетрамино, чтобы уничтожить его, и вы получите за это очки. Если вы построите башню из тетрамино, которая касается вершины сетки, вы проиграете. Вы переходите на следующий уровень
через каждые 10 завершенных рядов. Чем больше у вас уровень - тем больше очков вы получите за выполненные ряды.

## **Как создать и собрать этот проект в Visual Studio?**<br />
1. Загрузите этот репозиторий в виде файла .zip и распакуйте его.:<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/97809306-8ac0-4e7f-9203-5f7758804065)

2. Создайте пустой проект C++ в Visual Studio:<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/40bca872-b0f3-4969-acc4-f85216b9af0a)

3. Откройте папку проекта в проводнике и переместите в нее все файлы из архива:<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/2eaf6be5-f6a9-4732-a78f-3f3cece9cb12)

4. Теперь вы должны включить эти файлы в свой проект. Сначала, чтобы сделать все эти файлы видимыми в вашем проекте, нажмите кнопку «Show All Files» в обозревателе решений. После этого выберите их, ПКМ по ним и нажмите «Include in Project»:<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/8c15fa56-58c1-4219-a693-6a1ea2101b7b)

5. Теперь давайте перейдем к свойствам проекта:<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/208d3fc0-f57a-42ea-82d0-3b4a320853b7)

6. Давайте свяжем папку "Binaries" с проектом. Выберите «All Configurations» и «All Platforms». Затем перейдите на вкладку «Debugging», найдите поле «Working Directory» и введите «$(ProjectDir)Binaries»:<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/55605fb0-c65c-46e0-a198-3bb135f04d49)

7. Теперь подключим к проекту библиотеку SFML. Начнем с папки «include». Перейдите на вкладку «C/C++», найдите «Additional Include Directories», нажмите стрелку справа и нажмите "<Edit...>":<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/be6838e9-11bd-413d-a910-13c50deae4c7)

8. В новом окне дважды щелкните пустую строку, введите «$(ProjectDir)Libraries\SFML\include» и нажмите «ОК» внизу окна.:<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/5d0b9c04-0243-4a33-a541-2e50c82077a3)

9. Теперь сделайте то же самое с папкой «lib»: перейдите на вкладку «Linker», найдите «Additional Library Directories», нажмите стрелку справа и нажмите "<Edit...>":<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/18723745-d2cf-4731-9cf4-8ec7b7df1ada)

10. В новом окне дважды щелкните пустую строку, введите «$(ProjectDir)Libraries\SFML\lib» и нажмите «ОК» внизу окна.:<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/d26851be-f844-43fa-97f5-7fd8a13b6921)

11. Почти готово. Нам нужно только добавить файлы .dll в наш проект. Сохраните изменения, нажав кнопку «Apply» внизу свойств проекта, измените конфигурацию на «Debug», перейдите на вкладку «Linker» -> «Input», найдите «Additional Dependencies», нажмите стрелку справа. и нажмите "<Edit...>".<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/1ed08c65-6332-4b44-859d-9bb108f5a59e)

12. В новом окне напишите следующие строки:<br />
sfml-system-d.lib<br />
sfml-window-d.lib<br />
sfml-audio-d.lib<br />
sfml-graphics-d.lib<br />
sfml-network-d.lib<br />
и нажмите кнопку "Ok".<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/f816b73d-ce64-4a45-bcbb-47f8ae042159)

13. Нажимаем «Apply», переключите конфигурацию на «Release» и сделайте то же самое, только напишите следующие строки:<br />
sfml-system.lib<br />
sfml-window.lib<br />
sfml-audio.lib<br />
sfml-graphics.lib<br />
sfml-network.lib<br />
и нажмите кнопку "Ok".<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/de2d7b06-3c7d-4551-9b9a-7242be3e492b)

14. Вот и все! Нажмите «Apply», и теперь SFML связан с вашим проектом..

15. Для компиляции и запуска игры нажмите "Ctrl+F5".
