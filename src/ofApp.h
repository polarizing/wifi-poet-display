#pragma once

#include <deque>
#include "ofMain.h"
#include "ofxIO.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg) override;

		void setupGui();
		void fullScreenToggleChanged(bool & toggle);

		/* GUI */
		ofxPanel gui;
		bool guiHide;
		ofxToggle bFullScreen;

		/* Directory Watching */
		void onDirectoryWatcherItemAdded(const ofxIO::DirectoryWatcherManager::DirectoryEvent& evt)
		{ ofSendMessage("Added:    " + evt.item.path()); }
		void onDirectoryWatcherItemRemoved(const ofxIO::DirectoryWatcherManager::DirectoryEvent& evt)
		{ ofSendMessage("Removed:  " + evt.item.path()); }
		void onDirectoryWatcherItemModified(const ofxIO::DirectoryWatcherManager::DirectoryEvent& evt)
		{ ofSendMessage("Modified: " + evt.item.path()); }
		void onDirectoryWatcherItemMovedFrom(const ofxIO::DirectoryWatcherManager::DirectoryEvent& evt)
		{ ofLogNotice("ofApp::onDirectoryWatcherItemMovedFrom") << "Moved From: " << evt.item.path(); }
		void onDirectoryWatcherItemMovedTo(const ofxIO::DirectoryWatcherManager::DirectoryEvent& evt)
		{ ofLogNotice("ofApp::onDirectoryWatcherItemMovedTo") << "Moved To: " << evt.item.path(); }
		void onDirectoryWatcherError(const Poco::Exception& exc) 
		{ ofLogError("ofApp::onDirectoryWatcherError") << "Error: " << exc.displayText(); }
		ofxIO::DirectoryWatcherManager watcher;
		ofxIO::HiddenFileFilter fileFilter;
		std::deque<std::string> messages;

};
