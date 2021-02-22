# HeadsAndHandsTest
скрипт для билда под macOS

rm -rf build && mkdir build && cd build && cmake .. && cmake --build .

./HeadsAndHandsTest 
Помощь:
./HeadsAndHandsTest -h
Можно ограничить длину массивов(дефолтное значение 50):
./HeadsAndHandsTest -lc int
