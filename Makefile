.PHONY: clean All

All:
	@echo "==========Building project:[ VectorReturnEvenNumbers - Debug ]=========="
	@cd "VectorReturnEvenNumber" && "$(MAKE)" -f  "VectorReturnEvenNumbers.mk"
clean:
	@echo "==========Cleaning project:[ VectorReturnEvenNumbers - Debug ]----------"
	@cd "VectorReturnEvenNumber" && "$(MAKE)" -f  "VectorReturnEvenNumbers.mk" clean
