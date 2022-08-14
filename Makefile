BUILD_DIRECTORY = build
SOURCE_DIRECTORY = src


$(BUILD_DIRECTORY)/passgen: main.o arguments_parser.o password.o
	rm -r build
	mkdir build
	g++ -I./include -o $(BUILD_DIRECTORY)/passgen main.o arguments_parser.o password.o
	make clean

main.o: $(SOURCE_DIRECTORY)/main.cpp
	g++ -I./include -c $(SOURCE_DIRECTORY)/main.cpp

arguments_parser.o: $(SOURCE_DIRECTORY)/arguments_parser.cpp
	g++ -I./include -c $(SOURCE_DIRECTORY)/arguments_parser.cpp

password.o: $(SOURCE_DIRECTORY)/password.cpp
	g++ -I./include -c $(SOURCE_DIRECTORY)/password.cpp


clean:
	rm *.o