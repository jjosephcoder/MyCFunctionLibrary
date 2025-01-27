.PHONY: clean All

All:
	@echo "==========Building project:[ CursorOff - Debug ]=========="
	@cd "CursorOff" && "$(MAKE)" -f  "CursorOff.mk"
clean:
	@echo "==========Cleaning project:[ CursorOff - Debug ]----------"
	@cd "CursorOff" && "$(MAKE)" -f  "CursorOff.mk" clean
