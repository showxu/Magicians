//
//  Block.mm
//  Magicians
//
//  Created by Alchemist on 2016/11/23.
//  Copyright © 2016年 alchemistxxd. All rights reserved.
//

#import "^Block.h"

#import <Foundation/NSMethodSignature.h>
#import <objc/runtime.h>
#import <simd/simd.h>

_Pragma("clang assume_nonnull begin")

NSMethodSignature * __nullable __unused block_getSignature(const id block_literal) {
    // [A bridged cast is a C-style cast.](https://clang.llvm.org/docs/AutomaticReferenceCounting.html#bridged-casts )
    let block = (__bridge struct block_class *)block_literal;
    let flags = block->flags;
    
    if (flags & BLOCK_HAS_SIGNATURE) {
        let descriptor = block->descriptor;
        let sign = ({
            var opaque_pointer = (uint8_t *)block->descriptor;
            opaque_pointer += sizeof(descriptor->reserved) + sizeof(descriptor->size);
            if (flags & BLOCK_HAS_COPY_DISPOSE) {
                opaque_pointer += sizeof(descriptor->copy) + sizeof(descriptor->dispose);
            }
            (*(const char **)opaque_pointer);
        }) ?: ({
            // Unreliable Block-isa => (__NSMallocBlock__)(__NSStackBlock__.copy) || (__NSGlobalBlock__).
            descriptor->signature;
        });
        let block_sign = [NSMethodSignature signatureWithObjCTypes:sign];
        return block_sign;
    }
    return nil;
};

__attribute((overloadable))
BOOL __unused block_matchSignature(const NSMethodSignature *block_sign,
                                   const NSMethodSignature *method_sign) {
    if ((method_sign.numberOfArguments - block_sign.numberOfArguments != 1) ||
        (method_sign.methodReturnType[0] != block_sign.methodReturnType[0]) ) {
        return NO;
    }
    for (var i = 1; i < block_sign.numberOfArguments; i++) {
        // [if statement](http://en.cppreference.com/w/cpp/language/if )
        // [-std=c++17 (-std=c++1z in Clang 4 and earlier).](http://clang.llvm.org/cxx_status.html#cxx17 ).
        if (let block_t = [block_sign getArgumentTypeAtIndex:i];
            let method_t = [method_sign getArgumentTypeAtIndex:i + 1]) {
            if (!method_t || !block_t || method_t[0] != block_t[0]) {
                return NO;
            }
        }
    }
    return YES;
}

__attribute((overloadable))
BOOL __unused block_matchSignature(const id block_literal,
                                   id object,
                                   SEL selector) {
    let block_sign = block_getSignature(block_literal);
    let method_sign = [[object class] instanceMethodSignatureForSelector:selector];
    return block_matchSignature(block_sign, method_sign);
}

_Pragma("clang assume_nonnull end")

