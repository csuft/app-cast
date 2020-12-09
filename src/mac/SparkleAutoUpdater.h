#ifndef SPARKLEAUTOUPDATER_H
#define SPARKLEAUTOUPDATER_H

#include <QString>

class SparkleAutoUpdater {
	public:
		SparkleAutoUpdater(const QString& url);
		~SparkleAutoUpdater();

		void checkForUpdates();
	
	private:
		class SparkleAutoUpdaterPrivate;
		SparkleAutoUpdaterPrivate* d;
};

#endif
