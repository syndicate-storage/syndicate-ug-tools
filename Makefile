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
	rm -rf docs/*

.PHONY: docs
docs:
	git submodule init
	git submodule update
	mkdir -p docs/sources
	ln -sf ../../ug-tools docs/sources/ug-tools
	cd docs && make docs
