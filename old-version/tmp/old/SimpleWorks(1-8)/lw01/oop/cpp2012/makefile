CC = g++
CFLAGS = -O0 -D DEBUG

BUILD_PATH = _build/obj/
BUILD_PATHEXE = _build/

OBJ_TRANS  = $(BUILD_PATH)container_Constr.o $(BUILD_PATH)container_In.o $(BUILD_PATH)container_Out.o \
	$(BUILD_PATH)main.o \
	$(BUILD_PATH)rectangle_In.o $(BUILD_PATH)rectangle_Out.o \
	$(BUILD_PATH)shape_In.o \
	$(BUILD_PATH)triangle_In.o $(BUILD_PATH)triangle_Out.o

all : labwork

labwork : $(OBJ_TRANS)
	$(CC) -o $(BUILD_PATHEXE)labwork $(OBJ_TRANS) $(LIB_TRANS)

$(BUILD_PATH)container_Constr.o : container_atd.h container_Constr.cpp
	$(CC) $(CFLAGS) -c container_Constr.cpp -o $(BUILD_PATH)container_Constr.o

$(BUILD_PATH)container_In.o : container_atd.h container_In.cpp
	$(CC) $(CFLAGS) -c container_In.cpp -o $(BUILD_PATH)container_In.o

$(BUILD_PATH)container_Out.o : container_atd.h container_Out.cpp
	$(CC) $(CFLAGS) -c container_Out.cpp -o $(BUILD_PATH)container_Out.o

$(BUILD_PATH)main.o : container_atd.h main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o $(BUILD_PATH)main.o

$(BUILD_PATH)rectangle_In.o : rectangle_atd.h rectangle_In.cpp
	$(CC) $(CFLAGS) -c rectangle_In.cpp -o $(BUILD_PATH)rectangle_In.o

$(BUILD_PATH)rectangle_Out.o : rectangle_atd.h rectangle_Out.cpp
	$(CC) $(CFLAGS) -c rectangle_Out.cpp -o $(BUILD_PATH)rectangle_Out.o

$(BUILD_PATH)shape_In.o : shape_atd.h rectangle_atd.h triangle_atd.h shape_In.cpp
	$(CC) $(CFLAGS) -c shape_In.cpp -o $(BUILD_PATH)shape_In.o

$(BUILD_PATH)shape_Out.o : shape_atd.h shape_Out.cpp
	$(CC) $(CFLAGS) -c shape_Out.cpp -o $(BUILD_PATH)shape_Out.o

$(BUILD_PATH)triangle_In.o : triangle_atd.h triangle_In.cpp
	$(CC) $(CFLAGS) -c triangle_In.cpp -o $(BUILD_PATH)triangle_In.o

$(BUILD_PATH)triangle_Out.o : triangle_atd.h triangle_Out.cpp
	$(CC) $(CFLAGS) -c triangle_Out.cpp -o $(BUILD_PATH)triangle_Out.o

clean :
	rm _build/obj/*.o
	rm _build/labwork