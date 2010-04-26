//
//  XMPPEngine.h
//  Buddycloud
//
//  Created by Ross Savage on 4/7/10.
//  Copyright 2010 buddycloud. All rights reserved.
//

#import <Foundation/Foundation.h>

@class XMPPClient;
@class XMPPPubsub;
@class XMPPJID;
@class XMPPIQ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark Public XMPPEngine definition
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

@interface XMPPEngine : NSObject {
	XMPPClient *xmppClient;
	XMPPPubsub *xmppPubsub;
	
	bool isConnectionCold;
	bool isPubsubAddedToRoster;
	int lastItemIdReceived;
}

@property(nonatomic, retain) XMPPClient *xmppClient;
@property(readonly) int lastItemIdReceived;

- (void)connect;
- (void)disconnect;

@end


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark Private XMPPEngine definition
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

@interface XMPPEngine (PrivateAPI)

- (void)sendPresenceToPubsubWithLastItemId:(int)itemId;

- (void)sendPingResultTo:(XMPPJID *)recipient withIQId:(NSString *)iqId;
- (void)sendVersionResultTo:(XMPPJID *)recipient withIQId:(NSString *)iqId;
- (void)sendFeatureDiscovery:(XMPPIQ *)iq;

@end
