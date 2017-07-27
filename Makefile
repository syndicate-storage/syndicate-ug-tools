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
	if [ -f docs/Makefile ]; then cd docs && make clean; fi

.PHONY: docs
docs:
	git submodule init
	git submodule update
	mkdir -p docs/sources
	if [ ! -d docs/sources/ug-tools ]; then cp -r ug-tools docs/sources; fi
	if [ ! -d docs/sources/syndicate-core ]; then cd docs/sources && git clone https://github.com/syndicate-storage/syndicate-core; fi
	cd docs && make docs
