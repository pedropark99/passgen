BUILD_DIRECTORY = build
SOURCE_DIRECTORY = src
source_files = main.cpp


$(BUILD_DIRECTORY)/main: main.o arguments_parser.o
	rm -r build
	mkdir build
	g++ -I./include -o $(BUILD_DIRECTORY)/main main.o arguments_parser.o
	make clean

main.o: $(SOURCE_DIRECTORY)/main.cpp
	g++ -I./include -c $(SOURCE_DIRECTORY)/main.cpp

arguments_parser.o: $(SOURCE_DIRECTORY)/arguments_parser.cpp
	g++ -I./include -c $(SOURCE_DIRECTORY)/arguments_parser.cpp

clean:
	rm *.o