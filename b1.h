//#include <vector>
#include <cmath>
#include "t1.h"
double datas[9+1][9+1];
double return_output;
model input[9+1];
model net[10+1][9+1]; //dont use [?][0] or [0][?] 
model output;
double tmp[12+1][9+1];
double *f_value[1001];
void load(){
	input[1].set_i(&datas[1][1],1);input[1].set_i(&datas[2][1],2);input[1].set_i(&datas[3][1],3);input[1].set_i(&datas[4][1],4);input[1].set_i(&datas[5][1],5);input[1].set_i(&datas[6][1],6);input[1].set_i(&datas[7][1],7);input[1].set_i(&datas[8][1],8);input[1].set_i(&datas[9][1],9);input[1].set_o(&tmp[1][1]);
	input[2].set_i(&datas[1][2],1);input[2].set_i(&datas[2][2],2);input[2].set_i(&datas[3][2],3);input[2].set_i(&datas[4][2],4);input[2].set_i(&datas[5][2],5);input[2].set_i(&datas[6][2],6);input[2].set_i(&datas[7][2],7);input[2].set_i(&datas[8][2],8);input[2].set_i(&datas[9][2],9);input[2].set_o(&tmp[2][1]);
	input[3].set_i(&datas[1][3],1);input[3].set_i(&datas[2][3],2);input[3].set_i(&datas[3][3],3);input[3].set_i(&datas[4][3],4);input[3].set_i(&datas[5][3],5);input[3].set_i(&datas[6][3],6);input[3].set_i(&datas[7][3],7);input[3].set_i(&datas[8][3],8);input[3].set_i(&datas[9][3],9);input[3].set_o(&tmp[3][1]);
	input[4].set_i(&datas[1][4],1);input[4].set_i(&datas[2][4],2);input[4].set_i(&datas[3][4],3);input[4].set_i(&datas[4][4],4);input[4].set_i(&datas[5][4],5);input[4].set_i(&datas[6][4],6);input[4].set_i(&datas[7][4],7);input[4].set_i(&datas[8][4],8);input[4].set_i(&datas[9][4],9);input[4].set_o(&tmp[4][1]);
	input[5].set_i(&datas[1][5],1);input[5].set_i(&datas[2][5],2);input[5].set_i(&datas[3][5],3);input[5].set_i(&datas[4][5],4);input[5].set_i(&datas[5][5],5);input[5].set_i(&datas[6][5],6);input[5].set_i(&datas[7][5],7);input[5].set_i(&datas[8][5],8);input[5].set_i(&datas[9][5],9);input[5].set_o(&tmp[5][1]);
	input[6].set_i(&datas[1][6],1);input[6].set_i(&datas[2][6],2);input[6].set_i(&datas[3][6],3);input[6].set_i(&datas[4][6],4);input[6].set_i(&datas[5][6],5);input[6].set_i(&datas[6][6],6);input[6].set_i(&datas[7][6],7);input[6].set_i(&datas[8][6],8);input[6].set_i(&datas[9][6],9);input[6].set_o(&tmp[6][1]);
	input[7].set_i(&datas[1][7],1);input[7].set_i(&datas[2][7],2);input[7].set_i(&datas[3][7],3);input[7].set_i(&datas[4][7],4);input[7].set_i(&datas[5][7],5);input[7].set_i(&datas[6][7],6);input[7].set_i(&datas[7][7],7);input[7].set_i(&datas[8][7],8);input[7].set_i(&datas[9][7],9);input[7].set_o(&tmp[7][1]);
	input[8].set_i(&datas[1][8],1);input[8].set_i(&datas[2][8],2);input[8].set_i(&datas[3][8],3);input[8].set_i(&datas[4][8],4);input[8].set_i(&datas[5][8],5);input[8].set_i(&datas[6][8],6);input[8].set_i(&datas[7][8],7);input[8].set_i(&datas[8][8],8);input[8].set_i(&datas[9][8],9);input[8].set_o(&tmp[8][1]);
	input[9].set_i(&datas[1][9],1);input[9].set_i(&datas[2][9],2);input[9].set_i(&datas[3][9],3);input[9].set_i(&datas[4][9],4);input[9].set_i(&datas[5][9],5);input[9].set_i(&datas[6][9],6);input[9].set_i(&datas[7][9],7);input[9].set_i(&datas[8][9],8);input[9].set_i(&datas[9][9],9);input[9].set_o(&tmp[9][1]);
	net[1][1].set_i(&tmp[1][1],1);net[1][1].set_i(&tmp[2][1],2);net[1][1].set_i(&tmp[3][1],3);net[1][1].set_i(&tmp[4][1],4);net[1][1].set_i(&tmp[5][1],5);net[1][1].set_i(&tmp[6][1],6);net[1][1].set_i(&tmp[7][1],7);net[1][1].set_i(&tmp[8][1],8);net[1][1].set_i(&tmp[9][1],9);net[1][1].set_o(&tmp[1][2]);
	net[1][2].set_i(&tmp[1][1],1);net[1][2].set_i(&tmp[2][1],2);net[1][2].set_i(&tmp[3][1],3);net[1][2].set_i(&tmp[4][1],4);net[1][2].set_i(&tmp[5][1],5);net[1][2].set_i(&tmp[6][1],6);net[1][2].set_i(&tmp[7][1],7);net[1][2].set_i(&tmp[8][1],8);net[1][2].set_i(&tmp[9][1],9);net[1][2].set_o(&tmp[2][2]);
	net[1][3].set_i(&tmp[1][1],1);net[1][3].set_i(&tmp[2][1],2);net[1][3].set_i(&tmp[3][1],3);net[1][3].set_i(&tmp[4][1],4);net[1][3].set_i(&tmp[5][1],5);net[1][3].set_i(&tmp[6][1],6);net[1][3].set_i(&tmp[7][1],7);net[1][3].set_i(&tmp[8][1],8);net[1][3].set_i(&tmp[9][1],9);net[1][3].set_o(&tmp[3][2]);
	net[1][4].set_i(&tmp[1][1],1);net[1][4].set_i(&tmp[2][1],2);net[1][4].set_i(&tmp[3][1],3);net[1][4].set_i(&tmp[4][1],4);net[1][4].set_i(&tmp[5][1],5);net[1][4].set_i(&tmp[6][1],6);net[1][4].set_i(&tmp[7][1],7);net[1][4].set_i(&tmp[8][1],8);net[1][4].set_i(&tmp[9][1],9);net[1][4].set_o(&tmp[4][2]);
	net[1][5].set_i(&tmp[1][1],1);net[1][5].set_i(&tmp[2][1],2);net[1][5].set_i(&tmp[3][1],3);net[1][5].set_i(&tmp[4][1],4);net[1][5].set_i(&tmp[5][1],5);net[1][5].set_i(&tmp[6][1],6);net[1][5].set_i(&tmp[7][1],7);net[1][5].set_i(&tmp[8][1],8);net[1][5].set_i(&tmp[9][1],9);net[1][5].set_o(&tmp[5][2]);
	net[1][6].set_i(&tmp[1][1],1);net[1][6].set_i(&tmp[2][1],2);net[1][6].set_i(&tmp[3][1],3);net[1][6].set_i(&tmp[4][1],4);net[1][6].set_i(&tmp[5][1],5);net[1][6].set_i(&tmp[6][1],6);net[1][6].set_i(&tmp[7][1],7);net[1][6].set_i(&tmp[8][1],8);net[1][6].set_i(&tmp[9][1],9);net[1][6].set_o(&tmp[6][2]);
	net[1][7].set_i(&tmp[1][1],1);net[1][7].set_i(&tmp[2][1],2);net[1][7].set_i(&tmp[3][1],3);net[1][7].set_i(&tmp[4][1],4);net[1][7].set_i(&tmp[5][1],5);net[1][7].set_i(&tmp[6][1],6);net[1][7].set_i(&tmp[7][1],7);net[1][7].set_i(&tmp[8][1],8);net[1][7].set_i(&tmp[9][1],9);net[1][7].set_o(&tmp[7][2]);
	net[1][8].set_i(&tmp[1][1],1);net[1][8].set_i(&tmp[2][1],2);net[1][8].set_i(&tmp[3][1],3);net[1][8].set_i(&tmp[4][1],4);net[1][8].set_i(&tmp[5][1],5);net[1][8].set_i(&tmp[6][1],6);net[1][8].set_i(&tmp[7][1],7);net[1][8].set_i(&tmp[8][1],8);net[1][8].set_i(&tmp[9][1],9);net[1][8].set_o(&tmp[8][2]);
	net[1][9].set_i(&tmp[1][1],1);net[1][9].set_i(&tmp[2][1],2);net[1][9].set_i(&tmp[3][1],3);net[1][9].set_i(&tmp[4][1],4);net[1][9].set_i(&tmp[5][1],5);net[1][9].set_i(&tmp[6][1],6);net[1][9].set_i(&tmp[7][1],7);net[1][9].set_i(&tmp[8][1],8);net[1][9].set_i(&tmp[9][1],9);net[1][9].set_o(&tmp[9][2]);
	net[2][1].set_i(&tmp[1][2],1);net[2][1].set_i(&tmp[2][2],2);net[2][1].set_i(&tmp[3][2],3);net[2][1].set_i(&tmp[4][2],4);net[2][1].set_i(&tmp[5][2],5);net[2][1].set_i(&tmp[6][2],6);net[2][1].set_i(&tmp[7][2],7);net[2][1].set_i(&tmp[8][2],8);net[2][1].set_i(&tmp[9][2],9);net[2][1].set_o(&tmp[1][3]);
	net[2][2].set_i(&tmp[1][2],1);net[2][2].set_i(&tmp[2][2],2);net[2][2].set_i(&tmp[3][2],3);net[2][2].set_i(&tmp[4][2],4);net[2][2].set_i(&tmp[5][2],5);net[2][2].set_i(&tmp[6][2],6);net[2][2].set_i(&tmp[7][2],7);net[2][2].set_i(&tmp[8][2],8);net[2][2].set_i(&tmp[9][2],9);net[2][2].set_o(&tmp[2][3]);
	net[2][3].set_i(&tmp[1][2],1);net[2][3].set_i(&tmp[2][2],2);net[2][3].set_i(&tmp[3][2],3);net[2][3].set_i(&tmp[4][2],4);net[2][3].set_i(&tmp[5][2],5);net[2][3].set_i(&tmp[6][2],6);net[2][3].set_i(&tmp[7][2],7);net[2][3].set_i(&tmp[8][2],8);net[2][3].set_i(&tmp[9][2],9);net[2][3].set_o(&tmp[3][3]);
	net[2][4].set_i(&tmp[1][2],1);net[2][4].set_i(&tmp[2][2],2);net[2][4].set_i(&tmp[3][2],3);net[2][4].set_i(&tmp[4][2],4);net[2][4].set_i(&tmp[5][2],5);net[2][4].set_i(&tmp[6][2],6);net[2][4].set_i(&tmp[7][2],7);net[2][4].set_i(&tmp[8][2],8);net[2][4].set_i(&tmp[9][2],9);net[2][4].set_o(&tmp[4][3]);
	net[2][5].set_i(&tmp[1][2],1);net[2][5].set_i(&tmp[2][2],2);net[2][5].set_i(&tmp[3][2],3);net[2][5].set_i(&tmp[4][2],4);net[2][5].set_i(&tmp[5][2],5);net[2][5].set_i(&tmp[6][2],6);net[2][5].set_i(&tmp[7][2],7);net[2][5].set_i(&tmp[8][2],8);net[2][5].set_i(&tmp[9][2],9);net[2][5].set_o(&tmp[5][3]);
	net[2][6].set_i(&tmp[1][2],1);net[2][6].set_i(&tmp[2][2],2);net[2][6].set_i(&tmp[3][2],3);net[2][6].set_i(&tmp[4][2],4);net[2][6].set_i(&tmp[5][2],5);net[2][6].set_i(&tmp[6][2],6);net[2][6].set_i(&tmp[7][2],7);net[2][6].set_i(&tmp[8][2],8);net[2][6].set_i(&tmp[9][2],9);net[2][6].set_o(&tmp[6][3]);
	net[2][7].set_i(&tmp[1][2],1);net[2][7].set_i(&tmp[2][2],2);net[2][7].set_i(&tmp[3][2],3);net[2][7].set_i(&tmp[4][2],4);net[2][7].set_i(&tmp[5][2],5);net[2][7].set_i(&tmp[6][2],6);net[2][7].set_i(&tmp[7][2],7);net[2][7].set_i(&tmp[8][2],8);net[2][7].set_i(&tmp[9][2],9);net[2][7].set_o(&tmp[7][3]);
	net[2][8].set_i(&tmp[1][2],1);net[2][8].set_i(&tmp[2][2],2);net[2][8].set_i(&tmp[3][2],3);net[2][8].set_i(&tmp[4][2],4);net[2][8].set_i(&tmp[5][2],5);net[2][8].set_i(&tmp[6][2],6);net[2][8].set_i(&tmp[7][2],7);net[2][8].set_i(&tmp[8][2],8);net[2][8].set_i(&tmp[9][2],9);net[2][8].set_o(&tmp[8][3]);
	net[2][9].set_i(&tmp[1][2],1);net[2][9].set_i(&tmp[2][2],2);net[2][9].set_i(&tmp[3][2],3);net[2][9].set_i(&tmp[4][2],4);net[2][9].set_i(&tmp[5][2],5);net[2][9].set_i(&tmp[6][2],6);net[2][9].set_i(&tmp[7][2],7);net[2][9].set_i(&tmp[8][2],8);net[2][9].set_i(&tmp[9][2],9);net[2][9].set_o(&tmp[9][3]);
	net[3][1].set_i(&tmp[1][2],1);net[3][1].set_i(&tmp[2][2],2);net[3][1].set_i(&tmp[3][2],3);net[3][1].set_i(&tmp[4][2],4);net[3][1].set_i(&tmp[5][2],5);net[3][1].set_i(&tmp[6][2],6);net[3][1].set_i(&tmp[7][2],7);net[3][1].set_i(&tmp[8][2],8);net[3][1].set_i(&tmp[9][2],9);net[3][1].set_o(&tmp[1][3]);
	net[3][2].set_i(&tmp[1][2],1);net[3][2].set_i(&tmp[2][2],2);net[3][2].set_i(&tmp[3][2],3);net[3][2].set_i(&tmp[4][2],4);net[3][2].set_i(&tmp[5][2],5);net[3][2].set_i(&tmp[6][2],6);net[3][2].set_i(&tmp[7][2],7);net[3][2].set_i(&tmp[8][2],8);net[3][2].set_i(&tmp[9][2],9);net[3][2].set_o(&tmp[2][3]);
	net[3][3].set_i(&tmp[1][2],1);net[3][3].set_i(&tmp[2][2],2);net[3][3].set_i(&tmp[3][2],3);net[3][3].set_i(&tmp[4][2],4);net[3][3].set_i(&tmp[5][2],5);net[3][3].set_i(&tmp[6][2],6);net[3][3].set_i(&tmp[7][2],7);net[3][3].set_i(&tmp[8][2],8);net[3][3].set_i(&tmp[9][2],9);net[3][3].set_o(&tmp[3][3]);
	net[3][4].set_i(&tmp[1][2],1);net[3][4].set_i(&tmp[2][2],2);net[3][4].set_i(&tmp[3][2],3);net[3][4].set_i(&tmp[4][2],4);net[3][4].set_i(&tmp[5][2],5);net[3][4].set_i(&tmp[6][2],6);net[3][4].set_i(&tmp[7][2],7);net[3][4].set_i(&tmp[8][2],8);net[3][4].set_i(&tmp[9][2],9);net[3][4].set_o(&tmp[4][3]);
	net[3][5].set_i(&tmp[1][2],1);net[3][5].set_i(&tmp[2][2],2);net[3][5].set_i(&tmp[3][2],3);net[3][5].set_i(&tmp[4][2],4);net[3][5].set_i(&tmp[5][2],5);net[3][5].set_i(&tmp[6][2],6);net[3][5].set_i(&tmp[7][2],7);net[3][5].set_i(&tmp[8][2],8);net[3][5].set_i(&tmp[9][2],9);net[3][5].set_o(&tmp[5][3]);
	net[3][6].set_i(&tmp[1][2],1);net[3][6].set_i(&tmp[2][2],2);net[3][6].set_i(&tmp[3][2],3);net[3][6].set_i(&tmp[4][2],4);net[3][6].set_i(&tmp[5][2],5);net[3][6].set_i(&tmp[6][2],6);net[3][6].set_i(&tmp[7][2],7);net[3][6].set_i(&tmp[8][2],8);net[3][6].set_i(&tmp[9][2],9);net[3][6].set_o(&tmp[6][3]);
	net[3][7].set_i(&tmp[1][2],1);net[3][7].set_i(&tmp[2][2],2);net[3][7].set_i(&tmp[3][2],3);net[3][7].set_i(&tmp[4][2],4);net[3][7].set_i(&tmp[5][2],5);net[3][7].set_i(&tmp[6][2],6);net[3][7].set_i(&tmp[7][2],7);net[3][7].set_i(&tmp[8][2],8);net[3][7].set_i(&tmp[9][2],9);net[3][7].set_o(&tmp[7][3]);
	net[3][8].set_i(&tmp[1][2],1);net[3][8].set_i(&tmp[2][2],2);net[3][8].set_i(&tmp[3][2],3);net[3][8].set_i(&tmp[4][2],4);net[3][8].set_i(&tmp[5][2],5);net[3][8].set_i(&tmp[6][2],6);net[3][8].set_i(&tmp[7][2],7);net[3][8].set_i(&tmp[8][2],8);net[3][8].set_i(&tmp[9][2],9);net[3][8].set_o(&tmp[8][3]);
	net[3][9].set_i(&tmp[1][2],1);net[3][9].set_i(&tmp[2][2],2);net[3][9].set_i(&tmp[3][2],3);net[3][9].set_i(&tmp[4][2],4);net[3][9].set_i(&tmp[5][2],5);net[3][9].set_i(&tmp[6][2],6);net[3][9].set_i(&tmp[7][2],7);net[3][9].set_i(&tmp[8][2],8);net[3][9].set_i(&tmp[9][2],9);net[3][9].set_o(&tmp[9][3]);
	net[4][1].set_i(&tmp[1][3],1);net[4][1].set_i(&tmp[2][3],2);net[4][1].set_i(&tmp[3][3],3);net[4][1].set_i(&tmp[4][3],4);net[4][1].set_i(&tmp[5][3],5);net[4][1].set_i(&tmp[6][3],6);net[4][1].set_i(&tmp[7][3],7);net[4][1].set_i(&tmp[8][3],8);net[4][1].set_i(&tmp[9][3],9);net[4][1].set_o(&tmp[1][4]);
	net[4][2].set_i(&tmp[1][3],1);net[4][2].set_i(&tmp[2][3],2);net[4][2].set_i(&tmp[3][3],3);net[4][2].set_i(&tmp[4][3],4);net[4][2].set_i(&tmp[5][3],5);net[4][2].set_i(&tmp[6][3],6);net[4][2].set_i(&tmp[7][3],7);net[4][2].set_i(&tmp[8][3],8);net[4][2].set_i(&tmp[9][3],9);net[4][2].set_o(&tmp[2][4]);
	net[4][3].set_i(&tmp[1][3],1);net[4][3].set_i(&tmp[2][3],2);net[4][3].set_i(&tmp[3][3],3);net[4][3].set_i(&tmp[4][3],4);net[4][3].set_i(&tmp[5][3],5);net[4][3].set_i(&tmp[6][3],6);net[4][3].set_i(&tmp[7][3],7);net[4][3].set_i(&tmp[8][3],8);net[4][3].set_i(&tmp[9][3],9);net[4][3].set_o(&tmp[3][4]);
	net[4][4].set_i(&tmp[1][3],1);net[4][4].set_i(&tmp[2][3],2);net[4][4].set_i(&tmp[3][3],3);net[4][4].set_i(&tmp[4][3],4);net[4][4].set_i(&tmp[5][3],5);net[4][4].set_i(&tmp[6][3],6);net[4][4].set_i(&tmp[7][3],7);net[4][4].set_i(&tmp[8][3],8);net[4][4].set_i(&tmp[9][3],9);net[4][4].set_o(&tmp[4][4]);
	net[4][5].set_i(&tmp[1][3],1);net[4][5].set_i(&tmp[2][3],2);net[4][5].set_i(&tmp[3][3],3);net[4][5].set_i(&tmp[4][3],4);net[4][5].set_i(&tmp[5][3],5);net[4][5].set_i(&tmp[6][3],6);net[4][5].set_i(&tmp[7][3],7);net[4][5].set_i(&tmp[8][3],8);net[4][5].set_i(&tmp[9][3],9);net[4][5].set_o(&tmp[5][4]);
	net[4][6].set_i(&tmp[1][3],1);net[4][6].set_i(&tmp[2][3],2);net[4][6].set_i(&tmp[3][3],3);net[4][6].set_i(&tmp[4][3],4);net[4][6].set_i(&tmp[5][3],5);net[4][6].set_i(&tmp[6][3],6);net[4][6].set_i(&tmp[7][3],7);net[4][6].set_i(&tmp[8][3],8);net[4][6].set_i(&tmp[9][3],9);net[4][6].set_o(&tmp[6][4]);
	net[4][7].set_i(&tmp[1][3],1);net[4][7].set_i(&tmp[2][3],2);net[4][7].set_i(&tmp[3][3],3);net[4][7].set_i(&tmp[4][3],4);net[4][7].set_i(&tmp[5][3],5);net[4][7].set_i(&tmp[6][3],6);net[4][7].set_i(&tmp[7][3],7);net[4][7].set_i(&tmp[8][3],8);net[4][7].set_i(&tmp[9][3],9);net[4][7].set_o(&tmp[7][4]);
	net[4][8].set_i(&tmp[1][3],1);net[4][8].set_i(&tmp[2][3],2);net[4][8].set_i(&tmp[3][3],3);net[4][8].set_i(&tmp[4][3],4);net[4][8].set_i(&tmp[5][3],5);net[4][8].set_i(&tmp[6][3],6);net[4][8].set_i(&tmp[7][3],7);net[4][8].set_i(&tmp[8][3],8);net[4][8].set_i(&tmp[9][3],9);net[4][8].set_o(&tmp[8][4]);
	net[4][9].set_i(&tmp[1][3],1);net[4][9].set_i(&tmp[2][3],2);net[4][9].set_i(&tmp[3][3],3);net[4][9].set_i(&tmp[4][3],4);net[4][9].set_i(&tmp[5][3],5);net[4][9].set_i(&tmp[6][3],6);net[4][9].set_i(&tmp[7][3],7);net[4][9].set_i(&tmp[8][3],8);net[4][9].set_i(&tmp[9][3],9);net[4][9].set_o(&tmp[9][4]);
	net[5][1].set_i(&tmp[1][4],1);net[5][1].set_i(&tmp[2][4],2);net[5][1].set_i(&tmp[3][4],3);net[5][1].set_i(&tmp[4][4],4);net[5][1].set_i(&tmp[5][4],5);net[5][1].set_i(&tmp[6][4],6);net[5][1].set_i(&tmp[7][4],7);net[5][1].set_i(&tmp[8][4],8);net[5][1].set_i(&tmp[9][4],9);net[5][1].set_o(&tmp[1][5]);
	net[5][2].set_i(&tmp[1][4],1);net[5][2].set_i(&tmp[2][4],2);net[5][2].set_i(&tmp[3][4],3);net[5][2].set_i(&tmp[4][4],4);net[5][2].set_i(&tmp[5][4],5);net[5][2].set_i(&tmp[6][4],6);net[5][2].set_i(&tmp[7][4],7);net[5][2].set_i(&tmp[8][4],8);net[5][2].set_i(&tmp[9][4],9);net[5][2].set_o(&tmp[2][5]);
	net[5][3].set_i(&tmp[1][4],1);net[5][3].set_i(&tmp[2][4],2);net[5][3].set_i(&tmp[3][4],3);net[5][3].set_i(&tmp[4][4],4);net[5][3].set_i(&tmp[5][4],5);net[5][3].set_i(&tmp[6][4],6);net[5][3].set_i(&tmp[7][4],7);net[5][3].set_i(&tmp[8][4],8);net[5][3].set_i(&tmp[9][4],9);net[5][3].set_o(&tmp[3][5]);
	net[5][4].set_i(&tmp[1][4],1);net[5][4].set_i(&tmp[2][4],2);net[5][4].set_i(&tmp[3][4],3);net[5][4].set_i(&tmp[4][4],4);net[5][4].set_i(&tmp[5][4],5);net[5][4].set_i(&tmp[6][4],6);net[5][4].set_i(&tmp[7][4],7);net[5][4].set_i(&tmp[8][4],8);net[5][4].set_i(&tmp[9][4],9);net[5][4].set_o(&tmp[4][5]);
	net[5][5].set_i(&tmp[1][4],1);net[5][5].set_i(&tmp[2][4],2);net[5][5].set_i(&tmp[3][4],3);net[5][5].set_i(&tmp[4][4],4);net[5][5].set_i(&tmp[5][4],5);net[5][5].set_i(&tmp[6][4],6);net[5][5].set_i(&tmp[7][4],7);net[5][5].set_i(&tmp[8][4],8);net[5][5].set_i(&tmp[9][4],9);net[5][5].set_o(&tmp[5][5]);
	net[5][6].set_i(&tmp[1][4],1);net[5][6].set_i(&tmp[2][4],2);net[5][6].set_i(&tmp[3][4],3);net[5][6].set_i(&tmp[4][4],4);net[5][6].set_i(&tmp[5][4],5);net[5][6].set_i(&tmp[6][4],6);net[5][6].set_i(&tmp[7][4],7);net[5][6].set_i(&tmp[8][4],8);net[5][6].set_i(&tmp[9][4],9);net[5][6].set_o(&tmp[6][5]);
	net[5][7].set_i(&tmp[1][4],1);net[5][7].set_i(&tmp[2][4],2);net[5][7].set_i(&tmp[3][4],3);net[5][7].set_i(&tmp[4][4],4);net[5][7].set_i(&tmp[5][4],5);net[5][7].set_i(&tmp[6][4],6);net[5][7].set_i(&tmp[7][4],7);net[5][7].set_i(&tmp[8][4],8);net[5][7].set_i(&tmp[9][4],9);net[5][7].set_o(&tmp[7][5]);
	net[5][8].set_i(&tmp[1][4],1);net[5][8].set_i(&tmp[2][4],2);net[5][8].set_i(&tmp[3][4],3);net[5][8].set_i(&tmp[4][4],4);net[5][8].set_i(&tmp[5][4],5);net[5][8].set_i(&tmp[6][4],6);net[5][8].set_i(&tmp[7][4],7);net[5][8].set_i(&tmp[8][4],8);net[5][8].set_i(&tmp[9][4],9);net[5][8].set_o(&tmp[8][5]);
	net[5][9].set_i(&tmp[1][4],1);net[5][9].set_i(&tmp[2][4],2);net[5][9].set_i(&tmp[3][4],3);net[5][9].set_i(&tmp[4][4],4);net[5][9].set_i(&tmp[5][4],5);net[5][9].set_i(&tmp[6][4],6);net[5][9].set_i(&tmp[7][4],7);net[5][9].set_i(&tmp[8][4],8);net[5][9].set_i(&tmp[9][4],9);net[5][9].set_o(&tmp[9][5]);
	net[6][1].set_i(&tmp[1][5],1);net[6][1].set_i(&tmp[2][5],2);net[6][1].set_i(&tmp[3][5],3);net[6][1].set_i(&tmp[4][5],4);net[6][1].set_i(&tmp[5][5],5);net[6][1].set_i(&tmp[6][5],6);net[6][1].set_i(&tmp[7][5],7);net[6][1].set_i(&tmp[8][5],8);net[6][1].set_i(&tmp[9][5],9);net[6][1].set_o(&tmp[1][6]);
	net[6][2].set_i(&tmp[1][5],1);net[6][2].set_i(&tmp[2][5],2);net[6][2].set_i(&tmp[3][5],3);net[6][2].set_i(&tmp[4][5],4);net[6][2].set_i(&tmp[5][5],5);net[6][2].set_i(&tmp[6][5],6);net[6][2].set_i(&tmp[7][5],7);net[6][2].set_i(&tmp[8][5],8);net[6][2].set_i(&tmp[9][5],9);net[6][2].set_o(&tmp[2][6]);
	net[6][3].set_i(&tmp[1][5],1);net[6][3].set_i(&tmp[2][5],2);net[6][3].set_i(&tmp[3][5],3);net[6][3].set_i(&tmp[4][5],4);net[6][3].set_i(&tmp[5][5],5);net[6][3].set_i(&tmp[6][5],6);net[6][3].set_i(&tmp[7][5],7);net[6][3].set_i(&tmp[8][5],8);net[6][3].set_i(&tmp[9][5],9);net[6][3].set_o(&tmp[3][6]);
	net[6][4].set_i(&tmp[1][5],1);net[6][4].set_i(&tmp[2][5],2);net[6][4].set_i(&tmp[3][5],3);net[6][4].set_i(&tmp[4][5],4);net[6][4].set_i(&tmp[5][5],5);net[6][4].set_i(&tmp[6][5],6);net[6][4].set_i(&tmp[7][5],7);net[6][4].set_i(&tmp[8][5],8);net[6][4].set_i(&tmp[9][5],9);net[6][4].set_o(&tmp[4][6]);
	net[6][5].set_i(&tmp[1][5],1);net[6][5].set_i(&tmp[2][5],2);net[6][5].set_i(&tmp[3][5],3);net[6][5].set_i(&tmp[4][5],4);net[6][5].set_i(&tmp[5][5],5);net[6][5].set_i(&tmp[6][5],6);net[6][5].set_i(&tmp[7][5],7);net[6][5].set_i(&tmp[8][5],8);net[6][5].set_i(&tmp[9][5],9);net[6][5].set_o(&tmp[5][6]);
	net[6][6].set_i(&tmp[1][5],1);net[6][6].set_i(&tmp[2][5],2);net[6][6].set_i(&tmp[3][5],3);net[6][6].set_i(&tmp[4][5],4);net[6][6].set_i(&tmp[5][5],5);net[6][6].set_i(&tmp[6][5],6);net[6][6].set_i(&tmp[7][5],7);net[6][6].set_i(&tmp[8][5],8);net[6][6].set_i(&tmp[9][5],9);net[6][6].set_o(&tmp[6][6]);
	net[6][7].set_i(&tmp[1][5],1);net[6][7].set_i(&tmp[2][5],2);net[6][7].set_i(&tmp[3][5],3);net[6][7].set_i(&tmp[4][5],4);net[6][7].set_i(&tmp[5][5],5);net[6][7].set_i(&tmp[6][5],6);net[6][7].set_i(&tmp[7][5],7);net[6][7].set_i(&tmp[8][5],8);net[6][7].set_i(&tmp[9][5],9);net[6][7].set_o(&tmp[7][6]);
	net[6][8].set_i(&tmp[1][5],1);net[6][8].set_i(&tmp[2][5],2);net[6][8].set_i(&tmp[3][5],3);net[6][8].set_i(&tmp[4][5],4);net[6][8].set_i(&tmp[5][5],5);net[6][8].set_i(&tmp[6][5],6);net[6][8].set_i(&tmp[7][5],7);net[6][8].set_i(&tmp[8][5],8);net[6][8].set_i(&tmp[9][5],9);net[6][8].set_o(&tmp[8][6]);
	net[6][9].set_i(&tmp[1][5],1);net[6][9].set_i(&tmp[2][5],2);net[6][9].set_i(&tmp[3][5],3);net[6][9].set_i(&tmp[4][5],4);net[6][9].set_i(&tmp[5][5],5);net[6][9].set_i(&tmp[6][5],6);net[6][9].set_i(&tmp[7][5],7);net[6][9].set_i(&tmp[8][5],8);net[6][9].set_i(&tmp[9][5],9);net[6][9].set_o(&tmp[9][6]);
	net[7][1].set_i(&tmp[1][6],1);net[7][1].set_i(&tmp[2][6],2);net[7][1].set_i(&tmp[3][6],3);net[7][1].set_i(&tmp[4][6],4);net[7][1].set_i(&tmp[5][6],5);net[7][1].set_i(&tmp[6][6],6);net[7][1].set_i(&tmp[7][6],7);net[7][1].set_i(&tmp[8][6],8);net[7][1].set_i(&tmp[9][6],9);net[7][1].set_o(&tmp[1][7]);
	net[7][2].set_i(&tmp[1][6],1);net[7][2].set_i(&tmp[2][6],2);net[7][2].set_i(&tmp[3][6],3);net[7][2].set_i(&tmp[4][6],4);net[7][2].set_i(&tmp[5][6],5);net[7][2].set_i(&tmp[6][6],6);net[7][2].set_i(&tmp[7][6],7);net[7][2].set_i(&tmp[8][6],8);net[7][2].set_i(&tmp[9][6],9);net[7][2].set_o(&tmp[2][7]);
	net[7][3].set_i(&tmp[1][6],1);net[7][3].set_i(&tmp[2][6],2);net[7][3].set_i(&tmp[3][6],3);net[7][3].set_i(&tmp[4][6],4);net[7][3].set_i(&tmp[5][6],5);net[7][3].set_i(&tmp[6][6],6);net[7][3].set_i(&tmp[7][6],7);net[7][3].set_i(&tmp[8][6],8);net[7][3].set_i(&tmp[9][6],9);net[7][3].set_o(&tmp[3][7]);
	net[7][4].set_i(&tmp[1][6],1);net[7][4].set_i(&tmp[2][6],2);net[7][4].set_i(&tmp[3][6],3);net[7][4].set_i(&tmp[4][6],4);net[7][4].set_i(&tmp[5][6],5);net[7][4].set_i(&tmp[6][6],6);net[7][4].set_i(&tmp[7][6],7);net[7][4].set_i(&tmp[8][6],8);net[7][4].set_i(&tmp[9][6],9);net[7][4].set_o(&tmp[4][7]);
	net[7][5].set_i(&tmp[1][6],1);net[7][5].set_i(&tmp[2][6],2);net[7][5].set_i(&tmp[3][6],3);net[7][5].set_i(&tmp[4][6],4);net[7][5].set_i(&tmp[5][6],5);net[7][5].set_i(&tmp[6][6],6);net[7][5].set_i(&tmp[7][6],7);net[7][5].set_i(&tmp[8][6],8);net[7][5].set_i(&tmp[9][6],9);net[7][5].set_o(&tmp[5][7]);
	net[7][6].set_i(&tmp[1][6],1);net[7][6].set_i(&tmp[2][6],2);net[7][6].set_i(&tmp[3][6],3);net[7][6].set_i(&tmp[4][6],4);net[7][6].set_i(&tmp[5][6],5);net[7][6].set_i(&tmp[6][6],6);net[7][6].set_i(&tmp[7][6],7);net[7][6].set_i(&tmp[8][6],8);net[7][6].set_i(&tmp[9][6],9);net[7][6].set_o(&tmp[6][7]);
	net[7][7].set_i(&tmp[1][6],1);net[7][7].set_i(&tmp[2][6],2);net[7][7].set_i(&tmp[3][6],3);net[7][7].set_i(&tmp[4][6],4);net[7][7].set_i(&tmp[5][6],5);net[7][7].set_i(&tmp[6][6],6);net[7][7].set_i(&tmp[7][6],7);net[7][7].set_i(&tmp[8][6],8);net[7][7].set_i(&tmp[9][6],9);net[7][7].set_o(&tmp[7][7]);
	net[7][8].set_i(&tmp[1][6],1);net[7][8].set_i(&tmp[2][6],2);net[7][8].set_i(&tmp[3][6],3);net[7][8].set_i(&tmp[4][6],4);net[7][8].set_i(&tmp[5][6],5);net[7][8].set_i(&tmp[6][6],6);net[7][8].set_i(&tmp[7][6],7);net[7][8].set_i(&tmp[8][6],8);net[7][8].set_i(&tmp[9][6],9);net[7][8].set_o(&tmp[8][7]);
	net[7][9].set_i(&tmp[1][6],1);net[7][9].set_i(&tmp[2][6],2);net[7][9].set_i(&tmp[3][6],3);net[7][9].set_i(&tmp[4][6],4);net[7][9].set_i(&tmp[5][6],5);net[7][9].set_i(&tmp[6][6],6);net[7][9].set_i(&tmp[7][6],7);net[7][9].set_i(&tmp[8][6],8);net[7][9].set_i(&tmp[9][6],9);net[7][9].set_o(&tmp[9][7]);
	net[8][1].set_i(&tmp[1][7],1);net[8][1].set_i(&tmp[2][7],2);net[8][1].set_i(&tmp[3][7],3);net[8][1].set_i(&tmp[4][7],4);net[8][1].set_i(&tmp[5][7],5);net[8][1].set_i(&tmp[6][7],6);net[8][1].set_i(&tmp[7][7],7);net[8][1].set_i(&tmp[8][7],8);net[8][1].set_i(&tmp[9][7],9);net[8][1].set_o(&tmp[1][8]);
	net[8][2].set_i(&tmp[1][7],1);net[8][2].set_i(&tmp[2][7],2);net[8][2].set_i(&tmp[3][7],3);net[8][2].set_i(&tmp[4][7],4);net[8][2].set_i(&tmp[5][7],5);net[8][2].set_i(&tmp[6][7],6);net[8][2].set_i(&tmp[7][7],7);net[8][2].set_i(&tmp[8][7],8);net[8][2].set_i(&tmp[9][7],9);net[8][2].set_o(&tmp[2][8]);
	net[8][3].set_i(&tmp[1][7],1);net[8][3].set_i(&tmp[2][7],2);net[8][3].set_i(&tmp[3][7],3);net[8][3].set_i(&tmp[4][7],4);net[8][3].set_i(&tmp[5][7],5);net[8][3].set_i(&tmp[6][7],6);net[8][3].set_i(&tmp[7][7],7);net[8][3].set_i(&tmp[8][7],8);net[8][3].set_i(&tmp[9][7],9);net[8][3].set_o(&tmp[3][8]);
	net[8][4].set_i(&tmp[1][7],1);net[8][4].set_i(&tmp[2][7],2);net[8][4].set_i(&tmp[3][7],3);net[8][4].set_i(&tmp[4][7],4);net[8][4].set_i(&tmp[5][7],5);net[8][4].set_i(&tmp[6][7],6);net[8][4].set_i(&tmp[7][7],7);net[8][4].set_i(&tmp[8][7],8);net[8][4].set_i(&tmp[9][7],9);net[8][4].set_o(&tmp[4][8]);
	net[8][5].set_i(&tmp[1][7],1);net[8][5].set_i(&tmp[2][7],2);net[8][5].set_i(&tmp[3][7],3);net[8][5].set_i(&tmp[4][7],4);net[8][5].set_i(&tmp[5][7],5);net[8][5].set_i(&tmp[6][7],6);net[8][5].set_i(&tmp[7][7],7);net[8][5].set_i(&tmp[8][7],8);net[8][5].set_i(&tmp[9][7],9);net[8][5].set_o(&tmp[5][8]);
	net[8][6].set_i(&tmp[1][7],1);net[8][6].set_i(&tmp[2][7],2);net[8][6].set_i(&tmp[3][7],3);net[8][6].set_i(&tmp[4][7],4);net[8][6].set_i(&tmp[5][7],5);net[8][6].set_i(&tmp[6][7],6);net[8][6].set_i(&tmp[7][7],7);net[8][6].set_i(&tmp[8][7],8);net[8][6].set_i(&tmp[9][7],9);net[8][6].set_o(&tmp[6][8]);
	net[8][7].set_i(&tmp[1][7],1);net[8][7].set_i(&tmp[2][7],2);net[8][7].set_i(&tmp[3][7],3);net[8][7].set_i(&tmp[4][7],4);net[8][7].set_i(&tmp[5][7],5);net[8][7].set_i(&tmp[6][7],6);net[8][7].set_i(&tmp[7][7],7);net[8][7].set_i(&tmp[8][7],8);net[8][7].set_i(&tmp[9][7],9);net[8][7].set_o(&tmp[7][8]);
	net[8][8].set_i(&tmp[1][7],1);net[8][8].set_i(&tmp[2][7],2);net[8][8].set_i(&tmp[3][7],3);net[8][8].set_i(&tmp[4][7],4);net[8][8].set_i(&tmp[5][7],5);net[8][8].set_i(&tmp[6][7],6);net[8][8].set_i(&tmp[7][7],7);net[8][8].set_i(&tmp[8][7],8);net[8][8].set_i(&tmp[9][7],9);net[8][8].set_o(&tmp[8][8]);
	net[8][9].set_i(&tmp[1][7],1);net[8][9].set_i(&tmp[2][7],2);net[8][9].set_i(&tmp[3][7],3);net[8][9].set_i(&tmp[4][7],4);net[8][9].set_i(&tmp[5][7],5);net[8][9].set_i(&tmp[6][7],6);net[8][9].set_i(&tmp[7][7],7);net[8][9].set_i(&tmp[8][7],8);net[8][9].set_i(&tmp[9][7],9);net[8][9].set_o(&tmp[9][8]);
	net[9][1].set_i(&tmp[1][8],1);net[9][1].set_i(&tmp[2][8],2);net[9][1].set_i(&tmp[3][8],3);net[9][1].set_i(&tmp[4][8],4);net[9][1].set_i(&tmp[5][8],5);net[9][1].set_i(&tmp[6][8],6);net[9][1].set_i(&tmp[7][8],7);net[9][1].set_i(&tmp[8][8],8);net[9][1].set_i(&tmp[9][8],9);net[9][1].set_o(&tmp[1][9]);
	net[9][2].set_i(&tmp[1][8],1);net[9][2].set_i(&tmp[2][8],2);net[9][2].set_i(&tmp[3][8],3);net[9][2].set_i(&tmp[4][8],4);net[9][2].set_i(&tmp[5][8],5);net[9][2].set_i(&tmp[6][8],6);net[9][2].set_i(&tmp[7][8],7);net[9][2].set_i(&tmp[8][8],8);net[9][2].set_i(&tmp[9][8],9);net[9][2].set_o(&tmp[2][9]);
	net[9][3].set_i(&tmp[1][8],1);net[9][3].set_i(&tmp[2][8],2);net[9][3].set_i(&tmp[3][8],3);net[9][3].set_i(&tmp[4][8],4);net[9][3].set_i(&tmp[5][8],5);net[9][3].set_i(&tmp[6][8],6);net[9][3].set_i(&tmp[7][8],7);net[9][3].set_i(&tmp[8][8],8);net[9][3].set_i(&tmp[9][8],9);net[9][3].set_o(&tmp[3][9]);
	net[9][4].set_i(&tmp[1][8],1);net[9][4].set_i(&tmp[2][8],2);net[9][4].set_i(&tmp[3][8],3);net[9][4].set_i(&tmp[4][8],4);net[9][4].set_i(&tmp[5][8],5);net[9][4].set_i(&tmp[6][8],6);net[9][4].set_i(&tmp[7][8],7);net[9][4].set_i(&tmp[8][8],8);net[9][4].set_i(&tmp[9][8],9);net[9][4].set_o(&tmp[4][9]);
	net[9][5].set_i(&tmp[1][8],1);net[9][5].set_i(&tmp[2][8],2);net[9][5].set_i(&tmp[3][8],3);net[9][5].set_i(&tmp[4][8],4);net[9][5].set_i(&tmp[5][8],5);net[9][5].set_i(&tmp[6][8],6);net[9][5].set_i(&tmp[7][8],7);net[9][5].set_i(&tmp[8][8],8);net[9][5].set_i(&tmp[9][8],9);net[9][5].set_o(&tmp[5][9]);
	net[9][6].set_i(&tmp[1][8],1);net[9][6].set_i(&tmp[2][8],2);net[9][6].set_i(&tmp[3][8],3);net[9][6].set_i(&tmp[4][8],4);net[9][6].set_i(&tmp[5][8],5);net[9][6].set_i(&tmp[6][8],6);net[9][6].set_i(&tmp[7][8],7);net[9][6].set_i(&tmp[8][8],8);net[9][6].set_i(&tmp[9][8],9);net[9][6].set_o(&tmp[6][9]);
	net[9][7].set_i(&tmp[1][8],1);net[9][7].set_i(&tmp[2][8],2);net[9][7].set_i(&tmp[3][8],3);net[9][7].set_i(&tmp[4][8],4);net[9][7].set_i(&tmp[5][8],5);net[9][7].set_i(&tmp[6][8],6);net[9][7].set_i(&tmp[7][8],7);net[9][7].set_i(&tmp[8][8],8);net[9][7].set_i(&tmp[9][8],9);net[9][7].set_o(&tmp[7][9]);
	net[9][8].set_i(&tmp[1][8],1);net[9][8].set_i(&tmp[2][8],2);net[9][8].set_i(&tmp[3][8],3);net[9][8].set_i(&tmp[4][8],4);net[9][8].set_i(&tmp[5][8],5);net[9][8].set_i(&tmp[6][8],6);net[9][8].set_i(&tmp[7][8],7);net[9][8].set_i(&tmp[8][8],8);net[9][8].set_i(&tmp[9][8],9);net[9][8].set_o(&tmp[8][9]);
	net[9][9].set_i(&tmp[1][8],1);net[9][9].set_i(&tmp[2][8],2);net[9][9].set_i(&tmp[3][8],3);net[9][9].set_i(&tmp[4][8],4);net[9][9].set_i(&tmp[5][8],5);net[9][9].set_i(&tmp[6][8],6);net[9][9].set_i(&tmp[7][8],7);net[9][9].set_i(&tmp[8][8],8);net[9][9].set_i(&tmp[9][8],9);net[9][9].set_o(&tmp[9][9]);
	net[10][1].set_i(&tmp[1][9],1);net[10][1].set_i(&tmp[2][9],2);net[10][1].set_i(&tmp[3][9],3);net[10][1].set_i(&tmp[4][9],4);net[10][1].set_i(&tmp[5][9],5);net[10][1].set_i(&tmp[6][9],6);net[10][1].set_i(&tmp[7][9],7);net[10][1].set_i(&tmp[8][9],8);net[10][1].set_i(&tmp[9][9],9);net[10][1].set_o(&tmp[1][10]);
	net[10][2].set_i(&tmp[1][9],1);net[10][2].set_i(&tmp[2][9],2);net[10][2].set_i(&tmp[3][9],3);net[10][2].set_i(&tmp[4][9],4);net[10][2].set_i(&tmp[5][9],5);net[10][2].set_i(&tmp[6][9],6);net[10][2].set_i(&tmp[7][9],7);net[10][2].set_i(&tmp[8][9],8);net[10][2].set_i(&tmp[9][9],9);net[10][2].set_o(&tmp[2][10]);
	net[10][3].set_i(&tmp[1][9],1);net[10][3].set_i(&tmp[2][9],2);net[10][3].set_i(&tmp[3][9],3);net[10][3].set_i(&tmp[4][9],4);net[10][3].set_i(&tmp[5][9],5);net[10][3].set_i(&tmp[6][9],6);net[10][3].set_i(&tmp[7][9],7);net[10][3].set_i(&tmp[8][9],8);net[10][3].set_i(&tmp[9][9],9);net[10][3].set_o(&tmp[3][10]);
	net[10][4].set_i(&tmp[1][9],1);net[10][4].set_i(&tmp[2][9],2);net[10][4].set_i(&tmp[3][9],3);net[10][4].set_i(&tmp[4][9],4);net[10][4].set_i(&tmp[5][9],5);net[10][4].set_i(&tmp[6][9],6);net[10][4].set_i(&tmp[7][9],7);net[10][4].set_i(&tmp[8][9],8);net[10][4].set_i(&tmp[9][9],9);net[10][4].set_o(&tmp[4][10]);
	net[10][5].set_i(&tmp[1][9],1);net[10][5].set_i(&tmp[2][9],2);net[10][5].set_i(&tmp[3][9],3);net[10][5].set_i(&tmp[4][9],4);net[10][5].set_i(&tmp[5][9],5);net[10][5].set_i(&tmp[6][9],6);net[10][5].set_i(&tmp[7][9],7);net[10][5].set_i(&tmp[8][9],8);net[10][5].set_i(&tmp[9][9],9);net[10][5].set_o(&tmp[5][10]);
	net[10][6].set_i(&tmp[1][9],1);net[10][6].set_i(&tmp[2][9],2);net[10][6].set_i(&tmp[3][9],3);net[10][6].set_i(&tmp[4][9],4);net[10][6].set_i(&tmp[5][9],5);net[10][6].set_i(&tmp[6][9],6);net[10][6].set_i(&tmp[7][9],7);net[10][6].set_i(&tmp[8][9],8);net[10][6].set_i(&tmp[9][9],9);net[10][6].set_o(&tmp[6][10]);
	net[10][7].set_i(&tmp[1][9],1);net[10][7].set_i(&tmp[2][9],2);net[10][7].set_i(&tmp[3][9],3);net[10][7].set_i(&tmp[4][9],4);net[10][7].set_i(&tmp[5][9],5);net[10][7].set_i(&tmp[6][9],6);net[10][7].set_i(&tmp[7][9],7);net[10][7].set_i(&tmp[8][9],8);net[10][7].set_i(&tmp[9][9],9);net[10][7].set_o(&tmp[7][10]);
	net[10][8].set_i(&tmp[1][9],1);net[10][8].set_i(&tmp[2][9],2);net[10][8].set_i(&tmp[3][9],3);net[10][8].set_i(&tmp[4][9],4);net[10][8].set_i(&tmp[5][9],5);net[10][8].set_i(&tmp[6][9],6);net[10][8].set_i(&tmp[7][9],7);net[10][8].set_i(&tmp[8][9],8);net[10][8].set_i(&tmp[9][9],9);net[10][8].set_o(&tmp[8][10]);
	net[10][9].set_i(&tmp[1][9],1);net[10][9].set_i(&tmp[2][9],2);net[10][9].set_i(&tmp[3][9],3);net[10][9].set_i(&tmp[4][9],4);net[10][9].set_i(&tmp[5][9],5);net[10][9].set_i(&tmp[6][9],6);net[10][9].set_i(&tmp[7][9],7);net[10][9].set_i(&tmp[8][9],8);net[10][9].set_i(&tmp[9][9],9);net[10][9].set_o(&tmp[9][10]);
	output.set_i(&tmp[1][10],1);output.set_i(&tmp[2][10],2);output.set_i(&tmp[3][10],3);output.set_i(&tmp[4][10],4);output.set_i(&tmp[5][10],5);output.set_i(&tmp[6][10],6);output.set_i(&tmp[7][10],7);output.set_i(&tmp[8][10],8);output.set_i(&tmp[9][10],9);output.set_o(&return_output);
	int mem_x=1;
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			f_value[mem_x] = &input[i].f[j];
			mem_x++;
		}
		f_value[mem_x] = &input[i].fo;
		mem_x++;
	}
	for(int i=1;i<=10;i++){
		for(int j=1;j<=9;j++){
			for(int k=1;k<=9;k++){
				f_value[mem_x] = &net[i][j].f[k];
				mem_x++;
			}
			f_value[mem_x] = &net[i][j].fo;
			mem_x++;
		}
	}
	for(int i=1;i<=9;i++){
		f_value[mem_x] = &output.f[i];
		mem_x++;
	}
	f_value[mem_x] = &output.fo;
	
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			net[i][j].init();
		}
	}
	return;
}

void run(){
	for(int i=1;i<=9;i++){
		input[i].r1();
	}
	for(int i=1;i<=10;i++){
		for(int j=1;j<=9;j++){
			net[i][j].r1();
		}
	}
	output.r1();
}

void training(double step,double answer,int max){
	double x1,x2;
	run();
	x1 = answer - return_output;
	for(int i=1;i<=1000;i++){
		for(int j=0;j<max;j++){
			*f_value[i] += step;
			run();
			x2 = answer - return_output;
			//std::clog<<"[INFO] "<<"Loop Result: "<<return_output<<std::endl;
			if(std::abs(x2)>std::abs(x1)){
				*f_value[i] -= step*2;
				break;
			}
		}
		run();
		std::clog<<"[INFO] "<<"*f_value["<<i<<"] Set: "<<*f_value[i]<<std::endl;
		std::clog<<"[INFO] "<<"Output: "<<return_output<<std::endl;
	}
}
