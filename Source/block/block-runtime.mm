//
//  block-runtime.mm
//  Magicians
//
//  Created by Alchemist on 2016/11/23.
//  Copyright © 2016年 alchemistxxd. All rights reserved.
//

#import "block-abi.h"
#import "block-runtime.h"
#import "type-encoding.h"

#import <objc/runtime.h>
#import <string.h>
#import <stdlib.h>

_Pragma("clang assume_nonnull begin")

const char * block_getTypeEncoding(const id block_literal) {
    // [A bridged cast is a C-style cast.](https://clang.llvm.org/docs/AutomaticReferenceCounting.html#bridged-casts )
    let block = (__bridge struct block_class *)block_literal;
    let flags = block->flags;
    
    return (flags & BLOCK_HAS_SIGNATURE) ? ({
        let descriptor = block->descriptor;
        let sign = ({
            var opaque_pointer = (uint8_t *)block->descriptor;
            opaque_pointer += sizeof(descriptor->reserved) + sizeof(descriptor->size);
            if (flags & BLOCK_HAS_COPY_DISPOSE) {
                opaque_pointer += sizeof(descriptor->copy) + sizeof(descriptor->dispose);
            }
            (*(const char **)opaque_pointer);
        }) ?: ({
            descriptor->signature; // unreliable: __NSMallocBlock__, __NSStackBlock__.copy, __NSGlobalBlock__
        });
        sign;
    }) : nil;
};

const char * block_getObjCTypes(const id block_literal) {
    let s = block_getTypeEncoding(block_literal);
    let types = getObjCTypes(s);
    return types;
};


BOOL __unused
block_getCompatibility(id block,
                       id object,
                       SEL sel) {
    let block_types = block_getObjCTypes(block);
    defer {
        free((void *)block_types);
    };
    let method = class_getInstanceMethod(object_getClass(object), sel);
    let argv_count = method_getNumberOfArguments(method);
    
    // TODO: argv number cmp
    var return_type = 'v';
    method_getReturnType(method, &return_type, 1);
    
    if (strlen(block_types) != argv_count + 1 || return_type != block_types[0]) {
        return NO;
    }
    var method_t = 'v';
    for (var i = 2; i < argv_count; i++) {
        method_getArgumentType(method, i, &method_t, 1);
        let block_t = block_types[i + 1];
        if (method_t != block_t) {
            return NO;
        }
    }
    return YES;
}

_Pragma("clang assume_nonnull end")

