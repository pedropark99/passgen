BUILD_DIRECTORY = build
SOURCE_DIRECTORY = src
DOCS_DIRECTORY = docs


object_files = main.o arguments_parser.o password.o global_variables.o

$(BUILD_DIRECTORY)/passgen: $(object_files)
	rm -r build
	mkdir build
	g++ -I./include -o $(BUILD_DIRECTORY)/passgen $(object_files) -static-libstdc++
	make clean

main.o: $(SOURCE_DIRECTORY)/main.cpp
	g++ -I./include -c $(SOURCE_DIRECTORY)/main.cpp -static-libstdc++

arguments_parser.o: $(SOURCE_DIRECTORY)/arguments_parser.cpp
	g++ -I./include -c $(SOURCE_DIRECTORY)/arguments_parser.cpp -static-libstdc++

password.o: $(SOURCE_DIRECTORY)/password.cpp
	g++ -I./include -c $(SOURCE_DIRECTORY)/password.cpp -static-libstdc++

global_variables.o: $(SOURCE_DIRECTORY)/global_variables.cpp
	g++ -I./include -c $(SOURCE_DIRECTORY)/global_variables.cpp -static-libstdc++


clean:
	rm *.o


