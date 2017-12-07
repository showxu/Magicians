//
//  c-meta.h
//  Magicians
//
//  Created by Alchemist on 2017/12/3.
//  Copyright © 2017年 alchemistxxd. All rights reserved.
//

_Pragma("onece")

#import "base.h"

// Marco meta base
#pragma mark - Marco meta base

#define __concat(x, y) x ## y
#define concat(x, y) __concat(x, y)

#define __stringify(s) #s
#define stringify(s) __stringify(s)

#define __lead(x, ...) x
#define lead(...) __lead(__VA_ARGS__, 0)

#define __trail(_0, ...) __VA_ARGS__
#define trail(...) __trail(__VA_ARGS__)

#define expand(...) __VA_ARGS__

#define consume(...)

#define argv_at10(_0, _1, _2, _3, _4, _5, _6 , _7, _8, _9, ...) lead(__VA_ARGVS__)

#define argc(...) \
    argv_at10(__VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)

#endif
