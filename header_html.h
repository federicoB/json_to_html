/***************************************************************************
This file is part of json_to_html.

json_to_html is free software : you can redistribute it and / or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

json_to_html is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with json_to_html. If not, see <http://www.gnu.org/licenses/>.
***************************************************************************/

const std::string header_marker =
R"(
<!DOCTYPE html>                                                             
<html>                                                                       
  <head>                                                                       
    <meta http-equiv="content-type" content="text/html; charset=UTF-8" />  
    <title> 
      Display TRIP 
    </title>                                
    <script src="http://maps.google.com/maps/api/js?sensor=false"            
          type="text/javascript">
    </script>
  </head>                                                                      
  
  <body>                                                                       
    <div id="map" style="width: 1200px; height: 600px;">
    </div>             

    <script type="text/javascript">                                          

      var locations = [                                                        
                                                                            
)";

const std::string footer_marker = 
R"(                                                                            
      ];                                                                        
                                                                              
      var map = new google.maps.Map(document.getElementById('map'), {           
        zoom: 17,                                                               
        center: new google.maps.LatLng(locations[0][0], locations[0][1]),       
        mapTypeId: google.maps.MapTypeId.ROADMAP                                
      });                                                                       
                                                                              
      var infowindow = new google.maps.InfoWindow();                            
                                                                              
      var marker, i;                                                            
                                                                              
      for (i = 0; i < locations.length; i++) {                                  
        marker = new google.maps.Marker({                                       
          position: new google.maps.LatLng(locations[i][0], locations[i][1]),   
          map: map                                                              
        });                                                                     
                                                                              
        google.maps.event.addListener(marker,'mouseover',(function(marker, i){  
          return function() {                                                   
            infowindow.setContent(locations[i][0]);                             
            infowindow.open(map, marker);                                       
          }                                                                     
        })(marker, i));                                                         
      }                                                                         
    </script>                                                                   
  </body>                                                                       
</html>                                                                       
)";

const std::string header_poly = 
R"(
<!DOCTYPE html>
<html> 
  <head> 
    <meta http-equiv="content-type" content="text/html; charset=UTF-8" /> 
    <title>
      Display TRIP 
    </title> 
    <script src="https://maps.googleapis.com/maps/api/js?v=3.exp&signed_in=true"></script>
    <script type="text/javascript"  src="https://maps.googleapis.com/maps/api/js?v=3.21&sensor=false"></script>
    <script type="text/javascript"  src="https://maps.googleapis.com/maps/api/js?libraries=geometry"></script>  
<!-- Local libraries -->
    <script type="text/javascript" src="ruler/markerwithlabel.js"></script>
    <script type="text/javascript" src="ruler/ContextMenu.js"></script>
    <link rel="stylesheet" type="text/css" href="ruler/ruler_map.css">
    <script type="text/javascript" src="ruler/ruler_map.js"></script>       
  </head> 

  <body>
    <div id="map" style="width: 1250px; height: 900px;"></div>
    
    <script type="text/javascript">
      
    function initialize() {
      
      var map = null ;
      var locationstot = [

)";

const std::string footer_poly = 
R"(
      ];

      var locations=locationstot;
  
      var map = new google.maps.Map(document.getElementById('map'), {
        zoom: 17,
        center: new google.maps.LatLng(locations[1][0], locations[1][1]),
//        mapTypeId: google.maps.MapTypeId.SATELLITE
        mapTypeId: google.maps.MapTypeId.ROADMAP
      });

      var infowindow = new google.maps.InfoWindow();

      var marker, i;

      for (i = 0; i < locations.length; i++) {
        
        marker = new google.maps.Marker({
          position: new google.maps.LatLng(locations[i][0], locations[i][1]),
          map: map,
          zIndex: locations[i][1],
          icon: 'http://maps.gpsvisualizer.com/google_maps/icons/circle/green.png'
        });

        google.maps.event.addListener(marker, 'click', (function(marker, i) {
          return function() {
            infowindow.setContent(locations[i][2]);
            infowindow.open(map, marker);
          }
        })(marker, i));

      }

      var poly_path = [];
  
      for (i = 0; i < locations.length; i++) {  
        poly_path.push(new google.maps.LatLng(locations[i][0], locations[i][1]))
      }
    
      var Traiettorie = new google.maps.Polyline({
        path: poly_path,
        geodesic: true,
        strokeColor: '#CC0000',
        strokeOpacity: 1.,
        strokeWeight: 2
      });
  
      Traiettorie.setMap(map);
      ruler_map = new RulerMap( map ) ;
    }

    google.maps.event.addDomListener(window, 'load', initialize);

    </script>
  </body>
</html>
)";
