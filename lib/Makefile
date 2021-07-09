## Default formatting values for the printing tools below
DEBUG_DEFAULT_HDR_WIDTH:=130
DEBUG_DEFAULT_HDR_FG:=32
DEBUG_DEFAULT_HDR_CHAR:==


## Print bold header, n chars
## e.g.
##    ==============================================================================
##    | DB Vars
##    ==============================================================================
##
## https://misc.flogisoft.com/bash/tip_colors_and_formatting for bash format details
##
## e.g. $(call dump_header, $(DEBUG_DEFAULT_HDR_WIDTH), "SOME HEADER", $(DEBUG_DEFAULT_HDR_CHAR), $(DEBUG_DEFAULT_HDR_FG))
define dump_header
	@$(eval HDR_WIDTH:=$(1))
	@$(eval HDR_MSG:=$(2))
	@$(eval HDR_CHAR:=$(3))
	@$(eval HDR_FG:=$(4))
	@printf "\e[$(HDR_FG)m%0.s$(HDR_CHAR)\e[0m" {1..$(HDR_WIDTH)}
	@printf "\n"
	@printf "\e[1;$(HDR_FG)m| %s \e[0m" $(HDR_MSG)
	@printf "\n"
	@printf "\e[$(HDR_FG)m%0.s$(HDR_CHAR)\e[0m" {1..$(HDR_WIDTH)}
	@echo ""
endef


test: test/nmath_test

test/nmath_test:
	$(call dump_header, $(DEBUG_DEFAULT_HDR_WIDTH), "Build", $(DEBUG_DEFAULT_HDR_CHAR), $(DEBUG_DEFAULT_HDR_FG))
	clang -o tests/nmath_test external/open-simplex-noise.c tests/nmath_test.c
	$(call dump_header, $(DEBUG_DEFAULT_HDR_WIDTH), "Run Tests", $(DEBUG_DEFAULT_HDR_CHAR), $(DEBUG_DEFAULT_HDR_FG))
	./tests/nmath_test


clean:
	rm -rf ./tests/nmath_test
	