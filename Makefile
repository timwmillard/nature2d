
all: nature2d

nature2d:
	@cd cmd && $(MAKE) $@

clean:
	@cd cmd && $(MAKE) $@
	@cd lib && $(MAKE) $@
