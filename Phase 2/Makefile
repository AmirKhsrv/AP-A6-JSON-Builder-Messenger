CC := g++ -std=c++11

all: 2.out

2.out: main.o Messenger.o Channel.o ChannelObserver.o ChannelBot.o Exceptions.o
	$(CC) main.o Messenger.o Channel.o ChannelObserver.o ChannelBot.o  Exceptions.o -o 2.out

main.o: main.cpp Messenger.hpp Channel.hpp ChannelObserver.hpp ChannelBot.hpp Exceptions.hpp
	$(CC) -c main.cpp -o main.o

Messenger.o: Messenger.hpp Messenger.cpp Channel.hpp ChannelObserver.hpp ChannelBot.hpp Exceptions.hpp
	$(CC) -c Messenger.cpp -o Messenger.o

Channel.o: Channel.hpp Channel.cpp ChannelObserver.hpp ChannelBot.hpp Exceptions.hpp
	$(CC) -c Channel.cpp -o Channel.o

ChannelObserver.o: ChannelObserver.hpp ChannelObserver.cpp ChannelBot.hpp Exceptions.hpp
	$(CC) -c ChannelObserver.cpp -o ChannelObserver.o

ChannelBot.o: ChannelBot.hpp ChannelBot.cpp Exceptions.hpp Channel.hpp
	$(CC) -c ChannelBot.cpp -o ChannelBot.o

Exceptions.o: Exceptions.hpp Exceptions.cpp
	$(CC) -c Exceptions.cpp -o Exceptions.o

clean:
	rm -r *.o
	rm -r *.out