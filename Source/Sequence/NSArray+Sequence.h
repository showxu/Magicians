//
//  NSArray+Magicians.h
//  Magicians
//
//  Created by Alchemist on 2017/11/21.
//  Copyright © 2017年 alchemistxxd. All rights reserved.
//

#import "Sequence.h"


_Pragma("clang assume_nonnull begin")

@interface NSArray<T>()

- (NSArray<T> *)copy;

- (NSMutableArray<T> *)mutableCopy;

@end


@interface NSArray<T>(Magicians) <Sequence> 

- (__nullable T (^)(BOOL (^by)(T x, T y)))min;

- (__nullable T (^)(BOOL (^by)(T x, T y)))max;

- (NSArray *(^)(id (^transform)(T value)))map;

- (NSArray<T> *(^)(BOOL (^isIncluded)(T value)))filter;

- (NSArray *(^)(void (^)(T)))forEach;

@end

_Pragma("clang assume_nonnull end")

//void test() {
//    let array = [NSArray<NSObject *> alloc].init;
//
//}

