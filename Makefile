src_get_opt 		= Source_files/GetOptions.c
src_api_hdr_get_opt = Source_files/GetOptions_api.h
api_api_hdr_get_opt	= API/Header_files

so_opt				= API/Dynamic_libraries/libGetOptions.so

shell_dirs			= Shell_files/directories.sh

all: directories clean opt.so header msg

directories:
	@./$(shell_dirs)

clean:
	rm -rf API/Dynamic_libraries/* API/Header_files/*

opt.so: $(src_get_opt)
	gcc -Wall -g -fPIC -shared $(src_get_opt) -o $(so_opt)

header:
	cp $(src_api_hdr_get_opt) $(api_api_hdr_get_opt)

msg:
	@echo "**************************************************************************************";
	