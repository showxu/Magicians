
//
//  block-runtime.h
//  Magicians
//
//  Created by Alchemist on 2017/12/5.
//  Copyright © 2017年 alchemistxxd. All rights reserved.
//

_Pragma("once")

#import <objc/objc.h>

_Pragma("clang assume_nonnull begin")

/**
 * Returns the method type encoding (aka signature) of a specified block.
 *
 * @param block The block literal to look up.
 *
 * @return The type encoding (aka signature) for the block, or \c nil if the block
 *  does not have a signature.
 *
 */
OBJC_EXPORT const char *
block_getTypeEncoding(const id block)
    OBJC_AVAILABLE(10.0, 2.0, 9.0, 1.0, 2.0);

/**
 * Returns the ObjC types (aka filtered type encoding) of a specified block.
 *
 * @param block The block literal to look up.
 *
 * @return The ObjC types for the block, or \c nil if the block
 *  does not have a signature.
 *
 * @note You must free the ObjCTypes char * with \c free().
 */
OBJC_EXPORT const char *
block_getObjCTypes(const id block)
    OBJC_AVAILABLE(10.0, 2.0, 9.0, 1.0, 2.0);

/**
 * Returns the ObjCTypes compatibility of a specified block with given object.
 *
 * @param block The block literal to look up.
 * @param object The objc_object
 * @param sel The objc_selector
 *
 * @return YES for match, vice versa.
 */
OBJC_EXPORT BOOL __unused
block_getCompatibility(const id block, const id object, const SEL sel)
    OBJC_AVAILABLE(10.0, 2.0, 9.0, 1.0, 2.0);

_Pragma("clang assume_nonnull end")

