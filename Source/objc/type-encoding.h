//
//  type-encoding.h
//  Magicians
//
//  Created by Alchemist on 2017/12/5.
//  Copyright © 2017年 alchemistxxd. All rights reserved.
//

// [ObjC runtime Type Encodings](https://developer.apple.com/library/content/documentation/Cocoa/Conceptual/ObjCRuntimeGuide/Articles/ocrtTypeEncodings.html )

_Pragma("once")


/**
  filter ObjCTypes with the given char[]

 @param types char[] to look up
 
 @return ObjcTypes. You must free the array with \c free().
 */
#if defined(__cplusplus)
    extern "C"
#else
    extern
#endif
char * getObjCTypes(const char types[]);

