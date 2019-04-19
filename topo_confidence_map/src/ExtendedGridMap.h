#ifndef EXTENDEDGRIDMAP_H 
#define EXTENDEDGRIDMAP_H 

#include <cmath>
#include <vector>

//pcl related
#include <pcl/io/pcd_io.h>
#include <pcl/point_cloud.h>

//grid_map related
#include <grid_map_msgs/GridMap.h>
#include <grid_map_ros/grid_map_ros.hpp>


namespace topology_map {



//index of grid cell
struct MapIndex{

  //2D index 
  grid_map::Index oTwoIndex;//cell index in a matrix
  //1D index
  int iOneIdx; //cell index in a sequance

};

class ExtendedGM{

public:

	ExtendedGM();

	~ExtendedGM();

	void GetParam(const double & dMapMaxRange,
	               const double & dResolution,
	                  const double & dMinMapZ,
	                  const double & dMaxMapZ,
	          const std::string & sMapFrameID);
	

	void GenerateMap(const pcl::PointXYZ & oRobotPos);

	//transform point position to 1 Dimension index
	static int PointoOneDIdx(const pcl::PointXYZ & oPoint,
		                     const grid_map::GridMap & oFeatureMap);

	//transform point position to 1D and 2D indexes
	static MapIndex PointoAllTypeIdx(const pcl::PointXYZ & oPoint,
		                             const grid_map::GridMap & oFeatureMap);

	//transform 2D index to 1D index
	static int TwotoOneDIdx(const grid_map::Index & oIndex);
	static int TwotoOneDIdx(const int & iIndexX, 
		                    const int & iIndexY);

	//transform 1D index to 2D indexes
	static void OneDtoTwoDIdx(grid_map::Index & oTwoDIdx,
		                            const int & iOneDIdx);

	//generate a circle neighoorhood region prepared for circle neighborhood grids research
	std::vector<MapIndex> GenerateCircleMask(const double & dRadius);

	//get the neighboorhood grid indexes
	static void CircleNeighborhood(std::vector<MapIndex> & vNearbyGrids,
	                               const grid_map::GridMap & oFeatureMap,
	                           const std::vector<MapIndex> & vSearchMask,
	                                   const pcl::PointXYZ & oQueryPoint);
	static void CircleNeighborhood(std::vector<int> & vNearbyGrids,
	                         const grid_map::GridMap & oFeatureMap,
	                     const std::vector<MapIndex> & vSearchMask,
	                                     const int & iQueryGridIdx);

	//check inside points
	bool CheckInSidePoint(const pcl::PointXYZ & oPoint);

	//grid number in raws
	static int iGridRawNum;

	//the map - main body 
	grid_map::GridMap m_oFeatureMap;//grid map

	//**Grid map data**
    grid_map::Position3 m_oMinCorner; //Bounding box minimum corner of map.

    grid_map::Position3 m_oMaxCorner; //Bounding box maximum corner of map.

    //a neighboorhood search mask of robot
	std::vector<MapIndex> m_vRobotSearchMask;

	//a neighboorhood search mask of region operation 
	std::vector<MapIndex> m_vGrowSearchMask;

	//a mask region that generates a node 
	std::vector<MapIndex> m_vNodeMadeMask;

private:

	//note that the map size is fixed, thus it must be initialied large enough to pick the scene 
	double m_dMapMaxRange;///<it indicates the half length of bounding box (map)

	double m_dMapResolution; //resolution of map pixels/cells 

	//double m_dRbtLocalRadius;//construted maximum range of map 

	//double m_dNodeRadiusRate;//the rate between robot search radius and node generate radius

	grid_map::Position m_oMapOriginalPos;


};


}

#endif









 




