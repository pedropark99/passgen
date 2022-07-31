BUILD_DIRECTORY = build
SOURCE_DIRECTORY = src
source_files = main.cpp


$(BUILD_DIRECTORY)/main: main.o
	rm -r build
	mkdir build
	g++ main.o -o $(BUILD_DIRECTORY)/main
	make clean

main.o: $(SOURCE_DIRECTORY)/main.cpp
	g++ -c $(SOURCE_DIRECTORY)/main.cpp

clean:
	rm *.o