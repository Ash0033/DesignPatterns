#include <iostream> 
#include <string> 
using namespace std;

//product
class Computer { public: string CPU; string RAM; string GPU; string Storage;

     void showInfo() {
       cout << "Computer Configuration:\n";
       cout << "CPU: " << CPU << endl;
       cout << "RAM: " << RAM << endl;
       cout << "GPU: " << GPU << endl;
       cout << "Storage: " << Storage << endl;
    }
};
//builder interface 
class IComputerBuilder { 
    public: virtual void buildCPU() = 0; 
            virtual void buildRAM() = 0; 
            virtual void buildGPU() = 0; 
            virtual void buildStorage() = 0;

      virtual Computer getResult() = 0;
      virtual ~IComputerBuilder() = default;
};

class GamingComputerBuilder : public IComputerBuilder { 
    private: Computer computer;
public:
 void buildCPU() override { computer.CPU = "Intel Core i9"; }
 void buildRAM() override { computer.RAM = "32 GB"; }
 void buildGPU() override { computer.GPU = "NVIDIA RTX 4080";}
 void buildStorage() override { computer.Storage = "1 TB SSD"; }
 Computer getResult() override { return computer; }
};

  class Director { public: 
  void construct(IComputerBuilder& builder) {
     builder.buildCPU();
     builder.buildRAM(); 
     builder.buildGPU(); 
     builder.buildStorage(); 
     } 
};

int main() {

          GamingComputerBuilder builder;
              Director director;
          director.construct(builder);
      Computer computer = builder.getResult();
           computer.showInfo();

return 0;
}