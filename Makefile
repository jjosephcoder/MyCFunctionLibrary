.PHONY: clean All

All:
	@echo "==========Building project:[ FlashingCursorEffect - Debug ]=========="
	@cd "FlashingCursorEffect" && "$(MAKE)" -f  "FlashingCursorEffect.mk"
clean:
	@echo "==========Cleaning project:[ FlashingCursorEffect - Debug ]----------"
	@cd "FlashingCursorEffect" && "$(MAKE)" -f  "FlashingCursorEffect.mk" clean
