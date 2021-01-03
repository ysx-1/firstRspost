#ifndef __OAM_LOG_H
#define __OAM_LOG_H
/*
	文件说明：
	保存LOG相关 
*/
#include "../prepare.h"
enum LOG_LEVEL{
	LEV_OFF   = 0,
	LEV_ERROR = 1,
	LEV_WARN  = 2,
	LEV_INFO  = 3,
	LEV_DEBUG = 4,
	LEV_TOP   = 5,
};
oal_uint16 print_level = LEV_DEBUG;
#define print_level LEV_DEBUG

//void save_log_function(oal_int8* format, ...);

#define LOG(level, format, ...){\
    if(level <= print_level){\
        printf("[SERVER_DEBUG][%s,%s:%d]:" format, __FILE__, __FUNCTION__, __LINE__,##__VA_ARGS__);\
    }\
}
//save_log_function(format, ##__VA_ARGS__);
#endif