//
//  First.hpp
//  Eight Queens
//
//  Created by shuster on 2018/5/23.
//  Copyright © 2018 曹书恒. All rights reserved.
//

#ifndef First_hpp
#define First_hpp

#include <stdio.h>

#endif /* First_hpp */

bool invalid(int posn1, int posn2);

bool member(int x, int arr[8]);

void print(int queens[8]);

bool validqueen(int x, int queens[], int length);

void check(int row, int queens[8]);

