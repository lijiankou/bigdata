// Copyright 2014 lijiankou. All Rights Reserved.
// Author: lijk_start@163.com (Jiankou Li)
#ifndef ML_TOPIC_RTM_H
#define ML_TOPIC_RTM_H
#include "base/base_head.h"
#include "ml/document.h"
#include "ml/eigen.h"

namespace ml {
//model include the model parameter, 
struct RTM {
  double alpha;  // hyperparameter
  Mat ln_w; // topic-word distribution, col index word, row index topic
  Vec eta; // the regression papameter 
  double b; // the regression bias 
  int topic_num;
  
  RTM(int t_num, int a) : alpha(a), topic_num(t_num) {
    eta.resize(topic_num);
    eta.setRandom();
  }
  void Init(int term_num) {
    ln_w.resize(topic_num, term_num);
    ln_w.setZero();
  }
  int TopicNum() const { return ln_w.rows(); }
  int TermNum() const { return ln_w.cols(); }
};
typedef const RTM RTMC;

//the suffstats or expected suffstats for evaluating parameter
struct RTMSuffStats {
  Mat topic;
  Vec topic_sum;
  void SetZero(int k, int v);
  void InitSS(int k, int v);
};
typedef const RTMSuffStats RTMSuffStatsC;

}  // namespace ml 
#endif  // ML_TOPIC_RTM_H
