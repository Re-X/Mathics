#include <iostream>
#include <vector>

using namespace std;

template <typename T> class Matrix;

template <typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T> &m);

template <typename T>
std::istream& operator>>(std::istream& is, const Matrix<T> &m);

template <typename T>
class Matrix{
	public:
		vector<vector<T>> mat;
		
		T det = 0;
				
		Matrix(vector<vector<T>> _mat = {{}}){
			mat = _mat;
		}
		
		Matrix<T> Transpose(){
			Matrix<T> t;
			vector<vector<T>> temp(mat[0].size(), vector<T>(mat.size(), 1));
			t.mat = temp;
			for(int i = 0; i<mat.size(); i++){
				for(int j = 0; j<mat[i].size(); j++){
					t.mat[j][i] = mat[i][j];
				}
			}
			t.det = det;
			return t;
		}
		
		void operator=(vector<vector<T>> tmp){
			mat = tmp;
		}
		
		void operator=(Matrix<T> &other){
			vector<vector<T>> temp(other.mat.size(), vector<T>(other.mat[0].size(), 1));
			mat.clear();
			mat = temp;
			for(int i = 0; i<other.mat.size(); i++){
				for(int j = 0; j<other.mat[0].size(); j++){
					mat[i][j] = (T)other.mat[i][j];
				}
			}
		}
		
