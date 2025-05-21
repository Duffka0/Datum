exec = build/datum.dll
compiler = g++
linker = g++
stdver = 17

src = $(shell find ./src -name '*.cpp')
obj = $(src:.cpp=.o)

srch = $(shell find ./include -name '*.hpp')
objh = $(srch:.hpp=.hpp.gch) # Precompiled headers

# Compile flags
cmp_flags =\
	-m64\
	-Werror\
	-Wall\
	-Wextra\
	-g\
	-std=c++$(stdver)\
	-static\
	-static-libstdc++\
	-static-libgcc\

inc = -I include

# Command to compile source files to object files
obj_command =\
	$(compiler) $(cmp_flags) $(inc) -c $< -o $@ -Wl,-Bstatic

# Command to link object files into static library ( exec )
link_command =\
	$(linker) $(cmp_flags) -shared $(obj) -o $(exec)

# Link recipe
$(exec): $(objh) $(obj)
	$(link_command)

# Compile (.cpp) recipe
%.o: %.cpp
	$(obj_command)

# Compile (.hpp) recipe (Precompiled headers)
%.hpp.gch: %.hpp
	$(obj_command)

# Clean objects, output, and precompiled headers
.PHONY: full_clean
full_clean:
	rm -f $(obj)
	rm -f $(objh)
	rm -f $(exec)