//
//  Block.h
//  Magicians
//
//  Created by Alchemist on 2016/11/23.
//  Copyright © 2016年 alchemistxxd. All rights reserved.
//

#import <Foundation/NSObjCRuntime.h>
#import <os/base.h>

@class NSMethodSignature;

_Pragma("clang assume_nonnull begin")

/// [Block Implementation Specification](https://clang.llvm.org/docs/Block-ABI-Apple.html)
///
///
/// [High Level](http://clang.llvm.org/docs/Block-ABI-Apple.html#high-level)
///
/// The following flags bits are in use thusly for a possible ABI.2010.3.16:
///
///     enum {
///         BLOCK_HAS_COPY_DISPOSE =  (1 << 25),
///         BLOCK_HAS_CTOR =          (1 << 26), // helpers have C++ code
///         BLOCK_IS_GLOBAL =         (1 << 28),
///         BLOCK_HAS_STRET =         (1 << 29), // IFF BLOCK_HAS_SIGNATURE
///         BLOCK_HAS_SIGNATURE =     (1 << 30),
///     };
///
/// In 10.6.ABI the (1<<29) was usually set and was always ignored by the runtime - it had been a transitional marker that did not get deleted after the transition. This bit is now paired with (1<<30), and represented as the pair (3<<30), for the following combinations of valid bit settings, and their meanings:
///
///     switch (flags & (3<<29)) {
///         case (0<<29):      10.6.ABI, no signature field available
///         case (1<<29):      10.6.ABI, no signature field available
///         case (2<<29): ABI.2010.3.16, regular calling convention, presence of signature field
///         case (3<<29): ABI.2010.3.16, stret calling convention, presence of signature field,
///     }
typedef NS_OPTIONS(int, block_flags) {
    BLOCK_HAS_COPY_DISPOSE =   (1 << 25),
    BLOCK_HAS_CTOR =          (1 << 26), // helpers have C++ code
    BLOCK_IS_GLOBAL =         (1 << 28),
    BLOCK_HAS_STRET =         (1 << 29), // IFF BLOCK_HAS_SIGNATURE
    BLOCK_HAS_SIGNATURE =     (1 << 30)
};

/// The ABI of Blocks consist of their layout and the runtime functions required by the compiler. A Block consists of a structure of the following form:
///
///     struct Block_literal_1 {
///         void *isa; // initialized to &_NSConcreteStackBlock or &_NSConcreteGlobalBlock
///         int flags;
///         int reserved;
///         void (*invoke)(void *, ...);
///         struct Block_descriptor_1 {
///             unsigned long int reserved;         // NULL
///             unsigned long int size;         // sizeof(struct Block_literal_1)
///             // optional helper functions
///             void (*copy_helper)(void *dst, void *src);     // IFF (1<<25)
///             void (*dispose_helper)(void *src);             // IFF (1<<25)
///             // required ABI.2010.3.16
///             const char *signature;                         // IFF (1<<30)
///         } *descriptor;
///         // imported variables
///     };
///
/// As an example, the Block literal expression:
///
///     `^ { printf("hello world\n"); }`
///
/// would cause the following to be created on a 32-bit system:
///
///     struct __block_literal_1 {
///         void *isa;
///         int flags;
///         int reserved;
///         void (*invoke)(struct __block_literal_1 *);
///         struct __block_descriptor_1 *descriptor;
///     };
///
///     void __block_invoke_1(struct __block_literal_1 *_block) {
///         printf("hello world\n");
///     }
///
///     static struct __block_descriptor_1 {
///         unsigned long int reserved;
///         unsigned long int Block_size;
///     } __block_descriptor_1 = { 0, sizeof(struct __block_literal_1), __block_invoke_1 };
///
/// and where the Block literal itself appears:
///
///     struct __block_literal_1 _block_literal = {
///         &_NSConcreteStackBlock,
///         (1<<29), <uninitialized>,
///         __block_invoke_1,
///         &__block_descriptor_1
///     };

struct block_class {
    Class isa; // initialized to &_NSConcreteStackBlock or &_NSConcreteGlobalBlock
    block_flags flags;
    int reserved;
    void (__unused *invoke)(struct block_class *, ...);
    struct {
        unsigned long int reserved;         // NULL
        unsigned long int size;             // sizeof(struct block_class)
        // optional helper functions
        void (*copy)(void *dst, void *src);     // IFF (1<<25)
        void (*dispose)(void *src);             // IFF (1<<25)
        // required ABI.2010.3.16
        const char *signature;
        // IFF (1<<30)
    } *descriptor;
    // imported variables
};

typedef struct block_class * Block;

/**
 * Returns the method signature definition of a specified block.
 *
 * @param block_literal The block literal to look up.
 *
 * @return The \c NSMethodSignature object for the block, or \c nil if the block
 *  does not have a signature.
 */
OBJC_EXPORT
NSMethodSignature * __nullable __unused block_getSignature(const id block_literal)
    OBJC_AVAILABLE(10.0, 2.0, 9.0, 1.0, 2.0);

/**
 * Returns the method signature definition of a specified block.
 *
 * @param block_sign The invoke signature of block literal.
 * @param method_sign The method sigature of objc_object.
 *
 * @return The \c NSMethodSignature object for the block, or \c nil if the block
 *  does not have a signature.
 */
OBJC_EXPORT __attribute((overloadable))
BOOL __unused block_matchSignature(const NSMethodSignature *block_sign, const NSMethodSignature *method_sign)
    OBJC_AVAILABLE(10.0, 2.0, 9.0, 1.0, 2.0);

/**
 * Returns the method signature definition of a specified block.
 *
 * @param block_literal The block literal to look up.
 * @param object The objc_objec
 * @param selector The objc_selector
 *
 * @return The \c NSMethodSignature object for the block, or \c nil if the block
 *  does not have a signature.
 */
OBJC_EXPORT __attribute((overloadable))
BOOL __unused block_matchSignature(const id block_literal, const id object, const SEL selector)
    OBJC_AVAILABLE(10.0, 2.0, 9.0, 1.0, 2.0);

_Pragma("clang assume_nonnull end")
