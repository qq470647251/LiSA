/*
 * **************Bottleneck.h*******************************
 * 
 * Single_Machine algorithm
 *
 * @author Christian Schulz
 * @version 3.0
 *
 * 14.5.2001
 *
*/

#ifndef _single_machine_h 
#define _single_machine_h 

#include <iostream>

#include "../../basics/matrix.hpp"
#include "../../basics/graph.hpp"
#include "../../misc/except.hpp"
#include "../../lisa/lvalues.hpp"
#include "../../scheduling/schedule.hpp"

/// single machine branch and bound
/** The SingleMachineBB object solves single-machine-problems by a
    branch and bound method. To determine which job should be the next, the 
    algorithm computes lower bounds in every step for each possible
    job, i.e. there are no connected jobs to the choosen one within 
    the priority graph. The Job with the lowest lower bound will be taken. */
class SingleMachineBB{
  /// number of jobs
  int n;
  /// running mode SLOW=true or FAST=false
  bool  mode;
  /// to determine, if it is the very first computed schedule
  bool FirstSchedule;
  /// maximum of due dates
  double maxDD;
  /// maximum of release dates
  double maxRD;
  /// stores Lmax of bestSchedule
  double bestLmax;
  Lisa_Values* pLV;
  /// contains priority relations
  Lisa_MatrixListGraph* priority; 
  /// stores which jobs already done 
  Lisa_Vector<bool>* Done;
  /// includes the predeccesors of every job in the Lisa_MatrixListGraph priority
  Lisa_Vector<int>* Sources;
  /// contains schedule, which is currently developed
  Lisa_Vector<int>* Schedule;
  /// contains current best schedule
  Lisa_Vector<int>* bestSchedule;
  /// changes bestSchedule,
  /** if Lmax of Schedule is lower than the value of bestLmax */
  void   newSchedule();
  /// branch steps
  bool   branching(int k=0);
  /// lower bounds computation
  double lb(int k);
public:
  /// constructor
  /** create an object, in dependency on Lisa_Values and 
   a possible Lisa_MatrixListGraph, which contains priority relations 
   and running mode m */
  SingleMachineBB(Lisa_Values* pValues, Lisa_MatrixListGraph* pgraph=0, bool m=false);
  /// constructor
  /** create an object, in dependency on Lisa_Values and 
   a possible Lisa_MatrixListGraph, which contains priority relations 
   and running mode m */
  SingleMachineBB(Lisa_Values* pValues, bool m=false, Lisa_MatrixListGraph* pgraph=0);
  /// delete this object
  ~SingleMachineBB();
  /// compute the schedule
  /** store it in a latin rectangle of pSchedule */
  bool run(Lisa_Schedule *pSchedule);
  
  /// get the best schedule
  Lisa_Vector<int>* get_bestSchedule(){return bestSchedule;}
  
  /// get the best Lmax
  double get_bestLmax() {return bestLmax;}
};

#endif

