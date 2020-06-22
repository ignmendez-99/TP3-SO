CC = gcc
CFLAGS = -Wall -std=c99 -pedantic
ALL_OBJ = *.o
MY_SERVER_OBJ = myServer.o
CLIENT_OBJ = client.o
MY_SERVER_OUT = myServer
CLIENT_OUT = client
QUINE_OUT = quine

all: $(MY_SERVER_OUT) $(CLIENT_OUT)

$(MY_SERVER_OUT): $(MY_SERVER_OBJ)
	$(CC) -o $(MY_SERVER_OUT) $(MY_SERVER_OBJ) $(CFLAGS)

$(CLIENT_OUT): $(CLIENT_OBJ)
	$(CC) -o $(CLIENT_OUT) $(CLIENT_OBJ) $(CFLAGS)

clean:
	rm -rf $(CLIENT_OUT) $(MY_SERVER_OUT) $(QUINE_OUT) $(CLIENT_OBJ) $(MY_SERVER_OBJ)

.PHONY: all clean