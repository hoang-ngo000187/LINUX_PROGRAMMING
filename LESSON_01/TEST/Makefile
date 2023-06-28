include abcd.mk

var2 ?= "start"

var0 := "var0"
var1 := $(var0)
var2 ?= "var2"

var0 := "change"

rule1:
	@echo "var0: $(var0)"
	@echo "var1: $(var1)"
	@echo "var2: $(var2)"

rule2:
	@echo "hi am rule2"
rule3:
	@echo "hi am rule3"
