//
//  type-encoding.h
//  Magicians
//
//  Created by Alchemist on 2017/12/5.
//  Copyright © 2017年 alchemistxxd. All rights reserved.
//

#import <stdbool.h>
#import <stddef.h>

_Pragma("once")

// [ObjC runtime Type Encodings](https://developer.apple.com/library/content/documentation/Cocoa/Conceptual/ObjCRuntimeGuide/Articles/ocrtTypeEncodings.html )

_Pragma("clang assume_nonnull begin")

#if defined(__cplusplus)
extern "C" {
#endif
    
/**
 Return objc Types with the given c type encoding

 @param types The types you want to look up
 
 @return ObjcTypes. You must free the c string with \c free().
 */
extern char * _Nullable
    copyObjCTypes(const char types[_Nonnull]);
    
    
/**
 Return by reference objc types with the given c type encoding
 
 @param types The types you want to look up
 @param dst The reference string to store the description.
 @param dst_len The maximum number of characters that can be stored in \e dst.
 */
extern void
    getObjCTypes(const char types[_Nonnull], char * _Nullable dst, size_t dst_len);
    
/**
 Returns a string describing a single type from types.
 
 @param types The types you want to inquire about.
 @param index The index of the parameter you want to inquire about.
 @param dst The reference string to store the description.
 @param dst_len The maximum number of characters that can be stored in \e dst.
 
 @return A objc type. You must free the c string with \c free().
*/
extern char * _Nullable
    copyObjCType(const char types[_Nonnull], unsigned int index, char * _Nullable dst, size_t dst_len);


#if defined(__cplusplus)
}
#endif

_Pragma("clang assume_nonnull end")
