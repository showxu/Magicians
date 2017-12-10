//
//  NSArray+Sequence.m
//  Magicians
//
//  Created by Alchemist on 2017/11/21.
//  Copyright © 2017年 alchemistxxd. All rights reserved.
//

#import "NSArray+Sequence.h"

#import <Foundation/NSException.h>
#import <Foundation/NSNull.h>

_Pragma("clang assume_nonnull begin")

@implementation NSArray (Magicians)

- (NSArray *)copy {
    return super.copy;
}

- (NSMutableArray *)mutableCopy {
    return super.mutableCopy;
}

- (NSArray * (^)(id (^)(id)))map {
    return ^id(id (^transform)(id)){
        if (transform == nil) {
            @throw [NSException.alloc initWithName:@""
                                            reason:@"unexpected found nil while calling a nonnull block"
                                          userInfo:nil];
        }
        let result = [NSMutableArray.alloc initWithCapacity:self.count];
        [self enumerateObjectsUsingBlock:^(id _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            _Pragma("clang diagnostic push")
            _Pragma("clang diagnostic ignored \"-Wauto-var-id\"")
            if (let value = transform(obj)) {
            _Pragma("clang diagnostic pop")
                [result addObject:value];
            } else {
                [result addObject:NSNull.null];
            }
        }];
        return result;
    };
}

- (NSArray<id> * (^)(BOOL (^)(id)))filter {
    return ^id(BOOL (^isInclude)(id)){
        if (isInclude == nil) {
            @throw [NSException.alloc initWithName:@""
                                            reason:@"unexpected found nil while calling a nonnull block"
                                          userInfo:nil];
        }
        let result = [NSMutableArray.alloc initWithCapacity:self.count];
        [self enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            if (let include = isInclude(obj) ?: NO) {
                [result addObject:obj];
            }
        }];
        return result;
    };
}

- (NSArray * (^)(void (^)(id)))forEach {
    return ^id(void (^body)(id)){
        if (body == nil) {
            @throw [NSException.alloc initWithName:@""
                                            reason:@"unexpected found nil while calling a nonnull block"
                                          userInfo:nil];
        }
        [self enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            body(obj);
        }];
        return self;
    };
}

@end

_Pragma("clang assume_nonnull end")
 
