import xml.etree.ElementTree as ET
from xml.dom import minidom
import math

# Haversine formula to calculate the distance between two lat/lon points (in meters)
def haversine(lat1, lon1, lat2, lon2):
    R = 6371000  # Radius of Earth in meters
    phi1 = math.radians(lat1)
    phi2 = math.radians(lat2)
    delta_phi = math.radians(lat2 - lat1)
    delta_lambda = math.radians(lon2 - lon1)
    
    a = math.sin(delta_phi / 2) ** 2 + math.cos(phi1) * math.cos(phi2) * math.sin(delta_lambda / 2) ** 2
    c = 2 * math.atan2(math.sqrt(a), math.sqrt(1 - a))
    
    return R * c

# Linear interpolation between two lat/lon points
def interpolate_points(lat1, lon1, lat2, lon2, num_points=10):
    lat1_rad, lon1_rad = math.radians(lat1), math.radians(lon1)
    lat2_rad, lon2_rad = math.radians(lat2), math.radians(lon2)

    interpolated_points = []
    for i in range(num_points):
        frac = i / (num_points - 1)
        lat_interp = lat1_rad * (1 - frac) + lat2_rad * frac
        lon_interp = lon1_rad * (1 - frac) + lon2_rad * frac
        interpolated_points.append((math.degrees(lat_interp), math.degrees(lon_interp)))
    
    return interpolated_points

# Generate quarter circle arc between two points (simplified approximation)
def quarter_circle(p1, p2, num_points=10):
    lat1, lon1 = p1
    lat2, lon2 = p2
    
    # Approximate the midpoint of the two points and find a control point to simulate a quarter-circle
    lat_mid = (lat1 + lat2) / 2
    lon_mid = (lon1 + lon2) / 2
    
    # Use a control point to simulate a quarter-circle
    control_lat = lat_mid + (lat2 - lat1) / 2
    control_lon = lon_mid + (lon2 - lon1) / 2
    
    # Interpolate along the curve (using linear approximation to simulate a curve)
    interpolated_points = interpolate_points(lat1, lon1, control_lat, control_lon, num_points//2)
    interpolated_points += interpolate_points(control_lat, control_lon, lat2, lon2, num_points//2)
    
    return interpolated_points

# Function to create a GPX track with a combination of quarter-circle curves and straight lines
def create_gpx_curved_and_straight(gps_points, output_file, num_interpolated_points=10):
    # Create the root element <gpx> with the necessary attributes
    gpx = ET.Element("gpx", version="1.1", creator="GPS Generator", xmlns="http://www.topografix.com/GPX/1/1")
    
    # Add metadata (optional)
    metadata = ET.SubElement(gpx, "metadata")
    name = ET.SubElement(metadata, "name")
    name.text = "Curved and Straight GPX Path"
    
    # Add track element <trk>
    trk = ET.SubElement(gpx, "trk")
    trk_name = ET.SubElement(trk, "name")
    trk_name.text = "Curved and Straight Track"

    # Add track segment element <trkseg>
    trkseg = ET.SubElement(trk, "trkseg")

    # Add interpolated segments: alternating between quarter-circle and straight lines
    all_points = []
    num_points = len(gps_points)
    
    for i in range(num_points):
        p1 = gps_points[i]
        p2 = gps_points[(i + 1) % num_points]
        p3 = gps_points[(i + 2) % num_points] if i < num_points - 1 else gps_points[0]  # Loop back to start if needed
        
        if i % 2 == 0:
            # For even indices (0, 2, 4...), add a quarter-circle curve between consecutive points
            curved_segment = quarter_circle(p1, p2, num_interpolated_points)
            all_points.extend(curved_segment)
        else:
            # For odd indices (1, 3, 5...), add a straight line between consecutive points
            straight_segment = interpolate_points(p2[0], p2[1], p3[0], p3[1], num_interpolated_points)
            all_points.extend(straight_segment)
    
    # Add each point to GPX track
    for lat, lon in all_points:
        trkpt = ET.SubElement(trkseg, "trkpt", lat=str(lat), lon=str(lon))

    # Convert the tree to a string with proper indentation
    xml_str = ET.tostring(gpx, encoding='unicode')
    xml_pretty = minidom.parseString(xml_str).toprettyxml(indent="  ")

    # Write the formatted GPX to a file
    with open(output_file, "w") as f:
        f.write(xml_pretty)

# Example usage with eight GPS points
gps_points = [
    (40.748817, -73.985428),  # Point 1: Lat, Lon
    (40.748900, -73.985500),  # Point 2: Lat, Lon
    (40.748950, -73.985600),  # Point 3: Lat, Lon
    (40.749000, -73.985650),  # Point 4: Lat, Lon
    (40.749050, -73.985700),  # Point 5: Lat, Lon
    (40.749100, -73.985750),  # Point 6: Lat, Lon
    (40.749150, -73.985800),  # Point 7: Lat, Lon
    (40.749200, -73.985850)   # Point 8: Lat, Lon
]

output_gpx_file = "curved_straight_gpx_track.gpx"

# Create GPX track with curved and straight paths
create_gpx_curved_and_straight(gps_points, output_gpx_file, num_interpolated_points=20)

print(f"GPX file generated: {output_gpx_file}")
