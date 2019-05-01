#export HUSKY_GAZEBO_DESCRIPTION=$(rospack find husky_custom_gazebo)/urdf/custom_description.gazebo.xacro
export HUSKY_GAZEBO_DESCRIPTION=$(rospack find husky_custom_description)/urdf/custom_description.urdf.xacro
#sh $(rospack find husky_custom_description)/env-hooks/50.husky_custom_description.sh
export HUSKY_DESCRIPTION=$(rospack find husky_custom_description)/urdf/custom_description.urdf.xacro
#export HUSKY_DESCRIPTION=$(rospack find husky_custom_gazebo)/urdf/custom_description.gazebo.xacro
#export HUSKY_URDF_EXTRAS=$(rospack find husky_description)/urdf/empty.urdf
export HUSKY_URDF_EXTRAS=$(rospack find husky_custom_description)/urdf/custom_description.urdf.xacro
#sh $(rospack find husky_custom_gazebo)/env-hooks/50.husky_custom_gazebo.sh
export GAZEBO_MODEL_PATH=~/ros/Husky_Simulation/src/husky_custom_gazebo/models
