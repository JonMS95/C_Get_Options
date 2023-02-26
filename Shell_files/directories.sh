#!/bin/sh

if [ ! -d API ]; then
    mkdir API
fi

if [ ! -d API/Dynamic_libraries ]; then
    mkdir API/Dynamic_libraries
fi

if [ ! -d API/Header_files ]; then
    mkdir API/Header_files
fi

if [ ! -d Dependency_files ]; then
    mkdir Dependency_files
fi

if [ ! -d Dependency_files/Header_files ]; then
    mkdir Dependency_files/Header_files
fi

if [ ! -d Dependency_files/Dynamic_libraries ]; then
    mkdir Dependency_files/Dynamic_libraries
fi