		T Determinant(){
			if(det == 0){
				if (mat[0].size() != mat.size())
					throw std::invalid_argument("Matrix is not a square matrix.");
				else if(mat.size()==1){
					return mat[0][0];
				}
				else if (mat.size()==2){
					return mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];
				}
				T determinant = 0;
				Matrix<T> tmp;
				for(int x = 0; x<mat[0].size(); x++){
					if(mat[0][x]!=0){
						tmp.mat = mat;
						tmp.mat.erase(tmp.mat.begin());
						for(int y = 0; y<mat.size()-1; y++){
							(tmp.mat[y]).erase(tmp.mat[y].begin()+x, tmp.mat[y].begin()+x+1);
						}
						if(x%2==0){
							determinant = determinant + mat[0][x]*tmp.Det();
						}
						else{
							determinant = determinant - mat[0][x]*tmp.Det();
						}
					}
				}
				det = determinant;
				return determinant;
			}
			else
				return det;
		}
		
		T Det(){
			if(det == 0){
				if (mat[0].size() != mat.size())
					throw std::invalid_argument("Matrix is not a square matrix.");
				else if(mat.size()==1){
					return mat[0][0];
				}
				else if (mat.size()==2){
					return mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];
				}
				else if (mat.size()==3){
					T a, b, c;
					a = mat[0][0] * (mat[1][1]*mat[2][2] - mat[2][1]*mat[1][2]);
					b = -mat[0][1] * (mat[1][0]*mat[2][2] - mat[2][0]*mat[1][2]);
					c = mat[0][2] * (mat[2][1]*mat[1][0] - mat[2][0]*mat[1][1]);
					return a+b+c;
				}
				else {
					T determinant = 0;
					Matrix<T> tmp;
					for(int x = 0; x<mat[0].size(); x++){
						if(mat[0][x]!=0){
							tmp.mat = mat;
							tmp.det = 0;
							tmp.mat.erase(tmp.mat.begin());
							for(int y = 0; y<mat.size()-1; y++){
								(tmp.mat[y]).erase(tmp.mat[y].begin()+x, tmp.mat[y].begin()+x+1);
							}
							//cout<<tmp<<tmp.Det()<<endl;
							if(x%2==0){
								// cout<<" + mat[0]["<<x<<"] * ( ";
								// if(tmp.mat.size()==2){
									// cout<<"2det )";
								// }
								determinant = determinant + mat[0][x]*tmp.Det();
								
								//cout<<mat[0][x]<<" X "<<tmp.Det()<<" = "<<mat[0][x]*tmp.Det()<<endl<<endl;
							}
							else{
								// cout<<" - mat[0]["<<x<<"] * ( ";
								// if(tmp.mat.size()==2){
									// cout<<"2det )";
								// }
								determinant = determinant - mat[0][x]*tmp.Det();
								
								//cout<<-mat[0][x]<<" X "<<tmp.Det()<<" = "<<-mat[0][x]*tmp.Det()<<endl<<endl;
							}
							// if(tmp.mat.size()==2 && x==mat.size()-1)
								// cout<<") ";
						}
					}
					det = determinant;
					return determinant;
				}
			}
			else
				return det;
		}
		
		Matrix<T> operator+(Matrix<T> other){
			Matrix<T> res;
			res.mat = mat;
			for(int i = 0; i < mat.size(); i++){
				for(int j = 0; j < mat[0].size(); j++){
					res.mat[i][j] += other.mat[i][j];
				}
			}
			return res;
		}
		
		Matrix<T> operator-(Matrix<T> other){
			Matrix<T> res;
			res.mat = mat;
			for(int i = 0; i < mat.size(); i++){
				for(int j = 0; j < mat[0].size(); j++){
					res.mat[i][j] -= other.mat[i][j];
				}
			}
			return res;
		}
		
		void operator+=(Matrix<T> other){
			for(int i = 0; i < mat.size(); i++){
				for(int j = 0; j < mat[0].size(); j++){
					mat[i][j] += other.mat[i][j];
				}
			}
		}
		
		void operator-=(Matrix<T> other){
			for(int i = 0; i < mat.size(); i++){
				for(int j = 0; j < mat[0].size(); j++){
					mat[i][j] -= other.mat[i][j];
				}
			}
		}
		
		template <typename X>
		Matrix<double> operator*(Matrix<X> other){
			Matrix<double> res;
			res.mat.clear();
			double tmp;
			int x;
			if (mat[0].size() != other.mat.size())
        		throw std::invalid_argument("These matrices cannot be multiplied");
			for(int i = 0; i < mat.size(); i++){
				res.mat.push_back({});
				for(int j = 0; j < other.mat[0].size(); j++){
					tmp = 0;
					x = 0;
					
					while(x < mat[0].size()){
						tmp += mat[i][x] * other.mat[x][j];
						x++;
					}
					res.mat[i].push_back(tmp);
				}
			}
			return res;
		}
		
		Matrix<T> operator*(T k){
			Matrix<T> res;
			res.mat = mat;
			for(int i = 0; i<mat.size(); i++){
				for(int j = 0; j<mat[0].size(); j++){
					res.mat[i][j] = (double)mat[i][j]*k;
				}
			}
			return res;
		} 
		
		template <typename X>
		Matrix<double> operator/(X k){
			Matrix<double> res;
			vector<vector<double>> temp(mat.size(), vector<double>(mat[0].size(), 1));
			res.mat = temp;
			for(int i = 0; i<mat.size(); i++){
				for(int j = 0; j<mat[0].size(); j++){
					res.mat[i][j] = (double)mat[i][j]/k;
				}
			}
			return res;
		}
		
		vector<T> operator[](const int &rhs) {
			if (abs(rhs) > mat.size()) {
				throw std::invalid_argument("index out of bounds");
			}

			if (rhs >= 0) {
				return mat[rhs];
			} else {
				return mat[mat.size() + rhs];
			}
		}

		void operator++(int x){
			if(mat.size()==mat[0].size()){
				for(int i = 0; i<mat.size(); i++){
					mat[i][i] += 1;
				}
			}
		}
		
		template <typename X>
		bool operator==(Matrix<X> other){
			if(mat.size()==other.mat.size() && mat[0].size()==other.mat[0].size()){
				for(int i = 0; i<mat.size(); i++){
					for(int j = 0; j<mat[0].size(); j++){
						if(mat[i][j]!=other.mat[i][j]){
							return false;
						}
					}
				}
				return true;
			}
			else {
				return false;
			}
		}
		
		template <typename X>
		Matrix<T> operator+(X k){
			if(mat.size()!=mat[0].size()){
				throw std::invalid_argument("Given matrix is not a square matrix.");
			}
			Matrix<T> res;
			res.mat = mat;
			for(int i = 0; i<res.mat.size(); i++){
				res.mat[i][i] += k;
			}
			return res;
		}
		
		Matrix<T> Minor(){
			if (mat[0].size() != mat.size())
        		throw std::invalid_argument("Matrix is not a square matrix.");
			
			Matrix<T> tmp, Minor;
			
			Minor.mat = mat;
			
			for(int i = 0; i<mat.size(); i++){
				for(int x = 0; x<mat[0].size(); x++){
					tmp.mat = mat;
					tmp.det = 0;
					tmp.mat.erase(tmp.mat.begin()+i, tmp.mat.begin()+i+1);
					for(int y = 0; y<mat.size()-1; y++){
						(tmp.mat[y]).erase(tmp.mat[y].begin()+x, tmp.mat[y].begin()+x+1);
					}
					Minor.mat[i][x] = tmp.Det();
				}
			}
			return Minor;
		}
		
		Matrix<T> Cofactors(){
			if (mat[0].size() != mat.size())
        		throw std::invalid_argument("Matrix is not a square matrix.");
			
			Matrix<T> tmp, Co;
			
			Co.mat = mat;
			
			for(int i = 0; i<mat.size(); i++){
				for(int x = 0; x<mat[0].size(); x++){
					tmp.mat = mat;
					tmp.det = 0;
					tmp.mat.erase(tmp.mat.begin()+i, tmp.mat.begin()+i+1);
					for(int y = 0; y<mat.size()-1; y++){
						(tmp.mat[y]).erase(tmp.mat[y].begin()+x, tmp.mat[y].begin()+x+1);
					}
					if((i+x)%2==0)
						Co.mat[i][x] = tmp.Det();
					else
						Co.mat[i][x] = -tmp.Det();
				}
			}
			return Co;
		}
		
		Matrix<T> Adjoint(){
			return Cofactors().Transpose();
		}
		
		Matrix<double> Inverse(){
			if(det == 0){
				if(mat.size()==mat[0].size())
					det = Det();
				if(det!=0)
					return Adjoint()/det;
				else
					throw std::invalid_argument("Can't find inverse of a singular matrix.");
			}
			else
				return Adjoint()/det;
		}
};


