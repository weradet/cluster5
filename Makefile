  #the compiler: gcc for C program, define as g++ for C++
  CC = g++

  # compiler flags:
  #  -g    adds debugging information to the executable file
  #  -Wall turns on most, but not all, compiler warnings
  CFLAGS  = -g -Wall

  # the build target executable:
  TARGET = main
  FILEMAIN = main.cpp
  CLASS = Ui.cpp station.cpp Status.cpp Path.cpp Station_Controller.cpp Register.cpp TopupCard.cpp Buy_ticket.cpp ViewCycleTimes.cpp domainclass.cpp  StationList.cpp Renewcard.cpp Round.cpp node_Addstation.cpp Node_time.cpp 
  all: 
 
	$(CC) $(FILEMAIN) $(CLASS) $(CFLAGS)  -o $(TARGET)

  clean:
	rm $(TARGET)