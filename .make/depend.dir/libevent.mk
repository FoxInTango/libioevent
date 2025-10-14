DEPEND_TARGETS += libevent.recursive
ECHO_TARGETS += libevent.echo
libevent.recursive:
	@echo SUPER_MAKE_DIR=/Users/lidali/alpine/libraries/libioevent/               >> /Users/lidali/alpine/libraries/libevent/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/Users/lidali/alpine/libraries/libioevent/.make >> /Users/lidali/alpine/libraries/libevent/.make/super
	cd /Users/lidali/alpine/libraries/libevent/ && /Applications/Xcode.app/Contents/Developer/usr/bin/make recursive && /Applications/Xcode.app/Contents/Developer/usr/bin/make install
	-rm /Users/lidali/alpine/libraries/libevent/.make/super
libevent.echo:
	@echo SUPER_MAKE_DIR=/Users/lidali/alpine/libraries/libioevent/               >> /Users/lidali/alpine/libraries/libevent/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/Users/lidali/alpine/libraries/libioevent/.make >> /Users/lidali/alpine/libraries/libevent/.make/super
	cd /Users/lidali/alpine/libraries/libevent/ && /Applications/Xcode.app/Contents/Developer/usr/bin/make echo
	-rm /Users/lidali/alpine/libraries/libevent/.make/super
