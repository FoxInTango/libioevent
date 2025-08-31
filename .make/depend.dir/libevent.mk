DEPEND_TARGETS += libevent.build
ECHO_TARGETS += libevent.echo
libevent.build:
	@echo SUPER_MAKE_DIR=/mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libioevent/               >> /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libevent/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libioevent/.make >> /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libevent/.make/super
	cd /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libevent/ && make && make install
	-rm /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libevent/.make/super
libevent.echo:
	@echo SUPER_MAKE_DIR=/mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libioevent/               >> /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libevent/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libioevent/.make >> /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libevent/.make/super
	cd /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libevent/ && make echo
	-rm /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libevent/.make/super
