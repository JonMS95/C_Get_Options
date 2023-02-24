src_get_opt = Source_files/GetOptions.c

so_mult		= Dynamic_libraries/libGetOptions.so

shell_dirs	= Shell_files/directories.sh
shell_test	= Shell_files/test.sh

# all: directories clean main msg test
all: directories clean mult.so msg

directories:
	@./$(shell_dirs)

mult.so: $(src_get_opt)
	gcc -Wall -g -fPIC -shared $(src_get_opt) -o $(so_mult)

clean:
	rm -rf Dynamic_libraries/*

msg:
	@echo "**************************************************************************************";

# test:
# 	@./$(shell_test)