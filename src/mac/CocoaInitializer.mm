#include "CocoaInitializer.h"

#include <AppKit/AppKit.h>
#include <Cocoa/Cocoa.h>
#include <QtDebug>

class CocoaInitializer::CocoaInitializerPrivate
{
	public:
		NSAutoreleasePool* autoReleasePool_;
};

CocoaInitializer::CocoaInitializer()
{
	d = new CocoaInitializer::CocoaInitializerPrivate();
	NSApplicationLoad();
	d->autoReleasePool_ = [[NSAutoreleasePool alloc] init];
}

CocoaInitializer::~CocoaInitializer()
{
	[d->autoReleasePool_ release];
	delete d;
}
