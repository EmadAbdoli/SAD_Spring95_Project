#pragma once

#include <Windows.h>

static const WORD MAX_CONSOLE_LINES = 500;

#include <stdio.h>

#include <fcntl.h>

#include <io.h>

#include <iostream>

#include <fstream>

void RedirectIOToConsole();