#pragma once
//针对5*5图片
//输入层25节点
#include "cvUtil.h"
class NNode {
public:
	NNode(int connection_num);
	double bias;
	vector<double> weights;
	double tValue;
	double GetZ(vector<NNode>& front_layer);
};
class SimpleNN{
public:
	SimpleNN(int _input_num, int _hidden_num, int _output_num) {
		//建立隐藏层与输出层（随机初始化参数）
		for (int i = 0; i < _hidden_num; i++) {
			hidden_layer.push_back(NNode(_input_num));
		}
		for (int i = 0; i < _output_num; i++) {
			output_layer.push_back(NNode(_hidden_num));
		}
		//建立输入层
		for (int i = 0; i < _input_num; i++) {
			input_layer.push_back(NNode(1));
		}
	}

	double activateFunction(double z);
	double D_activateFunction(double z);

	vector<NNode> input_layer,hidden_layer, output_layer;

	void init(vector<int>& inputVec) {
		if (inputVec.size() != input_layer.size()) {
			throw;
			return;
		}
		else {
			for (int i = 0; i < inputVec.size(); i++) {
				input_layer[i].tValue = inputVec[i];
			}
		}
	}
	void feed(vector<int>& input_layer) {
		//计算隐藏层
		for (int j = 0; j < hidden_layer.size(); j++) {
			double t_result = 0.0;
			for (int i = 0; i < input_layer.size(); i++) {
				t_result += hidden_layer[j].weights[i] * input_layer[i];
			}
			t_result += hidden_layer[j].bias;
			hidden_layer[j].tValue = activateFunction(t_result);
		}
		//cout << "输出层：";
		//计算输出层
		for (int k = 0; k < output_layer.size(); k++) {
			double t_result = 0.0;
			for (int j = 0; j < hidden_layer.size(); j++) {
				t_result += output_layer[k].weights[j] * hidden_layer[j].tValue;
			}
			t_result += output_layer[k].bias;
			output_layer[k].tValue = activateFunction(t_result);
			//cout << output_layer[o_i].tValue << " ";
		}
		//cout << endl;
	}

	void bp(vector<int>& valVec) {
		if (valVec.size() != output_layer.size()) {
			cout << "val与NN输出层节点数量不一致\n";
			throw;
			return;
		}
		double w_rate = 0.1, b_rate = 0.1;
		vector<double> errVec;
		for (int i = 0; i < valVec.size(); i++) {
			errVec.push_back(output_layer[i].tValue - valVec[i]);
		}
		///////////////////
		/////bp输出层
		///////////////////

		for (int k = 0; k < output_layer.size(); k++) {
			double temz = output_layer[k].GetZ(hidden_layer);
			double b_pd = errVec[k]*D_activateFunction(temz);
			output_layer[k].bias -= b_rate*b_pd;
			for (int j = 0; j < hidden_layer.size(); j++) {
				double w_pd = b_pd*hidden_layer[j].tValue;
				output_layer[k].weights[j] -= w_rate*w_pd;
			}
		}
		/////////////////
		////bp隐藏层
		//////////////////
		for (int k = 0; k < output_layer.size(); k++) {
			double z_k = output_layer[k].GetZ(hidden_layer);
			for (int j = 0; j < hidden_layer.size(); j++) {
				double z_j = hidden_layer[j].GetZ(input_layer);
				double b_j_pd = errVec[k] * D_activateFunction(z_k)*output_layer[k].weights[j] * D_activateFunction(z_j);
				hidden_layer[j].bias -= b_rate*b_j_pd;
				for (int i = 0; i < input_layer.size(); i++) {
					double w_i_j_pd = b_j_pd*input_layer[i].tValue;
					hidden_layer[j].weights[i] -= w_rate*w_i_j_pd;
				}
			}
		}
	}

	double GetError(vector<int>& valVec) {
		if (valVec.size() != output_layer.size()) {
			cout << "val与NN输出层节点数量不一致\n";
			throw;
			return -1.0;
		}
		else {
			double error = 0.0;
			for (int i = 0; i < output_layer.size(); i++) {
				error += pow(output_layer[i].tValue - valVec[i], 2);
			}
			error /= 2;
			return error;
		}
	}

	double GetResult();

};