template <typename T>
ostream& operator<<(ostream &os, const Matrix<T> &m){
	for(int i = 0; i<m.mat.size(); i++){
		for(int j = 0; j<m.mat[i].size(); j++){
			os << m.mat[i][j] << " ";
		}
		os << endl;
	}
	return os;
}

template <typename T>
istream& operator>>(istream &is, Matrix<T> &m){
	
	int r,c;
	
	if(m.mat.size()==0 || m.mat[0].size()==0){
		cout<<"order : ";
		is>>r;
		is>>c;
		cout<<endl;
		vector<vector<T>> temp(r, vector<T>(c, 1));
		m.mat = temp;
	}
	else{
		r = m.mat.size();
		c = m.mat[0].size();
	}
	
	cout<<"elements ["<<r<<"X"<<c<<"] :"<<endl;
	for(int i = 0; i<r; i++){
		for(int j = 0; j<c; j++){
			is >> m.mat[i][j];
		}
	}
	return is;
}

Matrix<double> RandomMatrix(int r, int c){
	Matrix<double> R;
	R.mat.clear();
	for(int i = 0; i<r; i++){
		R.mat.push_back({(double)rand()/10000});
		for(int j = 0; j<c-1; j++){
			R.mat[R.mat.size()-1].push_back((double)rand()/10000);
		}
	}
	return R;
}

int main(){
	Matrix<int> M;
	Matrix<int> N;
	
	M = {{6, 1, -3},
	     {1, 3, -2},
	     {2, 1, 4}};
	
	//cin>>M;
	
	int d = 1;
	N = {{5},
	     {5},
	     {8}};
	
	//cin>>N;
	
	cout<<endl;
	cout<<"M = \n"<<M<<endl;
	cout<<"N = \n"<<N<<endl;
	cout<<"Det(M) = "<<M.Det()<<endl<<endl;
	cout<<"Minor = \n"<<M.Minor()<<endl;
	cout<<"Cofactors = \n"<<M.Cofactors()<<endl;
	cout<<"Adjoint = \n"<<M.Adjoint()<<endl;	
	cout<<"Inverse = \n"<<M.Inverse()<<endl;
	cout<<"Solution = \n"<<M.Inverse()*N<<endl;
	
	while (true){}
}
