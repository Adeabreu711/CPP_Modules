#!/bin/bash

if [ $# -ne 1 ]; then
	echo "Usage: ./GenerateClass.sh ClassName"
	exit 1
fi

CLASS_NAME=$1

UPPER_NAME=$(echo $CLASS_NAME | tr '[:lower:]' '[:upper:]')

SCRIPT_DIR=$(dirname "$0")

if [ -f "${CLASS_NAME}.hpp" ] || [ -f "${CLASS_NAME}.cpp" ]; then
	echo "Error: files already exist."
	exit 1
fi

cp ${SCRIPT_DIR}/templates/Template.hpp ${CLASS_NAME}.hpp
cp ${SCRIPT_DIR}/templates/Template.cpp ${CLASS_NAME}.cpp

sed -i "s/Template/${CLASS_NAME}/g" ${CLASS_NAME}.hpp
sed -i "s/Template/${CLASS_NAME}/g" ${CLASS_NAME}.cpp

sed -i "s/TEMPLATE/${UPPER_NAME}/g" ${CLASS_NAME}.hpp

echo "Class ${CLASS_NAME} created successfully."
