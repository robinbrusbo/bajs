g++ -c -I include/ source/*.cpp 
g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
./sfml-app