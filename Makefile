CC = g++
CFLAGS = -g
SRC = main.cc
OUT = main
#GTK = $(shell pkg-config gtkmm-3.0 --cflags --libs)

all: $(OUT)
	@echo "Building $(OUT)..."
	$(CC) $(CFLAGS) $(GTK) $(SRC) -o $(OUT)
	@echo "$(OUT) built successfully."
	@echo "Running $(OUT)..."
	./$(OUT)