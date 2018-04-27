CXX = g++
AR = ar cqs

TOP_DIR = ..

TARGET_EXE=demo

####################face_detect source file################### 
CXX_SOURCE += unit_test.cpp 

####################head file###################
DEP_INC_DIR += -I$(TOP_DIR)/common_include/
DEP_INC_DIR += -I$(TOP_DIR)/common_include/ncnn
DEP_INC_DIR += -I$(TOP_DIR)/common_include/opencv2.4.9 
DEP_INC_DIR += -I$(TOP_DIR)/common_include/opencv2.4.9/opencv 
DEP_INC_DIR += -I$(TOP_DIR)/common_include/opencv2.4.9/opencv2 

####################ld flag###################
LDFLAGS= libfacedetect.a
LDFLAGS+= $(TOP_DIR)/common_library/ncnn/libncnn.a  
LDFLAGS+= -L$(TOP_DIR)/common_library/opencv2.4.9 
LDFLAGS+= -lopencv_video -lopencv_highgui -lopencv_imgproc -lopencv_core 
LDFLAGS+= -ljpeg -fopenmp  -lm -pthread -lz -lrt -ldl

OBJ_CPP := $(patsubst %.cpp, %.o, $(CXX_SOURCE))

DEFINE_MACRO := 

CPPFLAGS := -Wall -g
CPPFLAGS += $(DEP_INC_DIR) $(DEFINE_MACRO) -lstdc++

$(TARGET_EXE):$(OBJ_CPP)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o : %.cpp
	$(CXX) $(CPPFLAGS) -O3 -o $@ -c $< 

clean:
	rm -rf $(OBJ_CPP) $(TARGET_EXE)
