#include "RecoPixelVertexing/PixelTrackFitting/interface/PixelTrackErrorParam.h"
#include <cmath>
#include <algorithm> 

double const PixelTrackErrorParam::ptPar0_[25] = {
    0.0494062, 0.0481573, 0.0494433, 0.0509793, 0.0518965, 
    0.0541088, 0.0564495, 0.058404, 0.0613199, 0.0657811, 
    0.0668737, 0.0720964, 0.0752415, 0.0801675, 0.0837472, 
    0.0879407, 0.0905341, 0.0931733, 0.095179, 0.0965753, 
    0.0988105, 0.100972, 0.102711, 0.108616, 0.113405};
double const PixelTrackErrorParam::ptPar1_[25] = {
    0.0239574, 0.0244798, 0.0239764, 0.0236808, 0.0233654, 
    0.0225266, 0.0217593, 0.0210034, 0.0199915, 0.0185826, 
    0.0181862, 0.0170128, 0.0160879, 0.0148883, 0.0137523, 
    0.0120505, 0.011127, 0.0106431, 0.0110392, 0.0122759, 
    0.014541, 0.0187583, 0.0232712, 0.029388, 0.0366684};

double const PixelTrackErrorParam::cotPar0_[25] = {
    0.00213472, 0.00181974, 0.00141473, 0.00106457, 0.000889918, 
    0.000961023, 0.00116, 0.00115963, 0.00101409, 0.000964437, 
    0.00113729, 0.00116469, 0.00101364, 0.00111189, 0.00104036, 
    0.00100723, 0.00106901, 0.000940168, 0.000883219, 0.000736283, 
    0.000756613, 0.000906564, 0.00111986, 0.00136062, 0.00197484};
double const PixelTrackErrorParam::cotPar1_[25] = {
    0.000388201, 0.000451948, 0.00066852, 0.000904649, 0.00106097, 
    0.00102086, 0.00106799, 0.00110299, 0.00150064, 0.00177285, 
    0.00194803, 0.00230273, 0.00300421, 0.00348461, 0.00432021, 
    0.00508771, 0.00611297, 0.00755584, 0.00942645, 0.0118813, 
    0.013826, 0.0163194, 0.018632, 0.0220511, 0.0247037};
double const PixelTrackErrorParam::cotPar2_[25] = {
    0.000290315, 0.000300312, 0.000269851, 0.000273811, 0.000289154, 
    0.000371789, 0.000419882, 0.00051815, 0.00051251, 0.000562468, 
    0.000648634, 0.000714208, 0.000691232, 0.000784168, 0.000780865, 
    0.000895448, 0.000941508, 0.00102813, 0.00101404, 0.00111243, 
    0.00131101, 0.00133329, 0.0013636, 0.001091, 0.00131116};

double const PixelTrackErrorParam::tipPar0_[25] = {
    9.90634e-05, 9.84316e-05, 9.7779e-05, 9.7172e-05, 9.59827e-05, 
    9.12931e-05, 8.8664e-05, 8.4127e-05, 7.84482e-05, 7.35595e-05, 
    6.88885e-05, 6.65879e-05, 6.13386e-05, 5.79879e-05, 5.25827e-05, 
    4.55881e-05, 4.29735e-05, 4.22894e-05, 4.81632e-05, 6.1353e-05, 
    8.30893e-05, 0.000120545, 0.000161677, 0.000209437, 0.000253306};
double const PixelTrackErrorParam::tipPar1_[25] = {
    0.000125424, 0.000127228, 0.000130865, 0.000135964, 0.000141355, 
    0.000148999, 0.000156763, 0.000164105, 0.000180502, 0.000199711, 
    0.000212115, 0.000238949, 0.00026887, 0.000284436, 0.000319527, 
    0.000354601, 0.000380476, 0.000423449, 0.000465315, 0.000505804, 
    0.000589181, 0.000628609, 0.000646786, 0.000703491, 0.000768749};

double const PixelTrackErrorParam::zipPar0_[25] = {
    0.000169077, 0.000122234, 7.81059e-05, 4.62916e-05, 3.28052e-05, 
    3.76424e-05, 5.75582e-05, 5.63495e-05, 4.67628e-05, 4.40946e-05, 
    6.15461e-05, 6.63201e-05, 5.73973e-05, 7.15086e-05, 6.90156e-05, 
    7.00145e-05, 8.36148e-05, 7.80617e-05, 8.25872e-05, 7.79393e-05, 
    7.9259e-05, 9.05574e-05, 0.000128749, 0.000194952, 0.000303037};
double const PixelTrackErrorParam::zipPar1_[25] = {
    5.28294e-05, 5.31931e-05, 5.40785e-05, 6.07465e-05, 6.69913e-05, 
    7.49936e-05, 8.8254e-05, 0.000102271, 0.000130148, 0.000160872, 
    0.000200952, 0.000259911, 0.000335115, 0.000446125, 0.0005964, 
    0.000774316, 0.0010434, 0.0014346, 0.00197845, 0.00289929, 
    0.00390585, 0.00565505, 0.00724132, 0.00944603, 0.0119224};

double const PixelTrackErrorParam::phiPar0_[25] = {
    8.69733e-06, 8.63657e-06, 8.59294e-06, 8.58639e-06, 8.47653e-06, 
    8.07612e-06, 7.75151e-06, 7.41186e-06, 6.92146e-06, 6.45626e-06, 
    6.13366e-06, 5.84499e-06, 5.37023e-06, 5.16333e-06, 4.52533e-06, 
    3.90497e-06, 3.63283e-06, 3.55382e-06, 4.16804e-06, 5.5828e-06, 
    7.86881e-06, 1.19253e-05, 1.68948e-05, 2.2651e-05, 2.86073e-05};
double const PixelTrackErrorParam::phiPar1_[25] = {
    1.19179e-05, 1.22353e-05, 1.25472e-05, 1.29066e-05, 1.35411e-05, 
    1.42899e-05, 1.52777e-05, 1.59837e-05, 1.75634e-05, 1.93287e-05, 
    2.06825e-05, 2.34967e-05, 2.63522e-05, 2.79937e-05, 3.12305e-05, 
    3.45185e-05, 3.71191e-05, 4.08867e-05, 4.39826e-05, 4.67677e-05, 
    5.41138e-05, 5.89463e-05, 5.9988e-05, 6.81183e-05, 7.61777e-05};


PixelTrackErrorParam::PixelTrackErrorParam(double eta, double pt)
 : thePt(pt)
{
  theIEta = std::min( static_cast<unsigned int>(10.*fabs(eta)), nEta-1);
  thePt2 = thePt*thePt;
}

double PixelTrackErrorParam::errPt()  const
{
  double err = ptPar0_[theIEta]*thePt + ptPar1_[theIEta]*thePt2;  
  double corr;
  if (thePt > 11.2) corr = 1.152; 
  else if (thePt < 0.1)  corr = 0.95;
  else corr =  7.68857e-01 + 6.79391e-02*thePt + 2.65445e-02/thePt  -3.02932e-03*thePt2 + -9.57928e-04/thePt2;
  err *= corr; 
  return err;
} 

