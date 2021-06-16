#pragma once

#include <stdio.h>
#include <stdarg.h>
#include <time.h>

#define LOG_LEVEL_I 0
#define LOG_LEVEL_E 1
#define LOG_LEVEL_F 2

void log(int log_level, const char *func, const char *file, const int line,
         const char *type, const char *format, ...);

void logf(int log_level, const char *func, const char *file, const int line,
          const char *type, const char *format, ...);

#define LOGI(type, format, ...) log(LOG_LEVEL_I,__func__, __FILE__, __LINE__, type, format, ##__VA_ARGS__)
#define LOGE(type, format, ...) log(LOG_LEVEL_E,__func__, __FILE__, __LINE__, type, format, ##__VA_ARGS__)
#define LOGF(type, format, ...) logf(LOG_LEVEL_F,__func__, __FILE__, __LINE__, type, format, ##__VA_ARGS__)


