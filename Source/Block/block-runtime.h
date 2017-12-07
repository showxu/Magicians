
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
 * Returns the type encoding of a specified block invoke.
 *
 * @param block The block to look up.
 *
 * @return The type encoding of the block invoke, or \c nil if the block
 *  does not have a signature.
 */
OBJC_EXPORT const char * _Nullable
block_getTypeEncoding(id _Nonnull block)
    OBJC_AVAILABLE(10.0, 2.0, 9.0, 1.0, 2.0);

/**
 * Returns the objc types (aka filtered type encoding) of a specified block invoke.
 *
 * @param block The block literal to look up.
 *
 * @return The objc types for the block, or \c nil if the block
 *  does not have a signature.
 *
 * @note You must free the string with \c free().
 */
OBJC_EXPORT const char * _Nullable
block_copyObjCTypes(id _Nonnull block)
    OBJC_AVAILABLE(10.0, 2.0, 9.0, 1.0, 2.0);

/**
 * Returns the number of arguments accepted by a block.
 *
 * @param block Pass the block in question.
 *
 * @return A size_t containing the number of arguments accepted by the given block.
 */
OBJC_EXPORT size_t
block_getNumberOfArguments(id _Nonnull block)
    OBJC_AVAILABLE(10.0, 2.0, 9.0, 1.0, 2.0)
        __attribute__((enable_if(0, "unavailable")));

/**
 * Returns a string describing a block's return type.
 *
 * @param block The block to inspect.
 *
 * @return A C string describing the return type. You must free the string with \c free().
 */
OBJC_EXPORT char * _Nonnull
block_copyReturnType(id _Nonnull block)
    OBJC_AVAILABLE(10.5, 2.0, 9.0, 1.0, 2.0)
        __attribute__((enable_if(0, "unavailable")));

/**
 * Returns a string describing a single parameter type of a block.
 *
 * @param block The block to inspect.
 * @param index The index of the parameter to inspect.
 *
 * @return A C string describing the type of the parameter at index \e index, or \c NULL
 *  if block has no parameter index \e index. You must free the string with \c free().
 *
 * @note block first argument represents this block self, which means when index == 1, the type encoding is @?
 */
OBJC_EXPORT char * _Nullable
block_copyArgumentType(id _Nonnull block, unsigned int index)
    OBJC_AVAILABLE(10.5, 2.0, 9.0, 1.0, 2.0)
        __attribute__((enable_if(0, "unavailable")));

/**
 * Returns by reference a string describing a block's return type.
 *
 * @param block The block you want to inquire about.
 * @param dst The reference string to store the description.
 * @param dst_len The maximum number of characters that can be stored in \e dst.
 *
 * @note The block's return type string is copied to \e dst.
 *  \e dst is filled as if \c strncpy(dst, parameter_type, dst_len) were called.
 */
OBJC_EXPORT void
block_getReturnType(id _Nonnull block, char * _Nonnull dst, size_t dst_len)
    OBJC_AVAILABLE(10.5, 2.0, 9.0, 1.0, 2.0)
        __attribute__((enable_if(0, "unavailable")));

/**
 * Returns by reference a string describing a single parameter type of a block.
 *
 * @param block The block you want to inquire about.
 * @param index The index of the parameter you want to inquire about.
 * @param dst The reference string to store the description.
 * @param dst_len The maximum number of characters that can be stored in \e dst.
 *
 * @note The parameter type string is copied to \e dst. \e dst is filled as if \c strncpy(dst, parameter_type, dst_len)
 *  were called. If the block contains no parameter with that index, \e dst is filled as
 *  if \c strncpy(dst, "", dst_len) were called.
 */
OBJC_EXPORT void
block_getArgumentType(id _Nonnull block, unsigned int index,
                       char * _Nullable dst, size_t dst_len)
    OBJC_AVAILABLE(10.5, 2.0, 9.0, 1.0, 2.0)
        __attribute__((enable_if(0, "unavailable")));

/**
 * Returns the ObjCTypes compatibility of a specified block with given object.
 *
 * @param block The block literal to look up.
 * @param cls The objc_class
 * @param sel The objc_selector
 *
 * @return YES for match, vice versa.
 */
OBJC_EXPORT BOOL __unused
block_getObjcTypesCompatibility(id _Nonnull block, Class _Nonnull cls, SEL sel)
    OBJC_AVAILABLE(10.0, 2.0, 9.0, 1.0, 2.0)
        __attribute__((enable_if(0, "unavailable")));

_Pragma("clang assume_nonnull end")


