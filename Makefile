include buildconf.mk

all: syndicate

syndicate: ug-tools

.PHONY: ug-tools
ug-tools:
	$(MAKE) -C ug-tools

.PHONY: install
install:
	$(MAKE) -C ug-tools install

.PHONY: uninstall
uninstall:
	$(MAKE) -C ug-tools uninstall

.PHONY: clean
clean:
	$(MAKE) -C ug-tools clean
	if [ -f docs/Makefile ]; then $(MAKE) -C docs clean; fi

.PHONY: docs
docs:
	if [ ! -f docs/Makefile ]; then git submodule init && git submodule update; fi
	mkdir -p docs/sources
	if [ ! -d docs/sources/ug-tools ]; then cp -r ug-tools docs/sources; fi
	if [ ! -d docs/sources/syndicate-core ]; then cd docs && ./getproject https://github.com/syndicate-storage/syndicate-core; fi
	$(MAKE) -C docs docs

.PHONY: installman
installman:
	$(MAKE) -C docs installman
