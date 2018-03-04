#ifndef RESOURCES_H_INCLUDED
#define RESOURCES_H_INCLUDED

#include <sstream>
#include <string>

#define to_string(x) static_cast<std::ostringstream&>(std::ostringstream()<<std::dec<<x).str()

extern const int WIN_SIZE, SQUARE_RADIUS,
                 PL_VEL, //PLAYER VELOCITY
                 EN_VEL, //ENEMY VELOCITY
                 PPS; //POINTS PER SECOND

#endif // RESOURCES_H_INCLUDED
