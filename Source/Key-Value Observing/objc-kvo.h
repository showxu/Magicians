//
//  NSObject+Key_Value_Observing.h
//  Magicians
//
//  Created by Alchemist on 2017/11/28.
//  Copyright © 2017年 alchemistxxd. All rights reserved.
//

#import <objc/objc.h>
#import <os/base.h>

_Pragma("clang assume_nonnull begin")

typedef void (^ _Nullable object_will_set_value)(id observable, char *key, id newValue);
typedef void (^ _Nullable object_did_set_value)(id observable, char *key, id oldValue);

/*
OBJC_EXPORT OS_OVERLOADABLE block_token_t _Nullable
object_observeKeyPath(id observable, char *key,
                      object_will_set_value will, object_did_set_value did)
     OBJC_AVAILABLE(10.0, 2.0, 9.0, 1.0, 2.0);


OBJC_EXPORT OS_OVERLOADABLE block_token_t _Nullable
object_observeKeyPath(id observable, char *key, id observer,
                      object_will_set_value will, object_did_set_value did)
    OBJC_AVAILABLE(10.0, 2.0, 9.0, 1.0, 2.0);


OBJC_EXPORT OS_OVERLOADABLE void
object_removeObserver(id _Nullable observable, id _Nullable observer, char * _Nullable key)
    OBJC_AVAILABLE(10.0, 2.0, 9.0, 1.0, 2.0);


OBJC_EXPORT OS_OVERLOADABLE void
object_removeObserver(id _Nullable observable, block_token_t _Nullable t)
    OBJC_AVAILABLE(10.0, 2.0, 9.0, 1.0, 2.0);
*/

_Pragma("clang assume_nonnull end")
