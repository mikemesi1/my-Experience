#ifndef BRACKETS_H
#define BRACKETS_H
/**
 * @brief a bracket class dictating shipping weight and prices for various weights.
 * 
 */
class brackets
{
    public:
            void set_brprc0(float &price) {br0prc = price;}
            void set_brprc1(float &price) {br1prc = price;}
            void set_brprc2(float &price) {br2prc = price;}
            void set_brwt1(float &weight) {wt1 = weight;}
            void set_brwt2(float &weight) {wt2 = weight;}
            float get_brprc0(){return br0prc;}
            float get_brprc1(){return br1prc;}
            float get_brprc2(){return br2prc;}
            float get_wt1(){return wt1;}
            float get_wt2(){return wt2;}
    private:
        float br0prc=3.99, br1prc=5.99, br2prc=9.99;
        float wt1=30,wt2=75;
};
#endif