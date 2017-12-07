//
//  objc-debug.h
//  Magicians
//
//  Created by Alchemist on 2017/12/4.
//  Copyright © 2017年 alchemistxxd. All rights reserved.
//

_Pragma("once")

#import <objc/objc.h>

_Pragma("clang assume_nonnull begin")

@class NSArray<T>, NSString;

/**
 A debug helper version for objc_getClassList()
 
 @return An array of class decription.
 */
OBJC_EXPORT NSArray<NSString *> * objc_getDebugClassList(void);

/**
 A debug helper version for class_getInstanceMethodList()

 @param cls The class you want to inspect
 @return An array of instance method decription
 */
OBJC_EXPORT NSArray<NSString *> * class_getDebugInstanceMethodList(Class _Nullable cls);

/**
 A debug helper version for class_getClassMethodList()
 
 @param cls The class you want to inspect
 @return An array of class method decription
 */
OBJC_EXPORT NSArray<NSString *> * class_getDebugClassMethodList(Class _Nullable cls);

/**
 A debug helper version for class_getInstanceVariableList()
 
 @param cls The class you want to inspect
 @return An array of instance variable decription
 */
OBJC_EXPORT NSArray<NSString *> * class_getDebugInstanceVariableList(Class _Nullable cls);

/**
 A debug helper version for class_getClassVariableList()
 
 @param cls The class you want to inspect
 @return An array of class variable decription
 */
OBJC_EXPORT NSArray<NSString *> * class_getDebugClassVariableList(Class _Nullable cls);

/**
 A debug helper version for class_getPropertyList()
 
 @param cls The class you want to inspect
 @return An array of property decription
 */
OBJC_EXPORT NSArray<NSString *> * class_getDebugPropertyList(Class _Nullable cls);

/**
 A debug helper version for class_getProtocolList()
 
 @param cls The class you want to inspect
 @return An array of protocol decription
 */
OBJC_EXPORT NSArray<NSString *> * class_getDebugProtocolList(Class _Nullable cls);

_Pragma("clang assume_nonnull end")

