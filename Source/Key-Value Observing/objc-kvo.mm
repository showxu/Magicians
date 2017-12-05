//
//  NSObject+Key_Value_Observing.m
//  Magicians
//
//  Created by Alchemist on 2017/11/28.
//  Copyright © 2017年 alchemistxxd. All rights reserved.
//

#import "objc-kvo.h"
#import "objc-runtime.h"

#import <Foundation/Foundation.h>
#import <string>
#import <objc/NSObject.h>
#import <objc/message.h>

_Pragma("clang assume_nonnull begin")

/*
static let kObservableClassPrefix = "k";

static let kObservableClassWillSetTableKey = @"kObservableClassWillSetTableKey";

static let kObservableClassDidSetTableKey = @"kObservableClassWillSetTableKey";

typedef NSDictionary<NSString*, NSMutableArray<id>*> DiaptchTable;

static let ObservableMap = [NSDictionary<NSString*, DiaptchTable*> alloc].init;

static inline void __setter__(id self, SEL _cmd, id newValue) {
    let sel = sel_transformToAccessor(_cmd);
    let key = @(sel_getName(sel));
    let cls = object_getClass(self);
    if (let m = class_getInstanceMethod(cls, sel)) {
        let reason = [NSString stringWithFormat:@"Object %@ does not have setter %@", self, key];
        @throw [NSException exceptionWithName:NSInvalidArgumentException
                                       reason:reason
                                     userInfo:nil];
        return;
    }
    id oldValue = [self valueForKey:key];
    
    var super_class = objc_super {
        .receiver = self,
        .super_class = class_getSuperclass(object_getClass(self))
    };

    let clsName = @(class_getName(cls));
    if (let willSetTable = ObservableMap[clsName][kObservableClassWillSetTableKey]) {
        [willSetTable enumerateObjectsUsingBlock:^(id block, NSUInteger idx, BOOL *stop) {
            dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
                newValue;
            });
        }];
    }
    
    ((void (*)(objc_super *, SEL, id))objc_msgSendSuper)(&super_class, _cmd, newValue);

    if (let willSetTable = ObservableMap[clsName][kObservableClassDidSetTableKey]) {
        [willSetTable enumerateObjectsUsingBlock:^(id block, NSUInteger idx, BOOL *stop) {
            dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
                oldValue;
            });
        }];
    }
}

//@implementation NSObject (KeyValueObserving)
//
//- (instancetype (^)(NSObject *, NSString *, didSet))addObserver {
//    return ^(NSObject *observer, NSString *keyPath, didSet didSet){
//        return self;
//    };
//}
//
//- (instancetype (^)(NSObject *, NSString *))removeObserver {
//    return (id)self;
//}
//
//@end

*/
_Pragma("clang assume_nonnull end")



