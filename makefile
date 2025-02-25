# dlshmas repurposeable extra annotated makefile

Make = make

# dependency directories
libsdeps = libraries/shifter.o libraries/shiftSplitter.o
deps = 

# executable name (for convenience)
target = main
exename = real

# link objects together
$(target): $(deps) $(libsdeps)
	g++ $(libsdeps) $(deps) -o $(exename).exe

# create objects in their directories
$(deps): $(deps:.o=.cpp)
	g++ -c -Wall $(deps:.o=.cpp)

$(libsdeps): $(libsdeps:.o=.cpp)
	$(Make) -C libraries

# runs the .exe file (does not build it)
run:
	./$(target).exe

# gets rid of all object files
clean:
	$(Make) clean -C libraries
	del *.o

# gets rid of all 'made' files
wash:
	del *.exe
	$(Make) clean

# to add dependencies in a new directory:
#
#	> create a variable following the template: directory_namedeps = directory_name/file_1.o directory_name/file_2.o (etc.)
#	> create a function $(directory_name): $(directory_name:.o=.cpp)
#	>		            $(Make) -C directory_name
#	> create a makefile in the new directory. put in a variable: targets = file1.o file2.o (etc.)
#	> create a function $(targets): $(targets:.o=.cpp)
#	>		            g++ -c $(targets:.o=.cpp)
#	> make a function   clean:
#	>		            del *.o
#	> and add a new line to the clean function in this file:
#				    $Make clean -C $(directory_name)
# 
# i think that is all... don't fudge this up. you can do it.
