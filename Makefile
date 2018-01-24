.PHONY: clean All

All:
	@echo "----------Building project:[ VT49 - Debug ]----------"
	@cd "VT49" && "$(MAKE)" -f  "VT49.mk"
clean:
	@echo "----------Cleaning project:[ VT49 - Debug ]----------"
	@cd "VT49" && "$(MAKE)" -f  "VT49.mk" clean
