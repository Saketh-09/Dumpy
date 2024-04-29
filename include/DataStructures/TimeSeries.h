

#ifndef DUMPY_TIMESERIES_H
#define DUMPY_TIMESERIES_H

#include "../Utils/ConversionUtil.h"
#include "../Const.h"
#include <cmath>
using namespace std;
class TimeSeries{
public:

    float* ts;
    float *paa;
    vector<unsigned short >* sax;

    explicit TimeSeries(float* _ts){
        ts = _ts;
        paa = ConversionUtil::paaFromTsFloat(ts, Const::tsLengthPerSegment, Const::segmentNum);
        sax = ConversionUtil::saxFromPaa(paa, Const::segmentNum, Const::cardinality);
    }

    ~TimeSeries(){
        delete[] paa;
        delete sax;
    }
};

struct createhash{
    size_t operator()(const float *ts) const{
        return ts[0] * 10000;
    }
};

struct isEqual{
    bool operator()(const float *ts1, const float*ts2) const{
        for(int i=0;i<Const::tsLength;++i){
            if(fabs(ts1[i] - ts2[i]) >= 1e-5)
                return false;
        }
        return true;
    }
};

#endif //DUMPY_TIMESERIES_H
