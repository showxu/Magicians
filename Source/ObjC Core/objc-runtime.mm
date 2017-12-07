//
//  objc_runtime.m
//  Magicians
//
//  Created by Alchemist on 2017/11/26.
//  Copyright © 2017年 alchemistxxd. All rights reserved.
//

#import <objc-runtime.h>

#import <string>
#import <objc/NSObject.h>
#import <string.h>
#import <stdlib.h>

_Pragma("clang assume_nonnull begin")

// class_getMethod stub
static let class_getMethod = ^(Class cls, SEL s, BOOL isMeta) {
    // class_getInstanceMethod(object_getClass(cls), s)
    return isMeta ? class_getClassMethod(cls, s) : class_getInstanceMethod(cls, s);
};

// method_getType stub
static let method_getType = ^(Method m) {
    let c = method_getNumberOfArguments(m);
    let arr = new char [c];
    method_getReturnType(m, &arr[0], 1);
    for (var i = 0; i < c; i ++) {
        method_getArgumentType(m, i, &arr[i + 1], 1);
    }
    return arr;
};

static inline Class __class__(id self, SEL _cmd) {
    return class_getSuperclass(object_getClass(self));
}

static let class_sel = @selector(class);

#pragma mark - objc_*

Class _Nonnull
objc_createObservableClass(Class _Nonnull cls, const char * _Nonnull name,
                           size_t extraBytes) {
    // objc_duplicateClass(Class  _Nonnull __unsafe_unretained original, const char * _Nonnull name, size_t extraBytes)
    if (let aCls = objc_getClass(name)) {
        return aCls;
    }
    // [if statement](http://en.cppreference.com/w/cpp/language/if )
    // [-std=c++17 (-std=c++1z in Clang 4 and earlier).](http://clang.llvm.org/cxx_status.html#cxx17 ).
    if (let newCls = objc_allocateClassPair(cls, name, 0); let clsMethod = class_getClassMethod(cls, class_sel)) {
        class_addMethod(object_getClass(newCls), class_sel, (IMP)__class__, method_getTypeEncoding(clsMethod));
        objc_registerClassPair(newCls);
        return newCls;
    }
    return nil;
}

#pragma mark - class_*

OS_OVERLOADABLE void 
class_exchangeImplementations(Class _Nullable cls, SEL s1, SEL s2, BOOL isMeta) {
    class_exchangeImplementations(cls, s1, isMeta, cls, s2, isMeta);
}

OS_OVERLOADABLE void
class_exchangeImplementations(Class _Nullable cls1, SEL s1, BOOL f1,
                                   Class _Nullable cls2, SEL s2, BOOL f2) {
    let getClass = ^(Class _Nullable cls, BOOL isMeta) {
        return isMeta? object_getClass(cls) : cls;
    };
    if (method_getCompatibility(cls1, s1, f1, cls2, s2, f2)) {
        cls1 = getClass(cls1, f1); cls2 = getClass(cls2, f2);
        
        if (let m1 = class_getInstanceMethod(cls1, s1); let m2 = class_getInstanceMethod(cls2, s2)) {
            if (cls1 == cls2 && f1 == f2 && class_addMethod(cls1, s1, method_getImplementation(m2), method_getTypeEncoding(m2))) {
                class_replaceMethod(cls2, s2, method_getImplementation(m1), method_getTypeEncoding(m1));
                return;
            }
            method_exchangeImplementations(m1, m2);
        }
    }
}

BOOL method_getCompatibility(Class _Nullable cls1, SEL s1, BOOL f1,
                             Class _Nullable cls2, SEL s2, BOOL f2) {
    let getCompatibility = ^(char argv1[], char argv2[], size_t argc){
        for (var i = 0; i < argc; i++) {
            if (let t1 = argv1[i], t2 = argv2[i]; t1 == t2) {} else {
                return NO;
            }
        }
        return YES;
    };
    if (let m1 = class_getMethod(cls1, s1, f1); let m2 = class_getMethod(cls2, s2, f2)) {
        if (let argc = method_getNumberOfArguments(m1); argc == method_getNumberOfArguments(m2)) {
            let argv1 = method_getType(m1);
            let argv2 = method_getType(m2);
            return getCompatibility(argv1, argv2, argc);
        }
    }
    return NO;
}

SEL _Nonnull
sel_transformToMutator(SEL _Nonnull sel) {
    var name = (std::string)sel_getName(sel);
    std::transform(name.begin(), name.begin() + 1, name.begin(), ::toupper);
    let mutator = "set" + name + ":";
    let mutator_sel = sel_getUid(mutator.c_str());
    return mutator_sel;
}

SEL _Nonnull
sel_transformToAccessor(SEL _Nonnull sel) {
    var name = (std::string)sel_getName(sel);
    
    if (name.find("set") != 0 || name.find_last_of(":") != name.length() - 1) {
        return sel;
    }
    name = name.substr(3, name.length() - 4);
    std::transform(name.begin(), name.begin() + 1, name.begin(), ::tolower);
    let accessor = sel_getUid(name.c_str());

    return accessor;
}

BOOL sel_getClassCompatibility(SEL _Nonnull sel, Class _Nullable cls) {
    if (var c = (unsigned int)0; let list = class_copyMethodList(cls, &c)) {
        defer {
            free(list);
        };
        for (var i = 0; i < c; i++) {
            if (sel == method_getName(list[i])) {
                return YES;
            }
        }
    }
    return NO;
}

SEL _Nullable
property_getMutator(objc_property_t _Nonnull property) {
    var p = std::string(property_getName(property));
    std::transform(p.begin(), p.begin() + 1, p.begin(), ::toupper);
    let mutator = "set" + p + ":";
    let sel = sel_getUid(mutator.c_str());
    return sel;
}

SEL _Nullable
property_getAccessor(objc_property_t _Nonnull property) {
    let p = property_getName(property);
    let sel = sel_getUid(p);
    return sel;
}

_Pragma("clang assume_nonnull end")
