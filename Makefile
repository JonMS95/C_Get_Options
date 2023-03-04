src_get_opt 		= Source_files/GetOptions.c

so_opt				= Dynamic_libraries/libGetOptions.so

shell_dirs	= Shell_files/directories.sh
shell_deps	= Shell_files/get_deps.sh
shell_API	= Shell_files/make_api.sh

all: directories clean deps opt.so api msg

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

msg:
	@echo "**************************************************************************************";
	