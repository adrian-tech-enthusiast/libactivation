#!/usr/bin/sh

# Global Settings.
BASE_NAME='libactivation';
PROJECT_PATH=$(pwd);
CODE_SEARCH_PATHS="$PROJECT_PATH/include $PROJECT_PATH/tests"; # The subdirectories that will contain all you source files (*.h, *.hpp, *.c, *.cpp, etc.)
BUILD_PATH="$PROJECT_PATH/build"; # This is the subdirectory where the compiler will create the binary files and the final executable.
BIN_PATH="$PROJECT_PATH/bin";
APP_NAME="$BASE_NAME.app";
APP_FILE="$BUILD_PATH/$APP_NAME";

# Get the code files to compile.
HEADER_FILES_TO_COMPILE=$(find $CODE_SEARCH_PATHS -maxdepth 3 -type f -name "*.h" -not -path '*/\.*' | sed 's/^\.\///g' | sort);
SOURCE_FILES_TO_COMPILE=$(find $CODE_SEARCH_PATHS -maxdepth 3 -type f -name "*.c" -not -path '*/\.*' | sed 's/^\.\///g' | sort);
FILES_TO_COMPILE="$HEADER_FILES_TO_COMPILE $SOURCE_FILES_TO_COMPILE";

# Go to the project folder.
cd $PROJECT_PATH;

# Clean up build and bin folder.
rm -rf $BUILD_PATH && mkdir -p $BUILD_PATH;
rm -rf $BIN_PATH && mkdir -p $BIN_PATH;

# Build the project.
cd $BUILD_PATH;

gcc -g -fpic -save-temps -Wall -Werror -pedantic-errors -o $APP_NAME $FILES_TO_COMPILE -lm;
if [ $? -ne 0 ]
then
  echo "Compile Failed!"
  exit 1
fi

# Give executable permissions to the APP.
if [ -f "$APP_FILE" ]; then
  chmod +w $APP_FILE;
fi

# Move executables and libraries files to the bin directory.
mv $APP_NAME $BIN_PATH;