//
//  BJYRTCTrtcAdapter.h
//  BJYRTCTrtcAdapter
//
//  Created by DeskMac on 2021/7/8.
//

#import <Foundation/Foundation.h>
#import "BJYRTCAdapter.h"

//! Project version number for BJYRTCTrtcAdapter.
FOUNDATION_EXPORT double BJYRTCTrtcAdapterVersionNumber;

//! Project version string for BJYRTCTrtcAdapter.
FOUNDATION_EXPORT const unsigned char BJYRTCTrtcAdapterVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <BJYRTCTrtcAdapter/PublicHeader.h>



@interface BJYTRTCSDKAdapter : BJYRTCAdapter

- (instancetype)initWithOptions:(BJYRoomOptions *)roomOptions sessionType:(BJYRTCSessionType)sessionType;
@end


