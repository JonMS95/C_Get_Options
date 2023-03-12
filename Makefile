src_get_opt	= Source_files/GetOptions.c
src_main	= Source_files/main.c

so_opt		= Dynamic_libraries/libGetOptions.so

obj_main	= Object_files/main.o

exe_main	= Executable_files/main

shell_dirs	= Shell_files/directories.sh
shell_deps	= Shell_files/get_deps.sh
shell_API	= Shell_files/make_api.sh
shell_test	= Shell_files/test.sh

all_but_test: directories clean deps opt.so api msg

all: all_but_test main.o main rm_obj msg test

directories:
	@./$(shell_dirs)

clean:
	rm -rf API/Dynamic_libraries/* API/Header_files/*

deps:
	@./$(shell_deps)

opt.so: $(src_get_opt)
	gcc -Wall -g -fPIC -shared $(src_get_opt) -o $(so_opt)

api:
	@./$(shell_API)

main.o:
	gcc -Wall -g -c $(src_main) -o $(obj_main)

main:
	gcc -g -Wall $(obj_main) -LDynamic_libraries -lGetOptions -LDependency_files/Dynamic_libraries -lSeverityLog -o $(exe_main)

rm_obj:
	rm -rf Object_files

msg:
	@echo "**************************************************************************************************"
	@echo "Don't forget to set the path:"
	@echo "export LD_LIBRARY_PATH=~/Desktop/scripts/C/C_Get_Options/Dynamic_libraries"
	@echo "**************************************************************************************************"

test:
	@./$(shell_test)