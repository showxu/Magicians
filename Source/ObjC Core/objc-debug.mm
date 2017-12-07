//
//  objc-debug.m
//  Magicians
//
//  Created by Alchemist on 2017/12/4.
//  Copyright © 2017年 alchemistxxd. All rights reserved.
//

#import <objc-debug.h>

#import <objc-layout.h>

#import <objc/runtime.h>
#import <string>
#import <sstream>
#import <Foundation/Foundation.h>

#pragma mark -

NSArray<NSString *> * objc_getDebugClassList() {
    let list = objc_getClassList();
    let cls = std::get<0>(list);
    let count = std::get<1>(list);
    
    return ({
        let result = NSMutableArray.array;
        for (var i = 0 ; i < count; i++) {
            let name = (std::string)class_getName(cls[i]);
            let version = (std::ostringstream)class_getVersion(cls[i]);
            let image = (std::string)(class_getImageName(cls[i]) ?: "");
            let pos = image.find_last_of("/");
            let desc = (pos != -1 ? image.substr(pos + 1, image.length()) : image) + ":" + name + version.str();
            [result addObject: [NSString.alloc initWithUTF8String: desc.c_str()]];
        }
        result;
    });
}

NSArray<NSString *> * class_getDebugInstanceMethodList(Class _Nullable cls) {
    let list = class_getInstanceMethodList(cls);
    let methods = std::get<0>(list);
    let count = std::get<1>(list);
    let isMeta = class_isMetaClass(cls);
    let type = (std::string)(isMeta ? "+" : "-");

    let result = NSMutableArray.array;
    for (var i = 0; i < count; i++) {
        let method = methods[i];
        let method_desc = method_getDescription(method);
        let sel_name = (std::string)sel_getName(method_desc->name);
        let types = (std::string)method_desc->types;
        let desc = type + sel_name + types;
        
        [result addObject: [NSString.alloc initWithUTF8String: desc.c_str()]];
    }
    return result;
}

NSArray<NSString *> * class_getDebugClassMethodList(Class _Nullable cls) {
    return class_getDebugInstanceMethodList(object_getClass(cls));
}

NSArray<NSString *> * class_getDebugInstanceVariableList(Class _Nullable cls) {
    let list = class_getInstanceVariableList(cls);
    let ivars = std::get<0>(list);
    let count = std::get<1>(list);
    
    let result = NSMutableArray.array;
    for (var i = 0; i < count; i++) {
        let ivar = ivars[i];
        let type = (std::string)ivar_getTypeEncoding(ivar);
        let name = (std::string)ivar_getName(ivar);
        let desc = [NSString.alloc initWithUTF8String: (type + name).c_str()];
        [result addObject:desc];
    }
    return result;
}

NSArray<NSString *> * class_getDebugClassVariableList(Class _Nullable cls) {
    return class_getDebugInstanceVariableList(object_getClass(cls));
}

NSArray<NSString *> * class_getDebugPropertyList(Class _Nullable cls) {
    let list = class_getPropertyList(cls);
    let properties = std::get<0>(list);
    let count = std::get<1>(list);
    
    let result = NSMutableArray.array;
    for (var i = 0; i < count; i++) {
        let p = properties[i];
        let name = (std::string)property_getName(p);
        let attributes = (std::string)property_getAttributes(p);
        let desc = [NSString.alloc initWithUTF8String: (attributes + name).c_str()];
        [result addObject:desc];
    }
    return result;
}

NSArray<NSString *> * class_getDebugProtocolList(Class _Nullable cls) {
    let list = class_getProtocolList(cls);
    let protocols = std::get<0>(list);
    let count = std::get<1>(list);
    
    let result = NSMutableArray.array;
    for (var i = 0; i < count; i++) {
        let p = protocols[i];
        let name = (std::string)protocol_getName(p);
        let desc = [NSString.alloc initWithUTF8String: name.c_str()];
        [result addObject:desc];
    }
    return result;
}

#pragma mark -


