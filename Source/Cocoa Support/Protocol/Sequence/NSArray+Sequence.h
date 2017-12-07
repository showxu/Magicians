//
//  NSArray+Magicians.h
//  Magicians
//
//  Created by Alchemist on 2017/11/21.
//  Copyright © 2017年 alchemistxxd. All rights reserved.
//

#import "Sequence.h"
#import <Foundation/NSArray.h>

_Pragma("clang assume_nonnull begin")


@interface NSArray<T>(FastEnumeration) <FastEnumeration>

- (T)enumeratedType;

@end


@interface NSArray<T>()

- (NSArray<T> *)copy
    __attribute__((objc_requires_super));

- (NSMutableArray<T> *)mutableCopy
    __attribute__((objc_requires_super));

@end


@interface NSArray<T>(Sequence) <Sequence>

- (__nullable T (^)(BOOL (^by)(T x, T y)))min;

- (__nullable T (^)(BOOL (^by)(T x, T y)))max;

- (NSArray *(^)(id (^transform)(T value)))map;

- (NSArray<T> *(^)(BOOL (^isIncluded)(T value)))filter;

- (NSArray *(^)(void (^)(T)))forEach;

@end

_Pragma("clang assume_nonnull end")

