//
//  objc-debug.m
//  Magicians
//
//  Created by Alchemist on 2017/12/4.
//  Copyright © 2017年 alchemistxxd. All rights reserved.
//

#import <objc-layout.h>

#import <Foundation/NSArray.h>
#import <Foundation/NSString.h>

#pragma mark - objc_*

std::tuple<__unsafe_unretained Class *, int>
objc_getClassList() {
    var count = objc_getClassList(nil, 0);
    var class_buffer = new Class[count];
    defer {
        delete[] class_buffer;
    };
    objc_getClassList(class_buffer, count);
    
    return ({
        let result = std::make_tuple(class_buffer, count);
        result;
    });
}

#pragma mark - class_*

std::tuple<objc_property_t *, int>
class_getPropertyList(Class _Nullable cls) {
    unsigned int count;
    objc_property_t *properties = class_copyPropertyList(cls, &count);
    defer {
        free(properties);
    };
    return ({
        let result = std::make_tuple(properties, count);
        result;
    });
}

std::tuple<Ivar *, int>
class_getInstanceVariableList(Class _Nullable cls) {
    var count = (unsigned int)0;
    Ivar *ivars = class_copyIvarList(cls, &count);
    defer {
        free(ivars);
    };
    return ({
        let result = std::make_tuple(ivars, count);
        result;
    });
}

std::tuple<Ivar *, int>
class_getClassVariableList(Class _Nullable cls) {
    return class_getInstanceVariableList(object_getClass(cls));
}

std::tuple<Method _Nonnull * _Nullable, int>
class_getInstanceMethodList(Class _Nullable cls) {
    var count = (unsigned int)0;
    let methods = class_copyMethodList(cls, &count);
    defer {
        free(methods);
    };
    return ({
        let result = std::make_tuple(methods, count);
        result;
    });
}

std::tuple<Method _Nonnull * _Nullable, int>
class_getClassMethodList(Class _Nullable cls) {
    return class_getInstanceMethodList(object_getClass(cls));
}

std::tuple<Protocol * __unsafe_unretained _Nonnull * _Nullable, int>
class_getProtocolList(Class _Nullable cls) {
    var count = (unsigned int)0;
    let protocols = class_copyProtocolList(cls, &count);
    defer {
        free(protocols);
    };
    return ({
        let result = std::make_tuple(protocols, count);
        result;
    });
}

