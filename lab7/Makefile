all: main test

main: main.cpp
	g++ -o main main.cpp -lm

test: main.cpp main_test.cpp
	g++ -coverage -o test -D TESTING main.cpp main_test.cpp -lm

cleanW: 
	-del test.exe
	-del main.exe

cleanL:
	rm test -f
	rm main -f

git:
	cd ../
	git add lab7
	git commit -m "updating"
	git pull
	git push
