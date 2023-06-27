[![en](https://img.shields.io/badge/Language-English-red.svg)](https://github.com/demianblogan/Game-The_Simplest_Tetris/blob/main/README.md)
[![ru](https://img.shields.io/badge/Language-Russian-blue.svg)](https://github.com/demianblogan/Game-The_Simplest_Tetris/blob/main/README.ru.md)
[![ua](https://img.shields.io/badge/Language-Ukrainian-green.svg)](https://github.com/demianblogan/Game-The_Simplest_Tetris/blob/main/README.ua.md)

# **Огляд**<br />
Це моя третя гра у моєму портфоліо. Цей проект написано на C++ із використанням SFML. Це класичний тетріс із деякою статистикою (закреслені ряди, поточний рівень та рахунок).

![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/ff65de37-7666-4587-b6b3-a6aa15581637)

## **Керування:**<br />
Стрілка вниз -> Перемістити блок вниз<br />
Стрілка вліво -> Перемістити блок вліво<br />
Стрілка вправо -> Перемістити блок вправо<br />
A -> Повернути блок вліво<br />
D -> Повернути блок вправо<br />
Escape -> Закрити гру<br />

## **Як грати?**<br />
Гра запускається одразу після запуску. Ви отримуєте довільне тетраміно і повинні розмістити його в нижній частині сітки. Після того, як ви розмістите його, з'явиться наступне випадкове тетраміно.
Ви повинні побудувати ряд тетраміно, щоб знищити його, і ви отримаєте за це окуляри. Якщо ви збудуєте вежу з тетраміно, яка торкається вершини сітки, ви програєте. Ви переходите на наступний рівень
через кожних 10 завершених рядів. Чим більший у вас рівень – тим більше очок ви отримаєте за виконані ряди.

## **Як створити та зібрати цей проект у Visual Studio?**<br />
1. Завантажте цей репозиторій у вигляді .zip і розпакуйте його:<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/97809306-8ac0-4e7f-9203-5f7758804065)

2. Створіть порожній проект C++ у Visual Studio:<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/40bca872-b0f3-4969-acc4-f85216b9af0a)

3. Відкрийте папку проекту у провіднику та перемістіть у неї всі файли з архіву:<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/2eaf6be5-f6a9-4732-a78f-3f3cece9cb12)

4. Тепер ви повинні включити ці файли до свого проекту. Спочатку, щоб зробити всі ці файли видимими у вашому проекті, натисніть кнопку «Show All Files» у браузері рішень. Після цього оберіть їх, ПКМ за ними та натисніть «Include in Project»:<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/8c15fa56-58c1-4219-a693-6a1ea2101b7b)

5. Тепер давайте перейдемо до властивостей проекту:<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/208d3fc0-f57a-42ea-82d0-3b4a320853b7)

6. Давайте зв'яжемо папку "Binaries" із проектом. Виберіть "All Configurations" та "All Platforms". Потім перейдіть на вкладку Debugging, знайдіть поле Working Directory і введіть $(ProjectDir)Binaries:<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/55605fb0-c65c-46e0-a198-3bb135f04d49)

7. Тепер підключимо до проекту бібліотеку SFML. Почнемо з папки "include". Перейдіть на вкладку C/C++, знайдіть Additional Include Directories, натисніть стрілку праворуч і натисніть "<Edit...>":<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/be6838e9-11bd-413d-a910-13c50deae4c7)

8. У новому вікні двічі клацніть порожній рядок, введіть "$(ProjectDir)Libraries\SFML\include" і натисніть "ОК" внизу вікна.<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/5d0b9c04-0243-4a33-a541-2e50c82077a3)

9. Тепер зробіть те саме з папкою "lib": перейдіть на вкладку "Linker", знайдіть "Additional Library Directories", натисніть стрілку праворуч і натисніть "<Edit...>":<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/18723745-d2cf-4731-9cf4-8ec7b7df1ada)

10. У новому вікні двічі клацніть порожній рядок, введіть "$(ProjectDir)Libraries\SFML\lib" і натисніть "ОК" внизу вікна.<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/d26851be-f844-43fa-97f5-7fd8a13b6921)

11. Майже готово. Нам потрібно лише додати файли .dll до нашого проекту. Збережіть зміни, натиснувши кнопку "Apply" внизу властивостей проекту, змініть конфігурацію на "Debug", перейдіть на вкладку "Linker" -> "Input", знайдіть "Additional Dependencies", натисніть стрілку праворуч. та натисніть "<Edit...>":<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/1ed08c65-6332-4b44-859d-9bb108f5a59e)

12. У новому вікні напишіть наступні рядки:<br />
sfml-system-d.lib<br />
sfml-window-d.lib<br />
sfml-audio-d.lib<br />
sfml-graphics-d.lib<br />
sfml-network-d.lib<br />
та натисніть кнопку "OK".<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/f816b73d-ce64-4a45-bcbb-47f8ae042159)

13. Натискаємо «Apply», переключіть конфігурацію на «Release» і зробіть те саме, тільки напишіть наступні рядки:<br />
sfml-system.lib<br />
sfml-window.lib<br />
sfml-audio.lib<br />
sfml-graphics.lib<br />
sfml-network.lib<br />
та натисніть кнопку "OK".<br />
![image](https://github.com/demianblogan/Game-The_Simplest_Tetris/assets/105989117/de2d7b06-3c7d-4551-9b9a-7242be3e492b)

14. От і все! Натисніть "Apply", і тепер SFML під'єднана до вашого проекту.

15. Для компіляції та запуску гри натисніть "Ctrl+F5".
