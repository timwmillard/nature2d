
all: lib cmd

lib:
	@cd lib && $(MAKE) $@

cmd:
	@cd cmd && $(MAKE) $@