CXX = g++
AR = ar cqs

TOP_DIR = ..

TARGET_LIBRARY = libfacedetect.a
####################face_detect source file################### 
CXX_SOURCE += mtcnn.cpp 
CXX_SOURCE += hasx_facedetect.cpp 

####################head file###################
DEP_INC_DIR += -I$(TOP_DIR)/common_include/
DEP_INC_DIR += -I$(TOP_DIR)/common_include/ncnn
DEP_INC_DIR += -I$(TOP_DIR)/common_include/opencv2.4.9 
DEP_INC_DIR += -I$(TOP_DIR)/common_include/opencv2.4.9/opencv 
DEP_INC_DIR += -I$(TOP_DIR)/common_include/opencv2.4.9/opencv2 

OBJ_CPP := $(patsubst %.cpp, %.o, $(CXX_SOURCE))

DEFINE_MACRO := 

CPPFLAGS := -Wall -g  
CPPFLAGS += $(DEP_INC_DIR) $(DEFINE_MACRO) -lstdc++

$(TARGET_LIBRARY):$(OBJ_CPP)
	$(AR) $@ $^ 

%.o : %.cpp
	$(CXX) $(CPPFLAGS) -O3 -o $@ -c $< 

clean:
	rm -rf $(OBJ_CPP) $(TARGET_LIBRARY)
