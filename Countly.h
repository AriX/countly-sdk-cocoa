
// Countly.h
//
// This code is provided under the MIT License.
//
// Please visit www.count.ly for more information.

#import <Foundation/Foundation.h>

@class EventQueue;

@interface Countly : NSObject {
	double unsentSessionLength;
	NSTimer *timer;
	double lastTime;
	BOOL isSuspended;
    EventQueue *eventQueue;
    NSTimeInterval _updateInterval;
#if TARGET_OS_IPHONE
    UIApplication *_app;
#endif
}

@property (nonatomic, assign) NSTimeInterval updateInterval;

#if TARGET_OS_IPHONE
@property (nonatomic, assign) UIApplication *app;
#endif

+ (Countly *)sharedInstance;

- (void)start:(NSString *)appKey withHost:(NSString *)appHost;

- (void)recordEvent:(NSString *)key count:(int)count;

- (void)recordEvent:(NSString *)key count:(int)count sum:(double)sum;

- (void)recordEvent:(NSString *)key segmentation:(NSDictionary *)segmentation count:(int)count;

- (void)recordEvent:(NSString *)key segmentation:(NSDictionary *)segmentation count:(int)count sum:(double)sum;

- (void)flushQueue;

@end


