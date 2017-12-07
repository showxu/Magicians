//
//  objc_runtime.h
//  Magicians
//
//  Created by Alchemist on 2017/11/26.
//  Copyright © 2017年 alchemistxxd. All rights reserved.
//

#import <objc/objc.h>
#import <objc/runtime.h>
#import <os/base.h>

_Pragma("clang assume_nonnull begin")

/**
 * Creates a new class and metaclass for Key Value Observing.
 *
 * @param cls The class to use as the observable class's superclass.
 * @param name The string to use as the observable class's name. The string will be copied.
 * @param extraBytes The number of bytes to allocate for indexed ivars at the end of
 *  the class and metaclass objects. This should usually be \c 0.
 *
 * @return The observable class.
 *
 * @note You can get a pointer to the new metaclass by calling \c object_getClass(newClass).
 */
OBJC_EXPORT Class _Nonnull
objc_createObservableClass(Class _Nonnull cls, const char * _Nonnull name,
                           size_t extraBytes)
    OBJC_AVAILABLE(10.0, 2.0, 9.0, 1.0, 2.0);


/**
 * Exchanges the two selector for class.
 *
 * @param s1 SEL to exchange with second SEL.
 * @param s2 SEL to exchange with first SEL.
 * @param isMeta Flag to distinguish cls, YES for Meta Class, NO for Class
 *
 */
OBJC_EXPORT void
class_exchangeImplementations(Class _Nullable cls, SEL s1, SEL s2,
                              BOOL isMeta) __attribute__((__overloadable__))
    OBJC_AVAILABLE(10.5, 2.0, 9.0, 1.0, 2.0);


/**
 * exchange Implementations of two selector for two class.
 *
 * @param cls1 Class to exchange with second Class.
 * @param s1 SEL to exchange with second SEL.
 * @param f1 Flag to distinguish s2, YES for class method(aka meta class instance method), NO for instance method.
 * @param cls2 Class to exchange with first Class.
 * @param s2 SEL to exchange with first SEL.
 * @param f2 Flag to distinguish s2, YES for class method, NO for instance method.
 *
 */
OBJC_EXPORT void
class_exchangeImplementations(Class _Nullable cls1, SEL s1, BOOL f1, Class _Nullable cls2,
                              SEL s2, BOOL f2) __attribute__((__overloadable__))
    OBJC_AVAILABLE(10.5, 2.0, 9.0, 1.0, 2.0);


/**
 * check method signature compatibility of two selector for class.
 *
 * @param cls1 Class to compare with second Class.
 * @param s1 SEL to compare with second SEL.
 * @param f1 Flag to distinguish s1, YES for ClassMethod, NO for InstanceMethod
 * @param cls2 Class to compare with first Class.
 * @param s2 SEL to compare with first SEL.
 * @param f2 Flag to distinguish s2, YES for ClassMethod, NO for InstanceMethod
 *
 * @return YES if (cls1, s1) is compatible with (cls2, s2), otherwise NO.
 *
 */
OBJC_EXPORT BOOL
method_getCompatibility(Class _Nullable cls1, SEL s1, BOOL f1,
                            Class _Nullable cls2, SEL s2, BOOL f2)
    OBJC_AVAILABLE(10.5, 2.0, 9.0, 1.0, 2.0);


/**
 * Transform a getter selector into setter.
 *
 * @param sel A selector.
 */
OBJC_EXPORT SEL _Nonnull
sel_transformToMutator(SEL _Nonnull sel)
    OBJC_AVAILABLE(10.5, 2.0, 9.0, 1.0, 2.0);


/**
 * Transform a setter selector into getter.
 *
 * @param sel A selector.
 */
OBJC_EXPORT SEL _Nonnull
sel_transformToAccessor(SEL _Nonnull sel)
    OBJC_AVAILABLE(10.5, 2.0, 9.0, 1.0, 2.0);


/**
 * Returns a Boolean value that indicates whether a class(not super class) response to a particular selector.
 *
 * @param sel A selector.
 * @param cls The class you want to inspect.
 *
 * @return \c YES if instances of the class response to the selector, otherwise \c NO.
 *
 */
OBJC_EXPORT BOOL
sel_getClassCompatibility(SEL _Nonnull sel, Class _Nullable cls)
    OBJC_AVAILABLE(10.5, 2.0, 9.0, 1.0, 2.0);


/**
 * Returns the setter of a property.
 *
 * @param property The property you want to inquire about.
 *
 * @return A SEL for the property's setter.
 */
OBJC_EXPORT SEL _Nullable
property_getMutator(objc_property_t _Nonnull property)
    OBJC_AVAILABLE(10.5, 2.0, 9.0, 1.0, 2.0);


/**
 * Returns the getter of a property.
 *
 * @param property The property you want to inquire about.
 *
 * @return A SEL for the property's getter.
 */
OBJC_EXPORT SEL _Nullable
property_getAccessor(objc_property_t _Nonnull property)
    OBJC_AVAILABLE(10.5, 2.0, 9.0, 1.0, 2.0);


_Pragma("clang assume_nonnull end")
