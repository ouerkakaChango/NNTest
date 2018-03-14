#include "stdafx.h"
#include "SimpleNN.h"

NNode::NNode(int connection_num):bias(rand_n1_1()) {
	for (int i = 0; i < connection_num; i++) {
		weights.push_back(rand_n1_1());
	}
}

double NNode::GetZ(vector<NNode>& front_layer) {
	double re = 0.0;
	for (int i = 0; i < front_layer.size(); i++) {
		re += front_layer[i].tValue*weights[i];
	}
	re += bias;
	return re;
}

double SimpleNN::activateFunction(double z) {
	return (exp(z) - exp(-z)) / (exp(z) + exp(-z));
}

double SimpleNN::D_activateFunction(double z) {
	return 1 - pow(activateFunction(z), 2);
}

double SimpleNN::GetResult() {
	int re = 0;
	double tmax = -1.0;
	for (int i = 0; i < output_layer.size(); i++) {
		if (output_layer[i].tValue > tmax) {
			re = i;
			tmax = output_layer[i].tValue;
		}
	}
	return re;
}