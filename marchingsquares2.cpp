#include<iostream>
#include<vector>
template<class AbstractScalarFunction>
class MarchingCubes{
	public:
		
	private:
		AbstractScalarFunction f;
		enum Color{
			WHITE,GRAY,BLACK
			};

		class square{
			private:
				Color getColor(){
					
					return WHITE;
					}
			public:
				int x;
				int y;
				int side;
				Color color; 
				square(int x_,int y_,int side_):x(x_),y(y_),side(side_){
					color=getColor();
					}
			};
		std::vector<square> stack;

		MarchingCubes(double xlow,double ylow,double xhigh,double yhigh,AbstractScalarFunction &func,int depth,int xmesh,int ymesh){
			f=func;
			stack.reserve(xmesh*ymesh);
			for(int i=0;i<xmesh;i++){
				for(int j=0;j<ymesh;j++){
					stack.push_back(square(i*(xhigh-xlow)/xmesh,j*(yhigh-ylow)/ymesh,(xhigh-xlow)/xmesh));
					}
				}
			while(!stack.empty){
				square top=stack.back();
				stack.resize(stack.size()-1);
				
				}
			}

	};

int circle(double x,double y){
	return (x*x+y*y-10>0.0);
	}

int main(){

	}
