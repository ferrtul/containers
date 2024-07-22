rwildcard = $(foreach d, $(wildcard $(1:=/*)), $(call rwildcard,$d,$2) $(filter $(subst *,%,$2), $d))

.PHONY: clean s21_containers.a gcov_report test
all: clean

test: clean
	@rm -rf build
	@mkdir build
	@cd build && cmake ../ && make && ./containers

clean:
	@rm -rf s21_containers.a *.o *.gcno *.gcda *.gcov *.gch \
		test ./test.DSYM *.png *.html *.css *.info ./build gcov_report.*\
		$(call rwildcard,.,*.o) \
		$(call rwildcard,.,*.html)
