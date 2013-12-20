#ifndef MESSAGES
#define MESSAGES
const char* HELP_MESSAGE = "Program must be run with 4 arguments\nName of output ppm file\nWidth of image\nHeight of image\nMax iteration\nExample execution command: main.exe test.ppm 400 400 1000";
const char* BAD_WIDTH_HEIGHT_OR_MAX_ITERATIONS = "Bad width,height or max iterations parameter, all of them must be a valid integer number";
const char* FAILED_TO_CREATE_FILE = "Failed to create output file";
#endif