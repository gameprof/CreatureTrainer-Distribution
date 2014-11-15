//
//  EECSRandom.h
//  CreatureTrainer
//
//  Created by Jeremy Gibson on 11/4/14.
//  Copyright (c) 2014 Jeremy Richard Gibson. All rights reserved.
//

#ifndef __CreatureTrainer__EECSRandom__
#define __CreatureTrainer__EECSRandom__

#include <iostream>
using namespace std;

class EECSRandom {

public:
    static int getInt();
    
    static double getDouble();
    
    static void setSeed(int u);

    static int range(int low, int high);
    
    static double range(double low, double high);

};
    
//private:
//    static int _SEED = 1;
//    static int m_z = 1;
//    static
//    
//    // This is an implementation of the Multiply-With-Carry PRNG algorithm
//    
//    static public uint m_z = 1; // Must not be 0
//    static public uint m_w = 1; // Must not be 0
//    
//    static public uint GetUint () {
//        m_z = 36969 * (m_z & 65535) + (m_z >> 16);
//        m_w = 18000 * (m_w & 65535) + (m_w >> 16);
//        
//        return (m_z << 16) + m_w;
//    }
//    
//    static public int GetInt() {
//        uint u = GetUint();
//        return( (int) u );
//    }
//    
//    static public float GetFloat() {
//        // 0 <= u < 2^32
//        uint u = GetUint();
//        // The magic number below is 1/(2^32 + 2).
//        // The result is strictly between 0 and 1.
//        double d = (u + 1.0) * 2.328306435454494e-10;
//        return ( (float) d );
//    }
//    
//    static public void SetSeed(uint u) {
//        SEED = u;
//    }
//    
//    static public uint SEED {
//        get {
//            return(_SEED);
//        }
//        set {
//            if (value == 0) {
//                value = uint.MaxValue;
//            }
//            _SEED = value;
//            Reset();
//        }
//    }
//    
//    static public void Reset() {
//        m_z = _SEED;
//        m_w = 1;
//    }
//    
//    static public float value {
//        get { return( GetFloat() ); }
//    }
//    
//    static public int iValue {
//        get { return( GetInt () ); }
//    }
//    
//    static public uint uValue {
//        get { return( GetUint () ); }
//    }
//    
//    static public int Range(int low, int high) {
//        float f = value;
//        float r = (high-low)*f + low;
//        int n = Mathf.FloorToInt(r);  //Mathf.RoundToInt(r);
//        if (n == high) n = high-1;
//        return(n);
//    }
//    
//    static public float Range(float low, float high) {
//        float f = value;
//        float r = (high-low)*f + low;
//        return(r);
//    }
    
//}


#endif /* defined(__CreatureTrainer__EECSRandom__) */
