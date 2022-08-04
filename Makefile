BUILD_DIRECTORY = build
SOURCE_DIRECTORY = src
source_files = main.cpp


$(BUILD_DIRECTORY)/main: main.o help.o options_parser.o
	rm -r build
	mkdir build
	g++ -I./include -o $(BUILD_DIRECTORY)/main main.o help.o options_parser.o
	make clean

main.o: $(SOURCE_DIRECTORY)/main.cpp
	g++ -I./include -c $(SOURCE_DIRECTORY)/main.cpp

help.o: $(SOURCE_DIRECTORY)/help.cpp
	g++ -I./include -c $(SOURCE_DIRECTORY)/help.cpp

options_parser.o: $(SOURCE_DIRECTORY)/options_parser.cpp
	g++ -I./include -c $(SOURCE_DIRECTORY)/options_parser.cpp

clean:
	rm *.o