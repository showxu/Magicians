//
//  Pragma.pch
//  Magicians
//
//  Created by Alchemist on 2017/12/1.
//  Copyright © 2017年 alchemistxxd. All rights reserved.
//

_Pragma("once")

#import "base.h"

#define assume_nonnull_begin _Pragma("clang assume_nonnull begin")

#define assume_nonnull_end _Pragma("clang assume_nonnull begin")

#define diagnostic_push _Pragma("clang diagnostic push")

#define diagnostic_pop _Pragma("clang diagnostic pop")

#define Wwarning(w) c_string(W ## w)

#define ignored(w) clang diagnostic ignored w

#define unused(x) _Pragma("unused(x)")

#endif 
