//
//  type-encoding.c
//  Magicians
//
//  Created by Alchemist on 2017/12/5.
//  Copyright © 2017年 alchemistxxd. All rights reserved.
//

#import "type-encoding.h"

#import <stdlib.h>
#import <string.h>
#import <regex.h>
#import <ctype.h>

char * getObjCTypes(const char types[]) {
    let len = strlen(types);
    
    var result = (char *)malloc(len *sizeof(char));
    for (var x = 0, y = 0; x < len; x ++) {
        let c = types[x];
        if (!isdigit(c)) {
            result[y ++] = c;
        }
    }
    return result;
}

