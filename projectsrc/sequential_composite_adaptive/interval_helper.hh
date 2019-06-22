#ifndef INTERVAL_HELPER_HH
#define INTERVAL_HELPER_HH

#include <vector>

typedef long double real;

namespace numerical
{
  class interval_helper     //support class to manage intervals in adaptive algorithm
  {

      private:
        real a,b;      //fixed extremes
        real length;   // length of the integration interval
        real alpha, beta;     //dynamical extremes

        std::vector<real> nodes;    //vector to store the final mesh

        bool finish = false;    //finish_flag
        bool inverted;          //inverted

      public:
        interval_helper(real aa, real bb) :
            a(aa), b(bb), length(), alpha(), beta(), nodes(), inverted()
                {
                if (b>=a)
                {
                  alpha = a;
                  beta = b;
                  length = b-a;
                  inverted = false;
                }
                else
                {
                  real temp = b;
                  b = a;
                  a = temp;
                  alpha = a;
                  beta = b;
                  length = b-a;
                  inverted = true;
                }
                nodes.push_back(a);
              }

        void divide_interval();     // split dynamical interval
        void extremes_update();     // update dynamical extremes

        void change_finish_flag() {finish = true;};    // integral has been computed
        bool get_finish_flag() const {return finish;};

        void print_intervals() const;    //print the final mesh

        // getters:
        real get_alpha() const {return alpha;};
        real get_beta() const {return beta;};
        real get_a() const {return a;};
        real get_b() const {return b;};
        real get_length() const {return length;};
        bool get_inverted() const {return inverted;};
  };
}
#endif // INTERVAL_HELPER_HH
