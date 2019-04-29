# Library Integration

Find It Cambridge pulls in events from the Cambridge Public Library system using its API.


## Team
* Leo Burd, Developer, leob@media.mit.edu
* Mauricio Dinarte, Developer, mauricio@agaric.com
* Clayton Dewey, Project Manager, clayton@agaric.com
* Nancy Tauber, Product Owner, ntauber@cambridgema.gov
* Reinhard Engels, Library Technical Consultant, rengels@cambridgema.gov



## Technical Specifications
The integration is powered by a custom Drupal module, FindIt LibCal, which uses the LibCal API, built and managed by Springshare, to pull in published library events.

### API & Field Mapping
Two APIs are used:
* Authentication API
* Event API


The following fields are mapped from a Library Event to a Find It Event.

| Library Event | Find It Cambridge Event |
| ------------- | ----------------------- |
| title         | title |
| date          | field_event_date |
| campus        | field_locations |
| category      | field_program_categories, field_age_eligibility |
| featured_image | field_logo |
| registration  | field_registration |
| description   | body |



### Age Ranges
Certain Library categories translate to specific Find It Cambridge ages.

| Cambridge Library Category | Find It Cambridge Ages |
| -------------------------- | ---------------------- |
| Children                   | 1-12                   |
| Teen                       | 12-18                  |
| Adult                      | 18+                    |
| Neither of the above are checked | 18+              |


### Categories
| Cambridge Library Category | Find It Cambridge Categories |
| -------------------------- | ---------------------------- |
| ADULT (age 19, 20 and 21+) | Adult Education & Activities |
| Author Event               | Children: Culture and Early Childhood Activities, Teens: Culture and Youth Support & Enrichment Activities, Adults and Blank: Culture and Adult Education & Activities |
| Book Groups                | Children: Culture and Early Childhood Activities, Teens:  Culture and Youth Support & Enrichment Activities, Adults and Blank: Culture and Adult Education & Activities |
| Cambridge Non-Profit       | Adult Education & Activities      |
| CHILDREN (Infant-age 10)   | Early Childhood Activities        |
| City Event                 | Used internally by the library. To be ignored by Find It.|
| ESOL                       | Adult Education & Activities and English classes/ESOL/ESL|
| Film screening             | Children: Early Childhood Activities, Teens: Youth Support & Enrichment Activities, Culture, Adults and Blank: Culture and Adult Education & Activities |
| Performance                | Children: Early Childhood Activities, Drama/Theatre, Teens: Youth Support & Enrichment Activities, Drama/Theatre, Adults: Drama/Theatre and Adult Education & Activities, Blank/Default: Drama/Theatre
| STEAM                      | Children: Early Childhood Activities, STEAM, Teens: Youth Support & Enrichment Activities, STEAM, Adults: STEAM and Adult Education & Activities, Blank/Default: STEAM |
| Sing Along                  | Early Education Activities  |
| Social Events               | Culture, Community Celebration |
| Speaker Series              | Children: Culture and Early Childhood Activities, Teens: Youth Support & Enrichment Activities, Culture, Adults and Blank: Culture and Adult Education & Activities |
| Storytime                   | Early Childhood Activities |
| Technology                  | Children: Computer Access and Classes, Teens: Computer Access and Classes, Adults and Blank: Computer Access and Classes |
| TEEN (ages 11-18)           | Youth Support & Enrichment Activities |
| Workshops and Classes       | Children: Culture and Early Childhood Activities, Teens: Youth Support & Enrichment Activities and Culture, Adults and Blank: Culture and Adult Education & Activities |


### Locations

| Cambridge Library Branches | Find It locations |
| -------------------------- | ----------------- |
| Boudreau Branch            | [Boudreau Branch](http://www.finditcambridge.org/location/boudreau-branch-library-245-concord-avenue-cambridge-massachusetts-02138) |
| Central Square Branch      | [Central Square Branch](https://www.finditcambridge.org/location/central-square-branch-library-45-pearl-street-cambridge-massachusetts-02139) |
| Collins Branch             | [Collins Branch](http://www.finditcambridge.org/location/collins-branch-library-64-aberdeen-ave-cambridge-massachusetts-02138) |
| Main Library               | [Main Library](https://www.finditcambridge.org/node/504) |
| O'Connell Branch           | [O'Connell Branch](http://www.finditcambridge.org/location/oconnell-branch-library-48-6th-street-cambridge-massachusetts-02141) |
| O'Neil Branch              | [O'Neil Branch](http://www.finditcambridge.org/location/oneill-branch-library-70-rindge-ave-cambridge-massachusetts-02140) |


### Repeating Events
While each repeating event is a unique instance on Library websites it is a single node with a repeating rule on the Find It Cambridge website.

### Log
A log of the imported events is visible to content managers at https://www.finditcambridge.org/admin/findit/libcal-events

### Event Import Frequency
Events are imported from the library on the site's cron job, which runs every hour.

### Events Excluded from Import
Events with the Library category “Program” are excluded from import. These are instead created manually on the Find It Cambridge website by the Find It team.

This setting is configurable at https://www.finditcambridge.org/admin/findit/libcal-events

### Configuration Options
The following aspects of the integration can be configured by a content manager from https://www.finditcambridge.org/admin/findit/libcal-events

* Number of events to import each time
* Cambridge Public Library user id
* Cambridge Public Library node id
* Event categories to exclude from import
* Cambridge Library Q&A page
* Cambridge Library logo file
* Term id for wheelchair accessible

## Unpublished Past Events
Once an event has not been updated for 6 months, it is automatically unpublished. This is to keep the number of search results to a reasonable level.



