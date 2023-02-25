src_get_opt = Source_files/GetOptions.c

so_opt		= Dynamic_libraries/libGetOptions.so

shell_dirs	= Shell_files/directories.sh

all: directories clean opt.so msg

directories:
	@./$(shell_dirs)

opt.so: $(src_get_opt)
	gcc -Wall -g -fPIC -shared $(src_get_opt) -o $(so_opt)

clean:
	rm -rf Dynamic_libraries/*

msg:
	@echo "**************************************************************************************";
	