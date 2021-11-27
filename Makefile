TARGET=main
all: *.c++
	g++  -w 1579f.c++ -o $(TARGET)
	./$(TARGET) < a.txt

clean:
	rm $(TARGET)