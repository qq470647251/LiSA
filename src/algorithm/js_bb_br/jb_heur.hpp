/* *********************************************************************** */
/*                               Filename: Heur.h                          */
/*                                                                         */
/*    Export: Procedure Heuristic_Schedule:                                */
/*                      Calculation of a heuristic solution for the        */
/*                      search tree node SonNode.                          */
//   @version 3.0
/* *********************************************************************** */

#ifndef _HEUR_H
#define _HEUR_H



/* ************************************************************************* */
/*                         Procedure  Heuristic_Schedule()                   */
/*                                                                           */
/*  INPUT:  -/-                                                              */
/*                                                                           */
/*  FUNCTION: Calculation of a heuristic schedule. The critical path is      */
/*            stored in CriticalPath. If the makespan improves the actual    */
/*            upper bound, UB and CurrentBest are reset. Also the solution   */
/*            is stored in the file output.dat.                              */
/* ************************************************************************* */
///Calculation of a heuristic schedule. 
/** The critical path is stored in CriticalPath. If the makespan improves the
    actual upper bound, UB and CurrentBest are reset. Also the solution is 
    stored in the file output.dat.*/                           
void Heuristic_Schedule (int problem_n, int problem_m);

#endif





