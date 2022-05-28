.PHONY: clean All

All:
	@echo "----------Building project:[ koreanDrama - Release ]----------"
	@cd "koreanDrama" && "$(MAKE)" -f  "koreanDrama.mk"
clean:
	@echo "----------Cleaning project:[ koreanDrama - Release ]----------"
	@cd "koreanDrama" && "$(MAKE)" -f  "koreanDrama.mk" clean
