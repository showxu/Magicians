//
//
//  Created by Alchemist on 2016/12/1.
//  Copyright © 2017年 alchemistxxd. All rights reserved.
//


#ifndef __objc_meta__
#define __objc_meta__

/*
#if defined(DEBUG) && !defined(NDEBUG)
    #define become_keyword \
        autoreleasepool {}
#else
    #define become_keyword \
        try {} @catch (...) {}
#endif

// Introduce Swift keyPath into objc family

#define keyPath(...) \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Warc-repeated-use-of-weak\"") \
metamacro_if_eq(1, metamacro_argcount(__VA_ARGS__))(keypath1(__VA_ARGS__))(keypath2(__VA_ARGS__)) \
_Pragma("clang diagnostic pop") \

#if defined(DEBUG) && !defined(NDEBUG)
    #define __keyPath_1__(keyPath) \
        ((void)(NO && ((void)keyPath, NO)), ({ \
            char *__keyPath__ = strchr(# keyPath, '.'); \
            assert(__keyPath__); \
            __keyPath__ + 1; \
        }))
#else
    #define __keyPath_1__(p) \
        ((void)NO, ({ strchr(c_string(p), '.') + 1; }))
#endif

#if defined(DEBUG) && !defined(NDEBUG)
    #define __keyPath_2__(o, p) \
        ((void)(NO && ((void)o.p, NO)), #p)
#else
    #define __keyPath_2__(o, p) \
        c_string(p)
#endif


#define NSLog(format, ...) \
    do { \
        fprintf(stderr, "<%s : %d> %s\n", \
        [[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], \
            __LINE__, __func__); \
        (NSLog)((format), ##__VA_ARGS__); \
        fprintf(stderr, "-----------\n"); \
    } while (0)


#endif
 */
