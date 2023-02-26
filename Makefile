src_get_opt 		= Source_files/GetOptions.c
src_api_hdr_get_opt = Source_files/GetOptions_api.h
api_api_hdr_get_opt	= API/Header_files

deps_h_org			= /home/jon/Desktop/scripts/C/C_Severity_Log/Source_files/SeverityLog_api.h
deps_h_dst			= Dependency_files/Header_files/SeverityLog_api.h

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

getdeps:
	cp $(deps_h_org)  $(deps_h_dst)

msg:
	@echo "**************************************************************************************";
	