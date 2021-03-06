//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------

// Use this enum class for indicating the lat/long direction
enum class Compass { N, S, W, E };

// Write your code here
class GPS {

private:
    double latitude;
    double longitude;
    Compass latitudeDirection;
    Compass longitudeDirection;

public:
    GPS() {
        latitude = 0.0;
        longitude = 0.0;
        latitudeDirection = Compass::N;
        longitudeDirection = Compass::W;
    }

    GPS(double lat, double lon) {
        lat < 0.0 || lat > 90.0 ? latitude = 0.0 : latitude = lat;
        lon < 0.0 || lon > 180.0 ? longitude = 0.0 : longitude = lon;

        latitudeDirection = Compass::N;
        longitudeDirection = Compass::W;
    }

    GPS(double lat, Compass latDir, double lon, Compass lonDir) {
        lat < 0.0 || lat > 90.0 ? latitude = 0.0 : latitude = lat;
        lon < 0.0 || lon > 180.0 ? longitude = 0.0 : longitude = lon;

        latDir == Compass::W || latDir == Compass::E ? latitudeDirection = Compass::N : latitudeDirection = latDir;
        lonDir == Compass::N || lonDir == Compass::S ? longitudeDirection = Compass::W : longitudeDirection = lonDir;
    }

    double getLatitude() {
        return latitude;
    }

    Compass getLatitudeDirection() {
        return latitudeDirection;
    }

    double getLongitude() {
        return longitude;
    }

    Compass getLongitudeDirection() {
        return longitudeDirection;
    }

};

//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------

TEST_CASE( "GPS" ) {
    SECTION( "t1" ) {
        GPS c;
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 0.0 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
    SECTION( "t2" ) {
        GPS c{12.12, 50.34};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
    SECTION( "t3" ) {
        GPS c{12.12, Compass::S, 50.34, Compass::E};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::S );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::E );
    }
    SECTION( "t4" ) {
        GPS c{122.12, 50.34};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLongitude() == 50.34 );
    }
    SECTION( "t5" ) {
        GPS c{122.12, 500.34};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLongitude() == 0.0 );
    }
    SECTION( "t6" ) {
        GPS c{-122.12, 50.34};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLongitude() == 50.34 );
    }
    SECTION( "t7" ) {
        GPS c{12.12, -50.34};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLongitude() == 0.0 );
    }
    SECTION( "t8" ) {
        GPS c{12.12, Compass::W, 50.34, Compass::E};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::E );
    }
    SECTION( "t9" ) {
        GPS c{12.12, Compass::N, 50.34, Compass::N};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
    SECTION( "t10" ) {
        GPS c{-12.12, Compass::E, 540.34, Compass::N};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 0.0 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
}
//------------------------------
