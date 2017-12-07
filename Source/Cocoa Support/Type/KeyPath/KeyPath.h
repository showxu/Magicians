//
//  KeyPath.h
//  Magicians
//
//  Created by Alchemist on 2017/12/3.
//  Copyright © 2017年 alchemistxxd. All rights reserved.
//

_Pragma("once")

#import <objc/NSObject.h>

// Introduce Swift keyPath into objc family
#pragma mark - Swift KeyPath

#   define keyPath(...) \
        _Pragma("clang diagnostic push") \
        _Pragma("clang diagnostic ignored \"-Warc-repeated-use-of-weak\"") \
            metamacro_if_eq(1, metamacro_argcount(__VA_ARGS__))(keypath1(__VA_ARGS__))(keypath2(__VA_ARGS__)) \
        _Pragma("clang diagnostic pop") \

#   if defined(DEBUG) && !defined(NDEBUG)
#       define __keyPath_1__(keyPath) \
            ((void)(NO && ((void)keyPath, NO)), ({ \
            char *__keyPath__ = strchr(# keyPath, '.'); \
            assert(__keyPath__); \
            __keyPath__ + 1; \
        }))
#   else
#       define __keyPath_1__(p) \
            ((void)NO, ({ strchr(c_string(p), '.') + 1; }))
#   endif

#   if defined(DEBUG) && !defined(NDEBUG)
#       define __keyPath_2__(o, p) \
            ((void)(NO && ((void)o.p, NO)), #p)
#   else
#       define __keyPath_2__(o, p) \
            c_string(p)
#   endif


// KeyPath
__attribute__((objc_subclassing_restricted))
__attribute__((objc_runtime_name("__KeyPath__")))
@interface KeyPath<Key, Value> : NSObject

@end
