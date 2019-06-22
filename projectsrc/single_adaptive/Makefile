EXE = cav_simp_single
OBJECTS = interval_helper.o adaptive_cav_simp_single.o cavalieri_simpson_5_points.o cavalieri_simpson.o main.o
CXXFLAGS += -Wall -std=c++11 \
	 -Werror \
   -Wextra \
   -Wconversion \
   -Wno-deprecated \
   -Winit-self \
   -Wsign-conversion \
   -Wredundant-decls \
   -Wvla -Wshadow -Wctor-dtor-privacy -Wnon-virtual-dtor -Woverloaded-virtual \
   -Winit-self \
   -Wpointer-arith \
   -Wcast-qual \
   -Wcast-align \
   -Wdouble-promotion \
   -Wold-style-cast -Wno-error=old-style-cast \
   -Wsign-promo \
   -Wswitch-enum \
   -Wswitch-default \
   -Wundef

all: $(EXE)

$(EXE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

main.o adaptive_cav_simp_single.o cavalieri_simpson.o: cavalieri_simpson.hh
main.o adaptive_cav_simp_single.o cavalieri_simpson_5_points.o: cavalieri_simpson_5_points.hh
main.o adaptive_cav_simp_single.o interval_helper.o: interval_helper.hh
main.o adaptive_cav_simp_single.o: adaptive_cav_simp_single.hh

.PHONY: all clean distclean

clean:
	$(RM) *.o
distclean: clean
	$(RM) $(EXE)
