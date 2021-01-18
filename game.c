
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { North, East, South, West } direction;

typedef struct location {
    char *name;
    struct location *north;
    struct location *east;
    struct location *south;
    struct location *west;
  } location;

void beschrijf(location *);
location* ga(location *, direction);

int main() {

  location ingang_appartement = { "aan de ingang", NULL, NULL, NULL, NULL };
  location ingang_eerstekamer = { "aan de ingang eerste kamer", NULL, NULL, NULL, NULL };
  location eerstekamer        = { "in de eerste kamer", NULL, NULL, NULL, NULL };
  location ingang_tweedekamer = { "aan de ingang tweede kamer", NULL, NULL, NULL, NULL };
  location tweedekamer        = { "in de tweede kamer", NULL, NULL, NULL, NULL };
  location ingang_living      = { "aan de ingang living", NULL, NULL, NULL, NULL };
  location ingang_toilet      = { "aan de ingang toilet", NULL, NULL, NULL, NULL };
  location ingang_badkamer    = { "aan de ingang badkamer", NULL, NULL, NULL, NULL };
  location badkamer           = { "in de badkamer", NULL };
  location toilet             = { "in het toilet", NULL };
  location living             = { "in de living", NULL };
  location keuken             = { "in de keuken", NULL };
  location bergruimte         = { "in de bergruimte", NULL };
  
  ingang_appartement.west     = &ingang_eerstekamer;
  ingang_eerstekamer.south    = &eerstekamer;
  ingang_eerstekamer.east     = &ingang_appartement;
  eerstekamer.north           = &ingang_eerstekamer;
  ingang_eerstekamer.west     = &ingang_tweedekamer;
  ingang_tweedekamer.south    = &tweedekamer;
  ingang_tweedekamer.east     = &ingang_eerstekamer;
  tweedekamer.north           = &ingang_tweedekamer;
  ingang_tweedekamer.west     = &ingang_living;
  ingang_living.south         = &ingang_toilet;
  ingang_toilet.south         = &ingang_badkamer;
  ingang_badkamer.south       = &badkamer;
  badkamer.north              = &ingang_badkamer;
  ingang_toilet.west          = &toilet;
  ingang_toilet.north         = &ingang_living;
  toilet.east                 = &ingang_toilet;
  ingang_badkamer.north       = &ingang_toilet;
  ingang_living.west          = &living;
  ingang_living.east          = &ingang_tweedekamer;
  living.east                 = &ingang_living;
  living.south                = &keuken;
  keuken.north                = &living;
  keuken.east                 = &bergruimte;
  bergruimte.west             = &keuken;

  location *kamer = &ingang_appartement;
  beschrijf(kamer);
  kamer = ga(kamer, West);
  kamer = ga(kamer, West);
  kamer = ga(kamer, West);
  kamer = ga(kamer, West);
  kamer = ga(kamer, South);
  kamer = ga(kamer, East);
  kamer = ga(kamer, West);
  kamer = ga(kamer, North);
  kamer = ga(kamer, East);
  kamer = ga(kamer, South);
  kamer = ga(kamer, West);
  kamer = ga(kamer, East);
  kamer = ga(kamer, South);
  kamer = ga(kamer, South);
  kamer = ga(kamer, North);
  kamer = ga(kamer, North);
  kamer = ga(kamer, North);
  kamer = ga(kamer, East);
  kamer = ga(kamer, South);
  kamer = ga(kamer, North);
  kamer = ga(kamer, East);
  kamer = ga(kamer, South);
  kamer = ga(kamer, North);
  kamer = ga(kamer, East);
}

void beschrijf(location *kamer) {
  printf("Ik ben %s.\n", kamer->name);
}

location* ga(location *kamer, direction d) {
  switch(d) {
  case North:
    kamer = (kamer->north) != NULL ? kamer->north : kamer;
    break;  
  case East:
    kamer = (kamer->east) != NULL ? kamer->east : kamer;
    break;  
  case South:
    kamer = (kamer->south) != NULL ? kamer->south : kamer;
    break;  
  case West:
    kamer = (kamer->west) != NULL ? kamer->west : kamer;
    break;  
  default:
    break;
  }
  beschrijf(kamer);
  return kamer;
}
