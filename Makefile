.PHONY: clean All

All:
	@echo "==========Building project:[ IntegerVectorMenu - Debug ]=========="
	@cd "IntegerVectorMenu" && "$(MAKE)" -f  "IntegerVectorMenu.mk"
clean:
	@echo "==========Cleaning project:[ IntegerVectorMenu - Debug ]----------"
	@cd "IntegerVectorMenu" && "$(MAKE)" -f  "IntegerVectorMenu.mk" clean
