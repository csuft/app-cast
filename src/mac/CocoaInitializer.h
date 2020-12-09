#ifndef COCOAINITIALIZER_H
#define COCOAINITIALIZER_H

class CocoaInitializer {
	public:
		CocoaInitializer();
		~CocoaInitializer();
	
	private:
		class CocoaInitializerPrivate;
		CocoaInitializerPrivate* d;
};

#endif
