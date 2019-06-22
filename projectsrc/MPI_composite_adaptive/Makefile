ifeq "$(origin CXX)" "default"
	CXX = mpicxx
endif
EXE = cav_simp_MPI_composite
OBJECTS = interval_helper.o adaptive_cav_simp_MPI_composite.o cavalieri_simpson_MPI.o cavalieri_simpson_composite.o main.o
EXE2 = speedup_MPI_composite
OBJECTS2 = interval_helper.o adaptive_cav_simp_MPI_composite.o cavalieri_simpson_MPI.o cavalieri_simpson_composite.o main_speedup.o
CXXFLAGS += -Wall -std=c++11 \
	 -Wno-unused \
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

all: $(EXE) $(EXE2)

$(EXE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(EXE2): $(OBJECTS2)
	$(CXX) $(CXXFLAGS) $^ -o $@

main_speedup.o main.o adaptive_cav_simp_MPI_composite.o cavalieri_simpson_MPI.o cavalieri_simpson_composite.o : cavalieri_simpson_composite.hh
main_speedup.o main.o adaptive_cav_simp_MPI_composite.o cavalieri_simpson_MPI.o: cavalieri_simpson_MPI.hh
main_speedup.o main.o adaptive_cav_simp_MPI_composite.o interval_helper.o: interval_helper.hh
main_speedup.o main.o adaptive_cav_simp_MPI_composite.o: adaptive_cav_simp_MPI_composite.hh

.PHONY: all clean distclean

clean:
	$(RM) *.o
distclean: clean
	$(RM) $(EXE)
